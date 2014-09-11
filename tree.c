/*Tree and its basics operation
Name: Garvit Bansal
Roll no.: Y11UC092 */

#include<stdio.h>
#include<stdlib.h>

struct tree_node
{
	int data;
	struct tree_node* lson;
	struct tree_node* rson;
};

struct node
{
	int data;
	struct tree_node* ptr;
	struct node* next;
};
struct tree_node *delete_rson(int,struct tree_node*);
struct tree_node *delete_lson(int,struct tree_node*);
struct tree_node* create_node()
{
	struct tree_node* temp=(struct tree_node*)malloc(sizeof(struct tree_node));
	temp->lson=NULL;
	temp->rson=NULL;
	return (temp); 
}

struct node* create_header()
{
	struct node* header=(struct node*)malloc(sizeof(struct node));
	header->data=0;
	header->ptr=NULL;
	header->next=NULL;
	return (header);
}

void push(struct node* head,struct tree_node* value)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->next=head->next;
	head->next=temp;
	temp->ptr=value;
	head->data++;
	
}

struct tree_node* pop(struct node* head)
{
	struct node* last=head;
	if(head->next==NULL)
	{
		return (NULL);
	}
	while(((last->next)->next!=NULL))
	{
		last=last->next;
	}
	struct node *temp=last->next;
	struct tree_node *ptr=(last->next)->ptr;
	last->next=NULL;
	free(temp);
	return (ptr);
}
struct tree_node* find_node(struct tree_node* root,int data)
{
	struct tree_node* temp;///
	if(root->data==data)
	{
		return (root);
	}
	if(((root->lson)==NULL)&&((root->rson)==NULL))
	{
		return (NULL);
	}
	struct node* head=create_header();
	push(head,root);
	while(head->next!=NULL)
	{
		temp=pop(head);
		if(temp->data==data)
		{
			return (temp);
		}
		if(temp->lson!=NULL)
		{
			push(head,temp->lson);
		}
		if(temp->rson!=NULL)
		{
			push(head,temp->rson);
		}
	}
free(head);
return(NULL);
}

struct tree_node* create_root()
{
	struct tree_node* root=create_node();
	root->data=0;
	return (root);
}

void create_lson(int parent_data,struct tree_node* root,int new_data)
{
	struct tree_node* parent=find_node(root,parent_data);
	struct tree_node* Temp=find_node(root,new_data);
	if(parent==NULL)
	{
		printf("Parent Node not found!!\n");
		return;
	}
	if(Temp!=NULL)
	{
		printf("Duplicate value already exist!!\n");
		return;
	}
	if(parent->lson!=NULL)
	{
		printf("Left Son already exist!!\n");
		return;
	}
	parent->lson=(struct tree_node*)malloc(sizeof(struct tree_node));
	(parent->lson)->data=new_data;
	(parent->lson)->lson=NULL;
	(parent->lson)->rson=NULL;
}

void create_rson(int parent_data,struct tree_node* root,int new_data)
{
	struct tree_node* parent=find_node(root,parent_data);
	struct tree_node* Temp=find_node(root,new_data);
	if(parent==NULL)
	{
		printf("Parent Node not found!!\n");
		return;
	}
	if(Temp!=NULL)
	{
		printf("Duplicate value already exist!!\n");
		return;
	}
	if(parent->rson!=NULL)
	{
		printf("Right Son already exist!!\n");
		return;
	}
	parent->rson=(struct tree_node*)malloc(sizeof(struct tree_node));
	(parent->rson)->data=new_data;
	(parent->rson)->lson=NULL;
	(parent->rson)->rson=NULL;
}

void display(struct tree_node* root)
{
	struct tree_node* temp;
	int i=1;
	printf("Level 0 : %d\n",root->data);
	if(((root->lson)==NULL)&&((root->rson)==NULL))
	{
		return;
	}
	struct node* head=create_header();
	push(head,root);
	while(head->next!=NULL)
	{
		temp=pop(head);
		if(temp->lson!=NULL)
		{
			push(head,temp->lson);
		}
		if(temp->rson!=NULL)
		{
			push(head,temp->rson);
		}	
		if(temp->lson!=NULL)
			printf("level %d  :%d",i,temp->lson->data);
	 	if(temp->rson!=NULL)
		 	printf("level %d  :%d",i,temp->rson->data);
    	i++;
			printf("\n");
	}
free(head);
}

