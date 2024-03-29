#include<stdio.h>
#include<stdlib.h>


struct node* create_new_list();
void insert_node(int, int, struct node*);
int search_node(int, struct node*);
void del_node(int, struct node*);
void display_list(struct node*);


struct node
{
	int data;
	struct node *next;
};

int main()
{
	int choice,index,new_data;
	struct node *head;
	
	head = create_new_list();
	printf("\n");
	
	do
	{
		printf("Operations menu:\n");
		printf("1. Insert a node.\n");
		printf("2. Find a node.\n");
		printf("3. Delete a node.\n");
		printf("4. Display list.\n");
		printf("5. Exit.\n");
		printf("Enter your choice..: ");
		scanf("%d",&choice);

		switch(choice)
		{

			case 1 	:	printf("\nEnter the data and index of the new node\n");
					printf("index : ");
					scanf("%d",&index);
					printf("data : ");
					scanf("%d",&new_data);
					insert_node(index, new_data, head);
					display_list(head);
					break;
			 
			case 2 	:	printf("\nEnter the data to be searched : ");
					scanf("%d",&new_data);
					index = search_node(new_data, head);
					if (index == -1)
						printf("\nGiven data not found in the list.!!!\n\n");
					else
						printf("\nPosition of the given data is... %d\n\n",index);
					break;

			case 3 	:	printf("\nEnter the data to be deleted : ");
					scanf("%d",&new_data);
					index = search_node(new_data, head);
					if (index == -1)
						printf("\nGiven data not found in the list.\n");
					else
						del_node(index, head);
					display_list(head);
					break;

			case 4	:	display_list(head);
					break;

			case 5	:	break;

			default :	printf("Please enter a valid choice !!!\n\n");
		}
	}
	while (choice!=5);
	
	return 0;
}


struct node* create_new_list()
{
	struct node *ptr;	
	ptr = (struct node*)malloc(sizeof(struct node*));
	ptr->data = 0;
	ptr->next=NULL;
	return ptr;
}


void insert_node(int index, int new_data, struct node* ptr)
{
	int i;
	struct node *newptr;
	if(index<0 || index > (ptr->data))
	{
		printf("Invalid index..!!!\n\n");
		return;
	}

	newptr = (struct node*)malloc(sizeof(struct node *));
	newptr->data = new_data;

	ptr->data = ptr->data+1;
	i=0;
	while(i < index)
	{
		ptr = ptr->next;
		i++;
	}
	
	newptr->next = ptr->next;
	ptr->next = newptr;
}


int search_node(int new_data, struct node *ptr)
{
	int i=1;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		if(ptr->data == new_data)
			return i;
		i++;
	}	
	
	return -1;
}


void del_node(int index, struct node *ptr)
{
	int i=1;
	struct node* temp_ptr;

	ptr->data = ptr->data - 1;
	
	while(i < index)
	{
		ptr = ptr->next;
		i++;
	}
	
	temp_ptr = ptr->next;
	ptr->next = (ptr->next)->next;

	free(temp_ptr);
}


void display_list(struct node *ptr)
{
	printf("\nList is...\n");
	while(ptr->next!=NULL)
	{
		ptr = ptr->next;
		printf("%d -> ",ptr->data);
	}
	printf("NULL\n\n");
}


