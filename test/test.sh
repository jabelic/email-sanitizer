# !/bin/zsh

assert(){
   # gcc -Wall -o ../ELF/main ../src/main.c
   # ../ELF/main $1
   gcc -Wall -o ELF/main src/main.c
   ELF/main $1

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
assert "email...1@gmail.com"  #FAIL ピリオドは連続して使用してはいけない
assert ".email1@gmail.com"    #FAIL ユーザー名の最初の文字はASCII文字(a-z)または数字(0-9)にする必要がある
assert "ema=il1@gmail.com"    #FAIL ユーザー名には＆、=、_、'、-、+、,、<>、を使用することはできない
assert "12345>@gmail.com"     #FAIL ユーザー名には＆、=、_、'、-、+、,、<>、を使用することはできない
assert "12345@gmail.com"      #FAIL 6文字から30文字の間で設定する必要がある
assert "email436287489143fofhdsjfkhsjfh@gmail.com" #FAIL 6文字から30文字の間で設定する必要がある


#yahooメール
assert "hoge@yahoo.co.jp"      #SUCCESS  4～31文字の半角英数字、記号（アンダーバー「_」のみ）が使える。大文字小文字の区別なし。
assert "hogE@yahoo.co.jp"      #SUCCESS  4～31文字の半角英数字、記号（アンダーバー「_」のみ）が使える。大文字小文字の区別なし。
assert "hoge_huga@yahoo.co.jp" #SUCCESS  4～31文字の半角英数字、記号（アンダーバー「_」のみ）が使える。大文字小文字の区別なし。
assert "10_23hoge@yahoo.co.jp" #SUCCESS  4～31文字の半角英数字、記号（アンダーバー「_」のみ）が使える。大文字小文字の区別なし
assert "hoge_@yahoo.co.jp"     #SUCCESS  4～31文字の半角英数字、記号（アンダーバー「_」のみ）が使える。大文字小文字の区別なし
assert "1hoge@yahoo.co.jp"     #FAIL     最初の文字は数字、記号ではなく必ずアルファベットにする。
assert "tmp@yahoo.co.jp"       #FAIL     ローカル部(ID)は4～31文字で構成される。
assert "t1p@yahoo.co.jp"       #FAIL     ローカル部(ID)は4～31文字で構成される。
