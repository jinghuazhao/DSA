/* Create Binary TREE */
/* CREAT_BT.C */

# include<stdio.h>
# include<malloc.h>

struct NODE
{
	int Info;
	struct NODE *Left_Child;
	struct NODE *Right_Child;
};

struct NODE *Binary_Tree (char *, int, int);
void Output(struct NODE *, int );

/* Function to insert an element into tree */

struct  NODE *  Binary_Tree (char *List, int Lower, int Upper)
{
	struct NODE *Node;
	int Mid = (Lower + Upper)/2;
	Node = (struct NODE *) malloc(sizeof(struct NODE));

	Node->Info = List [Mid];
	if ( Lower>= Upper)
	{
		Node->Left_Child = NULL;
		Node->Right_Child = NULL;
		return (Node);
	}

	if (Lower <= Mid - 1)
		Node->Left_Child = Binary_Tree (List, Lower, Mid - 1);
	else
		Node->Left_Child = NULL;
	if (Mid + 1 <= Upper)
		Node->Right_Child = Binary_Tree (List, Mid + 1, Upper);
	else
		Node->Right_Child = NULL;
	return(Node);
}

/* Output function */

void Output(struct NODE *T, int Level)
{
	int i;
	if (T)
	{
		Output(T->Right_Child, Level+1);
		printf("\n");
		for (i = 0; i < Level; i++)
			printf("   ");
		printf("%c", T->Info);
		Output(T->Left_Child, Level+1);
	}
}

/* Function main */

void main()
{
	char List[100];
	int Number = 0;
	char Info ;
	char choice;
	struct NODE *T = (struct NODE *) malloc(sizeof(struct NODE));
	T = NULL;
	printf("\n Input choice 'b' to break:");
	choice = getchar();
	while(choice != 'b')
	{
		printf("\n Input information of the node: ");
		scanf("%c", &Info);
		List[Number++] = Info;
		fflush(stdin);
		printf("\n Input choice 'b' to break:");
		choice = getchar();
	}
	Number --;
	printf("\n Number of elements in the lsit is %d", Number);
	T = Binary_Tree(List, 0, Number);
	Output(T,1);
}

