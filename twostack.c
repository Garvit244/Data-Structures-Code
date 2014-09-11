#include<stdio.h>
#include<stdlib.h>

int top1,top2;
int size;
int arr[5];
void push1(int num)
{
	if(top1 < top2 -1)
	{
		top1++;
		arr[top1]=num;	
	}
	else
		printf("Stack Overflow\n");
}

void push2(int num)
{
	if(top1 < top2 -1)
	{
		top2--;
		arr[top2]=num;	
	}
	else
		printf("Stack Overflow\n");
}

int pop1()
{
	if(top1 >= 0)
	{
		int x = arr[top1];
		top1--;
		return x;
	}
	else
	{
		printf("Stack is Empty\n");
		return 0;
	}
}

int pop2()
{
	if(top2 < size)
	{
		int x = arr[top2];
		top2++;
		return x;
	}
	else
	{
		printf("Stack is Empty\n");
		return 0;
	}
}

int main()
{
	size = 5;
	top1= -1;
	top2 = 5;
	push1(5);
	push2(10);
	push1(45);
	push1(12);
	push2(41);
	printf("Element Popped from stack 1 is: %d\n",pop1());				
	printf("Element Popped from stack 2 is: %d\n",pop2());
	return 0;
}
