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
int display_path(node *root);

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
		printf("Please Enter Your Choice Code\n1. Add Sons\n2. Search a Node\n3. Display All Paths\n4. Exit\n");
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
				search_node(root,search1);
				break;
			}
			case 3:
			{
				display_path(root);
				break;
			}
			case 4:
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
	sear = 1;
	char fath;
	node *temp;
	printf("Please The Father You Want To Add Son To and Enter 0 To Add Son To Root = ");
	scanf("%c",&fath);
	getchar();
	if(fath!='0')
		root = search_node(root,fath);
	if(root==NULL)
		return(0);
	printf("Data You Want TO Store = ");
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

node* search_node(node *root,char no_data)
{
	que *queue=NULL;
	node *temp=NULL;
	if(root->son!=NULL)
	{
		queue = create_queue();
		push_queue(queue,root);
	}
	else
	{
		printf("Tree Is Empty\n");
		return(NULL);
	}
	while(queue!=NULL)
	{
		temp = pop_queue(queue);
		if(temp->data==no_data)
		{/*printf("aas\n");
			if(sear==0)
			{*/
				
			return(temp);
		}
		if(temp->son!=NULL)
		{
			temp = temp->son;
			push_queue(queue,temp);
		}
		else
			continue;
		while(temp->sib!=NULL)
		{
			push_queue(queue,temp->sib);
			temp = temp->sib;
		}
	}
	printf("Data Not Found\n");
	return(NULL);
}

int display_path(node *root)
{
	que *queue=NULL;
	node *temp=NULL;
	/*int *sib1,m=1,n=0;
	sib1 = (int *)malloc(2*sizeof(int));
	sib1[0] = 1;*/
	if(root->son!=NULL)
	{
		queue = create_queue();
		push_queue(queue,root);
	}
	else
	{
		printf("Tree Is Empty\n");
		return(0);
	}
	while((queue->next)!=NULL)
	{
		/*sib1[n]--;
		sib1 = (char *)realloc(sib1,(m*sizeof(int))+2);
		sib1[m]++;*/
		temp = pop_queue(queue);
		printf("%c->",temp->data);
		if(temp->son!=NULL)
		{
			temp = temp->son;
			push_queue(queue,temp);
		}
		else
		{
			
			continue;
		}
		while(temp->sib!=NULL)
		{
			//sib1[m]++;
			push_queue(queue,temp->sib);
			temp = temp->sib;
		}
		/*if(sib1[n]==0)
		{
			m++;
			n++;
			printf("\n");
		}*/
	}
	printf("\n");
	return(0);
}

que* create_queue()
{
	que *temp;
	temp = (que *)malloc(sizeof(que));
	temp->data1 = 0;
	temp->next = NULL;
	return(temp);
}

int push_queue(que *queue,node *entry)
{
	que *temp;
	while(queue->next!=NULL)
	{
		queue = queue->next;
	}
	temp = (que *)malloc(sizeof(que));
	temp->next = NULL;
	temp->data1 = entry;
	queue->next = temp;
	return(0);
}

node* pop_queue(que *queue)
{
	que *temp;
	node *temp1;
	temp = queue->next;
	queue->next = queue->next->next;
	temp1 = temp->data1;
	free(temp);
	return(temp1);
}






