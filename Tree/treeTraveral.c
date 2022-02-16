//Program to print Preorder, Inorder and Postorder traversal of a tree

#include<stdio.h>
#include<stdlib.h>

struct node
{
struct node *lptr;
char data;
struct node *rptr;
};

void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);

void main()
{
	struct node *root;

	struct node *N1,*N2,*N3,*N4,*N5,*N6,*N7;
	
	N1=(struct node*)malloc(sizeof(struct node));
	N2=(struct node*)malloc(sizeof(struct node));
	N3=(struct node*)malloc(sizeof(struct node));
	N4=(struct node*)malloc(sizeof(struct node));
	N5=(struct node*)malloc(sizeof(struct node));
	N6=(struct node*)malloc(sizeof(struct node));
	N7=(struct node*)malloc(sizeof(struct node));

	root=N1;
	N1->data='A';
	N1->lptr=N2;
	N1->rptr=N3;

	N2->data='B';
	N2->lptr=N4;
	N2->rptr=NULL;

	N3->data='D';
	N3->lptr=N5;
	N3->rptr=N6;

	N4->data='C';
	N4->lptr=NULL;
	N4->rptr=NULL;

	N5->data='E';
	N5->lptr=NULL;
	N5->rptr=N7;

	N6->data='G';
	N6->lptr=NULL;
	N6->rptr=NULL;

	N7->data='F';
	N7->lptr=NULL;
	N7->rptr=NULL;

	printf("\nPreorder Traversal: ");
	preorder(root);
	printf("\n");

	printf("\nInorder Traversal: ");
	inorder(root);
	printf("\n");

	printf("\nPostorder Traversal: ");
	postorder(root);
	printf("\n\n");
}

void preorder(struct node *r)
{
	if(r==NULL)
		printf("Tree is Empty!");
	else
	{
		printf("%c ",r->data);
	
		if(r->lptr!=NULL)
			preorder(r->lptr);
		
		if(r->rptr!=NULL)
			preorder(r->rptr);
	}
}

void inorder(struct node *r)
{
	if(r==NULL)
		printf("Tree is Empty!");
	else
	{
		if(r->lptr!=NULL)
			inorder(r->lptr);

		printf("%c ",r->data);
		
		if(r->rptr!=NULL)
			inorder(r->rptr);
	}
}

void postorder(struct node *r)
{
	if(r==NULL)
		printf("Tree is Empty!");
	else
	{
	
		if(r->lptr!=NULL)
			postorder(r->lptr);
		
		if(r->rptr!=NULL)
			postorder(r->rptr);

		printf("%c ",r->data);
	}
}
