/* bubble.c */

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int array[], int size)
{
	int temp, i, j;

	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			if (array[i] < array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
}

void main(void)
{
	int values[30], i;
	printf("\n Unsorted list is as follows\n");

	for (i = 0; i < 10; i++)
	{
		values[i] = rand() % 100;
		printf(" %d", rand()%100);
	}
	bubble_sort(values, 10);
	printf("\n Sorted list is as follows\n");

	for (i = 0; i < 10; i++)
		printf("%d ", values[i]);
}

