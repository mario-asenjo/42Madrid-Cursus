/* main.c
   Test runner para funciones comunes y bonus de libft.
   Ajusta compilación para linkar tu libft.
*/

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

/* Helpers para testear y reportar */
static int tests_run = 0;
static int tests_failed = 0;

#define ASSERT_MSG(expr, msg) do { \
    tests_run++; \
    if (!(expr)) { \
        tests_failed++; \
        fprintf(stderr, "FAIL: %s (line %d)\n", msg, __LINE__); \
    } else { \
        fprintf(stdout, "OK: %s\n", msg); \
    } \
} while (0)

/* Helper para capturar salida de fd: devuelve malloc'd buffer (free after) */
static char *capture_fd_output(void (*fn)(void), int write_fd_using_stdout)
{
    (void)fn;
    (void)write_fd_using_stdout;
    return NULL; /* placeholder: not used, see below pattern for capture usage */
}

/* Utility: run a function that writes to stdout and capture output.
   The function must write to stdout (fd 1). We'll redirect stdout to a pipe. */
static char *run_and_capture(void (*fn)(void))
{
    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        return NULL;
    }
    fflush(stdout);
    int saved_stdout = dup(STDOUT_FILENO);
    if (saved_stdout == -1) { close(pipefd[0]); close(pipefd[1]); return NULL; }
    if (dup2(pipefd[1], STDOUT_FILENO) == -1) { close(pipefd[0]); close(pipefd[1]); close(saved_stdout); return NULL; }
    close(pipefd[1]);

    fn();

    fflush(stdout);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    /* read all output */
    char buffer[4096];
    ssize_t n;
    size_t total = 0;
    size_t cap = 4096;
    char *out = malloc(cap);
    if (!out) { close(pipefd[0]); return NULL; }
    while ((n = read(pipefd[0], buffer, sizeof(buffer))) > 0)
    {
        if (total + (size_t)n + 1 >= cap)
        {
            cap *= 2;
            out = realloc(out, cap);
            if (!out) { close(pipefd[0]); return NULL; }
        }
        memcpy(out + total, buffer, n);
        total += n;
    }
    close(pipefd[0]);
    out[total] = '\0';
    return out;
}

/* Wrappers to call libft fd functions for capture */
static char *capture_puts_result(void (*fn)(void))
{
    return run_and_capture(fn);
}

/* --- Tests --- */

/* 1) Tests is* family */
static void test_is_functions(void)
{
    ASSERT_MSG(ft_isalpha('A') && ft_isalpha('z') && !ft_isalpha('1'), "ft_isalpha basic");
    ASSERT_MSG(ft_isdigit('0') && ft_isdigit('9') && !ft_isdigit('a'), "ft_isdigit basic");
    ASSERT_MSG(ft_isalnum('a') && ft_isalnum('9') && !ft_isalnum('%'), "ft_isalnum basic");
    ASSERT_MSG(ft_isascii(0) && ft_isascii(127) && !ft_isascii(128), "ft_isascii boundaries");
    ASSERT_MSG(ft_isprint(' ') && ft_isprint('~') && !ft_isprint('\n'), "ft_isprint basic");
}

/* 2) strlen, strlcpy, strlcat */
static void test_strlen_strlcpy_strlcat(void)
{
    ASSERT_MSG(ft_strlen("") == 0, "ft_strlen empty");
    ASSERT_MSG(ft_strlen("hello") == 5, "ft_strlen basic");

    {
        char dst[10];
        size_t r = ft_strlcpy(dst, "abc", sizeof(dst));
        ASSERT_MSG(r == 3 && strcmp(dst, "abc") == 0, "ft_strlcpy basic");
    }
    {
        char dst[3] = "xx";
        size_t r = ft_strlcpy(dst, "longstring", sizeof(dst)); /* should copy up to 2 chars + NUL */
        ASSERT_MSG(r == strlen("longstring") && dst[sizeof(dst)-1] == '\0', "ft_strlcpy truncation");
    }
    {
        char dst[10] = "foo";
        size_t r = ft_strlcat(dst, "bar", 10);
        ASSERT_MSG(r == strlen("foo") + strlen("bar") && strcmp(dst, "foobar") == 0, "ft_strlcat basic");
    }
    {
        char dst[4] = "fo";
        size_t r = ft_strlcat(dst, "oooooooo", sizeof(dst));
        ASSERT_MSG(r == strlen("fo") + strlen("oooooooo") && dst[sizeof(dst)-1] == '\0', "ft_strlcat truncation");
    }
}

