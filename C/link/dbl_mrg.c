/*  MERGING TWO DOUBLY LINKED LISTS (ASCENDING ORDER) */
/*  DBL_MRG.C */

# include <stdio.h>
# include <malloc.h>

struct Double
{
	int info;
	struct Double *next;
	struct Double *previous;
};

int i;
struct Double  start, start1, *new1, *local;
void Doubly_insertion (struct Double * );
void Doubly_Create (struct Double * );
void Display (struct Double *);

/* Function create a list of five nodes */

void Doubly_Create (struct Double *node)
{
	start.next = NULL;  /* Empty list */
	start.previous = NULL;
	node = &start;      /* Point to the start of the list */

	for (i = 1; i < 10; i += 2)
	{
		node->next = (struct Double *) malloc(sizeof(struct Double ));
		node->next->previous = node;
		node = node->next;
		node->info = i;
		node->next = NULL;
	}
}

void Doubly_insertion (struct Double *node)
{
	struct Double *new1;
	start1.next = NULL;  /* Empty list */
	start1.previous = NULL;
	new1 = &start1;      /* Point to the start of the list */

	for (i = 2; i <= 10; i += 2)
	{
		new1->next = (struct Double *) malloc(sizeof(struct Double ));
		new1->next->previous = new1;
		new1= new1->next;
		new1->info = i;
		new1->next = NULL;
	}

	new1 = start1.next;
	printf("\n Second list is as follows");
	while(new1)
	{
		printf("\n 0x%x", new1);
		printf(" %d", new1->info);
		new1 = new1->next;
	}
	new1 = start1.next;

	while(new1)
	{
		int found = 0;
		local = (struct Double *) malloc(sizeof(struct Double));
		local = new1;
		new1 = new1->next;

		node = start.next;

		do
		{
			if ( node->info > local->info )
			{
				local->next = node;
				local->previous = node->previous;
				node->previous->next = local;
				node->previous = local;
				found = 1;
				break;
			}
			else
				node = node->next;
		} while ((node->next) && (! found));

		if (! found)
			if (node->info> local->info)
			{
				local->next = node;
				local->previous = node->previous;
				node->previous->next = local;
				node->previous = local;
			}
			else
			{
				local->next = NULL;
				local->previous = node;
				node->next = local;

			}
	}
}

/* Display the list */

void Display (struct Double *node)
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
	Doubly_Create (node);
	printf("\n First list is as follows\n");
	Display (node);
	Doubly_insertion (node);
	printf("\n List after merging above two lists (Ascending order)\n");
	Display (node);
}


