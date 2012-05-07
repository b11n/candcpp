#include<iostream>
long arr[10000],n;
void swap(long  *a, long *b)
{
  long t=*a; *a=*b; *b=t;
}
void sort(long arr[], long beg, long end)
{
  if (end > beg + 1)
  {
    long piv = arr[beg], l = beg + 1, r = end;
    while (l < r)
    {
      if (arr[l] <= piv)
        l++;
      else
        swap(&arr[l], &arr[--r]);
    }
    swap(&arr[--l], &arr[beg]);
    sort(arr, beg, l);
    sort(arr, r, end);
  }
}
int main()
{
    int i,j,k,count=0;
    scanf("%ld",&n);
    scanf("%ld",&k);
    for(i=0;i<n;i++)
    scanf("%ld",&arr[i]);
    
    sort(arr,0,n);
    
    
    
    for(i=0;i<n;i++)
    {
      for(j=i;j<n;j++)
      {if(arr[j]-arr[i]>k)
       break;
       else if(arr[j]-arr[i]==k)
       break;
      }              
    }
    
    printf("%ld",count);
    //scanf("\n%ld",&n);
               
    return 0;
}
