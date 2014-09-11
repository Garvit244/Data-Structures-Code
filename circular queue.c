#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *front=NULL,*rear=NULL;
int count=0;
void push(int n)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->link=NULL;
	if(count==0)
	front=temp;
	else
	rear->link=temp;
	rear=temp;
	rear->link=front;
	count ++;
}

int pop()
{
	int n;
	struct node *temp;
	if(count==0)
	return -1;
	count--;
	if(front==rear)
	{
		n=front->data;
		free(front);
		front=NULL;
		rear=NULL;
	}
	else
	{
		temp=front;
		n=front->data;
		free(temp);
		front=front->link;
		rear->link=front;
	}
	return n;
}
void display()
	{
	struct node *temp;
	int i;
	if(count==0)
	printf("Empty");
	else
	{
	temp=front;
	for(i=0;i<count;i++)
	{
	printf("%d ->",temp->data);
	temp=temp->link;
	}
	}
		printf("NULL\n");
	}
	
    int size()
	{
	return count;
	}
	
 main()
	{
	int n,ch;
	while(1)
	{
	printf("\n       What do you want to do??\n");
	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Display\n");
	printf("4.Size of the Queue\n");
	printf("5.EXIT\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	{
	printf("What no. do you want to push in node\n");
	scanf("%d",&n);
	push(n);
	break;
	}
	case 2:
	{
	n=pop();
	if(n==-1)
	printf("queue is empty\n");
	else
	printf("Number poped from queue is %d\n",n);
	break;
	}

	case 3:
	{
	printf("queue is -->> \n");
	display();
	}
	case 4:
	{
	n=size();
	printf("Size of queue is %d\n",n);
	break;
	}
	case 5:
	exit(1);
	break;
	default:
	printf("Wrong Choice\n");
	break;
}
	}
	}
