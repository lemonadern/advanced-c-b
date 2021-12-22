/* 上級CプログラミングB 出題日：2021/12/22
    3I 32番 氏名 仲泰志 提出日：2021/12/22 */
/* ファイル名：ex20.c
    リストによる自己再編成探索
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMBER_OF_ELEMENTS 10

struct Element
{
    char data[4];
    struct Element *next;
};
struct Element *head;

void initialize()
{
    head = NULL;
}

void display()
{
    int i;
    struct Element *p;
    for (i = 0, p = head; p != NULL; i++, p = p->next)
        printf("%3d: %s", i, p->data);
    printf("\n");
}

void add(char *data)
{
    // 設問１：ノード追加用の関数を作成（ただし，データとして文字列を扱う）
    struct Element *new_element = (struct Element *)malloc(sizeof(struct Element));
    strcpy(new_element->data, data);
    new_element->next = head;
    head = new_element;
}

int main(void)
{
    initialize();
    /* 設問２：探索用リストを構築（add を使用）
        "興", "鋼", "公", "校", "巧", "晃", "皇", "項", "高", "工"
    */
    char *characters[NUMBER_OF_ELEMENTS] = {"興", "鋼", "公", "校", "巧", "晃", "皇", "項", "高", "工"};
    for (int i = 0; i < 10; i++)
        add(characters[i]);

    // 以下で自己再編成探索システムを記述
    int mode = 1, id;

    display();
    while (mode)
    {
        int i;
        struct Element *p, *q;

        printf("?id = ");
        // 設問３：id の読み取り(この id （つまり番号）が変換したい漢字を指すことになる)
        scanf("%d", &id);

        // 設問４：自己再編成探索
        // p を 選択した候補，q をその一つ前まで移動させる（id 番目まで移動させる）
        for (i = 0, p = q = head; i != id && p != NULL; i++, q = p, p = p->next)
            ;
        // 設問５：変換結果（選択した候補（p が指すノード）のデータ部）の表示
        printf("%s\n", p->data);
        if (p == head || head == NULL)
        { // 選択７：選択した候補が既に先頭か，リストが空のとき，何もしない
        }
        else
        {
            // 設問８：自己再編成探索．p と q の next, head をつなぎかえ
            q->next = p->next;
            p->next = head;
            head = p;
        }
        display();
        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }
}

/*
出力結果を貼り付け

❯ ./a.out   
  0: 工  1: 高  2: 項  3: 皇  4: 晃  5: 巧  6: 校  7: 公  8: 鋼  9: 興
?id = 0
工
  0: 工  1: 高  2: 項  3: 皇  4: 晃  5: 巧  6: 校  7: 公  8: 鋼  9: 興
?continue(1) or quit(0) = 1
?id = 1
高
  0: 高  1: 工  2: 項  3: 皇  4: 晃  5: 巧  6: 校  7: 公  8: 鋼  9: 興
?continue(1) or quit(0) = 1
?id = 5
巧
  0: 巧  1: 高  2: 工  3: 項  4: 皇  5: 晃  6: 校  7: 公  8: 鋼  9: 興
?continue(1) or quit(0) = 1
?id = 9
興
  0: 興  1: 巧  2: 高  3: 工  4: 項  5: 皇  6: 晃  7: 校  8: 公  9: 鋼
?continue(1) or quit(0) = 1
?id = 7
校
  0: 校  1: 興  2: 巧  3: 高  4: 工  5: 項  6: 皇  7: 晃  8: 公  9: 鋼
?continue(1) or quit(0) = 0


*/
