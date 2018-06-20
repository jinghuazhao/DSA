/* SELECTION SORT */
/* selects.c */

# include<stdio.h>

int selection_sort(int , int *); /* Prototype */

void main()
{
	int number, list[200];
	int i;
	printf("Input the number of elements in the list:");
	scanf("%d", &number);
	printf("\n Number  of elements in the list is: %d", number);

	printf("\nInput the elements of the list\n");
	for(i = 0 ; i < number ; i++)
		scanf("%d", &list[i]);

	selection_sort( number, list);
}

/* Definition of function */

int selection_sort(int n, int l[])
{
	int min ;
	int k, index;

	for(index = 0; index< n - 1 ; index++)
	{
		min = index ;
		for(k = index + 1; k < n ; k ++)
		{
			if(l[min] > l[k])
				min = k ;
		}
		if( min != index)
		{
			int temp = l [index];
			l[index] = l[min];
			l[min] = temp ;
		}
	}

	printf("\n Entered list is as  follows:\n");
	for( index = 0 ; index < n; index++)
		printf(" %d", l[index]);
	return 0;
}
