#include<stdio.h>
#include<stdlib.h>

// queue のサイズを定数として宣言
#define QUEUE_SIZE 10

// 構造体の定義
// 配列queueと,int型のプロパティhead, tail, countを持つ
struct Queue_k
{
    char queue[QUEUE_SIZE];
    int head;
    int tail;
    int count;
};

// enterq, removeq, initialize, display は、構造体のポインタを受け取り、その構造体のデータを利用する形式に変更
// それ以外はex9と同じ
void enterq(struct Queue_k *q, char c)
{
    if(q->count >= QUEUE_SIZE)
    {
        printf("Queue is full.\n");
        return;
    }
    q->queue[q->tail++] = c;
    if(q->tail == QUEUE_SIZE)
        q->tail = 0;
    q->count++;
}

int removeq(struct Queue_k *q)
{
    if(q->count <= 0)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = q->queue[q->head++];
    if(q->head == QUEUE_SIZE)
        q->head = 0;
    q->count--;
    return data;
}

void initialize(struct Queue_k *q)
{
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}

void display(struct Queue_k *q)
{
    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        if(i == q->head)
            printf("head->");
        else
            printf("      ");
        printf("%2d:%3c ", i, q->queue[i]);
        if(i == q->tail)
            printf("<-tail");
        else
            printf("       ");
        printf("\n");
    }   
}

int main()
{
    struct Queue_k q;
    initialize(&q);
    
    // ファイルから読み込み
    FILE *fp = fopen("./input_kadai4.txt", "r");
    if(fp == NULL) {
        printf("Error: Cannnot open file.\n");
        return -1;
    }

    char c;
    // EOFに到達するまで
    while ((c = fgetc(fp)) != EOF)
    {
        // 改行文字だった場合
        if(c == '\n')
            // removeq を実行・戻り値を出力
            printf("%c", removeq(&q));
        else
            // それ以外は enterq を実行
            enterq(&q, c);
    }
    putchar('\n');
    display(&q);
    fclose(fp);

    return 0;
}    
    