#include<stdio.h>
#include<stdlib.h>

struct stack* top = NULL;
struct stack* create_new_stack();
void push();
int pop();
void display();

struct stack
{
	int data;
	struct stack *next;
};

int main()
{
	int choice,data;
	while(1)
	{
		printf("Operations menu for Stack:\n");
		printf("1. To push a element.\n");
		printf("2. To pop a element.\n");
		printf("3. Exit.\n");
		printf("Enter your choice..: ");
		scanf("%d",&choice);
		
        switch(choice)
		{

			case 1 	:	
					printf("Enter the data : ");
					scanf("%d",&data);
					push(data);
					display();
					break;
			 
			case 2 	:	
					printf("\nEnter the data  : ");
					if (data == -1)
						printf("\n Stack is empty.\n");
					else
						printf("\n The popped data is: %d,data\n");
						display();
					break;
			case 3	:
					exit(0);	
					break;

			default :	
					printf("Please enter a valid choice !!!\n\n");
		}
	}
	return 0;
}
	
void push(int data)
{    

	struct stack *newptr;
	newptr = (struct stack*)malloc(sizeof(struct stack *));
	newptr->data = data;
    newptr->next = top;
    top = newptr;
}

int pop()
{
    int new_data;
	struct stack *temp_ptr;
    if(top == NULL)
    {
  		printf("Data Underflow...!!!!\n\n");
    }                
    new_data=top->data;
    temp_ptr=top;
    top=top->next;
    return(new_data);
    free(temp_ptr);
}

void display()
{
     struct stack *ptr;
     ptr = top;
     printf("The stack is... :\n\n ");
     while(ptr!=NULL)
     {
                     printf("%d -> ",ptr->data);
                     ptr=ptr->next;
     }
}
