//Program to perform Insertion and Deletion in Queue

#include<stdio.h>
#include "queueop.h"

void main()
{
int n=5;
int Q[n+1];
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

	case 3: status(Q,&F,&R,n);
		break;

	case 4: printf("\n");
		break;

	default:printf("\nInvalid choice.\n");
}

}while(choice!=4);

}
