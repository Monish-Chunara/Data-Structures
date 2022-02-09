//Program to perform Insertion and Deletion in Queue

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
printf("\n\nMenu\n1.Insertion from rear\n2.Insertion from front\n3.Deletion from front\n4.Deletion from rear\n5.Print Queue\n6.Exit\nChoice: ");
scanf("%d",&choice);

switch(choice)
{
	case 1: printf("\nEnter the element to insert: ");
		scanf("%d",&y);
		enque(Q,&F,&R,n,y);
		break;

	case 2: printf("\nEnter the element to insert: ");
		scanf("%d",&y);
		dqinsert_front(Q,&F,&R,y);
		break;

	case 3: y=deque(Q,&F,&R);
		if(y!=0)		
			printf("\nElement removed = %d",y);
		break;

	case 4: y=dqdelete_rear(Q,&F,&R);
		if(y!=0)		
			printf("\nElement removed = %d",y);
		break;

	case 5: status(Q,&F,&R,n);
		break;

	case 6: printf("\n");
		break;

	default:printf("\nInvalid choice.\n");
}

}while(choice!=6);

}
