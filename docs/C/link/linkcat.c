/* CONCATENATE TWO LINKED LIST */
/* LINKCAT.C */

#include <stdio.h>
#include <malloc.h>

struct link
{
	int data;
	struct link *next;
};

struct link *start, *node;
struct link *list_one, *list_two, *list_three;

void  display(struct link *);
void  create_list(struct link *);
void  link_concat_list(struct link *, struct link *, struct link *);

void display(struct link *node)
{
	while (node->next)
	{
		printf(" %d",  node->data);
		node = node->next;
	}
}

/* Definition of the function */

void create_list(struct link *node)
{
	int i = 0;
	char ch;

	printf("\n Input choice n for break: ");
	ch = getchar();

	/* CREATE A LINKED LIST */

	while(ch != 'n')
	{
		printf("\n Input the node: %d: ", (i+1));
		scanf("%d", &node->data);
		node->next = (struct link * ) malloc(sizeof(struct link));
		node = node->next;
		node->next = NULL;
		fflush(stdin);
		printf("\n Input choice n for break: ");
		ch = getchar();
		i ++;
	}
	printf("\n Total nodes = %d", i);
}

void link_concat_list(struct link *list_one, struct link *list_two, struct link *list_three)
{

	/* Copying first list */

	while(list_one->next != NULL)
	{
		list_three->data = list_one->data;
		list_one = list_one->next;
		list_three->next = (struct link* ) malloc(sizeof(struct link));
		list_three = list_three->next;
	}

	/* Copying second list  */

	while(list_two->next !=NULL)
	{
		list_three->data = list_two->data;
		list_two = list_two->next;
		list_three->next = (struct link*)malloc(sizeof(struct link));
		list_three = list_three->next;
	}
	list_three->next = NULL;
}

/* Function main */

void main()
{
	struct link *list_one, *list_two, *list_three;

	/* Assign memory to link(struct) type variables */

	list_one = (struct link *)malloc(sizeof(struct link));
	list_two = (struct link *)malloc(sizeof(struct link));
	list_three = (struct link *)malloc(sizeof(struct link));

	create_list(list_one);
	printf("\n Original list ONE is as follows:\n");
	display(list_one);

	create_list(list_two);
	printf("\n Original list TWO is as follows:\n");
	display(list_two);

	link_concat_list(list_one, list_two, list_three);
	printf("\n Original list ONE + TWO is as follows:\n");
	display(list_three);
}

