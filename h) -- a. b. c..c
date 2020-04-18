//programme made by GARV SINGHAL

//programme for inorder traversing and height of tree

#include <stdio.h>

//creation node

  struct node
    {
        int data;
        struct node *left;
        struct node *right;
    }*root=NULL;

//insert function 

void insert(int n)
{
 struct node *t=root;
 struct node *q,*r;
 if(root==NULL)
 {
     q=(struct node *)malloc(sizeof(struct node));
     q->data=n;
     q->left=q->right=NULL ;
     root=q;
     return;
 }
 while(t!=NULL)
 {
     r=t;
     if(n<t->data)
        t=t->left;
   else  if(n>t->data)
        t=t->right ;
     else
        return ;
 }
 q=(struct node *)malloc(sizeof(struct node));
     q->data=n;
     q->left=q->right=NULL ;
     if(n<r->data)
        r->left=q;
     else
        r->right=q;
}

//INORDER TRAVERSING

void inorder(struct node *t)
{
    if(t)
    {
    inorder(t->left);

    printf("%d \n",t->data);
    inorder(t->right);
    }
}

//HEIGHT OF TREE

int heightOfTree(struct node *t)
{
    int p,r;
    if(t==NULL)
     return 0;
     if(!t->left && !t->right)
        return 0;
    else
    {
     p=heightOfTree(t->left);
     r=heightOfTree(t->right);
    return (1+(p>r?p:r));
    }
}

//MAIN FUNCTION

int main()
{
    int m,n,numb;
printf("Enter the no of elements that you want to insert in binary search tree \n");
scanf("%d",&n);
printf("Enter the integer datas to insert in binary  search tree \n");
for (int i = 0; i < n;i++)
	{
		scanf("%d",&numb);
		insert(numb);
	}
printf("Binary search tree of integer input are created \n");
printf("inorder transversal of tree are: \n ");
inorder(root);
m=heightOfTree(root);
printf("height of tree roted at top are %d",m);
return 0;
}
