#include<iostream>
long long int factorial(long i)
{
long long int k,j;
k=1;
for(j=1;j<i;j++)
  {
  k=k*(j+1);
  }
return k;
}
int main()
{   long n;
    scanf("%u",&n);
    long long int f;
    f=factorial(n);
    printf("\n%u",f);
    scanf("%u",&n);
    return 0;
}
