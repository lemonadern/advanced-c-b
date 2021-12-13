#include <stdio.h>
#include <stdlib.h>

struct Element
{
	int data;
	struct Element *next;
};
struct Element *head;

void initialize() { head = NULL; }

void display(struct Element *q)
{
	int i;
	struct Element *p;
	for (i = 0, p = head; p != NULL; i++, p = p->next)
	{
		printf("%6d: %p %6d %p", i, p, p->data, p->next);
		if (q == p)
		{
			printf(" *****");
		}
		printf("\n");
	}
}

void add(int data)
{ // 先頭に要素を追加
	struct Element *p;
	p = malloc(sizeof(struct Element));
	p->data = data;
	p->next = head;
	head = p;
}

void display_list(struct Element *p, struct Element *q)
{
	int j;
	struct Element *r;
	for (j = 0, r = head; r != NULL; j++, r = r->next)
	{
		printf("%6d: %p %6d %p", j, r, r->data, r->next);
		if (r == q && r == p)
		{
			printf(" <- q, p");
		}
		else if (r == q)
		{
			printf(" <- q");
		}
		else if (r == p)
		{
			printf(" <- p");
		}
		printf("\n");
	}
}

int delete (int data)
{
	struct Element *p, *q, *r;
	int i;
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
			}
			return i;
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
		for (i = 0, p = q = head; i < index && p->next != NULL;
				 i++, q = p, p = p->next)
		{
			display_list(p, q);
			printf("\n");
		}
		display_list(p, q);
		if (i == index)
		{
			r = malloc(sizeof(struct Element));
			q->next = r;
			r->data = data;
			r->next = p;
		}
		else
		{
			r = malloc(sizeof(struct Element));
			p->next = r;
			r->data = data;
			r->next = NULL;
		}
		display(r);
	}
}

void insert_sort(int data)
{
	struct Element *p, *q, *r;
	// リストが空の場合は、add()
	if (head == NULL)
	{
		add(data);
	}
	else
	{
		// リストの要素が順になる一まで移動
		for (p = q = head; p->data < data && p->next != NULL; q = p, p = p->next)
		{
		}
		// 末尾の場合
		if (p->next == NULL)
		{
			r = malloc(sizeof(struct Element));
			p->next = r;
			r->data = data;
			r->next = NULL;
		}
		// 先頭の場合
		else if (p == q)
		{
			r = malloc(sizeof(struct Element));
			head = r;
			r->data = data;
			r->next = p;
		}
		// それ以外
		else
		{
			r = malloc(sizeof(struct Element));
			q->next = r;
			r->data = data;
			r->next = p;
		}
	}
	display(r);
	printf("\n");
}

int search(int data)
{
	struct Element *p;
	int i;
	for (p = head, i = 0; p != NULL; p = p->next, i++)
	{
		if (p->data == data)
		{
			return i;
		}
	}
	return -1;
}

void clear()
{
	struct Element *p, *q;
	printf("CLEAR:\n");
	for (p = q = head; p != NULL;
			 q = p, p = p->next)
	{ // p でリストを辿りながら q を解放
		if (p == q)
		{
			continue;
		}
		display(q);
		printf("\n");
		free(q);
		head = p;
	}
	display(q);
	printf("\n");
	head = NULL;
}

int main(void)
{
	int length, i, data;
	initialize();
	// 標準入力からnを受け取る
	printf("n?: ");
	scanf("%d", &length);
	if (length <= 0)
	{
		printf("Invalid input: Enter an integer value greater than 0.\n");
		exit(1);
	}
	for (i = 0; i < length; i++)
	{
		// 50までのランダムな整数
		data = rand() % 50;
		insert_sort(data);
	}
	// リストをクリア
	clear();

	return 0;
}
