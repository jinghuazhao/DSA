/* SEARCH A NODE INTO A SIMPLE LINKED LIST WHEN INFORMATION IS KNOWN */
/* LINK_HEA.C */

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
void insertion(struct link *node);
void insertion_last(struct link *node);
void Delete_node( struct link *);

/* Function create a linked list */

void create_list(struct link *node)
{
        char ch;
        start.next = NULL;  /* Empty list */
        node = &start;      /* Point to the start of the list */

        /* Create a header node that is simply first node in the list */

        node->next = (struct link* ) malloc(sizeof(struct link));

        /* Creattion of linked list start from here */

        number = 0;
        printf("\n Input choice n for break: ");
        ch = getchar();
        while(ch != 'n')
        {
                node->next = (struct link* ) malloc(sizeof(struct link));
                node = node->next;
                printf("\n Input the node: %d: ", number+1);
                scanf("%d", &node->info);
                node->next = NULL;
                fflush(stdin);
                printf("\n Input choice n for break: ");
                ch = getchar();
                number++;
        }
        printf("\n Total nodes = %d",  number);

        /* Create header node */

        node = &start;      /* Point to the start of the list */
        node->info = number; /* Copy number of nodes in list, into the header node */
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
                printf("\n Information does not found in the list: ", search_node);
        }
}

/* Display the list */

void display(struct link *node)
{
        int count;
        node = &start;  /*start.next; */
        count = node->info;
        node = node->next;
        while (count)
        { 
                printf("\n 0x%x", node);
                printf(" %d",  node->info);
                node = node->next;
                count --;
        }
}

/* Inserting a node */

void insertion(struct link *node)
{
        int node_number = 0;
        int insert_node;
        node = start.next;
        previous = &start;

        printf("\n Input node number you want to insert:");
        printf("\n Value should be less are equalto the");
        printf("\n number of nodes in the list: ");
        scanf("%d", &insert_node);

        while(node)
        {
                if((node_number+1) == insert_node)
                {
                        new1 = (struct link* ) malloc(sizeof(struct link));
                        new1->next = node ;
                        previous->next = new1;
                        printf("\n Input the node value: ");
                        scanf("%d", &new1->info);
                        node = &start;
                        node->info = node->info+1;
                        break ;
                }
                else
                {
                        node = node->next;
                        previous= previous->next;
                }
                node_number ++;
        }
}




/* Function main */
void main()
{
        struct link *node = (struct link *) malloc(sizeof(struct link));

        create_list(node);
        display(node);
        search(node);
        insertion(node);
        display(node);
}
