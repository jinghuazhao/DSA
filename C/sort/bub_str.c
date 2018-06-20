/* BUBBLE SORT FOR SORTING STRINGS */
/* BUB_STR.C */

# include <stdlib.h>
# include <string.h>
# include <malloc.h>
# include <stdio.h>

void bubble_sort(char *array[], int );
void display(char *list[], int);

void bubble_sort(char *array[], int size)
{
	char *temp;
	int i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			if (strcmp(array[i], array[j]) < 0)
			{
				temp =(char *) malloc(sizeof(array[i]));
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
}
void display(char *list[], int n)
{
	int i;
	for(i = 0 ; i < n; i++)
	{
		printf("\n %s", list[i]);
	}
}

void main(void)
{
	char *list[100] = {
		"MONDAY", "TUESDAY", "WEDNESDAY", "FRIDAY", "SATARDAY"	};
	printf("\n Input list is as follows:");
	display(list, 5);
	bubble_sort(list, 5);
	printf("\n Sorted list is as follows:\n");
	display(list, 5);
}

