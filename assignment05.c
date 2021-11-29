#include <stdio.h>
#include <stdlib.h>

struct Element
{
  int data;
  struct Element *next;
};
struct Element *head;

void initialize()
{
  head = NULL;
}

void add(int data)
{
  struct Element *p;
  p = malloc(sizeof(struct Element));
  p->data = data;
  p->next = head;
  head = p;
}

int delete (int data)
{
  int i;
  struct Element *p, *q;
  int j;
  struct Element *r;

  for (i = 0, p = q = head; p != NULL; i++, q = p, p = p->next)
  {
    for (j = 0, r = head; r != NULL; j++, r = r->next)
    {
      printf("%6d: %p %6d %p", j, r, r->data, r->next);
      if (r == p && r == q)
        printf(" <- p, q\n");
      else if (r == p)
        printf(" <- p\n");
      else if (r == q)
        printf(" <- q\n");
      else
        printf("\n");
    }
    printf("\n");
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
    int i, j;
    struct Element *p, *q, *r;
    for (i = 0, p = q = head; i < index && p->next != NULL; i++, q = p, p = p->next)
    {
      for (j = 0, r = head; r != NULL; j++, r = r->next)
      {
        printf("%6d: %p %6d %p", j, r, r->data, r->next);
        if (r == p && r == q)
          printf(" <- p, q\n");
        else if (r == p)
          printf(" <- p\n");
        else if (r == q)
          printf(" <- q\n");
        else
          printf("\n");
      }
      printf("\n");
    }
    for (j = 0, r = head; r != NULL; j++, r = r->next)
    {
      printf("%6d: %p %6d %p", j, r, r->data, r->next);
      if (r == p && r == q)
        printf(" <- p, q\n");
      else if (r == p)
        printf(" <- p\n");
      else if (r == q)
        printf(" <- q\n");
      else
        printf("\n");
    }
    printf("\n");
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

void display(struct Element *q)
{
  int i;
  struct Element *p;
  for (i = 0, p = head; p != NULL; i++, p = p->next)
  {
    printf("%6d: %p %6d %p", i, p, p->data, p->next);
    if (p == q)
      printf(" ******\n");
    else
      printf("\n");
  }
}

int main(void)
{
  int mode = 1, id;
  initialize();
  while (mode)
  {
    printf("list process ?add(1), insert(2), search(3) or delete(0) = ");
    scanf("%d", &mode);
    if (mode == 1)
    {
      printf("?data = ");
      scanf("%d", &id);
      add(id);
    }
    else if (mode == 2)
    {
      int data;
      printf("?index = ");
      scanf("%d", &id);
      printf("?data = ");
      scanf("%d", &data);
      insert(id, data);
    }
    else if (mode == 3)
    {
      int index;
      printf("?data = ");
      scanf("%d", &id);
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
    display(head);
    printf("?continue(1) or quit(0) = ");
    scanf("%d", &mode);
  }

  return 0;
}
