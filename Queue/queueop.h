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

//Function to print status of queue
void status(int q[],int *f,int *r,int n)
{
	printf("\nElements in the Queue:\n");
	for(int i=1;i<=n;i++)
	{
		if(i<*f || i>*r)
			printf("_,");
		else
			printf("%d,",q[i]);
	}
}

//*****Functions for Circular Queue

//Function to insert an element in Circular Queue
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

//Function to delete an element in Circular Queue
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

//Function to show the Circular Queue status
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

//************Functions for Deque operations
//Insertion from front
void dqinsert_front(int q[],int *f,int *r,int x)
{
	if(*f==0)
	{
		printf("\nEmpty Queue");
	}
	else if(*f==1)
	{
		printf("\nQueue Overflow");
	}	
	else
	{	
		*f=*f-1;
		q[*f]=x;
	}
}

//Deletion from rear
int dqdelete_rear(int q[],int *f,int *r)
{
	if(*r==0)
	{
		printf("\nQueue Underflow!");
		return 0;
	}
	else
	{
		int x=q[*r];
		if(*f==*r)
		{
			*f=0;
			*r=0;
		}
		else
			*r=*r-1;
		return x;
	}
}
