//Program to perform insertion and deletion operations in Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node *link;

}*first=NULL,*last=NULL;

void cInsFirst(int);
void cInsLast(int);
void cInsOrd(int);
void cDelete(int);
void display();

void main()
{
int choice,x;

	do
	{
		printf("\n\nMenu\n1. Insert at beginning\n2. Insert at end\n3. Insert in ordered list\n4. Delete an element\n5. To display the LL\n6. Exit\nChoice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("\n\nEnter the element to insert: ");
				scanf("%d",&x);
				cInsFirst(x);
				break;
	
			case 2: printf("\n\nEnter the element to insert: ");
				scanf("%d",&x);
				cInsLast(x);
				break;

			case 3: printf("\n\nEnter the element to insert: ");
				scanf("%d",&x);
				cInsOrd(x);
				break;

			case 4: printf("\n\nEnter the element to delete: ");
				scanf("%d",&x);
				cDelete(x);
				break;

			case 5: display(first);
				break;

			case 6: printf("\n");
				break;

			default: printf("\nInvalid Choice.\n");
		}	

	}while(choice!=6);
}

//Insert at beginning
void cInsFirst(int x)
{
	struct node *New;
	New=(struct node *)malloc(sizeof(struct node));

	if(New==NULL)
	{
		printf("\nAvailability stack underflow");
		return;
	}

	New->info=x;
	
	if(first==NULL)
	{
		New->link=New;
		first=New;
		last=New;
	}
	else
	{
		New->link=first;
		first=New;
		last->link=New;
	}
}

//Insert at end
void cInsLast(int x)
{
	struct node *New;
	New=(struct node *)malloc(sizeof(struct node));

	if(New==NULL)
	{
		printf("\nAvailability stack underflow");
		return;
	}

	New->info=x;
	if(first==NULL)
	{
		New->link=New;
		first=New;
		last=New;
	}
	else
	{
		New->link=first;
		last->link=New;
		last=New;
	}
}

//Insert in ascending order
void cInsOrd(int x)
{
	struct node *New;
	New=(struct node *)malloc(sizeof(struct node));

	if(New==NULL)
	{
		printf("\nAvailability stack underflow");
		return;
	}

	New->info=x;
	if(first==NULL)
	{
		New->link=New;
		first=New;
		last=New;
	}
	else if(x<=first->info)
	{
		New->link=first;
		first=New;
		last->link=New;
	}
	else
	{
		struct node *save=first;

		while(save!=last && (save->link)->info<x)
			save=save->link;
		
		New->link=save->link;
		save->link=New;

		if(save==last)
			last=New;
		
	}
}

//Deletion
void cDelete(int x)
{
	if(first==NULL)
	{
		printf("\nList is empty");
		return;
	}

	struct node *save=first;
	struct node *pred;

	while(save->info!=x && save!=last)
	{
		pred=save;
		save=save->link;
	}

	if(save->info!=x)
	{
		printf("\nNode not found");
		return;
	}

	if(save==first)
	{
		if(first==last)
		{
			first=NULL;
			last=NULL;
		}
		else
		{	first=first->link;
			last->link=first;
		}
	}
	else
	{
		pred->link=save->link;
		if(save==last)
			last=pred;
	}
	printf("\nDeletion successful\n");

	free(save);
}

//Display the Linked List
void display()
{
	struct node *save=first;
	
	printf("\nThe circular linked list is :\n\n");

	if(first!=NULL)	
	{
		while(save!=last)
		{
			printf("%d -> ",save->info);
			save=save->link;
		}
		printf("%d",save->info);
	}
	else
		printf("NULL\n");
}
