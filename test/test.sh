# !/bin/zsh

assert(){
   expected="$1"
   input="$2"
   ./a.out "$input"
   actual="$?"

   if [ "$actual" = "$expected" ]; then
        echo "PASS: $input => $actual\n"
    else
        echo "$input => $expected expected, but got $actual"
        exit 1
    fi

   # if [ "$?" -eq "0" ]
   # then
   #    echo ">SUCCESS\n"
   # else 
   #    echo ">FAIL\n"
   # fi
}


# assert "email@example.com"

# #Gmailのテスト
# assert "email.1@gmail.com"    #SUCCESS 半角英字、数字、ピリオドを使用できる
# assert "email..1@gmail.com"   #FAIL ピリオドは連続して使用してはいけない
# assert "email...1@gmail.com"  #FAIL ピリオドは連続して使用してはいけない
# assert ".email1@gmail.com"    #FAIL ユーザー名の最初の文字はASCII文字(a-z)または数字(0-9)にする必要がある
# assert "ema=il1@gmail.com"    #FAIL ユーザー名には＆、=、_、'、-、+、,、<>、を使用することはできない
# assert "12345>@gmail.com"     #FAIL ユーザー名には＆、=、_、'、-、+、,、<>、を使用することはできない
# assert "12345@gmail.com"      #FAIL 6文字から30文字の間で設定する必要がある
# assert "email436287489143fofhdsjfkhsjfh@gmail.com" #FAIL 6文字から30文字の間で設定する必要がある


# # yahoo.co.jp
# # 4～31文字の半角英数字、記号（ _ ）が使える。先頭の文字は必ず英字。
# # おそらく末尾に記号（ _ ）は使えない
assert 0 "hoge@yahoo.co.jp"      #SUCCESS  
assert 0 "hogE@yahoo.co.jp"      #SUCCESS 
assert 0 "hoge_123_huga@yahoo.co.jp" #SUCCESS  
assert 1 "email436287489143fofhdsjfkhsjfhABC@yahoo.co.jp"     #FAIL  ローカル部(ID)は4～31文字で構成される。
assert 1 "tmp@yahoo.co.jp"       #FAIL     ローカル部(ID)は4～31文字で構成される。
assert 1 "t1p@yahoo.co.jp"       #FAIL     ローカル部(ID)は4～31文字で構成される。
assert 1 "1hoge@yahoo.co.jp"     #FAIL     最初の文字は数字、記号ではなく必ずアルファベットにする。
assert 1 "hoge<->@yahoo.co.jp"   #FAIL     半角英数字、記号（ _ ）が使える
assert 1 "hoge_@yahoo.co.jp"     #FAIL

# ymail.ne.jp
# 使用可能な文字：半角小文字英数字、「\_」（アンダーバー)、「.」(ドット)、「-」（ハイフン）
# 文字列の長さ：3 文字〜29 文字
# 先頭の文字は半角小文字英数字のみ使用できます
# 「.」(ドット)の末尾での使用や、連続使用はできません
# assert "hog@ymail.ne.jp"                     #SUCCESS
# assert "hoge-huga.123@ymail.ne.jp"           #SUCCESS
# assert "hoge_huga-123.piyo@ymail.ne.jp"      #SUCCESS
# assert "hoge_huga-123-@ymail.ne.jp"          #SUCCESS
# assert "hoge_huga-123_@ymail.ne.jp"          #SUCCESS
# assert "hoge_huga-123.@ymail.ne.jp"          #FAIL  「.」(ドット)の末尾での使用や、連続使用はできません
# assert "hoge_huga1..23@ymail.ne.jp"          #FAIL  「.」(ドット)の末尾での使用や、連続使用はできません
# assert "_huga-123@ymail.ne.jp"               #FAIL  先頭の文字は半角小文字英数字のみ使用できます
# assert "-huga_123@ymail.ne.jp"               #FAIL  先頭の文字は半角小文字英数字のみ使用できます
# assert ".huga_123@ymail.ne.jp"               #FAIL  先頭の文字は半角小文字英数字のみ使用できます

# assert "hoge@yahoo.ne.jp"      #FAIL Y!mobileには非対応