/* POLY NOMIAL WITH HELP OF LINKED LIST */
/* POLY.C */

# include <stdio.h>
# include <malloc.h>

struct link
{
	float coef;
	int expo;
	struct link *next;
};

int i;
int number;
struct link start, *previous, *new1;

void insertion(struct link *);
void create_poly(struct link *);
void display(struct link *);

/* Function create a ploynomial list */

void create_poly(struct link *node)
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
		printf("\n Input the coeficient value: %d: ", i+1);
		scanf("%f", &node->coef);
		printf("\n Input the exponent value: %d: ", i+1);
		scanf("%d", &node->expo);
		node->next = NULL;
		fflush(stdin);
		printf("\n Input choice n for break: ");
		ch = getchar();
		i++;
	}
	printf("\n Total nodes = %d", i);
}

/* Display the polynomial */

void display(struct link *node)
{
	node = &start;
	node = node->next;

	while (node)
	{
		printf("+ %f", node->coef);
		printf("X^%d", node->expo);
		node = node->next;
	}
}

/* Function main */

void main()
{
	struct link *node = (struct link *) malloc(sizeof(struct link));
	create_poly(node);
	display(node);
}
