/* LINEAR SEARCH */
/* lsearch.c */

# include<stdio.h>


int search;
int flag;
int	    input( int *, int , int);
int list[200];

void linear_search(int * , int , int );
void display(int *, int);

/* Definition of function */

void  linear_search(int l[], int n, int element)
{
	int k;
	flag = 1;
	for(k = 0; k< n; k++)
	{
		if(l[k] == element)
		{
			printf("\n Search is successful \n");
			printf("\n Element: %i Found at Location: %i", element,
			    k+1);
			flag = 0 ;
		}
	}
	if (flag)
		printf("\n Search is unsuccessful");
}

void display(int list[], int n)
{
	int i;
	for(i = 0 ; i < n ; i++)
	{
		printf(" %d", list[i]);
	}
}
input(int list[], int number, int key)
{ 
	int i;
	key = 30;
	printf("Input the number of elements in the list:");
	number = 20;
	for(i = 0 ; i < 20; i++)
	{
		list[i] = rand() %100;
	}
	printf("\n Element to be searched: %d", key);
	search = key;
	return number;
}

void main()
{
	int number, key, list[200];

	number = input( list, number, key);

	key = search ;
	printf("\n Entered list as follows:\n");
	display(list,number);
	linear_search(list, number, key);
	printf("\n In the following list\n");
	display(list,number);
}
