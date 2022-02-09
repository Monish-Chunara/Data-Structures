//Program to perform enque and deque in a circular queue

#include<stdio.h>
#include "queueop.h"

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
