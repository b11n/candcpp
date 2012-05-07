/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <stdio.h>
int main ()
{   int l,t,max,i,j,a,p,q,n,runs,arr[100000];
    scanf("%d",&t);
    for(l=0;l<t;l++)
    {
    scanf("%d",&n);
    
    scanf("%d",&runs);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    for(i=0;i<runs;i++)
    {
                    scanf("%d",&a);
                    scanf("%d",&p);
                    scanf("%d",&q);
                    max=a^arr[p-1];
                    for(j=p;j<q;j++)
                    {
                     if((a^arr[j])>max)
                     max=a^arr[j];
                    }
                    printf("%d\n",max);
    }
}
return 0;
}
