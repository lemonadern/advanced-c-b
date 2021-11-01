/* 上級CプログラミングB 出題日：2021/11/1
   3I 32番 氏名 仲泰志 提出日：2021/11/01 */
/* ファイル名：ex9.c
   演習9 キュー（待ち行列）
   キューを操作する関数 enterq(), removeq()を完成させる
   初期化用の関数 initialize(), 表示用の関数 display() を完成させる
 */
#include <stdio.h>

#define QUEUE_SIZE 5
int queue[QUEUE_SIZE]; // Queue Area
int head, tail; // Queue in:out Point
int count;  // count of Queue member

// 設問１：enterqの完成
void enterq(int data)
{
    if(count >= QUEUE_SIZE)
    {
        printf("Queue is FULL\n");
        return;
    }
    queue[tail++] = data;
    if(tail == QUEUE_SIZE)
        tail = 0;
    count++;
}

// 設問２：removeqの完成
int removeq()
{
    if(count <= 0)
    {
        printf("Queue is EMPTY\n");
        return -1;
    }
    int data = queue[head++];
    if(head == QUEUE_SIZE)
        head = 0;
    count--;
    return data;
}

// 設問３：initializeの完成（head, tail, count の初期化）
void initialize()
{
    head = 0;
    tail = 0;
    count = 0;
}

// 設問４：displayの完成
void display()
{
    // キューの(イメージ的に)左から右に for文を回す
    for (int i=0; i<QUEUE_SIZE; i++) {
        // head の位置には head-> と出力．でなければスペース
        if(i == head)
            printf("head->");
        else
            printf("      ");
        // 要素番号とキューの値を出力
        printf("%2d:%3d ", i, queue[i]);
        // tail の位置には <-tail と出力．でなければスペース
        if(i == tail)
            printf("<-tail");
        else
            printf("       ");
        printf("\n");
    }
}

int main(void)
{
    int mode = 1, id;
    initialize();
    while (mode) {
        printf("?enter(1) or remove(0) = ");
        scanf("%d", &mode);
        if (mode == 1) {
            printf("?id = ");
            scanf("%d", &id);
            // 設問５：id の値をキューに入力
            enterq(id);
        } else if (mode == 0) {
            // 設問６：キューから値を出力し，id に代入
            id = removeq();
            if (id > 0)
                printf("id = %d was removed\n", id);
        }
        // 設問７：キューの中身を表示
        display();
        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }

    return 0;
}

/* 実行結果を以下に貼り付ける
   データが正しく入出力される
   キューが FULL / EMPTY の場合に、それぞれエラー表示がされる
   head, tail が配列末尾に到達したとき，先頭（0）に戻る
❯ ./a.out  
?enter(1) or remove(0) = 0
Queue is EMPTY
head-> 0:  0 <-tail
       1:  0        
       2:  0        
       3:  0        
       4:  0        
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 10
head-> 0: 10        
       1:  0 <-tail
       2:  0        
       3:  0        
       4:  0        
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 20
head-> 0: 10        
       1: 20        
       2:  0 <-tail
       3:  0        
       4:  0        
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 30
head-> 0: 10        
       1: 20        
       2: 30        
       3:  0 <-tail
       4:  0        
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 0
id = 10 was removed
       0: 10        
head-> 1: 20        
       2: 30        
       3:  0 <-tail
       4:  0             
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 40
       0: 10        
head-> 1: 20        
       2: 30        
       3: 40        
       4:  0 <-tail
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 50
       0: 10 <-tail
head-> 1: 20        
       2: 30        
       3: 40        
       4: 50        
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 60
       0: 60        
head-> 1: 20 <-tail
       2: 30        
       3: 40        
       4: 50        
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 70
Queue is FULL
       0: 60        
head-> 1: 20 <-tail
       2: 30        
       3: 40        
       4: 50        
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 0
id = 20 was removed
       0: 60        
       1: 20 <-tail
head-> 2: 30        
       3: 40        
       4: 50        
?continue(1) or quit(0) = 0

*/