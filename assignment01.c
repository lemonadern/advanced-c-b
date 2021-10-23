// 上級Cプログラミング 課題01
// ! 「昇順」とあるが、ソートはしなくてよい

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 評価(A | B | C | F)を返す関数(prototype)
char evaluation_label(int);

int main(){
    // 問題1
    // データの管理に適した構造体の宣言
    struct score
    {
        int number;
        char name[20];
        int score01;
        int score02;
        int score03;
    };
    typedef struct score Score;

    // 問題2
    // 要件を満たすプログラムの作成

    // 構造体配列の要素数nをscanfによって標準入力から受け取る
    // !4以上の数字が入る前提
    int n;
    printf("Input the number of elements:");
    scanf("%d", &n);

    // 要素数n個分の構造体配列の領域をmalloc関数によって動的に確保する
    Score *struct_p;
    struct_p = (Score *)malloc(sizeof(Score) * n);

    // n人分のデータを構造体配列に代入する
    struct_p[0].number = 10001;
    strcpy(struct_p[0].name, "太郎");
    struct_p[0].score01 = 78;
    struct_p[0].score02 = 68;
    struct_p[0].score03 = 95;

    struct_p[1].number = 10002;
    strcpy(struct_p[1].name, "次郎");
    struct_p[1].score01 = 74;
    struct_p[1].score02 = 63;
    struct_p[1].score03 = 48;

    struct_p[2].number = 10003;
    strcpy(struct_p[2].name, "三郎");
    struct_p[2].score01 = 85;
    struct_p[2].score02 = 79;
    struct_p[2].score03 = 50;

    struct_p[3].number = 10004;
    strcpy(struct_p[3].name, "四郎");
    struct_p[3].score01 = 71;
    struct_p[3].score02 = 72;
    struct_p[3].score03 = 73;

    // n人分のデータを番号順に出力する
    // ! 番号順かどうかは代入作業によってのみ保証される
    for (int i = 0; i < n;i++){
        printf("%d,%s,%d,%d,%d\n", struct_p[i].number, struct_p[i].name, struct_p[i].score01, struct_p[i].score02, struct_p[i].score03);
    }

    // 区切りラインの出力
    printf("-------------------\n");

    // 各人の課題点から評価点を求める

    // 評価割合を保持する構造体の宣言・代入
    struct {
        int assignment01;
        int assignment02;
        int assignment03;
    } evaluation_percentages;
    evaluation_percentages.assignment01 = 30;
    evaluation_percentages.assignment02 = 30;
    evaluation_percentages.assignment03 = 40;

    // 各課題の評価点を保持する構造体配列の宣言・代入
    struct evaluation{
        int assignment01;
        int assignment02;
        int assignment03;
    };
    struct evaluation evaluations[n];
    // 各課題ごとの評価点の算出・代入
    for (int i = 0; i < n; i++){
        evaluations[i].assignment01 = struct_p[i].score01 * evaluation_percentages.assignment01 / 100;
        evaluations[i].assignment02 = struct_p[i].score02 * evaluation_percentages.assignment02 / 100;
        evaluations[i].assignment03 = struct_p[i].score03 * evaluation_percentages.assignment03 / 100;
    }

    // 結果の表示
    for (int i = 0; i < n; i++)
    {
        // ! struct_pとevaluationsの中身の順番はインデックスのみによって整合が保証されているので相互依存
        int point = evaluations[i].assignment01 + evaluations[i].assignment02 + evaluations[i].assignment03;
        printf("%s, %d, %c\n", struct_p[i].name, point, evaluation_label(point));
    }
    free(struct_p);
}

// 評価(A | B | C | F)を返す関数
char evaluation_label(int score){
    if(score >= 80)
        return 'A';
    else if (score >= 70)
        return 'B';
    else if (score >= 60)
        return 'C';
    else
        return 'F';
}