#include<stdio.h>

int factor(int n)
{
	if(n < 1 )
		return 0;
	else
	{
		int fact=1;
		int j;
		for(j=1;j<=n;j++)
			fact*= j;
		return fact;
	}
}

int main()
{
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	int result[10];
 	int temp=1000000;
	int i,res,k=0,l,m;
	int fact;
	for(i=1;i<10;i++)
	{
		fact=factor(10-i);
		res=temp/fact;
		printf("%d ",res);
		temp=temp % fact;
		if(a[res] == -1)
			res++;
		result[k++]=a[res];
		a[res]=-1;
		if(res == 0)
			break;		
	}
	for(i=0;i<10;i++)
		printf("\n%d\n",result[i]);
	return 0;
}
