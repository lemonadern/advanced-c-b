/* 上級CプログラミングB 出題日：2021/10/6
   3I 32番 氏名 仲泰志 提出日： 2021/10/6*/
/* 演習2 構造体の復習
   ファイル名 ex2.c */

#include <stdio.h>
#include <string.h>

int main() {
   // 設問１：氏名(name)，身長(height)，体重(weight)を管理するための構造体を宣言
   struct body
   {
      char name[20];
      int height;
      int weight;
   };
   
   // 設問２：構造体変数 a を宣言し，各メンバに "高専太郎", 174, 64.2 を代入
   struct body a = { "高専太郎", 174, 64.2 };
   
   // 設問３：「氏名：高専太郎，身長：174 cm 体重：64.2 kg」と出力
   printf("氏名：%s, 身長：%d, 体重：%d\n", a.name, a.height, a.weight);

   // 設問４：構造体ポインタ p を用いて，構造体 a の情報を設問３と同様に出力
   struct body *p = &a;
   printf("氏名：%s, 身長：%d, 体重：%d\n", p->name, p->height, p->weight);

   // 設問５：struct body 型の構造体配列 b (要素数3) を宣言し，
   // 0番目の要素に "高専太郎", 174, 64.2
   // 1番目の要素に "高専次郎", 163, 58.1
   // 2番目の要素に "高専三郎", 168, 70.3
   // を代入
   struct body b[3];
   // 愚直
   strcpy(b[0].name, "高専太郎");
   b[0].height = 174;
   b[0].weight = 64.2;

   strcpy(b[1].name, "高専次郎");
   b[1].height = 163;
   b[1].weight = 58.1;

   strcpy(b[2].name, "高専三郎");
   b[2].height = 168;
   b[2].weight = 70.3;

   // 設問６：構造体配列の情報を設問３と同様に出力．for文を用いること
   int i;
   for(int i=0; i<3; ++i) {
      printf("氏名：%s, 身長：%d, 体重：%d\n", b[i].name, b[i].height, b[i].weight);
   }

   return 0;
}

/* 実行結果を以下に貼り付ける
❯ ./ex2      
氏名：高専太郎, 身長：174, 体重：64
氏名：高専太郎, 身長：174, 体重：64
氏名：高専太郎, 身長：174, 体重：64
氏名：高専次郎, 身長：163, 体重：58
氏名：高専三郎, 身長：168, 体重：70

*/