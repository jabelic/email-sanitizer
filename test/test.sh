# !/bin/zsh

assert(){
   gcc -Wall -o ../ELF/main ../src/main.c
   ../ELF/main $1

   if [ "$?" -eq "0" ]
   then
      echo ">SUCCESS"
   else 
      echo ">FAIL"
   fi
}


assert "email@example.com"

#Gmailのテスト
assert "email.1@gmail.com"    #SUCCESS 半角英字、数字、ピリオドを使用できる
assert "email..1@gmail.com"   #FAIL ピリオドは連続して使用してはいけない
assert ".email1@gmail.com"    #FAIL ユーザー名の最初の文字はASCII文字(a-z)または数字(0-9)にする必要がある
assert "ema[il1@gmail.com"    #FAIL ユーザー名には＆、=、_、'、-、+、,、<>、を使用することはできない
assert "email436287489143fofhdsjfkhsjfhfsdhs534435kldfjdl@gmail.com" #FAIL 6文字から30文字の間で設定する必要がある