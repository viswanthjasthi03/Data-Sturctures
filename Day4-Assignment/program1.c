//Write a C program to reverse a single linked list.

#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *link;
};
int main()
{
struct node *head=(struct node *) malloc(sizeof(struct node));
head->data=56;
head->link=NULL;
struct node *ptr1=(struct node *) malloc(sizeof(struct node));
ptr1->data=25;
ptr1->link=NULL;
head->link=ptr1;
struct node *ptr2=(struct node *) malloc(sizeof(struct node));
ptr2->data=50;
ptr2->link=NULL;
ptr1->link=ptr2;
struct node *ptr3=(struct node *) malloc(sizeof(struct node));
ptr3->data=100;
ptr3->link=NULL;
printf("Before Reversing the list=%d\t%d\t%d\t%d\n",head->data,ptr1->data,ptr2->data,ptr3->data);
struct node *temp=(struct node *) malloc(sizeof(struct node));
temp->data=ptr3->data;
ptr3->data=head->data;
head->data=temp->data;
temp->data=ptr2->data;
ptr2->data=ptr1->data;
ptr1->data=temp->data;
printf("After Reversing the list=%d\t%d\t%d\t%d\n",head->data,ptr1->data,ptr2->data,ptr3->data);
free(temp);
free(head);
free(ptr1);
free(ptr2);
free(ptr3);
}
