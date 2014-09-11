#include<stdio.h>
#include<stdlib.h>

struct node
{
	int ssl;
	struct node *next;
};

typedef struct node usl;

int main()
{
	int i=0,temp;
	usl *sl,*temp1=NULL,*temp2=NULL;

	printf("Please Enter The UnSorted List One By One and after entering please enter a negative no.\n");

	sl = malloc(sizeof(usl));
	
	sl->next = NULL;
	sl->ssl = -1;
	
	while(1)
	{
		scanf("%d",&temp);

		if(temp<0)
			break;
		else
		{
			temp1 = sl;
			while(temp1->next!=NULL)
			{
				if((temp1->next->ssl)>temp)
				{
					temp2 = malloc(sizeof(usl));
					temp2->next = temp1->next;
					temp2->ssl = temp;
					temp1->next = temp2;
					break;
				}
				else
					temp1 = temp1->next;
			}
			if(temp1->next==NULL)
			{
				temp2 = malloc(sizeof(usl));
				temp2->ssl = temp;
				temp2->next = NULL;

				temp1->next = temp2;
			}
		}
	}
	while(sl->next!=NULL)
	{
		sl = sl->next;
		printf("%d->",sl->ssl);
	}

	printf("\n");
	return(0);
}
