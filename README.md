# email sanitizer

## 実行方法

`$ make test`

## Gmail

メールアドレスが Gmail の場合、Gmail の要件に基づいてサニタイズを実施する

ローカル部の仕様は下記の通り(公式のドキュメントはリスト下部のリンクを参照)

- 半角英字、数字、ピリオドを使用できる
- ピリオドは連続して使用してはいけない
- ユーザー名の最初の文字は半角英字(a-z)または数字(0-9)にする必要がある
- 6 文字から 30 文字の間で設定する必要がある
- ユーザー名にはアンパサンド（＆）、等号（=）、アンダースコア（\_）、アポストロフィ（'）、ダッシュ（-）、プラス記号（+）、カンマ（,）、山括弧（<>）、連続するピリオド（.）を使用することはできません。（実際にここであげられている記号以外も使用不可）

[Gmail ヘルプ - ユーザー名の作成](https://support.google.com/mail/answer/9211434?hl=ja#:~:text=%E3%83%A6%E3%83%BC%E3%82%B6%E3%83%BC%E5%90%8D%E3%81%AB%E3%81%AF%E3%82%A2%E3%83%AB%E3%83%95%E3%82%A1%E3%83%99%E3%83%83%E3%83%88,%E4%BD%BF%E7%94%A8%E3%81%99%E3%82%8B%E3%81%93%E3%81%A8%E3%81%AF%E3%81%A7%E3%81%8D%E3%81%BE%E3%81%9B%E3%82%93%E3%80%82)

## `yahoo.co.jp`

- 4 ～ 31 文字の半角英数字、記号（ \_ ）が使える。
- 先頭の文字は必ず英字。
- おそらく末尾に記号（ \_ ）は使えない(という体で進めます)

[ログインできない：ID やパスワードなどの文字を入力する際の注意点](https://support.yahoo-net.jp/PccLogin/s/article/H000004668)

> Yahoo! JAPAN ID は、半角のアルファベット（A ～ Z a ～ z）、数字、アンダーバー「 \_ 」を組み合わせた文字列です

参考：https://allabout.co.jp/gm/gc/23697/

> Yahoo!JAPAN ID は 4 ～ 31 文字の半角英数字、記号（アンダーバー「\_」のみ）です。大文字、小文字の区別はありません。また最初の文字は数字、記号ではなく必ずアルファベットにします。

## `ymail.ne.jp`

以下をそのままルールとして利用。ymail 登録ページから引用：

> 使用可能な文字：半角小文字英数字、「\_」（アンダーバー)、「.」(ドット)、「-」（ハイフン）
> 文字列の長さ：3 文字〜29 文字
> 先頭の文字は半角小文字英数字のみ使用できます
> 「.」(ドット)の末尾での使用や、連続使用はできません
