#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/constant.h"
#include "../include/sanitizer.h"

int is_valid_length(char *localport){
    size_t length = strlen(localport);
    if(GENERAL_YAHOO_MIN_LENGTH <= length && length <= GENERAL_YAHOO_MAX_LENGTH) return 0;
    else return -1;
}


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
int* chars_map_to_ints(int (*func)(char), char *array, size_t len) {
    int i;
    int *flags = (int *)calloc(len, sizeof(int));
    for (i = 0; i < len; i++) flags[i] = func(array[i]);
    return flags;
}

int find_char_in_available_chars(char c){
    for(int i = 0; available_chars[i]; i++){
        if(c == available_chars[i]) return 0;
    }
    return 1;
}

int add(int arg1, int arg2){ return arg1+arg2 ;};

int get_is_valid_chars(char *localport){
    int flags_length = strlen(localport);
    int *flags = chars_map_to_ints(find_char_in_available_chars, localport, flags_length);
    int summation = int_reduce(add, flags, flags_length);
    if(summation==0) return 0;
    else return 1;
}

int validate_localport_for_general_yahoo(char * localport){
    // 文字数
    if(is_valid_length(localport)!=0){
        fprintf(stderr, "不適合");
        return 1;
    }
    // 構成文字
    if(get_is_valid_chars(localport)!=0){
        fprintf(stderr, "不適合");
        return 1;
    }
    // 先頭は英字


    // .の連続使用
    return 0;
}