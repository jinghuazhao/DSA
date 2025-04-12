/*  INSERTING FIRST NODE IN THE DOUBLY LINKED LIST */
/*  DBL_IF.C */

# include <stdio.h>
# include <malloc.h>

struct Double
{
	char info[20];
	struct Double *next;
	struct Double *previous;
};

int i;
struct Double  start, *new1;
void Doubly_insertion_First (struct Double *);
void Doubly_Create_First (struct Double *);
void Display (struct Double *);

/* Function create a list of five nodes */

void Doubly_Create_First (struct Double *node)
{
	int i = 0;
	char ch;
	start.next = NULL;  /* Empty list */
	start.previous = NULL;
	node = &start;      /* Point to the start of the list */
	fflush(stdin);
	printf("\n Input choice n for break: ");
	ch = getchar();

	while (ch != 'n')
	{
		node->next = (struct Double *) malloc(sizeof(struct Double ));
		node->next->previous = node;
		node = node->next;
		printf("\n Input the value for: %d: ", i+1);
		gets(node->info);
		node->next = NULL;
		i++;
		fflush(stdin);
		printf("\n Input choice n for break: ");
		ch = getchar();
	}
}

void Doubly_insertion_First (struct Double *node)
{
	node = start.next;

	new1 = (struct Double *) malloc(sizeof(struct Double ));
	fflush(stdin);
	printf("\n Input the first node  value: ");
	gets(new1->info);
	printf("\n new1 address: 0x%x", new1);
	printf("\n Node address: 0x%x", node);
	new1->next = node;
	printf("\n New1 next address: 0x%x", new1->next);
	printf("\n Node previous address: 0x%x", node->previous);
	new1->previous = node->previous;
	node->previous->next = new1;
	printf("\n node->previous.next: 0x%x", node->previous->next);
	printf("\n Node previous address: 0x%x", node->previous);
	printf("\n Node next address: 0x%x", node->next);
	printf("\n new1 address: 0x%x", new1);
	node->previous = new1;
	printf("\n node->previous: 0x%x", node->previous);
}

/* Display the list */

void Display (struct Double *node)
{
	node = start.next;

	while (node)
	{
		printf("\n 0x%x", node);
		printf(" %s", node->info);
		node = node->next;
	}
}

/* main function */

void main()
{
	struct Double *node = (struct Double *) malloc(sizeof(struct Double));
	Doubly_Create_First (node);
	printf("\n Created list is as follows\n");
	Display(node);
	Doubly_insertion_First (node);
	printf("\n List after insertion of first node \n");
	Display (node);
}



