//Program to perform Insertion, Deletion and Copy Linked List operations
//and to display Linked List and count the number of nodes

#include<stdio.h>
#include<stdlib.h>

//Node Structure
struct node
{
int info;
struct node *link;
};

struct node *insert_first(struct node *,int);
struct node *insert_end(struct node *,int);
struct node *insord(struct node *,int);
void display(struct node *);
int count(struct node *);
struct node *delete_value(struct node *,int);
struct node *copy(struct node *);

void main()
{
	struct node *first=NULL;
	int choice,x,n;

	do
	{
		printf("\n\nMenu\n1. Insert at beginning\n2. Insert at end\n3. Insert in ordered list\n4. Delete an element\n5. Display the LL and Count nodes\n6. Copy the Linked List\n7. Exit\nChoice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("\n\nEnter the element to insert: ");
				scanf("%d",&x);
				first=insert_first(first,x);
				break;
	
			case 2: printf("\n\nEnter the element to insert: ");
				scanf("%d",&x);
				first=insert_end(first,x);
				break;

			case 3: printf("\n\nEnter the element to insert: ");
				scanf("%d",&x);
				first=insord(first,x);
				break;

			case 4: printf("\n\nEnter the value of element to delete: ");
				scanf("%d",&n);
				first=delete_value(first,n);
				break;

			case 5: display(first);
				int c=count(first);		//Count number of nodes
				printf("\nTotal nodes = %d\n",c);
				break;

			case 6: printf("\nOriginal LL: ");
				display(first);
				struct node *begin;
				begin=copy(first);
				printf("\n\nCopied LL: ");
				display(begin);
				break;

			case 7: printf("\n");
				break;

			default: printf("\nInvalid Choice.\n");
		}	

	}while(choice!=7);
	
}

//Insert at beginning
struct node *insert_first(struct node *f,int y)
{
	struct node *New;

	New=(struct node*)malloc(sizeof(struct node));
		
	if(New==NULL)
	{
		printf("\nAvailability Stack Underflow");
	}
	else
	{
		New->info = y;
		New->link = f;
		f = New;
	}
	return f;
}

//Insert at end
struct node *insert_end(struct node *f,int y)
{
	struct node *New;

	New=(struct node*)malloc(sizeof(struct node));
		
	if(New==NULL)
	{
		printf("\nAvailability Stack Underflow");
	}
	else
	{
		New->info = y;
		New->link = NULL;
		
		if(f==NULL)
			return New;
		else
		{
			struct node *save;
			save=f;
			while(save->link!=NULL)
			{
				save=save->link;
			}
			save->link=New;
		}
	}
	return f;
}

//Insert in ordered list
struct node *insord(struct node *f,int y)
{
	struct node *New;

	New=(struct node*)malloc(sizeof(struct node));
		
	if(New==NULL)
	{
		printf("\nAvailability Stack Underflow");
	}
	else
	{
		New->info = y;
		if(f==NULL)
		{
			New->link=NULL;
			return New;
		}
		else if(y<=f->info)
		{
			New->link=f;
			return New;
		}
		else
		{
			struct node *save=f;
			while(save->link!=NULL && (save->link)->info<y)
				save=save->link;
			
			New->link=save->link;
			save->link=New;
			
		}
	}
	return f;
}

//Displaying a Linked List
void display(struct node *first)
{
	//printing the list
	printf("\n\nThe Linked List is:\n");
	struct node *temp=first;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->info);
		temp=temp->link;
	}
	printf("NULL\n\n");
}

//Counting number of nodes
int count(struct node *first)
{
	int c=0;
	struct node *temp=first;
	while(temp!=NULL)
	{
		c++;
		temp=temp->link;
	}
	return c;
}

//Deletion with value
struct node *delete_value(struct node *f,int x)
{
	if(f==NULL)
	{
		printf("\nUnderflow!\n");
		return f;
	}
	else
	{
		struct node *save=f,*pred;
		
		while(save->info!=x && save->link!=NULL)
		{
			pred=save;
			save=save->link;
		}
		
		if(save->info!=x)
		{
			printf("\nNode not found!");
			return f;
		}
		else
		{
			if(save==f)
			{
				f=f->link;
			}
			else
			{
				pred->link=save->link;
				free(save);
			}
			printf("\nDeletion Successful\n");
			return f;
		}
	}
}

//Copying a Linked List
struct node *copy(struct node *f)
{
	struct node *begin;
	if(f==NULL)
		return NULL;
	else
	{
		struct node *New;

		New=(struct node*)malloc(sizeof(struct node));
			
		if(New==NULL)
		{
			printf("\nAvailability Stack Underflow");
		}
		else
		{
			New->info=f->info;
			begin=New;
			
			struct node *save,*pred;
			save=f;

			while(save->link!=NULL)
			{
				pred=New;
				save=save->link;

				New=(struct node*)malloc(sizeof(struct node));
			
				if(New==NULL)
				{
					printf("\nAvailability Stack Underflow");
				}
				else
				{
					New->info=save->info;
					pred->link=New;
				}
			}
			New->link=NULL;
			return begin;
		}
	}
	return begin;
}

