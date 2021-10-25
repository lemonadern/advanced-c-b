/* 上級CプログラミングB 出題日：2021/10/25
   3I 32番 氏名 仲泰志 提出日：2021/10/25 */
/* ファイル名：ex7.c
   演習7 スタック（棚）
   スタックを操作する関数 push(), pop()を完成させる
   初期化用の関数 initialize(), 表示用の関数 display() を完成させる
 */
#include <stdio.h>

#define STACK_SIZE 5 // Stack Size
int stack[STACK_SIZE]; // Stack Area
int sp; // Stack Point

// 設問１：push()の完成
void push(int data)
{
    // スタックがfull のときはエラーメッセージを出して終了
    // sp が STACK_SIZE-1 以上のときは full
    if( sp >= STACK_SIZE-1 ) {
        printf("Error: Stack FULL\n");
        return;
    }
    // spをインクリメントしてからstackのspのインデックスにdataを代入
    stack[++sp] = data;
    return;
}

// 設問２：pop()の完成
int pop()
{
    // stackが empty ならエラーメッセージを出し、-1を返して終了する
    // spが0よりも小さければ empty
    if(sp < 0) {
        printf("Error: Stack EMPTY\n");
        return -1;
    }
    // 現在のspの値を返した後にデクリメントする
    return stack[sp--];
}

// 設問３：initialize()の完成
void initialize()
{
    // sp の値を-1で初期化
    sp = -1;
}

// 設問４：display()の完成
void display()
{
    for (int i = STACK_SIZE - 1; i >= 0;i--)
    {                // スタックの上から下に for文を回す
        if (i == sp) // スタックポインタの位置のとき SP-> を出力
            printf("SP->");
        else
            printf("    ");
        // 要素番号とスタックの値を出力
        printf("%6d:%6d\n", i, stack[i]);
    }
}

int main(void)
{
    int mode = 1, id;
    // 設問５：スタックを初期化
    initialize();
    while (mode) {
        printf("?push(1) or pop(0) = ");
        scanf("%d", &mode);
        if (mode == 1) {
            printf("?id = ");
            scanf("%d", &id);
            // 設問６：id の値をスタックに入力
            push(id);
        } else if (mode == 0) {
            // 設問７：スタックから値を出力し id に代入
            id = pop();
            if (id > 0)
                printf("id = %d was picked\n", id);
        }
        // 設問８：スタックの中身を表示
        display();
        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }
}

/* 実行結果を以下に貼り付ける
   データが正しく pop, push される
   スタックが FULL / EMPTY の場合に、それぞれエラー表示がされる
 ~/git/my-adv-c-b │ master ?1                                           1m 31s │ system Node │ 16:16:44 
❯ gcc ex7.c 

 ~/git/my-adv-c-b │ master ?1                                                    system Node │ 16:17:20 
❯ ./a.out   
?push(1) or pop(0) = 1
?id = 2
         4:     0
         3:     0
         2:     0
         1:     0
SP->     0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 1
?id = 5
         4:     0
         3:     0
         2:     0
SP->     1:     5
         0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 1
?id = 8
         4:     0
         3:     0
SP->     2:     8
         1:     5
         0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
id = 8 was picked
         4:     0
         3:     0
         2:     8
SP->     1:     5
         0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 1
?id = 4
         4:     0
         3:     0
SP->     2:     4
         1:     5
         0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 1
?id = 7
         4:     0
SP->     3:     7
         2:     4
         1:     5
         0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 1
?id = 9
SP->     4:     9
         3:     7
         2:     4
         1:     5
         0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 1
?id = 2
Error: Stack FULL
SP->     4:     9
         3:     7
         2:     4
         1:     5
         0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
id = 9 was picked
         4:     9
SP->     3:     7
         2:     4
         1:     5
         0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
id = 7 was picked
         4:     9
         3:     7
SP->     2:     4
         1:     5
         0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
id = 4 was picked
         4:     9
         3:     7
         2:     4
SP->     1:     5
         0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 1
?id = 3
         4:     9
         3:     7
SP->     2:     3
         1:     5
         0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
id = 3 was picked
         4:     9
         3:     7
         2:     3
SP->     1:     5
         0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
id = 5 was picked
         4:     9
         3:     7
         2:     3
         1:     5
SP->     0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
id = 2 was picked
         4:     9
         3:     7
         2:     3
         1:     5
         0:     2
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
Error: Stack EMPTY
         4:     9
         3:     7
         2:     3
         1:     5
         0:     2
?continue(1) or quit(0) = 0

*/

