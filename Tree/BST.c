//Program to perform Insertion, Search and Deletion operations in BST
#include<stdio.h>
#include<stdlib.h>

struct node
{
struct node *lptr;
int data;
struct node *rptr;
};

struct node* insert(struct node *, int);
void search(struct node*,int);
void inorder(struct node*);
struct node *delete(struct node *,int);
struct node *findSuccessor(struct node *);

void main()
{
struct node *root;
root=NULL;

int n,m,choice;

do
{
	printf("\n\nMenu\n1. Insert\n2. Search\n3. Delete\n4. Display Inorder Traversal\n5. Exit\nChoice: ");
	scanf("%d",&choice);
	
	switch(choice)
	{
	case 1:	printf("\nEnter the element to insert: ");
		scanf("%d",&m);
		root=insert(root,m);
		break;

	case 2: printf("Enter the element to search: ");
		scanf("%d",&m);
		search(root,m);
		break;
	case 3:	printf("Enter the element to delete: ");
		scanf("%d",&m);
		root=delete(root,m);
		break;

	case 4:	printf("\n\nThe inorder traversal is : ");
		inorder(root);
		printf("\n\n");
		break;

	case 5: printf("\n");
		break;

	default: printf("\nInvalid Choice\n");
		break;
	}
}while(choice!=5);
}

//Insertion
struct node* insert(struct node *r, int x)
{
	struct node *New;
	New=(struct node *)malloc(sizeof(struct node));

	New->data=x;
	New->lptr=NULL;
	New->rptr=NULL;

	if(r==NULL)
		return New;

	struct node *save=r,*parent;

	while(save!=NULL)
	{
		if(x>save->data)
		{
			parent=save;
			save=save->rptr;
		}
		else
		{
			parent=save;
			save=save->lptr;
		}
	}

	if(x>parent->data)
		parent->rptr=New;
	else if(x<parent->data)
		parent->lptr=New;
	else
		printf("\nIdentical entries not allowed in BST.\n");

	return r;
}

//Searching
void search(struct node* r,int x)
{
	struct node *save=r;
	
	while(save!=NULL && save->data!=x)
	{
		if(x>save->data)
			save=save->rptr;
		else
			save=save->lptr;
	}
	
	if(save!=NULL)
		printf("\n%d exists in the BST\n",x);
	else
		printf("\n%d does not exist in the BST\n",x);
}

//Deletion
struct node *delete(struct node *r, int x)
{
	struct node *save,*parent;
	
	save=r;
	
	while(save!=NULL && save->data!=x)
	{
		parent=save;
		if(x<save->data)
			save=save->lptr;
		else
			save=save->rptr;
	}

	if(save==NULL)
	{
		printf("\n%d does not exist in the BST\n",x);
		return r;
	}
	
	//Case 1 - Leaf Node
	if(save->lptr==NULL && save->rptr==NULL)
	{
		//if the node to be deleted is root node
		if(save==r)
		{
			printf("\nDeletion successful\n");
			return NULL;		//tree becomes empty
		}

		if(save==parent->lptr)
			parent->lptr=NULL;
		else
			parent->rptr=NULL;
		free(save);
		printf("\nDeletion successful\n");
	}

	//case 2 - Non-terminal node with one subtree
	else if(save->lptr==NULL)
	{
		//if node to be deleted is root node
		if(save==r)
		{
			printf("\nDeletion successful\n");
			return save->rptr;
		}
	
		if(save==parent->lptr)
			parent->lptr=save->rptr;
		else
			parent->rptr=save->rptr;
		free(save);
		printf("\nDeletion successful\n");
	}

	else if(save->rptr==NULL)
	{
		//if node to be deleted is root node
		if(save==r)
		{	
			printf("\nDeletion successful\n");
			return save->lptr;
		}

		if(save==parent->lptr)
			parent->lptr=save->lptr;
		else
			parent->rptr=save->lptr;
		free(save);
		printf("\nDeletion successful\n");
	}
	
	//Case 3 - Non-terminal node with two subtrees
	else
	{
		struct node *New=findSuccessor(save);
		int n=New->data;
		delete(r,n);
		save->data=n;
	}
	return r;
}

//printing inorder traversal
void inorder(struct node *r)
{
	if(r==NULL)
		printf("Tree is Empty!");
	else
	{
		if(r->lptr!=NULL)
			inorder(r->lptr);

		printf("%d ",r->data);
		
		if(r->rptr!=NULL)
			inorder(r->rptr);
	}
}

//Find inorder successor node for case 3 of deletion
struct node *findSuccessor(struct node *save)
{
	save=save->rptr;
	
	while(save->lptr!=NULL)
		save=save->lptr;
	
	return save;
}
