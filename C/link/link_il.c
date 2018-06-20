/*  INSERT A NODE INTO A SIMPLE LINKED LIST AT THE END OF THE LIST */
/* LINK_IL.C */

# include <stdio.h>
# include <malloc.h>

struct link
{
	char info[20];
	struct link *next;
};

int i;
int number;
struct link start, *previous, *new1;

void insertion(struct link *);
void create_list(struct link *);
void display(struct link *);

/* Function create a linked list */

void create_list(struct link *node)
{
	char ch;
	start.next = NULL;  /* Empty list */

	node = &start;      /* Point to the start of the list */
	i = 0;
	printf("\n Input choice n for break: ");
	ch = getchar();
	while(ch != 'n')
	{
		node->next = (struct link* ) malloc(sizeof(struct link));
		node = node->next;
		printf("\n Input the node: %d: ", (i+1));
		gets(node->info);
		node->next = NULL;
		fflush(stdin);
		printf("\n Input choice n for break: ");
		ch = getchar();
		fflush(stdin);
		i++;
	}
}

/* Inserting a node */
void insertion(struct link *node)
{
	node = start.next;
	previous = &start;

	while(node)
	{
		node = node->next;
		previous= previous->next;
	}
	if(node == NULL)
	{
		new1 = (struct link* ) malloc(sizeof(struct link));
		new1->next = node ;
		previous->next = new1;
		printf("\n Input the last node value: ");
		gets(new1->info);
	}
}

/* Display the list */

void display(struct link *node)
{
	node = start.next;

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
	struct link *node = (struct link *) malloc(sizeof(struct link));

	create_list(node);
	printf("\n Created list is as follows:\n");
	display(node);
	insertion(node);
	printf("\n After Inserting a node list is as follows:\n");
	display(node);
}