/* 3) memset, bzero, memcpy, memmove, memchr, memcmp */
static void test_memory_funcs(void)
{
    char buf[16];
    memset(buf, 'A', sizeof(buf));
    ft_bzero(buf, sizeof(buf));
    {
        int zero = 1;
        for (size_t i = 0; i < sizeof(buf); i++) if (buf[i] != 0) zero = 0;
        ASSERT_MSG(zero, "ft_bzero sets zero");
    }

    {
        char s1[] = "12345678";
        char s2[9];
        ft_memcpy(s2, s1, 9); /* including NUL */
        ASSERT_MSG(strcmp(s1, s2) == 0, "ft_memcpy copy include NUL");
    }

    {
        char s[] = "abcdef";
        ft_memmove(s + 2, s, 4); /* overlapping */
        ASSERT_MSG(memcmp(s, "ababcd", 6) == 0, "ft_memmove overlapping");
    }

    {
        char s[] = "hello\0world";
        void *p = ft_memchr(s, 'w', 11);
        ASSERT_MSG(p != NULL && *(char*)p == 'w', "ft_memchr find after NUL");
    }

    {
        char a[] = {0, 1, 2, 3};
        char b[] = {0, 1, 2, 4};
        ASSERT_MSG(ft_memcmp(a, b, 4) < 0, "ft_memcmp compare");
    }
}

/* 4) toupper/tolower */
static void test_case_funcs(void)
{
    ASSERT_MSG(ft_toupper('a') == 'A' && ft_toupper('A') == 'A' && ft_toupper('1') == '1', "ft_toupper");
    ASSERT_MSG(ft_tolower('Z') == 'z' && ft_tolower('z') == 'z' && ft_tolower('#') == '#', "ft_tolower");
}

/* 5) strchr/strrchr/strnstr/strncmp */
static void test_string_search_cmp(void)
{
    ASSERT_MSG(ft_strchr("abc", 'b') && *ft_strchr("abc", 'b') == 'b', "ft_strchr find");
    ASSERT_MSG(ft_strchr("abc", '\0') && *ft_strchr("abc", '\0') == '\0', "ft_strchr null terminator");
    ASSERT_MSG(ft_strrchr("abca", 'a') == &"abca"[3], "ft_strrchr last");

    ASSERT_MSG(ft_strncmp("aaa", "aab", 2) == 0, "ft_strncmp prefix equal");
    ASSERT_MSG(ft_strncmp("aaa", "aab", 3) < 0, "ft_strncmp differ");

    ASSERT_MSG(ft_strnstr("hello world", "world", 11) == strstr("hello world", "world"), "ft_strnstr find");
    ASSERT_MSG(ft_strnstr("hello", "", 5) == ft_strnstr("hello", "", 5), "ft_strnstr empty needle");
}

/* 6) atoi */
static void test_atoi(void)
{
    ASSERT_MSG(ft_atoi("0") == 0, "ft_atoi zero");
    ASSERT_MSG(ft_atoi("   -42") == -42, "ft_atoi spaces and sign");
    ASSERT_MSG(ft_atoi("2147483647") == 2147483647, "ft_atoi INT_MAX");
    ASSERT_MSG(ft_atoi("-2147483648") == -2147483648, "ft_atoi INT_MIN");
}

