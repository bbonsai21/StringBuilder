#define BENCHMARKING

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringbuilder.h"

#define ITERATIONS  1000000

int main(void)
{
#ifndef BENCHMARKING
    /* ==================== DEMO MODE ==================== */
    printf("=== NORMAL STRING ===\n");
    const char *str = "Goodbye my past - here comes a vague taste! Hello, World! 3.14 69";
    printf("String: %s\nLength: %zu\n\n", str, strlen(str));

    printf("=== STRING BUILDER ===\n");
    StringBuilder* sb = sb_new_capacity_of(64);
    sb_appends(sb, "Goodbye my past - here comes a vague taste! ");
    sb_appends(sb, "Hello, World! ");
    sb_appendf(sb, 3.14);
    sb_appends(sb, " ");
    sb_appendi(sb, 69);

    char* result = sb_build(sb);
    printf("String: %s\nLength: %zu\n", result, sb_length(sb));

    sb_free(sb);
    free(result);
#endif

#ifdef BENCHMARKING
    /* ==================== BENCHMARK MODE ==================== */
    printf("=== STARTING BENCHMARK (%d iterations) ===\n", ITERATIONS);

    for (int i = 0; i < ITERATIONS; i++)
    {
        StringBuilder* sb = sb_new_capacity_of(32);

        sb_appends(sb, "Hello world ");
        sb_appendi(sb, i);
        sb_appends(sb, " - ");
        sb_appendf(sb, (double)rand() / RAND_MAX * 1000.0);

        char* built = sb_build(sb);
        volatile char first_char = built[0]; // anti-optimisation
        (void)first_char;

        sb_free(sb);
        free(built);
    }

    printf("Benchmark completed.\n");
#endif

    return 0;
}
