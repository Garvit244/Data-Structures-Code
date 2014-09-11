#include<stdio.h>
#include<stdlib.h>

struct N_tree
{
    int data;
    struct N_tree *child;
    struct N_tree *sibling;
};
struct N_tree *root=NULL;
void add_son(int,int,struct N_tree*);
struct N_tree* find_node(int,struct N_tree*);
void display();
main()
{
		int choice,data,n;
		struct N_tree *ptr;
		struct N_tree *root;
		root->data=0;
		root->child=NULL;
		root->sibling=NULL;
	do
	{
		printf("Operations menu:\n");
		printf("1. Add son.\n");
		printf("2. Search a son.\n");
		printf("3. Display the path.\n");
		printf("4. Exit.\n");
		printf("Enter your choice..: ");
		scanf("%d",&choice);
		
        switch(choice)
		{
			case 1 : printf("Enter the data value of the node");
					 scanf("%d",&data);
					 printf("enter the index");
					 scanf("%d",&n);
					 add_son(data,n,root);
					 break;
		 
			case 2	:	break;

			default :	printf("Please enter a valid choice !!!\n\n");
		}
	}
	while (choice!=2);

	return 0;
}
	
void add_son(int data,int n,struct N_tree *ptr)
{
      struct N_tree *temp;
      struct N_tree *temp1;
	  
      	temp1=(struct N_tree*)malloc(sizeof(struct N_tree*));
      	temp1->data = data;
      	temp1->child = NULL;
      	temp1->sibling = NULL;
      	temp = ptr;
       	if(temp->child!=NULL)
       	{
       		temp =temp->child;
       		while(temp->sibling!=NULL)
       		{
       			temp=temp->sibling;
       		}
       		temp->sibling=temp1;
       		printf("sibling node added");
       	}
       	else
       	{
       		temp->child=temp1;
       		printf("added son\n");
       	}
}
   
     

