#include <stdio.h>
#include <stdlib.h>

#include "../../include/constant.h"
#include "../../include/old_domain.h"
#include "../../include/sanitizer.h"

void print_result(char *testcase, char *result) {
    fprintf(stdout, "  pass! \n    target: %s\n    toBe  : %s\n", testcase,
            result);
}

/* yahoo.co.jp */
int describe_for_is_valid_length() {
    /** test: 引数localportが有効な長さで構成されているかどうかを返す　*/
    char testcases[][GENERAL_YAHOO_MAX_LENGTH + 5] = {
        "hogehuga", "ema", "email436287489143fofhdsjfkhsjfhA"};
    int expected[] = {0, 1, 1};
    const int CASES = 3;

    /** unit test 実行 */
    for (int i = 0; i < CASES; i++) {
        if (is_valid_length(testcases[i]) != expected[i]) {
            fprintf(stderr, "ERROR\n");
            return 1;
        } else {
            print_result(testcases[i],
                         expected[i] == 0 ? "supported" : "not-supported");
        }
    }
    printf("\n");
    return 0;
}

int describe_for_find_char_in_available_chars() {
    /** test: 引数cが有効な文字のうちのどれかであるかどうかを返す */
    char testcases[][2] = {"A", "a", "_", "]", "."};
    int expected[] = {0, 0, 0, 1, 1};
    const int CASES = 5;

    /** unit test 実行 */
    for (int i = 0; i < CASES; i++) {
        if (find_char_in_available_chars(testcases[i][0]) != expected[i]) {
            fprintf(stderr, "ERROR\n");
            return 1;
        } else {
            print_result(testcases[i],
                         expected[i] == 0 ? "supported" : "not-supported");
        }
    }
    printf("\n");
    return 0;
}

int describe_for_get_is_valid_head_char() {
    /** test: 文字列の先頭が有効な文字であるかどうかを返す */
    char testcases[][GENERAL_YAHOO_MAX_LENGTH] = {"hgoehuga",     "Abcdefg",
                                                  "0123hogehuga", "_hogehuga",
                                                  "-hogehuga",    ".hogehuga"};
    int expected[] = {0, 0, 1, 1, 1, 1};
    const int CASES = 6;

    /** unit test 実行 */
    for (int i = 0; i < CASES; i++) {
        if (get_is_valid_head_char(testcases[i]) != expected[i]) {
            fprintf(stderr, "ERROR\n");
            return 1;
        } else {
            print_result(testcases[i],
                         expected[i] == 0 ? "supported" : "not-supported");
        }
    }
    printf("\n");
    return 0;
}

int describe_for_get_is_valid_tail_char() {
    /** test: 末尾が有効な文字であるかどうかを返す */
    char testcases[][GENERAL_YAHOO_MAX_LENGTH] = {"hgoehuga",     "abcdefA",
                                                  "hogehuga0123", "hogehuga_",
                                                  "hogehuga=",    "hogehuga."};
    int expected[] = {0, 0, 0, 1, 1, 1};
    const int CASES = 6;

    /** unit test 実行 */
    for (int i = 0; i < CASES; i++) {
        if (get_is_valid_tail_char(testcases[i]) != expected[i]) {
            fprintf(stderr, "  unexpected!\n");
            return 1;
        } else {
            print_result(testcases[i],
                         expected[i] == 0 ? "supported" : "not-supported");
        }
    }
    printf("\n");
    return 0;
}

int unittest() {
    fprintf(stdout, "=====       unit test       =====\n");

    int is_passed;

    /** yahoo.co.jp */
    fprintf(stdout, "UNIT TEST:  %s\n", "is_valid_length");
    is_passed = describe_for_is_valid_length();
    if (is_passed != 0) return 1;

    fprintf(stdout, "UNIT TEST:  %s\n", "find_char_in_available_chars");
    is_passed = describe_for_find_char_in_available_chars();
    if (is_passed != 0) return 1;

    fprintf(stdout, "UNIT TEST:  %s\n", "is_valid_head_char");
    is_passed = describe_for_get_is_valid_head_char();
    if (is_passed != 0) return 1;

    fprintf(stdout, "UNIT TEST:  %s\n", "is_valid_tail_char");
    is_passed = describe_for_get_is_valid_tail_char();
    if (is_passed != 0) return 1;

    fprintf(stdout, "===== all cases are passed! =====\n\n");
    return 0;
}
