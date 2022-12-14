#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/constant.h"
#include "include/sanitizer.h"
#include "include/utils.h"

int check_localport_gmail(char *localport) {
    // 6文字から30文字の間であることを確認
    int len = strlen(localport);
    if (len < GMAIL_MIN_LENGTH || GMAIL_MAX_LENGTH < len) {
        printf("6文字から30文字の間で設定する必要があります\n");
        return 1;
    }

    //使用不可の記号が利用されていないことを確認（ブラックリスト方式）
    //参考：https://www.jpcert.or.jp/sc-rules/c-str02-c.html
    const char ng_chars[] = "&=_'-+,<>";
    for (int i = 0; i < sizeof(ng_chars); i++) {
        for (int j = 0; j < len; j++) {
            if (ng_chars[i] == localport[j]) {
                printf(
                    "アンパサンド（＆）、等号（=）、アンダースコア（_"
                    "）、アポストロフィ（'）、ダッシュ（-）、プラス記号（+"
                    "）、カンマ（,）、山括弧（<>"
                    "）を使用することはできません。\n");
                return 1;
            }
        }
    }

    //半角英字、数字、ピリオドのみで構成されていること確認（ホワイトリスト方式）
    //参考：https://www.jpcert.or.jp/sc-rules/c-str02-c.html
    const char ok_chars[] =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "1234567890.";
    for (int i = 0; i < len; i++) {
        bool flag = false;
        for (int j = 0; j < sizeof(ok_chars); j++) {
            if (localport[i] == ok_chars[j]) {
                flag = true;
            }
        }
        if (!flag) {
            printf("アルファベット、数字、ピリオドのみが使用できます\n");
            return 1;
        }
    }

    //先頭にピリオドが含まれていないことを確認
    if (localport[0] == '.') {
        printf(
            "最初の文字は半角英字(a-z)または数字(0-9)にする必要があります\n");
        return 1;
    }

    //ピリオドが連続して使用されていないことを確認
    bool flag1 = false;
    bool flag2 = false;
    for (int i = 0; i < len; i++) {
        if (localport[i] == '.' && !flag1) {
            flag1 = true;
        } else if (localport[i] == '.' && flag1) {
            flag2 = true;
        } else if (localport[i] != '.' && flag1) {
            flag1 = false;
        }

        if (flag1 && flag2) {
            printf("ユーザー名に連続するピリオドを含めることが出来ません\n");
            return 1;
        }
    }
    return 0;
}

int check_domain(char *mail) {
    int res = 0;

    // 文字列をlocalportとdomainに分割
    // NOTE: strtokの使用には下記を参照
    // https://www.jpcert.or.jp/sc-rules/c-str06-c.html
    char *copy;
    // NOTE: 動的メモリ確保の際には例外処理を行う(第12回資料P.9)
    if ((copy = (char *)malloc(strlen(mail) + 1)) == NULL) {
        perror("malloc()");
        exit(1);
    }
    strcpy(copy, mail);
    char *localport = strtok(copy, "@");
    char *domain = strtok(NULL, "@");

    /** domainまたはlocalpostがNULLだった場合は弾く */
    if (domain == NULL || localport == NULL) {
        free_and_NULL_padding(copy);
        return 1;
    }
    /** Gmail */
    if (strcmp(domain, "gmail.com") == 0) {
        printf("これはGmailのメールアドレスです\n");
        res = check_localport_gmail(localport);
        free_and_NULL_padding(copy);
        return res;
    }
    /** Yahoo!Japan(co.jp) */
    else if (strcmp(domain, YAHOO_GENERAL_DOMAIN) == 0) {
        if (validate_localport_for_general_yahoo(localport) != 0) {
            free_and_NULL_padding(copy);
            return 1;
        } else {
            free_and_NULL_padding(copy);
            return 0;
        }
    }
    /** Yahoo!Japan(ne.jp) */
    else if (strcmp(domain, YAHOO_NEW_DOMAIN) == 0) {
        printf("Yahoo!Japan(ne.jp)のメールアドレスは未対応です。");
        free_and_NULL_padding(copy);
        return 0;
    } else {
        printf("これは非対応のメールアドレスです\n");
        free_and_NULL_padding(copy);
        return 1;
    }
    free_and_NULL_padding(copy);

    return res;
}

int main(int argc, char *argv[]) {
    /** dev mode のときはunittestを走らせる　*/
    // FIXME: "-dev"を定数にする
    if (argv != NULL && argv[1] != NULL && strcmp(argv[1], "-dev") == 0) {
        int is_passed = unittest();
        if (is_passed != 0) {
            return 1;
        } else {
            return 0;
        }
    } else if (argv != NULL && argv[1] != NULL && check_domain(argv[1]) == 0) {
        return 0;
    } else {
        return 1;
    }
}
