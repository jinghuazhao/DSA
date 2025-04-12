/* DELETE A NODE FROM A SIMPLE DOUBLY LINKED LIST */
/* DBL_D.C */

# include <stdio.h>
# include <malloc.h>

struct Double
{
	char info;
	struct Double *next;
	struct Double *previous;
};

int num ;
struct Double start;

void Doubly_Link_Del (struct Double *);
void Doubly_Link_Creat (struct Double *);
void display (struct Double *);

/* Function creates a doubly linked list */

void Doubly_Link_Creat (struct Double *node)
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
		printf("\n Input the values of the node: %d:", (num+1));
		scanf("%d",  &node->info);
		node->next = NULL;
		fflush(stdin);
		printf("\n Input choice n for break: ");
		ch = getchar();
		num ++;
	}
	printf("\n Total nodes = %d", num);
}

/* Function delete */

void Doubly_Link_Del (struct Double *node)
{
	int delete_node;
	int search_counter = 0;

	printf("\n Input the node number to which you want delete: ");
	scanf("%d", &delete_node);

	node = start.next;
	if ( node == NULL)
	{
		printf("\n Underflow\n");
		printf("\n List is empty\n");
	}
	else

		while(node)
		{
			if((search_counter + 1) == delete_node)
			{
				node->previous->next = node->next ;
				node->next->previous = node->previous ;
				free(node);
			}
			else
			{
				node = node->next;

			}
			search_counter++;
		}
}

/* Display the list */

void display(struct Double *node)
{
	node = start.next;

	while (node)
	{
		printf("\n 0x%x", node);
		printf("  %d", node->info);
		node = node->next;
	}
}

/* Function main */

void main()
{
	struct Double *node = (struct Double *) malloc(sizeof(struct Double));
	Doubly_Link_Creat(node);
	printf("\n Created linked list is as follows\n");
	display(node);
	Doubly_Link_Del(node);
	printf("\n After deletion of a node linked list is as follows\n");
	display(node);
}
