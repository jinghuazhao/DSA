/*  INSERTING SOME NODES IN THE DOUBLY LINKED LIST */
/*  DBL_IL.C */

# include <stdio.h>
# include <malloc.h>

struct Double {
	char info;
	struct Double *next;
	struct Double *previous;
};
int i;
struct Double  start, *new1;
void Doubly_insertion_Last (struct Double *);
void Doubly_Create_Last (struct Double *);
void Display (struct Double *);

/* Function create a list of five nodes */

void Doubly_Create_Last (struct Double *node)
{
	int i = 0;
	char ch;
	start.next = NULL;  /* Empty list */
	start.previous = NULL;
	node = &start;      /* Point to the start of the list */

	printf("\n Input choice n for break: ");
	ch = getchar();

	while (ch != 'n')
	{
		node->next = (struct Double *) malloc(sizeof(struct Double ));
		node->next->previous = node;
		node = node->next;
		printf("\n Input the value for: %d: ", i+1);
		scanf("%c", &node->info);
		node->next = NULL;
		i++;
		fflush(stdin);
		printf("\n Input choice n for break: ");
		ch = getchar();
	}
}


void Doubly_insertion_Last (struct Double *node)
{
	node = start.next;

	new1 = (struct Double *) malloc(sizeof(struct Double ));
	fflush(stdin);
	printf("\n Input the last node  value: ");
	scanf("%c", &new1->info);

	if (node == NULL)
	{
		printf("\n List is empty\n");
		printf("\n Insert as last node\n");
	}
	else
		while(node)
		{
			node = node->next;
		}

	new1->next = node;
	new1->previous = node->previous;
	node->previous->next = new1;
	node->next = new1;
}

/* Display the list */

void Display (struct Double *node)
{
	node = start.next;

	while (node)
	{
		printf("\n 0x%x", node);
		printf("  %c", node->info);
		node = node->next;
	}
}

/* Function main */

void main()
{
	struct  Double *node = (struct Double *) malloc(sizeof(struct Double));
	Doubly_Create_Last (node);
	printf("\n Created list is as follows\n");
	Display(node);
	Doubly_insertion_Last (node);
	printf("\n List after insertion of last node \n");
	Display (node);
}


