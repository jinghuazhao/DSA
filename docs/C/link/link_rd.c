/* SEARCH A NODE INTO A SIMPLE LINKED LIST WITH INFORMATION IS KNOWN */
/* LINK_RD.C */

# include <stdio.h>
# include <malloc.h>

struct link
{
	int info;
	struct link *next;
};

int i;
int number;
struct link start, *previous, *new1;

void search(struct link *);
void create_list(struct link *);
void display(struct link *);

/* Function create a linked list */

void create_list(struct link *node)
{
	char ch;
	start.next = NULL;  /* Empty list */

	node = &start;      /* Point to the start of the list */
	i = 0;
	printf("\n Input choice n for break: ");
	ch = getchar();
	while(ch != 'n')
	{
		node->next = (struct link* ) malloc(sizeof(struct link));
		node = node->next;
		printf("\n Input the node: %d: ", i+1);
		scanf("%d", &node->info);
		node->next = NULL;
		fflush(stdin);
		printf("\n Input choice n for break: ");
		ch = getchar();
		i++;
	}
	printf("\n Total nodes = %d", i);
}

/* Display the list */

void display(struct link *node)
{
	node = start.next;
	while (node)
	{
		printf("\n 0x%x", node);
		printf(" %d", node->info);
		node = node->next;
	}
}
/* Function main */

void main()
{
	struct link *node = (struct link *) malloc(sizeof(struct link));
	create_list(node);
	printf("\n List in which we have to search\n");
	display(node);
	search (node);
	printf("\n List after removal of duplicate elements from the list\n	    ");
	display(node);
}
                                                                              
/* Searching a value */                                                       
                                                                              
void search(struct link *node)                                                
{                                                                             
        int node_number = 1;                                                  
        int search_node;                                                      
        int flag = 0;                                                         
        node = &start;                                                        
        previous = &start;                                                    
                                                                              
        printf("\n Input information of a node we want to search:");          
        scanf("%d", &search_node);                                            
        if (node == NULL)                                                     
        {                                                                     
                printf("\n List is empty");                                   
        }                                                                     
                                                                              
        /*  By pass header node*/                                             
                                                                              
        node = node->next;                                                    
        previous= previous->next;                                             
                                                                              
        while(node)                                                           
        {                                                                     
                if( search_node == node->info )                               
                {                                                             
                        printf("\n Search is successful");                    
                        printf("\n Information to which we want search is: %d", search_node);
                        printf("\n Position from beginning of the list: %d", node_number);
                        node = node->next;                                    
                        previous= previous->next;                             
                        flag = 1;                                             
                }                                                             
                else                                                          
                {                                                             
                        node = node->next;                                    
                        previous= previous->next;                             
                }                                                             
                node_number ++;                                               
        }                                                                     
        if(!flag)                                                             
        {                                                                     
                printf("\n Search is unsuccessful");                          
                printf("\n Information does not found in the list: %i", search_node);
        }                                                                     
}                                                                             
                                                                              
