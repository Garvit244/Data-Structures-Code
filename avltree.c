#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int key;
	int ht;
	struct node *left,*right,*parent;
};
struct node *insert(struct node *,int );
struct node *check(struct node *);
struct node *disbalance(struct node *);
struct node* insrt;
struct node* xy=NULL;
struct node* create_avl()
{
	struct node* root=(struct node*)malloc(sizeof(struct node));
	root->left=NULL;
	root->right=NULL;
	root->parent=NULL;
	return(root);
}

int depth(struct node* a)
{
	if(a->left== NULL && a->right== NULL)
		return 0;
	if(a->left!=NULL && a->right!=NULL)
		return(1+max(depth(a->left),depth(a->right)));
	if(a->left==NULL)
		return 1+depth(a->right);
	if(a->right==NULL)
		return 1+depth(a->left);
}

struct node *s_r_right(struct node* a)
{
	struct node* temp;
	temp=a->left;
	a->left=temp->right;
	a->left->parent=a;
	temp->right=a;
	temp->parent=a->parent;
	a->parent=temp;
	if(temp->parent->key > temp->key)
		temp->parent->left=temp;
	else
		temp->parent->right=temp;
	return temp;
}

struct node *s_r_left(struct node* a)
{
	struct node* temp;
	temp=a->right;
	a->right=temp->left;
	a->right->parent=a;
	temp->left=a;
	temp->parent=a->parent;
	a->parent=temp;
	if(temp->parent->key > temp->key)
		temp->parent->left=temp;
	else
		temp->parent->right=temp;
	return temp;
}

struct node *d_r_l_r(struct node *a)
{
	a->left=s_r_right(a->left);
	return (s_r_left(a));
}

struct node *d_r_r_l(struct node *a)
{
	a->right=s_r_left(a->right);
	return (s_r_right(a));
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

struct node *insert(struct node *a,int n)
{
	
	struct node* root;
	root=a;
	if(n > a->key)
	{
		if(a->right!=NULL)
			a->right=insert(a->right,n);
		else
		{
			a->right=(struct node*)malloc(sizeof(struct node));
			a->right->parent=a;
			a=a->right;
			a->key=n;
			a->left=NULL;
			a->right=NULL;
			insrt=a;
		}
	}
	else
	{
		if(a->left!=NULL)
			a->left=insert(a->left,n);
		else
		{
			a->left=(struct node*)malloc(sizeof(struct node));
			a->left->parent=a;
			a=a->left;
			a->key=n;
			a->left=NULL;
			a->right=NULL;
			insrt=a;
		}
	}
	return root;
}

struct node* disbalance(struct node* a)
{
	struct node *b;
	int x=-1,y=-1;
	if(a->left!=NULL)
		x=depth(a->left);
	if(a->right!=NULL)
		y=depth(a->right);	
	if(abs(x-y) > 1)
		return a;
	else if(a->parent!=NULL && abs(x-y)<=1)
		b=disbalance(a->parent);
	else if(a->parent==NULL && abs(x-y)<=1)
		return NULL;
	return b;
}

struct node* check(struct node* a)
{
	if(a->key > insrt->key)
	{
		if(a->left->key > insrt->key)
			a=s_r_left(a);
		else
			a=d_r_l_r(a);
	}
	else
	{
		if(a->right->key < insrt->key)
			a=s_r_right(a);
		else	
			a=d_r_r_l(a);
	}
	return a;
}

void display(struct node *temp)   //Func to Display TREE level by level//
{
	struct node **a,**b;
	a=(struct node **)malloc(sizeof(struct node *));
	*a=temp;
	int flag=1,i=0,j=0,k=0,l=0;
	b=a;
	while(flag)
	{
		a=b;
		k=0;
		l=0;
		while(k<pow(2,i))
		{
			if(a[k] != NULL)
				printf("%d	",a[k]->key);
			else
				printf("*	");
			k++;
		}
		j=pow(2,i);
		k=0;
		i++;
		b=(struct node ** )malloc(sizeof(struct node *)*pow(2,i));
		while(k<j)
		{
			if(a[k]!=NULL)
			{
				b[l++]=a[k]->left;
				b[l++]=a[k]->right;
			}
			else
			{
				b[l++]=NULL;
				b[l++]=NULL;
			}
			k++;
		}
		k=0;
		flag=0;
		while(k<l)
		{	if(b[k]!=NULL)
				flag=1;
			k++;
		}
		printf("\n");
	}
}

main()
{
	struct node* root;
	int n,k;
	root=create_avl();
	printf("**********Input the binary Tree*************\n\n");
	printf("1.Insert into the binary tree\n\n");
		printf("Enter the root node -->\n");
	scanf("%d",&root->key);
	printf("Enter the number of nodes in the AVL tree\n\n");
	scanf("%d",&n);
	while(n--)
	{
		printf("Enter the node value:\n");
		scanf("%d",&k);
		root=insert(root,k);
	}
	printf("The Binary Search Tree:\n\n");
	display(root);
	printf("Enter the node to be inserted in the AVL tree:\n");
	scanf("%d",&k);
	insert(root,k);
	printf("\n");
	printf("After the adition of the node to the tree:\n\n");
	display(root);
	struct node *temp;
	temp=disbalance(insrt);
	printf("\n\n\n%d\n\n",temp->key);
	if(temp!=NULL)
		check(temp);
	if(xy!=NULL)
		display(xy);
	else
		display(root);
}