/* 上級CプログラミングB 出題日：2021/12/13
   3I 32番 氏名 仲泰志 提出日：2021/12/13 */
/* ファイル名：ex19.c
    演習 木の静的な作成．縦型探索用 の printTree 関数を作成
*/

#include <stdio.h>

// 設問１：ノード用の構造体（struct Node）の定義
// 2進木を考えるので、left と right
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// 設問２：根を指すポインタ root の宣言，初期化
struct Node *root = NULL;

void PrintTree(struct Node *p)
{
    // 設問４：縦型探索（三通り記述．実行時は他の二つをコメントアウト）

    if (p != NULL)
    {
        // 行きがけ順
        // printf("%d ", p->data);
        // PrintTree(p->left);
        // PrintTree(p->right);

        // // 通りがけ順
        // PrintTree(p->left);
        // printf("%d ", p->data);
        // PrintTree(p->right);

        // 帰りがけ順
        PrintTree(p->left);
        PrintTree(p->right);
        printf("%d ", p->data);
    }
}

int main()
{
    // 設問３：構造体配列（要素数10）を宣言し，木を静的に作成
    // data部に値を代入し，left, right を正しく接続
    struct Node tree[10];
    tree[0].data = 21;
    tree[1].data = 15;
    tree[2].data = 10;
    tree[3].data = 49;
    tree[4].data = 35;
    tree[5].data = 77;
    tree[6].data = 92;
    tree[7].data = 86;
    tree[8].data = 83;
    tree[9].data = 93;

    tree[0].left = &tree[1];
    tree[0].right = &tree[3];
    tree[1].left = &tree[2];
    tree[1].right = NULL;
    tree[2].left = NULL;
    tree[2].right = NULL;
    tree[3].left = &tree[4];
    tree[3].right = &tree[5];
    tree[4].left = NULL;
    tree[4].right = NULL;
    tree[5].left = NULL;
    tree[5].right = &tree[6];
    tree[6].left = &tree[7];
    tree[6].right = &tree[9];
    tree[7].left = &tree[8];
    tree[7].right = NULL;
    tree[8].left = NULL;
    tree[8].right = NULL;
    tree[9].left = NULL;
    tree[9].right = NULL;

    // 設問５：根の設定
    root = tree;
    PrintTree(root); // 縦型探索関数呼び出し（変更の必要なし）
    putchar('\n');

    return 0;
}

/* 行きがけ順，通りがけ順，帰りがけ順のそれぞれの出力結果を貼り付ける
行きがけ順
❯ ./a.out   
21 15 10 49 35 77 92 86 83 93 

通りがけ順
❯ ./a.out   
10 15 21 35 49 77 83 86 92 93 

帰りがけ順
❯ ./a.out   
10 15 35 83 86 93 92 77 49 21 

*/
