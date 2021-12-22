#include <stdio.h>
#include <stdlib.h>

struct Element
{
  char data;
  struct Element *next;
};

struct Element *head, *tail;

void initialize()
{
  head = tail = NULL;
}

void enterq_char(char data)
{
  struct Element *p;
  p = malloc(sizeof(struct Element));
  p->data = data;

  if (head == NULL)
  {
    head = tail = p;
  }
  else
  {
    tail->next = p;
    tail = p;
  }
  tail->next = NULL;
};

char removeq_char()
{
  if (head == NULL)
    return -1;
  char data;
  struct Element *p;
  p = head;
  data = p->data;
  head = p->next;
  free(p);
  return data;
};

int main(void)
{
  FILE *fp;
  fp = fopen("./input.txt", "r");
  if (fp == NULL)
  {
    printf("Error: Cannnot open file.\n");
    return -1;
  }

  initialize();

  // 改行文字以外を読み込む
  char c;
  while ((c = fgetc(fp)) != EOF)
  {
    printf("%c", c);
    if (c != '\n')
      enterq_char(c);
  }

  while (1)
  {
    c = getchar();
    // qならば終了
    if (c == 'q')
    {
      break;
    }
    // nならば取り出して出力
    else if (c == 'n')
    {
      if (head == NULL)
      {
        printf("(ファイルの末尾に到達しました)\n");
        break;
      }
      char data = removeq_char();
      printf("ファイルの中身は %c \n", data);
    }
  }

  fclose(fp);
  return 0;
}