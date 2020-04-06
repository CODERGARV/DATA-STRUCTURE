// BINARY TREE TRAVERSAL PROGRAMME

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

// CREATING NODE FOR TREE
struct node;
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

//FUNCTION TO GET A NEW NODE AT THE TIME OF INSERTION
struct node* getnewnode(int data) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

//FUNCTION TO INSERT NODE IN TREE
struct node* insert(struct node* root,int data) {
	if(root == NULL) { // empty tree
		root = getnewnode(data);
	}
	else if(data <= root->data)
    {
       root->left = insert(root->left,data);
    }
    else
    {
        root->right = insert(root->right,data);
    }
	return root;
}

// FUNCTION FOR PREORDER TRAVERSAL
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

// FUNCTION FOR POSTORDER TRAVERSAL
void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}

// FUNCTION FOR INORDER TRAVERSAL
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}

int main()
{
    while(1)
    {   char x;
        int n;
        printf("do you want to entere a number in bst:- y or n = ");
        fflush(stdin);
        scanf("%c",&x);
        fflush(stdin);
        if(x == 'y')
        {
            printf("enter number you want to enter in bst:-");
            scanf("%d",&n);
            root = insert(root,n);
            printf("PREORDER TRAVERSING:-");
            preorder(root);
            printf(",\n");
            printf("POSTORDER TRAVERSING:-");
            postorder(root);
            printf(",\n");
            printf("INORDER TRAVERSING:-");
            inorder(root);
            printf(",\n");
        }
        else
        {
            break;
        }
    }
}