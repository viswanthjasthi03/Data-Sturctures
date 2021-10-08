/*Write a program to add following initial elements to double Linked lists 4, 7, 9, 11, 15, 18.Then insert element '13' after the element '11'.
After insertion, delete element '15' from the lists.*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev_link;
    struct node *next_link;
}*head;
struct node* create_list(int n)
{
    head = malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Memory is not allocated for the HEAD:");
    }
    else
    {
        struct node *ptr = malloc(sizeof(struct node));
        int num,i;
        printf("Enter the Data of 1 node:");
        scanf("%d",&num);
        head->prev_link = NULL;
        head->data = num;
        head->next_link = NULL;
        ptr = head;
        
        for(i=1;i<n;i++)
        {
            struct node *temp = malloc(sizeof(struct node));
            if(temp == NULL)
            {
                printf("Menory is not allocated for the TEMP:");
            }
            printf("Enter the data of %d node:",i+1);
            scanf("%d",&num);
            temp->data = num;
            temp->next_link = NULL;
            temp->prev_link = ptr;
            ptr->next_link = temp;
            
            ptr = ptr->next_link;
            
        }
    }
    return head;
}
struct node* display_list()
{
    struct node *ptr;
    if(ptr == NULL)
    {
        printf("Linked list is Empty:");
    }
    ptr = head;
    while (ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next_link;
    }
}
struct node* inserting_node(struct node* head)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr,*temp1;
    
    temp1 = head;
    if(temp == NULL)
    {
        printf("Memory is not allocated for the temp:");
    }
    else
    {
    int num;
    int position = 4;
    printf("\nEnter the number to insert:");
    scanf("%d",&num);
    temp->prev_link = NULL;
    temp->data = num;
    temp->next_link = NULL;
    
    while(position!=1)
    {
        
        temp1 = temp1->next_link;
        position--;
    }
    ptr = temp1->next_link;
    temp1->next_link = temp;
    ptr->prev_link = temp;
    temp->next_link = ptr;
    temp->prev_link = temp1;
    }
    return head;
}
struct node* deletion_node(struct node* head)
{
    int position = 5;
    struct node *temp ;
    struct node *temp1,*ptr;
    temp1 = head;
    while(position!=1)
    {
        temp1 = temp1->next_link;
        position--;
    }
    ptr = temp1->next_link->next_link;
    temp = ptr->prev_link;
    temp1->next_link = ptr;
    ptr->prev_link = temp;
    
    return head;
    
}
int main()
{
    int num_node,end;
    printf("Enter the number of nodes:");
    scanf("%d",&num_node);
    head = create_list(num_node);
    printf("\nDisplaying the linked list:");
    display_list();
    head = inserting_node(head);
    printf("Displaying the insertion list:");
    display_list();
    head = deletion_node(head);
    printf("\nDisplaying the deletion List:");
    display_list();
}