struct tree_node *delete_lson(int nodeDV,struct tree_node *root)
{
	if(root == NULL)
	{
		printf("Cannot delete the node\n");
		return NULL;
	}
	struct tree_node *node_DV_ptr=find_node(root,nodeDV);
	if(node_DV_ptr == NULL)
	{
		printf("node_dv does not exist\n");
		return NULL;
	}
	if(node_DV_ptr->lson == NULL)
	{
		printf("node_dv exist but dont habe lson\n");
		return NULL;
	}	
	struct tree_node *node_DV_lson_ptr=node_DV_ptr->lson;
	if((node_DV_lson_ptr->lson == NULL) && (node_DV_lson_ptr->rson == NULL))
	{
		free(node_DV_lson_ptr);
		node_DV_ptr->lson = NULL; // errors
		return root;
	}
	if(node_DV_lson_ptr->lson != NULL)
		root=delete_lson(((node_DV_lson_ptr->lson)->data),node_DV_lson_ptr);
	if(node_DV_lson_ptr->rson != NULL)
		root=delete_rson(((node_DV_lson_ptr->rson)->data),node_DV_lson_ptr);
	free(node_DV_lson_ptr);
	node_DV_ptr->lson=NULL; //errors
	return root;
}
struct tree_node *delete_rson(int nodeDV,struct tree_node *root)
{
	if(root == NULL)
	{
		printf("Cannot delete the node\n");
		return NULL;
	}
	struct tree_node *node_DV_ptr=find_node(root,nodeDV);
	if(node_DV_ptr == NULL)
	{
		printf("node_dv does not exist\n");
		return NULL;
	}
	if(node_DV_ptr->rson == NULL)
	{
		printf("node_dv exist but dont have rson\n");
		return NULL;
	}	
	struct tree_node *node_DV_rson_ptr=node_DV_ptr->rson;
	if((node_DV_rson_ptr->lson == NULL) && (node_DV_rson_ptr->rson == NULL))
	{
		free(node_DV_rson_ptr);
		node_DV_ptr->rson = NULL;
		return root;
	}
	if(node_DV_rson_ptr->lson != NULL)
		root=delete_rson(((node_DV_rson_ptr->lson)->data),node_DV_rson_ptr);
	if(node_DV_rson_ptr->rson != NULL)
		root=delete_lson(((node_DV_rson_ptr->rson)->data),node_DV_rson_ptr);
	free(node_DV_rson_ptr);
	node_DV_ptr->rson=NULL;
	return root;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	if(a == b)
		return b;
	return(b);
}
int depth_of_tree(struct tree_node* root)
{
	if(root == NULL)
	return -1;
	if((root->lson == NULL) && (root->rson == NULL))
		return 0;
	struct tree_node *abt_ls_ptr=root->lson;
	struct tree_node *abt_rs_ptr=root->rson;
	if(abt_ls_ptr == NULL)
		return(1+depth_of_tree(abt_rs_ptr));
	if(abt_rs_ptr == NULL)
		return(1+depth_of_tree(abt_ls_ptr));
	return(1+max(depth_of_tree(abt_ls_ptr),depth_of_tree(abt_rs_ptr)));
}

int no_leaf_node(struct tree_node *root)
{
/*	int leaf=0,parent=0;
	struct tree_node* temp;
	struct node* head=create_header();
	push(head,root);
	while(head->next!=NULL)
	{
		temp=pop(head);
		if(temp->lson == NULL && temp->rson == NULL)
			leaf++;
		if(temp->lson!=NULL || temp->rson!=NULL)
			parent++;
		if(temp->lson!=NULL)
		{
			push(head,temp->lson);
		}
		if(temp->rson!=NULL)
		{
			push(head,temp->rson);
		}
	}
free(head);
return parent;*/
if(root == NULL)
	return 0;
if(root->lson!=NULL || root->rson!=NULL)
		return(no_leaf_node(root->lson)+no_leaf_node(root->rson));
else
	return 1;
}

int main()
{
	struct tree_node* root=create_root(),*temp;
	int i,parent,val,depth;
	while(1)
	{
		printf("\n-------MENU--------\n");
		printf("1. Insert Left Child\n");
		printf("2. Insert Right Child\n");
		printf("3. Find\n");
		printf("4. Delete the lson\n");
		printf("5. Delete the rson\n");
		printf("6. Display\n");
		printf("7. Depth of tree\n");
		printf("8. Number of leaf node\n");
		printf("9. Exit\n");
		printf("Enter your choice...");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				printf("Enter the data of the parent node: ");
				scanf("%d",&parent);
				printf("Enter the data to be entered: ");
				scanf("%d",&val);
				create_lson(parent,root,val);
				display(root);
				break;
			case 2:
				printf("Enter the data of the parent node: ");
				scanf("%d",&parent);
				printf("Enter the data to be entered: ");
				scanf("%d",&val);
				create_rson(parent,root,val);
				display(root);
				break;
			case 3: printf("Enter the value to be searched:");
					scanf("%d",&val);
					struct tree_node *tmp=find_node(root,val);
					if(tmp == NULL)
						printf("Node does not exist\n");
					else
						printf("Node is present");
					break;
			case 4: printf("Enter the lson to be deleted:");
					scanf("%d",&val);
					temp=delete_lson(val,root);
					break; 
			case 5: printf("Enter the rson to be deleted:");
					scanf("%d",&val);
					temp=delete_rson(val,root);
					break;
			case 6:
				display(root);
				break;
			case 7:depth=depth_of_tree(root);
					if(depth == -1)
						printf("Tree not exist\n");
					else	
					    printf("Depth of the tree is :%d ",depth);
					break;
			case 9: exit(0);
					break;
			case 8: depth=no_leaf_node(root);
					printf("Number of leaf node in the tree are:%d",depth);
					

		}
	}
return 0;
}
