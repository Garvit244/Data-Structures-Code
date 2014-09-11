#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int A[MAX];
int B[MAX];
int D[MAX];
int E[MAX];
int C[MAX];
void heapify(int D[], int C[], int n)
{
	int ind,i,j,l,k,m,q,s;
	
	for(i=0;i<n;i++)
	{
		j=i;
		B[j]=D[j];
		E[j]=A[j];
		if (j%2!=0)
		{
			ind=(j-1)/2;
		}
		else
		{	
			//printf("check\n");
			ind=(j-2)/2;
		}
		while(ind>=0)
		{
			if (B[j]>B[ind])
			{	
				k=B[j];
				
				B[j]=B[ind];
				
				B[ind]=k;
				s=E[j];
				E[j]=E[ind];
				E[ind]=s;
			}
			j=ind;
			if(j==0)
			break;
			else
			{
				if (j%2!=0)
				{
					ind=(j-1)/2;
				}
				else
				{
					ind=(j-2)/2;
				}
			}
		}
	}
	for(k=0;k<n;k++)
	{
		printf("%d  ", B[k]);
	}
	printf("\n");
	
	for(k=0;k<n;k++)
	{
		printf("%d  ", E[k]);
	}
	/*for(m=0;m<n;m++)
	{
		A[m]=B[m];
	}
	
	int x;
	
	if(n==1)
	{
		C[0]=B[0];
	}
	
	else
	{
		if(n>>1)
		{	
			//printf("check\n");	
			x=B[n-1];
			B[n-1]=B[0];
			B[0]=x;
			C[n-1]=B[n-1];
			heapify(B, C, n-1);
		}
	}
	/*for(p=0;p<value;p++)
	{
		printf("%d  ", C[p]);
	}
	printf("\n");*/
	
return;	
}

int main()
{
	int i,value,k,m, p;
	printf("enter the no. of elements\n");
	scanf("%d", &value);
	//int A[value], C[value] ,D[value];	
	printf("enter the list\n");
	for(i=0;i<value;i++)
	{
		scanf("%d",&A[i]);
		scanf("%d",&D[i]);
	}
	for(k=0;k<value;k++)
	{
		printf("%d  ", A[k]);
	}
	printf("\n");
	for(k=0;k<value;k++)
	{
		printf("%d  ", D[k]);
	}
	printf("\n");
	heapify(D,C,value);
	/*for(m=0;m<value;m++)
	{
		A[m]=D[m];
	}*/
	printf("heapified list\n");
	/*for(k=0;k<value;k++)
	{
		printf("%d  ", B[k]);
	}*/
	printf("\n");		
	/*printf("sorted list\n");
	for(p=0;p<value;p++)
	{
		printf("%d  ", C[p]);
	}
	printf("\n");*/
}
	
