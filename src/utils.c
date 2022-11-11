#include "include/utils.h"

#include <stdio.h>
#include <stdlib.h>

int int_reduce(int (*func)(int, int), int *array, size_t len) {
    int i;
    int result = 0;
    for (i = 0; i < len; i++) result = func(result, array[i]);
    return result;
}

/**
    map風関数
    - charの配列の各要素に関数を適用し、intの配列を返す
*/
int *chars_map_to_ints_with_calloc(int (*func)(char), char *array, size_t len) {
    int i;
    int *flags;
    // NOTE: 動的メモリ確保の際には例外処理を行う(第12回資料P.9)
    if ((flags = (int *)calloc(len, sizeof(int))) == NULL) {
        perror("calloc()");
        exit(1);
    }
    for (i = 0; i < len; i++) flags[i] = func(array[i]);
    return flags;
}

int add(int arg1, int arg2) { return arg1 + arg2; };

int free_and_NULL_padding(char *cp) {
    if (cp == NULL) return 1;
    free(cp);
    cp = NULL;
    return 0;
}