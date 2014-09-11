#include<stdio.h>
#include<stdlib.h>

int quick_sort(int *usl,int left,int right);
int main()
{
	int no_data,*ip=NULL,i;			

	printf("Plaese Enter The no. of data to input\n");	
	scanf("%d",&no_data);				

	printf("Please Enter Data One By One\n");
	ip = (int *)malloc(no_data*sizeof(int));

	for(i=0;i<no_data;i++)
	{
		scanf("%d",&ip[i]);			
	}

	quick_sort(ip,0,(no_data-1));	

	for(i=0;i<no_data;i++)			
	{
		printf("%d->",ip[i]);
	}
	printf("\n");
	return(0);
}

int quick_sort(int *usl,int left,int right)	
{
	int l,r,temp;					

	l = left;
	r = right-1;

	while(l<=r)
	{
		while(usl[l]<usl[right])
		{
			l++;
		}
		while(usl[r]>usl[right])
		{
			r--;
		}
		if(l<r)
		{
			temp = usl[l];
			usl[l] = usl[r];
			usl[r] = temp;
			l++;
			r--;
		}
	}
	if(l<right)
	{
		temp = usl[l];
		usl[l] = usl[right];
		usl[right] = temp;
	}
	if(l>(left+1))
	{
		quick_sort(usl,left,(l-1));
	}
	if(l<(right-1))
	{
		quick_sort(usl,(l+1),right);
	}
	return(0);
}
