/* SORTING A LINKED LIST IN ASCENDING ORDER */
/* LINKSORT.C */

 #include <stdio.h>
 #include <malloc.h>

  struct link
    {
      int data;
    struct  link *next;
    };

   int i;
   int number ;
struct   link *start, *node, *previous, *new1, *counter;

   void doubly_link_sort()
   {
   printf("\n Input the number of node we need to create: ");
scanf("%d", &number );

   start->next = NULL;  /* Empty list */

   node = start;      /* Point to the start of the list */

  /* CREATE A LINKED LIST */

   for (i = 0; i < number ; i++)
     {
       node->next = (struct link* ) malloc(sizeof(struct link));
       node = node->next;
     printf("\n Input the first node: %d: ", i+1);
scanf("%d", &node->data);
       node->next = NULL;
     }

 /* END OF CREATION   */

  /* SORTING THE LINK LIST START FROM HERE */

      new1 = start;
      for(; new1->next != NULL; new1 = new1->next)
	   {
	     for(counter = new1->next; counter != NULL; counter = counter->next)
	       {
		 if(new1->data > counter->data)
		   {
		     int temp = new1->data;
		     new1->data = counter->data;
		     counter->data = temp;
		    }
		 }
	      }

/* END OF SORTING */

  /* Display the list */

    node = start->next;
    printf("\n After sorting the list is as follows:\n");
    while (node)
      {
	printf(" %d", node->data);
	node = node->next;
      }
   }

   /* Function main */

    void main()
	 {
   doubly_link_sort();
	 }


