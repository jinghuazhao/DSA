/* DELETE A NODE FROM A SIMPLE DOUBLY LINKED LIST*/
/* DBL_DL.C */

# include <stdio.h>
# include <malloc.h>

struct Double
{
	int info;
	struct Double *next;
	struct Double *previous;
};

int num ;
struct Double start;

void Doubly_Link_Del_Last (struct Double *);
void Doubly_Link_Creat_Last (struct Double *);
void display (struct Double *);

/* Function creates a doubly linked list */

void Doubly_Link_Creat_Last (struct Double *node)
{
	char ch;
	start.next = NULL;  /* Empty list */
	start.previous = NULL;
	node = &start;      /* Point to the start of the list */

	num = 0;

	printf("\n Input choice n for break: ");
	ch = getchar();

	while(ch != 'n')
	{
		node->next = (struct Double *) malloc(sizeof(struct Double));
		node->next->previous = node;
		node = node->next;
		printf("\n Input the values of the node: %d: ", (num+1));
		scanf("%d", &node->info);
		node->next = NULL;
		fflush(stdin);
		printf("\n Input choice n for break:");
		ch = getchar();
		num ++;
	}
	printf("\n Total nodes = %d", num);
}

/* Function delete */

void Doubly_Link_Del_Last (struct Double *node)
{
	num = 0;
	node = start.next;
	if( node == NULL)
	{
		printf("\n Underflow");
	}
	else
		while(node)
		{
			node = node->next;
			num ++;
		}
	node = start.next;

	while(num != 1)
	{
		node = node->next;
		num --;
	}

	/* Delete last node */

	node->previous->next = node->next ;
	node->next->previous = node->previous;
	node->next = NULL;
	free(node);
}

/* Display the list */

void display(struct Double *node)
{
	node = start.next;
	if (node == NULL)
	{
		printf("\n List is empty\n");
	}
	else
		while (node)
		{
			printf("\n 0x%x", node);
			printf(" %d", node->info);
			node = node->next;
		}
}

/* Function main */

void main()
{
	struct Double *node = (struct Double *) malloc(sizeof(struct Double));
	Doubly_Link_Creat_Last (node);
	printf("\n Created linked list is as follows\n");
	display(node);
	Doubly_Link_Del_Last(node);
	printf("\n After deletion of last node list is as follows\n");
	display(node);
}
