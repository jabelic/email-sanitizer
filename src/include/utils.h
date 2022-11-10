#include <stdlib.h>
int int_reduce(int (*func)(int, int), int *array, size_t len);
int* chars_map_to_ints_with_calloc(int (*func)(char), char *array, size_t len);
int add(int arg1, int arg2);
int free_and_NULL_padding(char *cp);