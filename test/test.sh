# !/bin/zsh

assert(){
   gcc -Wall -o ELF/main src/main.c
   ./ELF/main $1
}


assert "email@example.com"