//Program to perform insertion and deletion in Doubly Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
struct node *lptr;
int info;
struct node *rptr;
}*L=NULL,*R=NULL;

void insert(int);
void delete(int);
void display();

void main()
{
int choice,n,m;

do
{
	printf("\n\nMenu:\n1. Insertion \n2. Deletion \n3. Display \n4. Exit\nChoice: ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: printf("\nEnter the element to insert: ");
			scanf("%d",&n);
			insert(n);
			printf("\nThe updated linked list is:\n");
			display();
			break;

		case 2: printf("\nEnter the element to delete: ");
			scanf("%d",&n);
			delete(n);
			printf("\nThe updated linked list is:\n");
			display();
			break;

		case 3: printf("\nThe linked list is:\n");
			display();
			break;

		case 4: printf("\n");
			break;

		default: printf("\nInvalid choice\n");
			 break;
	}
}while(choice!=4);
}

//Insertion to the left of an element
void insert(int x)
{
	int m;
	struct node *New,*save=L;
	
	New=(struct node *)malloc(sizeof(struct node));

	if(New==NULL)
	{
		printf("\nAvailability stack overflow");
		return;
	}
	
	New->info=x;
	
	if(R==NULL)
	{
		New->rptr=NULL;
		New->lptr=NULL;
		L=New;
		R=New;
		return;
	}
	
	printf("\nEnter the element before which to insert: ");
	scanf("%d",&m);

	if(L->info==m)
	{
		New->lptr=NULL;
		New->rptr=L;
		L->lptr=New;
		L=New;
		return;
	}

	while(save->rptr!=NULL && save->info!=m)
		save=save->rptr;
	
	if(save->info!=m)
		printf("\nNode not found\n");

	else
	{
		New->lptr=save->lptr;
		New->rptr=save;
		(save->lptr)->rptr=New;
		save->lptr=New;
	}
}

//Deletion
void delete(int x)
{
	if(R==NULL)
	{
		printf("\nUnderflow\n");
		return;
	}

	if(L==R && L->info==x)
	{
		free(L);
		L=NULL;
		R=NULL;
	}
	else if(L->info==x)
	{
		L=L->rptr;
		L->lptr=NULL;
	}
	else if(R->info==x)
	{
		R=R->lptr;
		R->rptr=NULL;
	}
	else
	{
		struct node *save=L;

		while(save->rptr!=NULL && save->info!=x)
			save=save->rptr;

		if(save->info!=x)
			printf("\nNode not found\n");
		else
		{
			(save->lptr)->rptr=save->rptr;
			(save->rptr)->lptr=save->lptr;
		}
	}
}

//Displaying the Linked List
void display()
{
	struct node *temp=L;

	printf("\n");
	while(temp!=NULL)
	{
		printf("%d <--> ",temp->info);
		temp=temp->rptr;
	}
	printf("NULL\n");
	
}
