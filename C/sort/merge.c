/* MERGE SORT */
/* merge.c */

# include<stdio.h> 
# include<stdlib.h>

void merge_sort(float *, int , int , int );
void merge_pass(float *, int , int );

/* Definition of the function */

void merge_sort(float l[], int top, int size, int bottom)
{
	float temp[1000];
	int f = top;
	int s = size +1 ;
	int t = top ;
	int upper;
	while(( f <= size)&&(s <=bottom))
	{  
		if(l[f] <= l[s])
		{
			temp[t] = l[f] ;
			f ++;
		}

		else
		{
			temp[t] = l[s] ;
			s ++;
		}

		t ++;
	}

	if(f <=size)
	{
		for(f = f ; f<=size; f++)
		{
			temp[t] = l[f];
			t++;
		}
	}

	else
	{
		for(s = s ; s<= bottom ; s++)
		{
			temp[t]=l[s];
			t++;
		}

	}

	for(upper = top; upper <= bottom ; upper++)
	{
		l[upper]=temp[upper];
	}

}

/* Definition of the function */

void merge_pass( float append[], int m, int n )
{
	if( m!= n)
	{
		int mid = (m+n)/2;
		merge_pass( append, m, mid );

		merge_pass( append, mid+1, n );
		merge_sort( append, m, mid, n );
	}
}

/* main function */

void main()
{
	float list[1000];
	int i, n = 30;
	printf("\n Size of the list: %d", n);

	for(i = 0 ; i < n ; i++)
	{
		list[i] = (float) (rand() %100);
	}

	printf("\n Entered list as follows:\n");
	for( i = 0 ; i<n ; i++)
		printf(" %d ", (int) list[i]);

	i = 0 ;

	merge_pass(list, i, n-1);

	printf("\n Merge sorted list is as follows:\n");
	for( i = 0 ; i<n ; i++)
		printf(" %d", (int) list[i]);
}





