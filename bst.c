/* Name: Garvit Bansal
*/
#include<stdio.h>
#include<stdlib.h>

struct bst				//For  Each Node
{
	int data,height,bf;
	struct bst *parent;
	struct bst *left_Son;
	struct bst *right_Son;
};


typedef struct bst node;			//To Define  data  type for each nde

node* create_Bst();			//To Create New Bst
int insert_Node(node *head);			//To insert new node
node* search_Node(node *head, int check);			//To Search a node
int delete_Node(node *head);
int print(node *head);

int main()
{
	node *head=NULL;				//the head pointer  for root
	int choice=0,check=0;			//Choice is for users  option and check is to check that the bst is created or not

	

	while(choice!=5)				//To repeateedly get the users choice
	{
		printf("Please Select Your Choice\n1. Add a Node.\n2. Search Node.\n3. Delete Node.\n4. Exit.\n");		//Prompt statement
		scanf("%d",&choice);			//scaning  choice

		switch(choice)
		{
			case 1:				//To insert or create Bst
			{
				if(check==0)		//If Bst is not created
				{
					head = create_Bst();		//To create Bst
					check = 1;					//confirming that the Bst is created
					
				}
				else			//If Bst already created
				{
					insert_Node(head);			//To insert new node
				}
				break;
			}
			case 2:					//For searching a node
			{
				search_Node(head,0);
				break;
			}
			case 3:					//For searching a node
			{
				delete_Node(head);
				break;
			}
			case 4:
			{
				print(head);
				printf("\n");
				break;
			}
		}
	}

	
	return 0;
}

node* create_Bst()				//Function to create new node
{
	node *temp=NULL;					//Temperory pointer to store  new node
	int temp1;					//Temperory int to store data value

	
	printf("Please Enter The Data\n");		//Prompt statement

	scanf("%d",&temp1);				//scanning data value


	temp = (node *)malloc(sizeof(node));		//to allocate memory for new node
	temp->data = temp1;				//sttoring  data value  in node

	temp->right_Son = NULL;				//Initializing the values of the  node
	temp->left_Son = NULL;
	temp->height = 0;
	temp->bf = 0;
	temp->parent =  NULL;

	return(temp);					//returning root  pointer to store in head
}

int insert_Node(node *head)				//To add new node              here head is passed to get the bst root pointer
{
	int data;					//Data is to input new node value
	node *temp;					//To temperory store the new node pointer

	printf("Please Enter The Data\n");		//Prompt statement
	scanf("%d",&data);				//To get node value

	temp = (node *)malloc(sizeof(node));		//To allocate memory for new node
	temp->data = data;				//storing node value in node

	temp->right_Son = NULL;				//Initializing the values of the  node
	temp->left_Son = NULL;
	temp->height = 0;
	temp->bf = 0;

	while(1)					//to repeatedly traverse in the tree
	{
		if(data>(head->data))			//checking wether to store in right son(If greater)  or left son(If smaller or equal to)
		{
			if((head->right_Son)==NULL)				//For greater           //If Null  then thats the point to add
			{
				
				head->right_Son = temp;				//Adding node to tree
				temp->parent = head;				//Filling parents pointer

				if((head->left_Son)==NULL)			//Checking wether updating is necessary
				{
					temp = head;				//to keep track of head

					temp->height++;
					while((temp->parent)!=NULL)					//To update the  family
					{
						temp = temp->parent;
						temp->bf = (temp->left_Son->height) - (temp->right_Son->height);

						if((temp->height)>(temp))
					}
				}

				if((head->left_Son)!=NULL)				//Updating balancing height
				{
					head->bf = (head->left_Son->height) - 0;

				}
				else
				{
					head->bf = -1;
				}
				break;						//To get out of loop as we have added the node
			}
			else
			{
				head = head->right_Son;				//If still there is are nodes left in tree then modre to traverse
			}
		}
		else							//left son(If smaller or equal to)
		{
			if((head->left_Son)==NULL)				//For Smaller           //If Null then thats the point to add
			{
				head->left_Son = temp;				//Adding pointer to tree
				temp->parent = head;				//Filling parents pointer
				
				break;						//To get out of the loop as we have added the node
			}
			else
			{
				head = head->left_Son;				//If still there is are nodes left in tree then modre to traverse
			}
		}
	}

	

	return 0;				//Adding completed
	
}

node* search_Node(node *head, int check)			//To search a given data value here check is to check who is calling the function
{
	if(head==NULL)				//If bst is not created
	{
		printf("BST Not Yet  Created\n");
		return(NULL);
	}

	int data;			//To take input data

	printf("Please Enter The Data That is to be Searched\n");			//Prompt Statement
	scanf("%d",&data);				//Taking data

	while(1)
	{
		if(data==(head->data))				//if data is searched
		{
			if((head->parent)==NULL)			//If it is a root node
			{
				if(check==0)						//If function is called by main
					printf("The Given Data is in Root\n");		//Giving o/p

				else							//If called by delete function
					return(head);
			}
			else
			{
				if(check==0)
					printf("The Given Data is Under %d\n",(head->parent->data));			//giving o/p if not a root
				else
					return(head);
			}
			return(NULL);
		}
		if(data>(head->data))						//if given data is greater then the present one then going to right son
		{
			if((head->right_Son)==NULL)				//If no right son, then data is not there
			{
				printf("Data Not Yet Inserted\n");
				return(NULL);
			}
			else						//if right son exists then traverse to it
			{
				head = head->right_Son;
				continue;
			}
		}
		else					//if given data is smaller then or equal to present one then going to left son
		{
			if((head->left_Son)==NULL)				//if no left son exists then data not present
			{
				printf("Data Not Yet Inserted\n");
				return(NULL);
			}
			else						//if left son exists the traverse to it
			{
				head = head->left_Son;
				continue;
			}
		}
	}

	return(NULL);
}

int delete_Node(node *head)
{
	head = search_Node(head,1);
	if(head==NULL)					//If node does not exist or BST not created
	{
		return 0;
	}
	else
	{
		node *temp;			//Temp variable to traverse to get greatest left
		if((head->left_Son)!=NULL)		//Shifting  left greatest to top so as to delete top and head is the node to delete
		{
			temp = head->left_Son;			//Going to 

			while((temp->right_Son)!=NULL)
			{
				temp = temp->right_Son;
			}
			head->data = temp->data;
			if((temp->parent->left_Son)==temp)
				temp->parent->left_Son = NULL;
			else
				temp->parent->right_Son = NULL;

			free(temp);
			return 0;
		}
		else
		{
			if((head->right_Son)!=NULL)
			{
				temp = head->right_Son;

				while((temp->left_Son)!=NULL)
				{
					temp = temp->left_Son;		
				}
				head->data = temp->data;
				if((temp->parent->left_Son)==temp)
					temp->parent->left_Son = NULL;
				else
					temp->parent->right_Son = NULL;

				free(temp);
				return 0;
			}
			else
			{
				if((temp->parent->left_Son)==temp)
					temp->parent->left_Son = NULL;
				else
					temp->parent->right_Son = NULL;

				free(temp);
				return 0;
			}
		}
	}
}

int print(node *head)
{
	int data;
	node *temp;
	data = head->data;
	printf("%d         ",data);

	temp = head->left_Son;
	if(temp!=NULL)
		print(temp);

	temp = head->right_Son;
	if(temp!=NULL)
		print(temp);
	return 0;
}
