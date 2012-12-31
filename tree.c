#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#define MAX_SCORP 25 
#define BASE 10

typedef struct tree{

	int data;
	struct tree *l;
	struct tree *r;
}tree_t;
void array_init(int *arr, int size)
{
	int i = 0;
	srand(time(NULL));

	while(i < size)
	{
		*(arr + i) = (rand() % (MAX_SCORP - 10 + 1) + BASE);
		i++;
	}
}

void array_show(int *arr, int size)
{
	int i = 0;
	while(i < size)
		printf("%d ", *(arr + i++));
	putchar('\n');

}
void create_tree(tree_t **t, int*arr, int idx, int len)
{
	if(idx > len)
	{
		return;
	}
	*t = malloc(sizeof(tree_t));

	(*t)->data = arr[idx];
	(*t)->l = (*t)->r = NULL;

	create_tree(&((*t)->l), arr, 2 * idx + 1, len);
	create_tree(&((*t)->r), arr, 2 * idx + 2, len);
}

void _pprint(tree_t *t)
{
	if(!t)
	{
		printf("()");
	}
	else
	{
		printf("(");
		printf("%d", t->data);
		_pprint(t->l);
		_pprint(t->r);
		printf(")");
	}
}

void pprint(tree_t *t)
{
	printf("\t\\tree");
	_pprint(t);
	printf("\n\n");
}
int main(void)
{
	tree_t *t;

	int arr[MAX_SCORP];

	array_init(arr, MAX_SCORP);
	array_show(arr, MAX_SCORP);

	create_tree(&t, arr, 0, MAX_SCORP - 1);
	
	pprint(t);
	return 0;
}
