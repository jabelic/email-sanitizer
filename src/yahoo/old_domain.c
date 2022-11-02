#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/constant.h"
#include "../include/sanitizer.h"
#include "../include/utils.h"

/** 
    引数localportが有効な長さで構成されているかどうかを返す
*/
int is_valid_length(char *localport){
    size_t length = strlen(localport);
    if(GENERAL_YAHOO_MIN_LENGTH <= length && length <= GENERAL_YAHOO_MAX_LENGTH) return 0;
    else { return 1; }
}

/**
    引数cが有効な文字のうちのどれかであるかどうかを返す
*/
int find_char_in_available_chars(char c){
    for(int i = 0; available_chars_for_general_yahoo[i]; i++){
        if(c == available_chars_for_general_yahoo[i]) return 0;
    }
    return 1;
}

int add(int arg1, int arg2){ return arg1+arg2; };

/** 
    localportが有効な文字で構成されているかどうかを返す
*/
int get_is_valid_chars(char *localport){
    int flags_length = strlen(localport);
    int *flags = chars_map_to_ints(find_char_in_available_chars, localport, flags_length);
    int summation = int_reduce(add, flags, flags_length);
    if(summation==0) return 0;
    else { return 1; }
}

/**
    文字列の先頭が有効な文字であるかどうかを返す
*/
int get_is_valid_head_char(char *localport){
    char head_char = localport[0];
    
    /** 先頭の文字がNULLなら無効(存在チェック)　*/
    if(!head_char) return 1;

    for(int i = 0; available_head_char_for_general_yahoo[i]; i++){
        if(head_char == available_head_char_for_general_yahoo[i]) return 0;
    }
    return 1;
}

/** 
    末尾が有効な文字であるかどうかを返す
*/
int get_is_valid_tail_char(char *localport){
    int localport_length = strlen(localport);
    char tail_char = localport[localport_length-1];
    if(!tail_char) return 1;
    for(int i = 0; available_tail_char_for_general_yahoo[i]; i++){
        if(tail_char == available_tail_char_for_general_yahoo[i]) return 0;
    }
    return 1;
}

int validate_localport_for_general_yahoo(char * localport){
    // 文字数
    if(is_valid_length(localport)!=0){
        fprintf(stderr, "不適合\n");
        return 1;
    }
    // 構成文字
    else if(get_is_valid_chars(localport)!=0){
        fprintf(stderr, "不適合\n");
        return 1;
    }
    // 先頭は英字
    else if(get_is_valid_head_char(localport)!=0){
        fprintf(stderr, "不適合\n");
        return 1;
    }
    // 末尾はアンダーバー（ _ ）は使えず、半角英数字のみ使える
    else if(get_is_valid_tail_char(localport)!=0){
        fprintf(stderr, "不適合\n");
        return 1;
    }
    else{
        return 0;
    }
}