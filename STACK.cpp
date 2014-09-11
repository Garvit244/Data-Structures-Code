#include<stdio.h>
#include<stdlib.h>

struct stack{
       int data;
       struct stack *next;
       };
struct stack *top= NULL;
void push(int data);
int pop();
void display();
main()
{
      
      int choice,item;
      do
      {
          printf("\n");
          printf("List of operations... :\n ");
          printf("1.To push an element\n");
          printf("2.To pop an element\n");
          printf("3.Exit\n");
          printf("Enter your choice... : ");
          scanf("%d",&choice);
          
          switch(choice)
          {
                        case 1 : printf("Enter the data\n");
                                 printf("Data : ");
                                 scanf("%d",&item);
                                 push(item);
                                 display();
                                 break;
                        case 2: item = pop();
                                if(item== -1)
                                printf("The stack is empty.....!!!! \n\n");
                                else
                                {
                                    printf("The popped data is : %d",item);
                                }
                                display();
                                break;
                        case 3 : break;
                        default : printf("Enter valid choice...!!!!");
          }
      }
      while(choice!=3);
      return 0;
      getchar();
}

void push(int item)
{
     struct stack *new_ptr ;
     new_ptr = (struct stack*)malloc(sizeof(struct stack*));
     new_ptr->data = item;
     new_ptr->next = top;
     top = new_ptr;
}

int pop()
{
    int new_data;
    struct stack *t_ptr;
    if(top==NULL)
    {
                 printf("Data Underflow...!!!!\n\n");
    }                
    new_data=top->data;
    t_ptr = top;
    top=top->next;
    return(new_data);
    free(t_ptr);
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
                             
                             
    
    
