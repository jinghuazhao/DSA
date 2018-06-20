/* DELETING A NODE FROM A SIMPLE LINKED LIST */
/* WHEN INFORMATION OF A NODE IS GIVEN */
/* LINK_DIN.C */

# include <stdio.h>
# include <malloc.h>

struct link
{
	int info;
	struct link *next;
};

int i;
int number ;
struct link start, *previous;
void  Delete_node(struct link *);
void  creat_node(struct link *);

/* Create linked list */

void creat_node(struct link *node)
{
	char ch;

	i = 0;

	start.next = NULL;  /* Empty list */
	node = &start;      /* Point to the start of the list */

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

	node = start.next;
	printf("\n Created list is as follows: \n");
	while (node)
	{
		printf("\n 0x%x", node);
		printf(" %d", node->info);
		node = node->next;
	}
}


/* Removing a node */

void Delete_node(struct link *node)
{
	int node_number = 1;
	int delete_node;

	node = start.next;
	previous = &start;


	printf("\n Input information of a node you want to delete: ");
	scanf("%d", &delete_node);

	while(node)
	{
		if(node->info == delete_node)
		{
			printf("\n Position of the information in the list is : %d", node_number);
			previous->next = node->next;

			free(node);
			break ;
		}
		else
		{
			node = node->next;
			previous = previous->next;
		}
		node_number++;
	}


	/* Display the list */

	node = start.next;
	printf("\n After deleting a node list is as follows:\n");
	while (node)
	{
		printf("\n 0x%x", node);
		printf(" %d", node->info);
		node = node->next;
	}
}


void main()
{
	struct link *node = (struct link *) malloc(sizeof(struct link));
	creat_node(node);
	Delete_node(node);
}
