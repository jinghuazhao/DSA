/* REVERSING A LINKED LIST */
/* LINK_REV.C */

#include <stdio.h>
#include <malloc.h>

struct link
{
	int data;
	struct link *next;
};

int i, number;
struct link *start, *node, *previous, *current1, *counter;

void display(struct link *);
void create_list(struct link *);
struct link * reverse(struct link *);

/* Reversing the list */

struct link * reverse(struct link *start)
{
	current1 = start;
	previous = NULL ;

	while( current1 != NULL )
	{
		counter = (struct link *)malloc(sizeof(struct link));
		counter = current1->next ;
		current1->next = previous ;
		previous = current1 ;
		current1 = counter;
	}

	start = previous;
	return(start);
}

/* Definition of the function */

void  display(struct link *node)
{
	while (node != NULL)
	{
		printf(" %d", node->data);
		node = node->next;
	}
}

/* Definition of the function */

void create_list(struct link *node)
{
	int i;
	int number;

	printf("\n Input the number of nodes you want to create:");
	scanf("%d", &number);

	/* CREATE A LINKED LIST */

	for (i = 0; i < number ; i++)
	{
		printf("\n Input the node: %d: ", i+1);
		scanf("%d", &node->data);
		node->next = (struct link* ) malloc(sizeof(struct link));
		if( i == number - 1)
			node->next = NULL;
		else
			node = node->next;
	}
	node->next = NULL;
}

/* End of function creation */

/* Function main */

void main()
{
	struct link *node;
	struct link *p;

	node = (struct link *) malloc(sizeof(struct link));
	create_list(node);
	printf("\n Original List is as follows:\n");
	display(node);
	p = ( struct link *)malloc(sizeof(struct link));
	p = reverse(node);
	printf("\n After reverse operation list is as follows:\n");
	display(p);
}
