/* DELETE A NODE FROM A SIMPLE DOUBLY LINKED LIST */
/* DBL_DF.C */

# include <stdio.h>
# include <malloc.h>

struct Double
{
	char info[20];
	struct Double *next;
	struct Double *previous;
};

int num ;
struct Double start;

void Doubly_Link_Del_First (struct Double *);
void Doubly_Link_Creat_First (struct Double *);
void display (struct Double *);

/* Function creates a doubly linked list */

void Doubly_Link_Creat_First (struct Double *node)
{
	char ch;
	start.next = NULL;  /* Empty list */
	start.previous = NULL;
	node = &start;      /* Point to the start of the list */

	num = 0;

	printf("\n Input choice n for break:");
	ch = getchar();

	while(ch != 'n')
	{
		node->next = (struct Double *) malloc(sizeof(struct Double));
		node->next->previous = node;
		node = node->next;
		fflush(stdin);
		printf("\n Input the values of the node : %d:", (num+1));
		gets(node->info);
		node->next = NULL;
		fflush(stdin);
		printf("\n Input choice n for break:");
		ch = getchar();
		num ++;
	}
	printf("\n Total nodes = %d", num);
}

/* Function delete */

void Doubly_Link_Del_First (struct Double *node)
{
	node = start.next;
	if( node == NULL)
	{
		printf("\n Underflow");
	}
	else
	{
		node->previous->next = node->next ;
		node->next->previous = node->previous ;
		free(node);
	}
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
			printf(" %s", node->info);
			node = node->next;
		}
}

/* Function main */

void main()
{
	struct Double *node = (struct Double *) malloc(sizeof(struct Double));
	Doubly_Link_Creat_First (node);
	printf("\n Created linked list is as follows\n");
	display (node);
	Doubly_Link_Del_First (node);
	printf("\n After deletion of first node list is as follows\n");
	display(node);
}
