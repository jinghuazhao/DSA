/* INSERT A NODE INTO A SIMPLE LINKED LIST */
/* LINK_CIR.C */

# include <stdio.h>
# include <malloc.h>

struct link
{
	int info;
	struct link *next;
};

int i;
int number;
struct link *start, *previous, *new1;

void insertion(struct link *);
void create_list(struct link *);
void display(struct link *);

/* Function create a linked list */

void create_list(struct link *node)
{
	char ch;
	start->next = NULL;  /* Empty list */

	node = start;      /* Point to the start of the list */
	node->next = (struct link* ) malloc(sizeof(struct link));
	i = 0;
	printf("\n Input choice n for break: ");
	ch = getchar();
	while(ch != 'n')
	{
		node->next = (struct link* ) malloc(sizeof(struct link));
		node = node->next;
		printf("\n Input the node: %d: ", (i+1));
		scanf("%d", &node->info);
		node->next = NULL;
		fflush(stdin);
		printf("\n Input choice n for break: ");
		ch = getchar();
		i++;
	}
	printf("\n Total nodes = %d", i);
	node = start;
	node->info = i;
}

/* Inserting a node */

void insertion(struct link *node)
{
	int node_number = 1;
	int insert_node;
	int count = node->info;

	node = start;
	previous = start;

	node = node->next;
	previous = previous->next;
	node = node->next;
	previous = previous->next;

	printf("\n Input node number you want to insert:");
	printf("\n Value should be less are equal to the");
	printf("\n number of nodes in the list: ");
	scanf("%d", &insert_node);

	while(node)
	{
		if((node_number) == insert_node)
		{
			new1 = (struct link* ) malloc(sizeof(struct link));
			new1->next = node->next ;
			previous->next = new1;
			printf("\n Input the node value: ");
			scanf("%d", &new1->info);
		}
		else
		{
			node = node->next;
			previous= previous->next;
		}
		node_number ++;
	}
	if (node == NULL)
	{
		node = start;  /* Points to header node */
		node->info = node->info+1;
	}
}

/* Display the list */

void display(struct link *node)
{
	int count = node->info;

	node = previous; 
	//start;
	node = node->next;
	printf("\n After Inserting a node list is as follows:\n");
	while (count)
	{
		printf("\n 0x%x", node);
		printf(" %d", node->info);
		node = node->next;
		count --;
	}
}

/* Function main */

void main()
{
	struct link *node = (struct link *) malloc(sizeof(struct link));

	create_list(node);
	insertion(node);
	display(node);
}
