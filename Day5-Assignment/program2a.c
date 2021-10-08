/*Write a program to add following initial elements to single Linked lists 4, 7, 9, 11, 15, 18.Then insert element '13' after the element '11'.
After insertion, delete element '15' from the lists.*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
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
        head->data = num;
        head->link = NULL;
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
            temp->link = NULL;
            ptr->link = temp;
            ptr = ptr->link;
            
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
        ptr = ptr->link;
    }
}
struct node* insertion(int num)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *temp1,*ptr;
    temp1 = head;
    if(temp == NULL)
    {
        printf("Memory is not allocated:");
    }
    else
    {
        int position = 4;
        temp->data = num;
        temp->link = NULL;
        
    while(position!=1)
    {
        temp1 = temp1->link;
        position--;
    }
    ptr = temp1->link;
    temp->link = ptr;
    temp1->link = temp;
    }
    return head;
    
}
struct node* deletion()
{
    
    struct node *temp1,*ptr,*temp;
    temp1 = head;
    if(temp1 == NULL)
    {
        printf("Elements are not present:");
    }
    else
    {
        int position = 5;
        
        while(position!=1)
        
        {
            
            temp1 = temp1->link;
            position--;
        }
        temp = temp1->link;
        temp1->link = temp->link;
        free(temp);
        temp = NULL;
        
        
        return head;
    }
}
int main()
{
    int num_node,num;
    printf("Enter the number of nodes:");
    scanf("%d",&num_node);
    head = create_list(num_node);
    display_list();
    printf("\nEnter the number to be inserted:\n");
    scanf("%d",&num);
    head = insertion(num);
    display_list();
    head = deletion();
    printf("\nAfter deletion the linked list is:\n");
    display_list();
}
