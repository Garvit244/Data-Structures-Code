#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50
struct node
{
	char data[max];
	int top;
};
void push(struct node *s1,char item)
{
	if(s1->top == max-1)
		printf("\n Stack is full");
	else
		{
			s1->top=s1->top + 1;
			s1 ->data[s1->top]= item;
		}
}
char pop(struct node *s1)
{
	char item;
	if(s1->top == -1)
		printf("Stack is null\n");	
	else
	{
		item=s1->data[s1->top];
		s1->top=s1->top - 1;	
	}
	return item;
	
}
int prec(char ch)
{
    switch(ch)
    {
    	case ')':return 1;
        case '(':return 2;
        case '+':
        case '-':return 3;
        case '*':
        case '/':
        case '%':return 4;
        case '^':return 5;
        default:return 0; 
    }
} 

void conversion(char infix[])
{
	struct node *s1;
	s1 = (struct node *)malloc(sizeof(struct node *));
	char postfix[max];
	int i,j,k;
	char ch;
	s1->top = -1;
	push(s1,')');
 	k=strlen(infix);
	infix[k++]='(';
	for(i=0,j=0;i<k;i++)
	{
		switch(prec(infix[i]))
		{
			case 1: push(s1,infix[i]);
					break;
			case 2: ch=pop(s1);
					while(ch!=')')
					{
						postfix[j++]=ch;
						ch=pop(s1);
					}
					break;
			case 3: ch=pop(s1);
					while(prec(ch)>3)
					{
						postfix[j++]=ch;
						ch=pop(s1);
					}
					push(s1,ch);
					push(s1,infix[i]);
	 				break;
			case 4 :ch=pop(s1);
					while(prec(ch)>4)					{
						postfix[j++]=ch;
						ch=pop(s1);
					}
					push(s1,ch);
					push(s1,infix[i]);
					break;
			case 5:	push(s1,infix[i]);
					break;
			default:postfix[j++]=infix[i];
			}	
	}
	postfix[j++]='\0';
	printf("The postfix expression is:%s \n",strrev(postfix));
}

int main()
{
	char infix[max];
	printf("Enter the infix expression:\n");
	scanf("%s",infix);
	strrev(infix);
	conversion(infix);
}
