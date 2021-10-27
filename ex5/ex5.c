/* 上級CプログラミングB 出題日：2021/10/18
   3I 32番 氏名 提出日： 2021/10/18*/
/* ファイル名：ex5.c
   演習5 2次元配列の動的割当 */
#include <stdio.h>
#include <stdlib.h> // 設問１：必要なヘッダファイルのインクルード

#define N1 10 // 10人
#define N2 5 // 5科目

int main() {
    int i, j; // i:行，j:列 の走査用
    // 設問２：2次元配列に対応する2連鎖ポインタpを宣言する
    int **p;
    
    // 設問３：2次元配列を動的に確保
    p = (int **)malloc(sizeof(int *) * N1);

    for (int i = 0; i < N1; i++) {
        p[i] = (int *)malloc(sizeof(int) * N2);
    }
    
    // 設問４：input.txt から配列へデータ入力
    FILE *fp; // ファイルポインタを宣言
    fp = fopen("./input.txt", "r"); // ファイルオープン
    if(fp == NULL) {
        printf("Error: Cannnot open file.\n");
        return -1;
    }

    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N2; j++) {
            // データの読み込み
            fscanf(fp, "%d", &p[i][j]);
            printf("p[%d][%d]:%d\n", i, j, p[i][j]);  // 読み込みと同時に確認のため出力
        }
    }
    fclose(fp);

    // 設問５：データを output.csv に出力
    fp = fopen("./output.csv", "w"); // ファイルオープン
    if(fp == NULL) {
        printf("Error: Cannnot open file.\n");
        return -1;
    }
    for (int i = 0; i < N1; i++) {
        int total = 0; // 合計点
        for (int j = 0; j < N2; j++) {
            // データの書き込み
            fprintf(fp, "%d,", p[i][j]);
            total += p[i][j]; // 合計点の計算
        }
        fprintf(fp, "%d\n", total); // 合計点の書き込み
    }
    fclose(fp);

    // 設問６：二次元配列領域の解放(freeする順番に注意)
    for (int i = 0; i < N1; i++) {
        free(p[i]);
    }
    free(p);
}

/* 実行結果を以下に貼り付ける
❯ ./ex5           
p[0][0]:100
p[0][1]:90
p[0][2]:55
p[0][3]:20
p[0][4]:30
p[1][0]:50
p[1][1]:50
p[1][2]:5
p[1][3]:50
p[1][4]:33
p[2][0]:20
p[2][1]:30
p[2][2]:40
p[2][3]:50
p[2][4]:60
p[3][0]:30
p[3][1]:20
p[3][2]:45
p[3][3]:1
p[3][4]:65
p[4][0]:23
p[4][1]:45
p[4][2]:85
p[4][3]:90
p[4][4]:100
p[5][0]:90
p[5][1]:90
p[5][2]:90
p[5][3]:80
p[5][4]:30
p[6][0]:0
p[6][1]:25
p[6][2]:45
p[6][3]:60
p[6][4]:70
p[7][0]:100
p[7][1]:90
p[7][2]:95
p[7][3]:90
p[7][4]:98
p[8][0]:30
p[8][1]:20
p[8][2]:11
p[8][3]:15
p[8][4]:30
p[9][0]:25
p[9][1]:60
p[9][2]:80
p[9][3]:75
p[9][4]:1
*/
