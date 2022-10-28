#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_domain(char *mail){
    char *str = strtok(mail, "@");
    if(strcmp(*str[1],"gmail.com")==0){
        printf("これはGmailのメールアドレスです\n");
        //サニタイズの処理を実装
    }
    else{
        printf("これはその他のメールアドレスです\n");
        //サニタイズの処理を実装
    }
}

int main(int argc, char *argv[]){
    char *string;
    int const SIZE = 100;
    string = (char *)calloc(SIZE,sizeof(char)); // 1byte * SIZE分のメモリを確保
    fprintf(stdout, "%s", argv[1]);

    check_domain(argv[1]);

    fprintf(stdout, "%s", string);
    return 0;
}

