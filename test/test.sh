# !/bin/zsh

assert(){
   gcc -Wall -o main src/main.c
   ./main $1
}


assert "email@example.com"