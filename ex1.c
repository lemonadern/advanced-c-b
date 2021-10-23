/* 上級CプログラミングB 出題日：2021/10/4
   3I 32番 氏名 仲泰志 提出日：10/4 */
/* 演習1 ポインタの復習
   ファイル名 ex1.c */

#include <stdio.h>

int main()
{
    /* 通常のポインタ変数 */
    {
        int a;
        a = 5;
        int *p;
        p = &a;  /* 同時に書くと int *p=&a; */
        printf("&a : %p, a : %d\n", &a, a);
        /* 設問１：pが指す変数のアドレス，pが指す変数の値をpを用いて出力 */
        printf("p : %p, *p : %d\n", p, *p);
    }

    {
        int a[5] = {1, 2, 3, 4, 5};
        int *p1, *p2;
        p1 = &a[2];
        p2 = &a[4];
        printf("&a[2] : %p, a[2] : %d\n", &a[2], a[2]);
        printf("&a[4] : %p, a[4] : %d\n", &a[4], a[4]);
        /* 設問２：
        p1が指す変数のアドレス，p1が指す変数の値をp1を用いて出力
        
        p2が指す変数のアドレス，p2が指す変数の値をp2を用いて出力

        */
       printf("p1    : %p, *p1  : %d\n", p1, *p1);
       printf("p2    : %p, *p2  : %d\n", p2, *p2);
    }

    /* 配列としてのポインタ */
    {
        int a[5] = {1, 2, 3, 4, 5};
        int *p;
        p = a;   /* p = &a[0]; も同じ意味 */
        printf("&a[0] : %p, a[0] : %d\n", &a[0], a[0]);
        printf("&a[2] : %p, a[2] : %d\n", &a[2], a[2]);
        /* 設問３：pが指す変数（配列）のアドレス，pが指す配列の先頭の値をpを用いて出力する */
        printf("p     : %p, *p   : %d\n", p, *p);
        /* 設問４：a[2]のアドレス，値をpを用いて出力 */
        printf("p+2   : %p, *(p+2): %d\n", p+2, *(p+2));
        /* 設問５：a[2]のアドレス，値をpを用いて出力（配列風の記述で） */
        printf("&p[2] : %p, p[2] : %d\n", &p[2], p[2]);
        /* 設問６：a[2]のアドレス，値をaを用いて出力（ポインタ風の記述で） */
        printf("a+2   : %p, *(a+2): %d\n", a+2, *(a+2));        
    }

    /* 関数ポインタ */
    {
        int func(int); /* プロトタイプ宣言 */
        int (*p_func)(int);
        p_func = func;
        printf("funcのアドレス : %p, func(5) : %d\n", func, func(5));
        /* 設問７：関数ポインタ p_func が指すアドレス，p_funcが指す関数を呼び出し */
        printf("p_funcのアドレス: %p, p_func(5): %d\n", p_func, p_func(5));
    }

    {
        /* 設問８：正しくプロトタイプ宣言する */
        void swap(int*, int*);
        int a[2] = {5, 3};
        printf("a[0] = %d, a[1] = %d\n", a[0], a[1]);
        /* 設問９：正しく swap関数呼び出し，a[0]とa[1]の値を交換する */
        swap(&a[0], &a[1]);
        /* 表示して確認 */
        printf("swap後\n");
        printf("a[0]=%d, a[1]=%d\n", a[0], a[1]);
    }

    return 0;
}

/* 関数ポインタで管理する関数．変更の必要なし */
int func(int i)
{
    return i;
}

/* 設問１０：swap関数を作成する */
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

/* 実行結果を以下に貼り付ける
❯ ./ex1      
&a : 0x7ffdcdb36514, a : 5
p : 0x7ffdcdb36514, *p : 5
&a[2] : 0x7ffdcdb36548, a[2] : 3
&a[4] : 0x7ffdcdb36550, a[4] : 5
p1    : 0x7ffdcdb36548, *p1  : 3
p2    : 0x7ffdcdb36550, *p2  : 5
&a[0] : 0x7ffdcdb36540, a[0] : 1
&a[2] : 0x7ffdcdb36548, a[2] : 3
p     : 0x7ffdcdb36540, *p   : 1
p+2   : 0x7ffdcdb36548, *(p+2): 3
&p[2] : 0x7ffdcdb36548, p[2] : 3
a+2   : 0x7ffdcdb36548, *(a+2): 3
funcのアドレス : 0x5599881d89d8, func(5) : 5
p_funcのアドレス: 0x5599881d89d8, p_func(5): 5
a[0] = 5, a[1] = 3
swap後
a[0]=3, a[1]=5

*/