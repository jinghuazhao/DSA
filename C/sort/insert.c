/* Insertion sort */
/* INSERT.C */

# include<stdio.h>
# include<stdlib.h>

void insertion_sort(int *, int);
void display(int*, int);

void insertion_sort(int l[], int n)
{
	int pointer, temp;
	int i, k;

	l[0] = -0;
	for(i = 1 ; i <= n; i++)
	{
		pointer = i -1;
		temp = l[i];
		while(temp < l[pointer])
		{
			l[pointer+1] = l[pointer];
			pointer --;
		}
		l[pointer+1] = temp;
		printf("Step = %d", i);
		for(k = 0; k <= n; k++)
			printf(" %d", l[k]);
		printf("\n");
	}
}

void display(int l[], int n)
{
int i;
	printf("\n Sorted list is as follows\n");
	for(i = 1; i <= n; i++)
		printf(" %d", l[i]);
}

void main()
{
	int number = 10;
	int list[100];
	int i;

	printf("\n Number of elements in the list: %i", number);
	printf("\n Unsorted list is as follows \n");

	for(i = 1; i <= number; i++)
	{
		list[i] = rand() %100;
		printf(" %d", rand() %100);
	}
	printf("\n");

	printf("\n Step wise result is as follows \n\n");

	insertion_sort(list,number);
	display(list, number);
}

