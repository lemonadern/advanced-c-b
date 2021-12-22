/* 上級CプログラミングB 出題日：2021/12/15
    3I 32番 氏名 仲泰志 提出日：2021/12/15 */
/* ファイル名：ex19.c
    演習 二分探索木のノードの探索，挿入用の関数の作成
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root = NULL;

struct Node *nodeAdd(struct Node *p, int data)
{
    // 設問１：二分探索木となるようにノードを挿入する関数の作成
    // 着目ノードがNULLの場合
    if (p == NULL)
    {
        // 動的確保し、データを代入
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        p = new_node;
        p->data = data;
        p->left = NULL;
        p->right = NULL;
    }
    else
    {
        // ノードの値が引数のdataと同じ場合
        if (data == p->data)
        {
            printf("%d is already exist in the tree.\n", data);
        }
        // ノードの値が引数のdataよりも大きい場合
        else if (data < p->data)
        {
            // 左の子ノードに挿入
            p->left = nodeAdd(p->left, data);
        }
        // ノードの値が引数のdataよりも大きい場合
        else
        {
            // 右の子ノードに挿入
            p->right = nodeAdd(p->right, data);
        }
    }
    return p;
}

void nodeSearch(struct Node *p, int data)
{
    // 設問２：二分探索木の探索用関数の作成
    // ノードがNULLの場合
    if (p == NULL)
    {
        printf("%d is not found.\n", data);
    }
    else
    {
        // ノードの値が引数のdataと同じ場合
        if (data == p->data)
            printf("%d is found.\n", data);
        // ノードの値が引数のdataよりも大きい場合
        else if (data < p->data)
            nodeSearch(p->left, data);
        // ノードの値が引数のdataよりも小さい場合
        else
            nodeSearch(p->right, data);
    }
}

// 変更の必要なし
void PrintTree(struct Node *p)
{
    if (p != NULL)
    {
        PrintTree(p->left);
        printf("%d ", p->data);
        PrintTree(p->right);
    }
}

int main()
{
    int i;
    int a[10] = {21, 49, 35, 15, 77, 92, 93, 86, 83, 10};

    // 設問３：nodeAdd を用いて，配列aの値を木に順に挿入
    for (i = 0; i < 10; i++)
    {
        root = nodeAdd(root, a[i]);
    }
    // 設問４：printTree を用いて通りがけ順で出力
    PrintTree(root);
    putchar('\n');
    // 設問５：nodeSearch を用いて 35 を探索
    nodeSearch(root, 35);
    // 設問６：nodeSearch を用いて 34 を探索
    nodeSearch(root, 34);
    return 0;
}

/* 出力結果の貼り付け

❯ ./a.out   
10 15 21 35 49 77 83 86 92 93 
35 is found.
34 is not found.


*/
