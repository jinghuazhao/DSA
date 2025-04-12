/* CREATING SIMPLE LINKED LIST */
/* LINK_C.C */

# include <stdio.h>
# include <malloc.h>

struct link
{
	int info;
	struct link *next;
};

int i;
struct link *start = NULL; /* Shows empty list */

void creat_link_list (struct link *);
void display (struct link *);

void creat_link_list (struct link *node)
{
	char ch;
	printf("\n Input choice n for break: ");
	i = 0;
	ch = getchar();
	while(ch !='n')
	{
		printf("\n Input the node: %d :", i+1);
		scanf("%d",&node->info);
		node->next = (struct link* ) malloc (sizeof (struct link));
		node = node->next;
		node->next = start;
		i++;
		printf("\n Input choice n for break: ");
		ch = getchar();
	}
}

/* Display the list */

void  display(struct link *node)
{
	printf("\n Values of the entered nodes are as follows:\n");
	while (node)
	{
		printf("  %d", node->info);
		node = node->next;
	}
}

/* Function main */

void main()
{
	struct link *node = (struct link *)malloc(sizeof(struct link));
	creat_link_list(node);
	display(node);
}
 

