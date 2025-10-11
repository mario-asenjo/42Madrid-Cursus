#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// Importa la cabecera obligatoria o bonus según necesites
#include "get_next_line_bonus.h"

// Colores para output bonito
#define GREEN   "\033[0;32m"
#define RED     "\033[0;31m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define RESET   "\033[0m"

// Ruta a los archivos de prueba
#define TEST_DIR "test_files/"

// Prototipo de get_next_line
char *get_next_line(int fd);

// Helpers para imprimir test
void print_header(const char *title) {
    printf(BLUE "\n===== %s =====\n\n" RESET, title);
}

void print_result(int success, const char *msg) {
    if (success)
        printf(GREEN "✔️  %s\n" RESET, msg);
    else
        printf(RED "❌ %s\n" RESET, msg);
}

// Crea archivos de test
void create_test_files(void) {
    system("mkdir -p test_files");

    struct {
        const char *filename;
        const char *content;
    } files[] = {
        {"empty.txt", ""},
        {"one_line.txt", "Una sola linea\n"},
        {"multiple_lines.txt", "Linea 1\nLinea 2\nLinea 3\n"},
        {"no_newline.txt", "Sin salto de linea final"},
        {"huge_line.txt", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ". 
                          "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n"},
        {"special_chars.txt", "Linea con ñ, ç, ☺, 漢字, emojis 😊\n"},
    };

    for (int i = 0; i < sizeof(files) / sizeof(files[0]); i++) {
        char path[256];
        snprintf(path, sizeof(path), "%s%s", TEST_DIR, files[i].filename);
        FILE *f = fopen(path, "w");
        if (f) {
            fputs(files[i].content, f);
            fclose(f);
        } else {
            perror("Error creating test file");
        }
    }
}

void test_basic_file(const char *filename, int expected_lines) {
    char path[256];
    snprintf(path, sizeof(path), "%s%s", TEST_DIR, filename);
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("open failed");
        return;
    }

    printf(YELLOW "Testing file: %s\n" RESET, filename);
    int lines = 0;
    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("  Line %d: \"%s\"\n", ++lines, line);
        free(line);
    }
    close(fd);
    print_result(lines == expected_lines, "Número correcto de líneas leídas");
}

void test_invalid_fd(void) {
    print_header("FD inválidos");

    char *line = get_next_line(-1);
    print_result(line == NULL, "FD -1 devuelve NULL");
    if (line) free(line);

    line = get_next_line(1000);  // probablemente inválido
    print_result(line == NULL, "FD 1000 devuelve NULL o error controlado");
    if (line) free(line);

    // Leer de STDOUT_FILENO
    line = get_next_line(STDOUT_FILENO);
    print_result(line == NULL, "FD de salida estándar no es legible");
    if (line) free(line);
}

void test_closed_fd(void) {
    print_header("Lectura tras close(fd)");

    char path[256];
    snprintf(path, sizeof(path), "%smultiple_lines.txt", TEST_DIR);
    int fd = open(path, O_RDONLY);
    if (fd < 0) return;

    char *line = get_next_line(fd);
    free(line);
    close(fd);

    line = get_next_line(fd);
    print_result(line == NULL, "Lectura tras close devuelve NULL");
    if (line) free(line);
}

void test_bonus_multi_fd(void) {
    print_header("Bonus: múltiples FDs simultáneos");

    int fd1 = open(TEST_DIR "multiple_lines.txt", O_RDONLY);
    int fd2 = open(TEST_DIR "one_line.txt", O_RDONLY);
    int fd3 = open(TEST_DIR "no_newline.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0) {
        perror("open failed");
        return;
    }

    char *l1 = get_next_line(fd1);
    char *l2 = get_next_line(fd2);
    char *l3 = get_next_line(fd3);

    print_result(l1 && strcmp(l1, "Linea 1\n") == 0, "FD1 lectura correcta");
    print_result(l2 && strcmp(l2, "Una sola linea\n") == 0, "FD2 lectura correcta");
    print_result(l3 && strcmp(l3, "Sin salto de linea final") == 0, "FD3 lectura correcta");

    free(l1); free(l2); free(l3);
    close(fd1); close(fd2); close(fd3);
}

int main(void) {
    create_test_files();

    print_header("Tests básicos");
    test_basic_file("empty.txt", 0);
    test_basic_file("one_line.txt", 1);
    test_basic_file("multiple_lines.txt", 3);
    test_basic_file("no_newline.txt", 1);
    test_basic_file("huge_line.txt", 1);
    test_basic_file("special_chars.txt", 1);

    test_invalid_fd();
    test_closed_fd();
    test_bonus_multi_fd();

    printf(GREEN "\n✅ Todos los tests han terminado. Usa valgrind para comprobar memoria.\n" RESET);
    return 0;
}

