/* Double_i.c */
/* Inserting nodes in a double linked list */

#include <stdio.h>
#include <malloc.h>

void main(void)
{
	int i;

	struct ListEntry {
		int number;
		struct ListEntry *next;
		struct ListEntry *previous;
	} start, *node, *new;

	start.next = NULL;  
	/* Empty list */
	    start.previous = NULL;
	node = &start;      
	/*  Point to the start of the list */

	    for (i = 1; i < 10; i += 2)
	{
		node->next = (struct ListEntry *) malloc(sizeof(struct ListEntry));
		node->next->previous = node;
		node = node->next;
		node->number = 50 + i;
		node->next = NULL;
	}

	/* Display the list */

	printf("\n List before inserting nodes\n ");

	node = start.next;
	do {
		printf("%d ", node->number);
		node = node->next;
	} while (node);

	/* inserting some nodes in the list */

	for (i = 2; i <= 10; i += 2)
	{
		int found = 0;

		new = (struct ListEntry *) malloc(sizeof(struct ListEntry));
		new->number = 50 + i;
		node = start.next;

		do {
			if (node->number > new->number)
			{
				new->next = node;
				new->previous = node->previous;
				node->previous->next = new;
				node->previous = new;
				found = 1;
			}
			else
				node = node->next;
		} while ((node->next) && (! found));

		if (! found)
			if (node->number > new->number)
			{
				new->next = node;
				new->previous = node->previous;
				node->previous->next = new;
				node->previous = new;
			}
			else
			{
				new->next = NULL;
				new->previous = node;
				node->next = new;
			}
	}

	/* Display the list */

	printf("\n List after inserting nodes\n ");

	node = start.next;
	do {
		printf("%d ", node->number);
		node = node->next;
	} while (node);
}


