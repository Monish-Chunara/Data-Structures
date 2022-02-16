//Program to perform insertion in Circular Linked List with Header Node
//while also using first and last pointers

#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node *link;

}*head,*first,*last;

void chead_InsFirst(int);
void chead_InsLast(int);
struct node *findAddress(int);
void chead_InsAftr(struct node *,int);
void display();

void main()
{
int choice,x,y;

//Initializing the header node
struct node *New;
New=(struct node *)malloc(sizeof(struct node));
New->link=New;

head=New;

	do
	{
		printf("\n\nMenu\n1. Insert at beginning\n2. Insert at end\n3. Insert after a node\n4. To display the LL\n5. Exit\nChoice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("\n\nEnter the element to insert: ");
				scanf("%d",&x);
				chead_InsFirst(x);
				break;
	
			case 2: printf("\n\nEnter the element to insert: ");
				scanf("%d",&x);
				chead_InsLast(x);
				break;

			case 3: printf("\n\nEnter the element to insert: ");
				scanf("%d",&y);

				printf("\n\nEnter the element after which %d is to be inserted: ",y);
				scanf("%d",&x);
				struct node *temp = findAddress(x);
				if(temp!=0)
					chead_InsAftr(temp,y);
				else
					printf("\nNode not found\n");

				break;

			case 4: display();
				break;

			case 5: printf("\n");
				break;

			default: printf("\nInvalid Choice.\n");
		}	

	}while(choice!=5);
}

//Insert at beginning
void chead_InsFirst(int x)
{
	struct node *New;
	New=(struct node *)malloc(sizeof(struct node));

	if(New==NULL)
	{
		printf("\nAvailability stack underflow");
		return;
	}

	New->info=x;
	
	New->link=head->link;

	if(head->link==head)
		last=New;
	head->link=New;
	first=New;
}

//Insertion at end
void chead_InsLast(int x)
{
	struct node *New;
	New=(struct node *)malloc(sizeof(struct node));

	if(New==NULL)
	{
		printf("\nAvailability stack underflow");
		return;
	}

	New->info=x;
	New->link=head;

	last->link=New;
	last=New;
}

//Function to find the address of a node (to be used for chead_InsAftr)
struct node *findAddress(int x)
{
	struct node *save;
	save=head->link;

	while(save->link!=head && save->info!=x)
		save=save->link;

	if(save->info==x)
		return save;
	else
		return 0;
}

//Insert after a particular address
void chead_InsAftr(struct node *p,int y)
{
	struct node *New;
	New=(struct node *)malloc(sizeof(struct node));

	if(New==NULL)
	{
		printf("\nAvailability stack underflow");
		return;
	}

	New->info=y;
	
	New->link=p->link;
	p->link=New;

	if(p==last)
		last=New;
}


//Displaying the Linked List
void display()
{
	struct node *save=head->link;
	
	printf("\nThe circular linked list with header node is :\n\n");

	if(save!=head)	
	{
		while(save->link!=head)
		{
			printf("%d -> ",save->info);
			save=save->link;
		}
		printf("%d",save->info);
	}
	else
		printf("NULL\n");
}
