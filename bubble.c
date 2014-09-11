//BUBBLE SORT


#include<stdio.h>
#include<stdlib.h>

int bubble_sort(int no);		
int *data=NULL;					
main()
{
	int i,no_data,temp,reverse;		


	printf("No. Of Data To Be Sorted = ");		
	scanf("%d",&no_data);					

	data = (int *)realloc(data,((no_data+1)*sizeof(int)));		
	printf("Please Enter Data One After Another\n");		

	for(i=0;i<no_data;i++)						
    {
		scanf("%d",&data[i]);
	}
	
	reverse = bubble_sort(no_data);					

	for(i=(reverse-1);i>=0;i--)					
	{
		printf("%d->",data[i]);
	}

	for(i=reverse;i<no_data;i++)
	{
		printf("%d->",data[i]);
	}
	printf("\n");
}

int bubble_sort(int no)			
{
	int temp=0,i,check=0,reverse=0;

	printf("hello\n");
	for(i=0;i<(no-1);i++)		
	{
		if(data[i]>data[i+1])	
		{
			if((temp>data[i+1])||(i==0))		
				reverse++;

			temp = data[i+1];							data[i+1] = data[i];
			data[i] = temp;

			check++;					
		}
	}
	if((no==0)||(check==0))				
		return 0;
	
	if(reverse==no-1)					
		return(reverse);
	else							
		return(bubble_sort(no-1));
}
