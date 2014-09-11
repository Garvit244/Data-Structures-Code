#include<stdio.h>
#include<stdlib.h>

int heapifing(int *ip,int no,int parent);
int rehead(int *ip,int change);
int main()
{
	int *ip,i=0,j,no_data,temp;

	printf("Please Enter The No. Of Data\n");
	scanf("%d",&no_data);
	ip = (int *)malloc(no_data*sizeof(int));

	printf("Please Enter The Data One By One\n");
	for(i=0;i<no_data;i++)
	{
		scanf("%d",&ip[i]);
	}

	for(i=(no_data);i>0;i--)
	{
		heapifing(ip,i,0);
		temp = ip[0];
	
		ip[0] = ip[i-1];
		ip[i-1] = temp;
}

	
for(j=0;j<no_data;j++)
		{
			printf("\n%d",ip[j]);
		}
	
getchar ();
getchar ();
}

int heapifing(int *ip,int no,int parent)
{
	int left_Index,right_Index,temp;

	left_Index = (parent*2)+1;
	right_Index = (parent*2)+2;

	if(left_Index<no)
	{
		if(ip[parent]<ip[left_Index])
		{
			if((ip[left_Index]>ip[right_Index])||(right_Index>=no))
			{
				temp = ip[parent];
				ip[parent] = ip[left_Index];
				ip[left_Index] = temp;
				if(parent!=0)
				{
					reheap(ip,parent);
				}
			}
			else
			{
				temp = ip[parent];
				ip[parent] = ip[right_Index];
				ip[right_Index] = temp;
				if(parent!=0)
				{
					reheap(ip,parent);
				}
			}
				
		}

		heapifing(ip,no,left_Index);
		heapifing(ip,no,right_Index);
	}

	return 0;

}

int reheap(int *ip,int change)
{
	int check,temp;
	if((change%2)==0)
	{
		check = (change-2)/2;
	}
	else
	{
		check = (change-1)/2;
	}
	while(ip[check]<ip[change])
	{
		temp = ip[check];
		ip[check] = ip[change];
		ip[change] = temp;
		change = check;
		if(change>0)
		{
			if((change%2)==0)
			{
				check = (change-2)/2;
			}
			else
			{
				check = (change-1)/2;
			}
		}
	}

	return 0;
}
