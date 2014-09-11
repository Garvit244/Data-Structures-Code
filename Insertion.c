#include<stdlib.h>
#include<stdio.h>
#define MAX 20

main()
{
     int arr[MAX],i,j,k,n;
     printf ("\nEnter the no. of elements : ");
     scanf ("%d",&n);
     for (i = 0; i < n; i++)
     {
         printf ("\nEnter element %d : ",i+1);
         scanf ("%d", &arr[i]);
     }
     printf ("\nUSL is :\n");
     for (i = 0; i < n; i++)
     printf ("%d ", arr[i]);
     printf ("\n");

            for(j=1;j < n;j++)
            {
                      k=arr[j]; 
                      for(i=j-1; i>=0 && k<arr[i]; i--)
                      {
                                 arr[i+1]=arr[i];
                      }
                      arr[i+1]=k;
                      printf ("\nPass %d, Element to be inserted in proper place: %d\n",j,k);
                      for (i = 0; i < n; i++)
                      printf ("%d ", arr[i]);
                      printf ("\n");
            }
            printf ("\nSL is :\n");
            for (i = 0; i < n; i++)
            printf ("%d ", arr[i]);
            
}
