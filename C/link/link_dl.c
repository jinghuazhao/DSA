/* DELETING LAST NODE FROM A SIMPLE LINKED LIST */
/* LINK_DL.C */

# include <stdio.h>
# include <malloc.h>

struct link
{
	char info;
	struct link *next;
};

int i;
int number ;
struct link start, *previous;

void  Delete_node(struct link *);
void  creat_node(struct link *);

void creat_node(struct link *node)
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
		printf("\n Input the node: %d: ", (i+1));
		scanf("%c", &node->info);
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
		printf("  %c",  node->info);
		node = node->next;
	}
}

/* Removing a node */

void Delete_node(struct link *node)
{
	int node_number = 0;

	node = start.next;
	previous = &start;

	if (node == NULL)
	{
		printf("\n Underflow");
	}

	else

		while(node)
		{
			node = node->next;
			previous = previous->next;
			node_number ++;
		}
	printf("\n Total Nodes = %d", node_number);

	node = start.next;
	previous = &start;

	while(node_number != 1)
	{
		node = node->next;
		previous = previous->next;
		node_number --;
	}
	if(node_number == 1)
	{
		previous->next = node->next;
		free(node);
	}
	/* Display the list */

	node = start.next;
	printf("\n After deleting last node list is as follows\n");
	while (node)
	{
		printf("\n 0x%x", node);
		printf(" %c", node->info);
		node = node->next;
	}
}

/* Function main */

void main()
{
	struct link *node = (struct link *) malloc(sizeof(struct link));
	creat_node(node);
	Delete_node(node);
}
