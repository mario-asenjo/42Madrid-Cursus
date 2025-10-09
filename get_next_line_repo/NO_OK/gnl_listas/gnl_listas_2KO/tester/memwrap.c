#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static int malloc_calls = 0;
static int fail_after = -1;

void set_malloc_fail_after(int n)
{
	fail_after = n;
	malloc_calls = 0;
}

void *debug_malloc(size_t size)
{
	if (fail_after >= 0 && malloc_calls++ >= fail_after)
	{
		fprintf(stderr, "[MEMWRAP] Simulating malloc failure at call #%d\n", malloc_calls);
		return NULL;
	}
	return malloc(size);
}
