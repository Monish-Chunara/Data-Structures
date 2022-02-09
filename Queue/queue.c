//Program to perform Insertion and Deletion in Queue

#include<stdio.h>

void enque(int [],int *,int *,int,int);
int deque(int [],int *,int *);

void main()
{
int n=5;
int Q[n];
int F=0,R=0;

int y;
int choice;

do
{
printf("\n\nMenu\n1.Enque\n2.Deque\n3.Check Queue\n4.Exit\nChoice: ");
scanf("%d",&choice);

switch(choice)
{
	case 1: printf("\nEnter the element to enque: ");
		scanf("%d",&y);
		enque(Q,&F,&R,n,y);
		break;

	case 2: y=deque(Q,&F,&R);
		if(y!=0)		
			printf("\nElement removed = %d",y);
		break;

	case 3: printf("\nElements in the Queue:\n");
		if(F!=0)
		{
			for(int i=F;i<=R;i++)
			{
				printf("%d,",Q[i]);
			}
		}
		break;

	case 4: printf("\n");
		break;

	default:printf("\nInvalid choice.\n");
}

}while(choice!=4);

}

//Enque function definition
void enque(int q[],int *f,int *r,int n,int x)
{
	if(*r>=n)
	{
		printf("\nQueue Overflow!");
	}
	else
	{	
		*r=*r+1;
		q[*r]=x;
		
		if(*f==0)
			*f=*f+1;
	}
}

//Deque function definition
int deque(int q[],int *f,int *r)
{
	if(*f==0)
	{
		printf("\nQueue Underflow!");
		return 0;
	}
	else
	{
		int x=q[*f];
		if(*f==*r)
		{
			*f=0;
			*r=0;
		}
		else
			*f=*f+1;
		return x;
	}
}
