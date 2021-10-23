#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// プロトタイプ宣言
void init_random_img(int **img, int row, int column, int seed);
void copy_img(int **original, int **copy, int row, int column);
void average_img(int **original, int **output, int row, int column);
void dilate_img(int **original, int **output, int row, int column);

void print_img(char name[20], int **img, int row, int column);

int main(){
    /*
    問題1:二次元配列input, outputの領域を動的に確保するプログラムを記述せよ。
    */

    // 配列の大きさrow, columnを標準入力で受け付ける
    int row, column;
    printf("row:");
    scanf("%d", &row);
    printf("column:");
    scanf("%d", &column);

    // 二次元配列input, outputの動的確保
    int **input, **output;
    input = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++) {
        input[i] = (int *)malloc(sizeof(int) * column);
    }
    output = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++) {
        output[i] = (int *)malloc(sizeof(int) * column);
    }
    

    /*
    問題2:inputの全要素の値を100よりも小さいランダムな値で初期化する。
    inputに対して平均化を行ったものをoutputに格納し、iniput及び outputの全要素の値を出力する。
    */

    // ランダムな値で初期化(乱数生成のシード値には現在時刻を整数にキャストしたものを設定)
    init_random_img(input, row, column, (unsigned int)time(NULL));

    // inputの中身をoutputにコピーする
    copy_img(input, output, row, column);
    
    // outputに対して平均化処理を行う
    average_img(input, output, row, column);

    // input 及び outputの出力
    printf("\n");
    printf("averaging\n");
    print_img("input", input, row, column);
    print_img("output", output, row, column);


    /*
    問題3:inputに対して膨張処理を行った後の値を出力する。
    */

    // outputに対して膨張処理を行う
    dilate_img(input, output, row, column);
    // input 及び outputの出力
    printf("dilation\n");
    print_img("input", input, row, column);
    print_img("output", output, row, column);


    // input及びoutputのメモリ解放
    for (int i = 0; i < row; i++) {
        free(input[i]);
    }
    free(input);
    for (int i = 0; i < row; i++) {
        free(output[i]);
    }
    free(output);
    
    return 0;
}

// ランダムな要素で初期化する関数
// （引数には、 二次元配列のアドレス・行サイズ・列サイズ・乱数のシード値 を指定）
void init_random_img(int **img, int row, int column, int seed){
    // シード値を設定
    srand(seed);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            // 0から99のうちランダムな値を各要素に代入
            img[i][j] = rand() % 100;
        }
    }   
}

// 配列要素をコピーする関数
// （引数には、オリジナル配列・コピー先配列・行サイズ・列サイズ を指定）
void copy_img(int **original, int **copy, int row, int column) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            // copyの各要素にoriginalの該当要素を代入
            copy[i][j] = original[i][j];
        }
    }
}

// original配列に対しての平均化処理をoutputに行う関数
// ! 外周部分の要素について、outputがoriginalと同一であることに依存している
void average_img(int **original, int **output, int row, int column) {
    for (int i = 1; i < row - 1; i++)
    {
        for (int j = 1; j < column - 1; j++)
        {
            int sum_of_neighbors = original[i - 1][j - 1] + original[i - 1][j] + original[i - 1][j + 1] + original[i][j - 1] + original[i][j] + original[i][j + 1] + original[i + 1][j - 1] + original[i + 1][j] + original[i + 1][j + 1];
            output[i][j] = sum_of_neighbors / 9;
        }
    }
}

// original配列に対しての膨張処理をoutputに行う関数
// ! 外周部分の要素について、outputがoriginalと同一であることに依存している
void dilate_img(int **original, int **output, int row, int column) {
    for (int i = 1; i < row - 1; i++)
    {
        for (int j = 1; j < column - 1; j++)
        {
            int max = -1;
            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    if(max < original[i+r][j+c])
                    max = original[i + r][j + c];
                }
            }
            output[i][j] = max;
        }
    }
}

// 配列を整形して表示する関数
void print_img(char name[20], int **img, int row, int column) {
    printf("%s\n", name);
    printf("    |");
    for (int i = 0; i < column; i++)
    {
        printf("%3d", i);
    }
    printf("\n");
    printf("-------------------------------\n");
    for (int i = 0; i < row; i++)
    {
        printf("%3d |", i);
        for (int j = 0; j < column; j++)
        {
            printf("%3d", img[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
