/* DELETING FIRST NODE FROM A SIMPLE LINKED LIST */
/* LINK_DF.C*/

# include <stdio.h>
# include <malloc.h>

struct link
{
	int data;
	struct link *next;
};

int i;
int number ;
struct link start, *node, *previous;

void  Delete_node();
void  creat_node();

void creat_node()
{
	char ch;
	i = 0;

	start.next = NULL;  /* Empty list */
	node = &start;      /* Point to the start of the list */

	printf("\n Input choice n for break:");
	ch = getchar();

	while(ch != 'n')
	{
		node->next = (struct link* ) malloc(sizeof(struct link));
		node = node->next;
		printf("\n Input the node: %d: ", i+1);
		scanf("%d", &node->data);
		node->next = NULL;
		fflush(stdin);
		printf("\n Input choice n for break:");
		ch = getchar();
		i++;
	}

	node = start.next;
	previous = &start;
	printf("\n Created list is as follows\n");

	while (node)
	{
		printf("\n 0x%x", node);
		printf(" %d", node->data);
		node = node->next;
	}
}


/* Removing a node */
void Delete_node()
{
	node = start.next;
	previous = &start;

	if (node == NULL)
	{
		printf("\n Under flow");
	}
	else
	{
		previous->next = node->next;
		free(node);
	}

	/* Display the list */

	node = start.next;
	printf("\n After deleting first node list is as follows\n");
	while (node)
	{
		printf("\n 0x%x", node);
		printf(" %d", node->data);
		node = node->next;
	}
}

/* Function main */

void main()
{
	creat_node();
	Delete_node();
}
