#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char *string;
    int const SIZE = 100;
    string = (char *)calloc(SIZE,sizeof(char)); // 1byte * SIZE分のメモリを確保
    fprintf(stdout, "%s", argv[1]);
    fprintf(stdout, "%s", string);
    return 0;
}