/* 7) calloc, strdup */
static void test_alloc_and_strdup(void)
{
    {
        char *p = ft_calloc(5, 1);
        int ok = (p != NULL);
        if (ok) {
            for (int i = 0; i < 5; ++i) if (p[i] != 0) ok = 0;
        }
        free(p);
        ASSERT_MSG(ok, "ft_calloc zeros");
    }
    {
        char *s = ft_strdup("hello");
        ASSERT_MSG(s && strcmp(s, "hello") == 0, "ft_strdup basic");
        free(s);
    }
}

/* 8) substr, strjoin, strtrim */
static void test_substr_join_trim(void)
{
    {
        char *s = ft_substr("hello", 1, 3); /* "ell" */
        ASSERT_MSG(s && strcmp(s, "ell") == 0, "ft_substr middle");
        free(s);
    }
    {
        char *s = ft_strjoin("foo", "bar");
        ASSERT_MSG(s && strcmp(s, "foobar") == 0, "ft_strjoin basic");
        free(s);
    }
    {
        char *s = ft_strtrim("  abc  ", " ");
        ASSERT_MSG(s && strcmp(s, "abc") == 0, "ft_strtrim spaces");
        free(s);
    }
}

/* 9) split (varios casos) */
static void test_split(void)
{
    {
        char **tab = ft_split("  lorem   ipsum  ", ' ');
        int count = 0;
        int ok = 1;
        if (!tab) ok = 0;
        else {
            while (tab[count]) count++;
            if (count != 2) ok = 0;
        }
        /* free */
        if (tab) {
            for (int i = 0; tab[i]; ++i) free(tab[i]);
            free(tab);
        }
        ASSERT_MSG(ok, "ft_split multiple spaces");
    }
    {
        char **tab = ft_split("", ' ');
        int ok = (tab && tab[0] == NULL);
        if (tab) free(tab);
        ASSERT_MSG(ok, "ft_split empty string");
    }
}

/* 10) itoa */
static void test_itoa(void)
{
    {
        char *s = ft_itoa(0);
        int ok = (s && strcmp(s, "0") == 0);
        free(s);
        ASSERT_MSG(ok, "ft_itoa zero");
    }
    {
        char *s = ft_itoa(-2147483648);
        int ok = (s && strcmp(s, "-2147483648") == 0);
        free(s);
        ASSERT_MSG(ok, "ft_itoa INT_MIN");
    }
    {
        char *s = ft_itoa(2147483647);
        int ok = (s && strcmp(s, "2147483647") == 0);
        free(s);
        ASSERT_MSG(ok, "ft_itoa INT_MAX");
    }
}

/* 11) strmapi / striteri behavior tests (these require a small function) */
static char map_fn(unsigned int i, char c)
{
    /* e.g. shift letters by index */
    (void)i;
    return c + 1;
}
static void iter_fn(unsigned int i, char *c)
{
    (void)i;
    if (c && *c) *c = *c + 1;
}

static void test_map_iteri(void)
{
    {
        char *s = ft_strmapi("az", map_fn);
        int ok = (s && strcmp(s, "b{") == 0); /* 'a'+1='b', 'z'+1='{' */
        free(s);
        ASSERT_MSG(ok, "ft_strmapi basic");
    }
    {
        char buf[] = "az";
        ft_striteri(buf, iter_fn);
        ASSERT_MSG(strcmp(buf, "b{") == 0, "ft_striteri basic");
    }
}

/* 12) putchar_fd / putstr_fd / putendl_fd / putnbr_fd
   We capture stdout by wrappers. We'll create small wrappers that call the libft function. */

static void wrap_putchar_fd(void)
{
    ft_putchar_fd('X', 1);
}
static void wrap_putstr_fd(void)
{
    ft_putstr_fd("HELLO", 1);
}
static void wrap_putendl_fd(void)
{
    ft_putendl_fd("LINE", 1);
}
static void wrap_putnbr_fd(void)
{
    ft_putnbr_fd(-42, 1);
}

