//Write a program to know whether a linked list is circular or not.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * link;
}*head;
 

void ClListcreation(int n)
{
    int i, num;
    struct node *preptr, *newnode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        head->data = num;
        head->link = NULL;
        preptr = head;
        for(i=2; i<=n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf(" Input data for node %d : ", i);
            scanf("%d", &num);
            newnode->data = num;
            newnode->link = NULL;	// next address of new node set as NULL
            preptr->link = newnode;	// previous node is linking with new node
            preptr = newnode;   		// previous node is advanced
        }
        preptr->link = head; 		//last node is linking with first node
    }
}


struct node* circular_or_not(struct node* head)
{
    struct node *ptr;
    ptr = head;
    while(ptr->link != head)
    {
        ptr = ptr->link;
    }
    if(ptr->link == head)
    {
        printf("CIRCULAR");
    }
    else
    {
        printf("NOT CIRCULAR:");
    }
}
int main()
{
    int n;
    head = NULL;	   	
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
 
    ClListcreation(n); 
   
    circular_or_not(head);
    return 0;
}
