//Write a program to represent polynomial using linked list.implement polynomial multiplication operation.

#include<stdio.h>
#include<stdlib.h>
struct node{
    float coefficient;
    int exponent;
    struct node *link;
};
struct node* insert_list(struct node* head,float coeff,int expo)
{
    struct node *temp;
    struct node *duphead = malloc(sizeof(struct node));
    duphead->coefficient = coeff;
    duphead->exponent = expo;
    duphead->link = NULL;
    
    if(head == NULL || expo>head->exponent)
    {
        duphead->link = head;
        head = duphead;
    }
    else
    {
        temp = head;
        while(temp->link!=NULL && temp->link->exponent >= expo)
        
            temp = temp->link;
        
        duphead->link = temp->link;
        temp->link = duphead;
    }
    return head;
}
struct node* create_list(struct node* head)
{
    int n,i;
    float coeff;
    int expo;
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the Coefficient %d: ",i+1);
        scanf("%f",&coeff);
        printf("\nEnter the Exponent %d:",i+1);
        scanf("%d",&expo);
        head = insert_list(head,coeff,expo);
    }
    return head;
}
struct node* mul_poly(struct node* head1,struct node* head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    if(head1 == NULL || head2 == NULL)
    {
        printf("Zero polynomial:");
        return 0;
    }
    while(ptr1!=NULL)
    {
        while(ptr2!=NULL)
        {
            head3 = insert_list(head3,ptr1->coefficient * ptr2->coefficient,ptr1->exponent+ptr2->exponent);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
        ptr2 = head2;
    }
    printf("\nMultiplication of two polynomials");
    display(head3);
}
void display(struct node* head3)
{
    if(head3 == NULL)
    {
        printf("No polynomial");
    }
    else
    {
        struct node *temp;
        temp = head3;
        while(temp!=NULL)
        {
            printf("(%.1fx^%d)",temp->coefficient,temp->exponent);
            temp = temp->link;
            if(temp!=NULL)
            {
                printf("+");
            }
            else
            printf("\n");
        }
    }
}
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf("Enter the polynomial 1:");
    head1 = create_list(head1);
    printf("\nEnter the polynomial 2");
    head2 = create_list(head2);
    mul_poly(head1,head2);
    
}