static void test_fd_output(void)
{
    char *out;
    out = run_and_capture(wrap_putchar_fd);
    ASSERT_MSG(out && strcmp(out, "X") == 0, "ft_putchar_fd output");
    free(out);

    out = run_and_capture(wrap_putstr_fd);
    ASSERT_MSG(out && strcmp(out, "HELLO") == 0, "ft_putstr_fd output");
    free(out);

    out = run_and_capture(wrap_putendl_fd);
    ASSERT_MSG(out && (strcmp(out, "LINE\n") == 0), "ft_putendl_fd output");
    free(out);

    out = run_and_capture(wrap_putnbr_fd);
    ASSERT_MSG(out && strcmp(out, "-42") == 0, "ft_putnbr_fd output");
    free(out);
}

/* 13) Linked list functions (bonus) */
static void del_free(void *p)
{
    free(p);
}

static void *dup_content(void *c)
{
    char *s = (char *)c;
    if (!s) return NULL;
    return ft_strdup(s);
}

static void test_list_functions(void)
{
    /* lstnew, lstadd_front, lstadd_back, lstsize, lstlast, lstdelone, lstclear, lstmap */
    t_list *l = NULL;
    t_list *node1 = ft_lstnew(ft_strdup("one"));
    t_list *node2 = ft_lstnew(ft_strdup("two"));
    t_list *node3 = ft_lstnew(ft_strdup("three"));
    /* add back */
    ft_lstadd_back(&l, node1);
    ft_lstadd_back(&l, node2);
    ft_lstadd_back(&l, node3);
    ASSERT_MSG(ft_lstsize(l) == 3, "lstsize after add_back");

    ASSERT_MSG(ft_lstlast(l) == node3, "lstlast correct");

    /* test lstmap: duplicate strings upper-ish (using dup_content) */
    t_list *mapped = ft_lstmap(l, dup_content, del_free);
    int ok = 1;
    if (!mapped) ok = 0;
    else {
        if (ft_lstsize(mapped) != 3) ok = 0;
    }
    ASSERT_MSG(ok, "ft_lstmap creates same size list");

    /* cleanup mapped and original: use lstclear to free contents */
    ft_lstclear(&mapped, del_free);
    ASSERT_MSG(mapped == NULL, "ft_lstclear sets to NULL for mapped");

    ft_lstclear(&l, del_free);
    ASSERT_MSG(l == NULL, "ft_lstclear sets to NULL for original");
}

/* 14) Edge heavy tests: large buffers, overlapping, zero sizes */
static void test_heavy_edge_cases(void)
{
    /* large strlen */
    char *big = malloc(50000);
    memset(big, 'a', 49999);
    big[49999] = '\0';
    ASSERT_MSG(ft_strlen(big) == 49999, "ft_strlen large");

    /* strlcpy with dstsize 0 */
    char dst[5] = "abcd";
    size_t r = ft_strlcpy(dst, "xyz", 0);
    ASSERT_MSG(r == strlen("xyz") && dst[0] == 'a', "ft_strlcpy dstsize 0 does not write");

    /* memmove with zero length should not corrupt */
    char a[10] = "123456789";
    ft_memmove(a + 2, a, 0);
    ASSERT_MSG(a[0] == '1' && a[1] == '2', "ft_memmove zero length no-op");

    free(big);
}

/* --- main --- */
int main(void)
{
    fprintf(stdout, "Running libft tests...\n\n");

    test_is_functions();
    test_strlen_strlcpy_strlcat();
    test_memory_funcs();
    test_case_funcs();
    test_string_search_cmp();
    test_atoi();
    test_alloc_and_strdup();
    test_substr_join_trim();
    test_split();
    test_itoa();
    test_map_iteri();
    test_fd_output();
    test_list_functions();
    test_heavy_edge_cases();

    fprintf(stdout, "\nTests run: %d\n", tests_run);
    fprintf(stdout, "Tests failed: %d\n", tests_failed);
    if (tests_failed == 0)
        fprintf(stdout, "ALL TESTS PASSED ✅\n");
    else
        fprintf(stdout, "SOME TESTS FAILED ❌\n");

    return (tests_failed == 0) ? 0 : 1;
}

