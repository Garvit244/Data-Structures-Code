#include<stdio.h>
#include<stdlib.h>

main()
{
	int no_test,*test=NULL,i=0,n1,n2,ans,p,quest=0;

	scanf("%d",&no_test);

	test = (int *)malloc(no_test*sizeof(int));

	for(i=0;i<no_test;i++)
	{
		scanf("%d",&test[i]);
		n1=1;
		quest = 0;
		for(p=2;p<=test[i]&&n1<p;p++)
		{
		
				n2 = p-n1;
				ans = (n2*n2)+(n1*n1);
				n1++;
				if(ans==test[i])
				{printf("n1 = %d,  p = %d\n",n1,p);
					printf("Yes\n");
					p = test[i]+1;
					quest = 1;
					break;
					}	
			}
			

		}
		if(quest==0)
		{
			printf("NO\n");
		}
}

