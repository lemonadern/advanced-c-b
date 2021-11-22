/* 上級CプログラミングB 出題日：2021/11/17
   3I 32番 氏名 仲泰志 提出日： 2021/11/17
/* ファイル名：ex12.c
   演習 リストの操作
   設問 initialize(), add(), delete(), insert(), search() を作成する
*/
#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int data;
    struct Element *next;
};
struct Element *head;

// 設問 １：リストの基本処理のための関数を作成
void initialize()
{
    head = NULL;
}

void add(int data)
{
    // 領域を確保
    struct Element *p;
    p = malloc(sizeof(struct Element));
    p->data = data;
    // head をp->nextに置換
    p->next = head;
    head = p;
}

int delete (int data)
{
    int i;
    struct Element *p, *q;
    for (i = 0, p = q = head; p != NULL; i++, q = p, p = p->next)
    {
        if (p->data == data)
        {
            if (p == head)
            {
                head = p->next;
                free(p);
            }
            else
            {
                q->next = p->next;
                free(p);
                return i;
            }
        }
    }
    return -1;
}

void insert(int index, int data)
{
    if (index <= 0 || head == NULL)
    {
        add(data);
    }
    else
    {
        int i;
        struct Element *p, *q, *r;
        for (i = 0, p = q = head; i < index && p->next != NULL; i++, q = p, p = p->next)
            ;
        r = malloc(sizeof(struct Element));
        q->next = r;
        r->data = data;
        if (i == index)
        {
            r->next = p;
        }
        else
        {
            r->next = NULL;
        }
    }
}

int search(int data)
{
    int i;
    struct Element *p;
    for (i = 0, p = head; p != NULL; i++, p = p->next)
    {
        if (p->data == data)
        {
            return i;
        }
    }
    return -1;
}

// displayは変更の必要はない
void display()
{
    int i;
    struct Element *p;
    for (i = 0, p = head; p != NULL; i++, p = p->next)
        printf("%6d: %p %6d %p\n", i, p, p->data, p->next);
}

int main(void)
{
    int mode = 1, id;
    // 線形リストの初期化（関数の呼び出し）
    initialize();
    while (mode)
    {
        printf("list process ?add(1), insert(2), search(3) or delete(0) = ");
        scanf("%d", &mode);
        if (mode == 1)
        {
            printf("?data = ");
            scanf("%d", &id);
            // 設問２：ノードの追加を実行（関数の呼び出し）
            add(id);
        }
        else if (mode == 2)
        {
            int data;
            printf("?index = ");
            scanf("%d", &id);
            printf("?data = ");
            scanf("%d", &data);
            // 設問３：ノードの挿入を実行（関数の呼び出し）
            insert(id, data);
        }
        else if (mode == 3)
        {
            int index;
            printf("?data = ");
            scanf("%d", &id);
            // 設問４：ノードの探索を実行（index = ??; の形で関数の呼び出し）
            search(index);
            if (index == -1)
            {
                printf("data = %d was not found\n", id);
            }
            else
            {
                printf("data = %d was found at %d\n", id, index);
            }
        }
        else if (mode == 0)
        {
            printf("?data = ");
            scanf("%d", &id);
            if (delete (id) < 0)
                printf("id = %d was not found\n", id);
        }
        display();
        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }

    return 0;
}

/* 実行結果を以下に貼り付ける
   add(), delete(), insert(), search() の動作確認
   
❯ ./a.out   
list process ?add(1), insert(2), search(3) or delete(0) = 2
?index = 2
?data = 4
     0: 0x55ff19a13a80      4 (nil)
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 0
?data = 4
id = 4 was not found
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 1
?data = 5
     0: 0x55ff19a13a80      5 (nil)
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 1
?data = 6
     0: 0x55ff19a13aa0      6 0x55ff19a13a80
     1: 0x55ff19a13a80      5 (nil)
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 1
?data = 7
     0: 0x55ff19a13ac0      7 0x55ff19a13aa0
     1: 0x55ff19a13aa0      6 0x55ff19a13a80
     2: 0x55ff19a13a80      5 (nil)
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 1
?data = 8
     0: 0x55ff19a13ae0      8 0x55ff19a13ac0
     1: 0x55ff19a13ac0      7 0x55ff19a13aa0
     2: 0x55ff19a13aa0      6 0x55ff19a13a80
     3: 0x55ff19a13a80      5 (nil)
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 0
?data = 6
     0: 0x55ff19a13ae0      8 0x55ff19a13ac0
     1: 0x55ff19a13ac0      7 0x55ff19a13a80
     2: 0x55ff19a13a80      5 (nil)
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 3
?data = 5
data = 5 was found at 32766
     0: 0x55ff19a13ae0      8 0x55ff19a13ac0
     1: 0x55ff19a13ac0      7 0x55ff19a13a80
     2: 0x55ff19a13a80      5 (nil)
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 2
?index = 1
?data = 9
     0: 0x55ff19a13ae0      8 0x55ff19a13aa0
     1: 0x55ff19a13aa0      9 0x55ff19a13ac0
     2: 0x55ff19a13ac0      7 0x55ff19a13a80
     3: 0x55ff19a13a80      5 (nil)
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 0
?data = 8
id = 8 was not found
     0: 0x55ff19a13aa0      9 0x55ff19a13ac0
     1: 0x55ff19a13ac0      7 0x55ff19a13a80
     2: 0x55ff19a13a80      5 (nil)
?continue(1) or quit(0) = 0

 */
