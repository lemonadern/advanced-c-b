#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>

#define STACK_SIZE 5 // Stack Size
int stack[STACK_SIZE]; // Stack Area
int sp; // Stack Point

// function prototypes
void push(int);
int pop();
void initialize();
void display();
int parse_int(char);

int main() {
    // read file
    FILE *fp; 
    fp = fopen("./input.txt", "r"); 
    if(fp == NULL) {
        printf("Error: Cannnot open file.\n");
        return -1;
    }

    // init stack
    initialize();

    char c;
    // EOFに到達するまで
    while ((c = fgetc(fp)) != EOF)
    {
        // +, -, *. / のとき、要素を2つpopして計算結果をpushする
        // stackなので、計算順は後に取り出したもの-前に取り出したもの
        if (c == '+')
        {
            // plus
            int f = pop();
            int l = pop();
            printf("%2d +%2d を計算します\n", l, f);
            push(l + f);
            display();
        }
        else if (c == '*')
        {
            // multiple
            int f = pop();
            int l = pop();
            printf("%2d *%2d を計算します\n", l, f);
            push(l * f);
            display();
        }
        else if (c == '-')
        {
            // minus
            int f = pop();
            int l = pop();
            printf("%2d -%2d を計算します\n", l, f);
            push(l - f);
            display();
        }
        else if (c == '/')
        {
            // devide
            int f = pop();
            int l = pop();
            printf("%2d /%2d を計算します\n", l, f);
            push(l / f);
            display();
        }
        else if(isdigit(c)) {
            // number process
            int n = parse_int(c);
            printf("数字の%2d をpushします\n", n);
            push(n);
            display();
        }
        else if (c == '=')
        {
            // answer output
            int answer = pop();
            printf("計算結果は%3d です\n", answer);
            printf("\n");
        }
        else
        {
            printf("Error: invalid input was detected.");
            return -1;
        }
    }

    // close file
    fclose(fp);    
    return 0;
}

// functions
void push(int data)
{
    // Stackが満杯ならエラー
    if( sp >= STACK_SIZE-1 ) {
        printf("Error: Stack FULL\n");
        return;
    }
    // 更新してからpush
    stack[++sp] = data;
    return;
}

int pop()
{
    // Stackが空ならエラー
    if(sp < 0) {
        printf("Error: Stack EMPTY\n");
        return -1;
    }
    // popしてから更新
    return stack[sp--];
}

void initialize()
{
    sp = -1;
}

void display()
{
    for (int i = STACK_SIZE - 1; i >= 0;i--)
    {            
        // spのときだけSP->と表示    
        if (i == sp) 
            printf("SP->");
        else
            printf("    ");
        // 要素番号とスタックの値を出力
        printf("%6d:%6d\n", i, stack[i]);
    }
}

// parse int to char
int parse_int(char c) {
    // asciiでの'0'との差分をとる
    return c - '0';
}