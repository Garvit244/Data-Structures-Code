#include <stdio.h>
#include <stdlib.h>

struct queue *front=NULL, *rear=NULL;
void push(int element);
int pop();
void display(struct queue*);

struct queue
{
    int data;
    struct queue *next;
};
int main()
{
    int choice, element;
    do
    { 
        printf("Enter your choice for the queue:\n\n");
        printf("1. PUSH AN ELEMENT\n");
        printf("2. POP AN ELEMENT\n");
        printf("3. DISPLAY THE QUEUE\n");
        printf("4. EXIT\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: 
                printf("Enter a value to Push into the queue:\n");
                scanf("%d",&element);
                push(element);
                display(front);
                break;
            case 2:
                element=pop();
                if (element!= -1);
                    printf("Popped element: %d",element);
                    display(front);
                break;
            case 3:
                display(front);
                break;
            case 4:
                break;
            dafault: 
                printf("Enter a valid choice....!!!");
        }   
    }         
     while (choice!=4);
     return 0;
 }

void push(int x)            
 {
     struct queue *node;
     node=(struct queue*)malloc(sizeof(struct queue));
     node->data=x;
     node->next=NULL;
     if (front==NULL)
          front=node;
     else
          rear->next=node;
     rear=node;
 }
 
 int pop()
 {
     int element=-1;
     struct queue *ptr;
     if (front==NULL)
          printf("Queue Underflow..!! \n");
     else 
     {
         element=front->data;
         ptr=front;
         front=front->next;
         free(ptr);
     }
     return element;
 } 
 
void display(struct queue *ptr)
{
	printf("\n\n");
	while(ptr!=NULL)
	{
		
		printf("%d -> ",ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n\n");
}           
 
                                                                             
        
                              
