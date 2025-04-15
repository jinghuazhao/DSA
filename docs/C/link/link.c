/* LINK.C */
/* This program segment defines linked list having a character type node */

# include<stdio.h>
# include<malloc.h>
        struct list
             {
              char data ;
              struct list *next ;
	     } ;

     typedef  struct list Linked;

     void main()
     {
	      Linked *start, node1, node2 , node3 , node4;
	      int i ;
	      start = (struct list *) malloc(sizeof(Linked));
	      start = &node1;

	      node1.data = 'A' ;
	      node1.next = &node2;

	      node2.data = 'B' ;
	      node2.next = &node3;

	      node3.data = 'C' ;
	      node3.next = &node4;
	      node4.data = 'D' ;

	for( i = 0 ; i < 4 ; i++ )
	{
		printf("\n %c", start->data);
		start = start->next ;
		printf("\nPress a key");
		getchar() ;
	 }
     }

