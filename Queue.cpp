#include<stdio.h>
#include<stdlib.h>

struct queue{

       int data ;
       struct queue *next;
       };
struct queue *top = NULL;
struct queue *pushptr = NULL;
struct queue *popptr = NULL;
void push(int item);
int pop();
void display();
main()
{
      int option,item;
      do
      {
     	printf("Operations menu:\n");
		printf("1. To push a element.\n");
		printf("2. To pop a element.\n");
		printf("3. Exit.\n");
		printf("Enter your choice..: ");
		scanf("%d",&option);
		
        switch(option)
		{

			case 1 	:	
					printf("Enter the data : ");
					scanf("%d",&item);
					push(item);
					display();
					break;
			 
			case 2 	:	
					printf("\nEnter the data  : ");
					if (item == -1)
						printf("\n The Queue is empty.\n");
					else
						printf("\n The popped data is: %d",item);
					break;
			case 3	:	break;

			default :	printf("Please enter a valid choice !!!\n\n");
		}
	}
	while (option!=3);
	
	return 0;
}
void push(int item)
{    
	
    struct queue *newptr;
	
	newptr = (struct queue*)malloc(sizeof(struct queue*));
	newptr->data = item;

	newptr->next = pushptr;
    newptr->next = top;
    top = newptr;
}

int pop()
{   int data;
      struct queue *newptr;
    while(newptr!= NULL)
	{
		newptr= newptr->next;
     }
     
   
}
void display()
{
     struct queue *ptr;
     printf("The queue is... :\n\n ");
     while(ptr!=NULL)
     {
                             printf("%d -> ",ptr->data);
                             ptr=ptr->next;
     }
}
