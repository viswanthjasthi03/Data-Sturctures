//Write the program which uses recursive function to find the number of elements in the given binary search tree

#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newNode(int data)
{
struct node* node = (struct node*) malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;
	
return(node);
}


int size(struct node* node)
{
if (node==NULL)
	return 0;
else	
	return(size(node->left) + 1 + size(node->right));
}

	
int main()
{
struct node *root = newNode(1);
root->left	 = newNode(2);
root->right	 = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
printf("Number of  elements in the tree is : %d\n", size(root));
getchar();
return 0;
}
