#include<stdio.h>
#include<stdlib.h>

struct tree
{
	char  data;
	struct tree *sib;
	struct tree *son;
};
typedef struct tree node;
struct qu
{
	node *data1;
	struct qu *next;
};

typedef struct qu que; 

node* create_new();
int add_son(node *root);
node* search_node(node *root,char no_data);

que* create_queue();
int push_queue(que *queue,node *entry);
node* pop_queue(que *queue);

int sear=0;
main()
{
	int choice=0;
	node *root;
	root = create_new();
	while(choice!=4)
	{
		printf("Please Enter Your Choice \n1. Add Sons\n2. Search a Node\n3. Display \n4. Exit\n");
		scanf("%d",&choice);
		getchar();
		switch(choice)
		{
			case 1:
			{
				add_son(root);
				break;
			}
			case 2:
			{
				char search1;
				printf("Data You Want To Search = ");
				scanf("%c",&search1);
			
				break;
			}
			case 3:
			{
				break;
			}
		}
	}

}

node* create_new()
{
	node  *temp;
	temp = malloc(sizeof(node));
	temp->data = 0;
	temp->sib = NULL;
	temp->son = NULL;
	return(temp);
}

int add_son(node *root)
{

	char fath;
	node *temp;
	sear = 1;
	printf("Please Enter 'The Father You Want To Add Son To' and Enter 0 'To Add Son To Root' =");
	scanf("%c", &fath);
	getchar();
	if(root==NULL)
		return(0);
	printf("Enter Data: ");
	scanf("%c",&fath);
	getchar();
	temp = (node *)malloc(sizeof(node));
	temp->data = fath;
	temp->sib = root->son;
	temp->son = NULL;
	root->son = temp;
	printf("Node Has Been Sucessfully Added\n");
	sear = 0;
	return(0);
}


