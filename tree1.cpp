#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *sonptr;
    struct node *sibptr;
};



void add_son(int,struct node*);

main()
{
    int a,b,c;
    struct node *p;
    p->data=0;
    p->sonptr=NULL;
    p->sibptr=NULL;
    printf("operations on tree....\n");
    printf("1.Insert in tree....\n");
    printf("2.Find in tree....\n");
    
    printf("enter your choice ....");
    scanf("%d",&b);
    switch(b)
    {
        case 1:printf("enter value in tree\n");
               scanf("%d",&a);
               add_son(a,p);
   }    
}   



void add_son(int a,struct node *q)
{
      struct node *temp;
      struct node *temp1;
     
      
      temp=q;
      if(temp->sonptr=NULL)
      {
      temp1=(struct node*)malloc(sizeof(struct node*));
      temp1->data=a;
      temp1->sonptr=NULL;
      temp1->sibptr=NULL;
      q=temp1;
      printf("son added successfully");
      temp->sonptr=temp1;
      } 
      
        
}    
