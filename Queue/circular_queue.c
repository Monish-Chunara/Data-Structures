//Program to perform enque and deque in a circular queue

#include<stdio.h>

void cqinsert(int [],int *, int *, int, int);
int cqdelete(int [],int *, int *, int);
void cqstatus(int [],int *,int *,int);

void main()
{
int n=5;
int Q[n];
int F=0,R=0;

int y;
int choice;

do
{
printf("\n\nMenu\n1.Insertion\n2.Deletion\n3.Print Queue\n4.Exit\nChoice: ");
scanf("%d",&choice);

switch(choice)
{
	case 1: printf("\nEnter the element to enque: ");
		scanf("%d",&y);
		cqinsert(Q,&F,&R,n,y);
		break;

	case 2: y=cqdelete(Q,&F,&R,n);
		if(y!=0)		
			printf("\nElement removed = %d",y);
		break;

	case 3: cqstatus(Q,&F,&R,n);
		break;

	case 4: printf("\n");
		break;

	default:printf("\nInvalid choice.\n");
}

}while(choice!=4);
}

void cqinsert(int q[],int *f, int *r, int n, int x)
{
	int temp=*r;
	
	if(*r==n)
		*r=1;
	else
		*r=*r+1;

	if(*r==*f)
	{
		printf("\nQueue Overflow\n");
		*r=temp;
	}
	else
	{
		q[*r]=x;

		if(*f==0)
			*f=1;
	}

}

int cqdelete(int q[],int *f, int *r, int n)
{
	int temp;
	
	if(*f==0)
		printf("\nQueue Underflow\n");
	else
	{
		temp=q[*f];

		if(*f==*r)
		{
			*f=0;
			*r=0;
		}
		else if(*f==n)
		{
			*f=1;
		}
		else
		{
			*f=*f+1;
		}

		return temp;
	}

	return 0;
}


void cqstatus(int q[],int *f,int *r,int n)
{
	printf("\nElements in the Queue:\n");
	
	if(*f!=0)
	{
		if(*r>=*f)
		{
			for(int i=1;i<=n;i++)
			{
				if(i>=*f && i<=*r)
					printf("%d,",q[i]);
				else
					printf("_,");
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(i>=*f || i<=*r)
					printf("%d,",q[i]);
				else
					printf("_,");
			}
		}
	}
}
