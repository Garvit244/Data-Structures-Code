#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int USL[MAX];
void merge(int a, int c, int b )
{
     int temp[MAX];
     int i = a;
     int j = c +1 ;
     int k = a ;
     while((i<=c) && (j<=b))
     {
                       if(USL[i]<=USL[j])
                       temp[k++] = USL[i++] ;
                       else
                       temp[k++] = USL[ j++] ;
     }
     while( i <= c )
     temp[k++]=USL[i++];
     while( j <= b )
     temp[k++]=USL[j++];
     for(i=a; i<=b; i++)
     USL[i]=temp[i];
}

void merge_sort(int a, int b )
{
     int c;
     if(a!=b)
     {
                      c = (a+b)/2;
                      merge_sort( a , c );
                      merge_sort( c+1, b );
                      merge(a, c, b );
     }
}
main()
{
      int i,n;
      printf ("\nEnter the number of elements : ");
      scanf ("%d",&n);
      for (i=0;i<n;i++)
      {
          
          scanf ("%d",&USL[i]);
      }
      printf ("\nUnsorted list is :\n");
      for ( i = 0 ; i<n ; i++)
      printf ("%d ", USL[i]);
      merge_sort(0,n-1);
      printf ("\nSorted list is :\n");
      for ( i = 0 ; i<n ; i++)
      printf ("%d ", USL[i]);
      
}
