#2章

##データリンク層を扱うには


###socket

- ソケットの作成。失敗したら`-1`が返ってくる

```
#TCPのソケット
socket(PF_INET, SOCK_STREAM, 0);
#UDPのソケット
socket(PF_INET, SOCK_DGRAM, 0);
#Ethernet
socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
```

###snprintf

http://www.c-tipsref.com/reference/stdio/snprintf.html

- 下の例で言えば`s`に特定の文字列を書き込む。（出力はしない）

```
/* header files */
#include <stdio.h>
#include <stdlib.h>

/* macros */
#define N 256

/* main */
int main(void) {
	char s[N] = {'\0'};
	char name[] = "チャーリー・ブラウン";
	char sex[] = "男性";
	int age = 4;

	snprintf(s, N, "%sさんは%d歳の%sです．", name, age, sex);

	printf("%s\n", s); 

	return EXIT_SUCCESS;
}
```


###fprintf


###memset


###ntohs



##結果を実行してみる

```
$ gcc ltest.c
$ sudo ./a.out eth1

ether_header--------------------
ether_dhost=08:00:27:4f:b8:06
ether_shost=52:54:00:12:35:02
ether_type=800
```

#3章

##includeの違い

```
//自分で書いたヘッダーファイル
#include "write_own.h"
//システムにあるファイル
#include <stdio.h>
```

- `.h`ファイルに関数を宣言しとくのは、外から使いたい場合には関数を宣言しておく必要がある。

##`u_char`型

- unsigned charの略らしい

>u_int型とかu_char型ってなに？ - Clouder::Blogger
http://blog.clouder.jp/blog/2008/12/12/u-intu-char/



##return(-1)とかreturn(0)とかの違いって何？

- 勘だけど`return(-1)`だとエラーで終了の感じを出すのかな？

##構造体のキャストって何？

https://github.com/r-fujiwara/understanding-packet-flowing-by-creating-router/blob/master/chapter3/analyze.c#L40

- 以下のように文字列を構造体にキャストするとはどういうことか？

```
u_char *ptr;
struct ether_header *arp;

arp = (struct ether_arp *)ptr
```

