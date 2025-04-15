/* CREATING CIRCULAR HEADER LINKED LIST */
/* CIRCLIST.C */

# include <stdio.h>
# include <malloc.h>

struct link
{
	int info;
	struct link *next;
};

int i; /* Represents number of nodes in the list */
int number;
struct link *start, *new1;

void insertion(struct link *);
void create_circular_list(struct link *);
void display(struct link *);


/* Function create a circular header linked list */

void create_circular_list( struct link *node)
{
	char ch;

	node = start;      /* Point to the header node in the list */
	node->next = (struct link *) malloc(sizeof(struct link));
	i = 0;
	printf("\n Input choice n for break: ");
	ch = getchar();
	while(ch != 'n')
	{
		node->next = (struct link* ) malloc(sizeof(struct link));
		node = node->next;
		printf("\n Input the node: %d:", (i+1));
		scanf("%d", &node->info);
		fflush(stdin);
		printf("\n Input choice n for break: ");
		ch = getchar();
		i++;
	}
	printf("\n Total nodes = %d", i);
	node = start;
	node->info = i; /* Assign total number of nodes to the header node */
}

/* Inserting a node in circular header linked */
void insertion(struct link *node)
{
	int count = node->info;
	int node_number = 0;
	int insert_node;

	node = start;
	node = node->next;

	printf("\n Input node number you want to insert: ");
	printf("\n Value should be less are equal to the");
	printf("\n number of nodes in the list: ");
	scanf("%d", &insert_node);

	while(count)
	{
		if((node_number+1) == insert_node)
		{
			new1 = (struct link* ) malloc(sizeof(struct link));
			new1->next = node->next ;
			node->next = new1;
			printf("\n Input the node value: ");
			scanf("%d", &new1->info);
			node = node->next;
			count--;
		}
		else
		{
			node = node->next;
			count--;
		}
		node_number ++;
	}
	if (count == 0)
	{
		node = start;  /* Points to header node */
		node->info = node->info+1;
	}
}

/* Display the list */

void display(struct link *node)
{
	int count = node->info;

	node = start;
	node = node->next;

	while (count-1)
	{
		printf("\n 0x%x", node);
		printf(" %d ", node->info);
		node = node->next;
		count --;
	}
}

/* Function main */

void main()
{
	struct link *node = (struct link *) malloc(sizeof(struct link));
	create_circular_list(node);
	printf("\n Before inserting a node list is as follows:\n");
	display(node);
	insertion(node);
	printf("\n After inserting a node list is as follows:\n");
	display(node);
}
