#include<stdio.h>
#include<stdlib.h>

int merge_sort(int *op,int left,int right);
int z=0;
int main()
{
	int *ip=NULL,index=0,no_data;

	printf("Please Enter The No. Of Data\n");
	scanf("%d",&no_data);				

	printf("Please Enter The Data One By One\n");

	ip = (int *)malloc(no_data*sizeof(int));
	for(index=0;index<no_data;index++)
	{
		scanf("%d",&ip[index]);				
        }

	merge_sort(ip,0,(no_data-1));				
    	for(index=0;index<no_data;index++)
	{
		printf("%d,",ip[index]);	
	}
	printf("\n");

	return(0);
}

int merge_sort(int *op,int left,int right)
{
	int no;					
	no = right-left+1;		
	if(no>1)
	{z++;
		int n1,n2;			
		if((no%2)==0)
			n1 = no/2;		
		else
			n1 = (no-1)/2;
		n2 = no-n1;		



		if(n1>1)
		{

			merge_sort(op,left,(left+n1-1));
            	}
			
		if(n2>1)
			merge_sort(op,(right-n2+1),right);	
            		int i,j=1,*temp=NULL,k=0,l=0;				

		temp = (int *)malloc(n1*sizeof(int));	
		for(i=0;i<n1;i++)					
		{
			temp[i] = op[left+i];

		}

		for(i=left;i<=right;i++)				
        {
			if((j<=n2)&&(l<n1))				
            		{
				if(temp[l]>op[right-n2+j])		
                	{
					op[i] = op[right-n2+j];
					j++;
				}
				else
				{
					op[i] = temp[l];
					l++;
				}
			}
			else
				break;
		}
		if(l<n1)					
		{
			for(l=l;l<n1;l++)
			{

				op[i] = temp[l];
				i++;
			}
		}
		return(0);
	}
	else							
		return(0);
}






s
