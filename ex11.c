/* 上級CプログラミングB 出題日：2021/11/15
   3I 32番 氏名 仲泰志 提出日：2021/11/15 */
/* ファイル名：ex11.c
   演習 リスト序論、node[N]を連結しfor文で出力する．
 */

#include <stdio.h>
#define N 10

// 設問１：ノードを表現するための構造体を定義する
struct Element {
  int data; // データ
  struct Element *next; // 次のノードへのポインタ
};


int main()
{
    // 設問２：ノード用の構造体配列 node（要素数 N）を宣言する
   struct Element node[N];
    // 設問３：配列 0 から 9 番目をノードとして順に連結する
    // ノードの data に代入する値は i の二乗とする
    for (int i = 0; i < N; i++)
    {
      node[i].data = i * i;
      node[i].next = &node[i + 1];
    }
    

    // 設問４：末端ノードを正しく設定する
    node[9].next = NULL;

    // 設問５：head を正しく設定する
    struct Element *head = node;  // 線形リストの先頭

    // 設問６：線形リスト用のfor文(ポインタ p を用いる)によって先頭から出力する
    // 出力する値は，現在のノードのアドレス，現在のノードの値，次のノードのアドレス
   for(struct Element *p = head; p != NULL; p = p->next)
   {
       printf("%p %4d %p\n", p, p->data, p->next);  
   }

    return 0;
}

// 実行結果
// ❯ ./a.out   
// 0x7ffcf83cf6e0    0 0x7ffcf83cf6f0
// 0x7ffcf83cf6f0    1 0x7ffcf83cf700
// 0x7ffcf83cf700    4 0x7ffcf83cf710
// 0x7ffcf83cf710    9 0x7ffcf83cf720
// 0x7ffcf83cf720   16 0x7ffcf83cf730
// 0x7ffcf83cf730   25 0x7ffcf83cf740
// 0x7ffcf83cf740   36 0x7ffcf83cf750
// 0x7ffcf83cf750   49 0x7ffcf83cf760
// 0x7ffcf83cf760   64 0x7ffcf83cf770
// 0x7ffcf83cf770   81 (nil)

