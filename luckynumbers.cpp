#include<iostream>
#include<math.h>
bool IsPrime(int num)
{
	if(num<=1)
		return false;
	if(num==2)
		return true;
	if(num%2==0)
		return false;
	double sRoot = sqrt(num*1.0);
	for(int i=3; i<=sRoot; i+=2)
	{
		if(num%i==0)
			return false;
	}
	return true;
}

int main()
{
    int t;
    long long int a,b;
    char str[20];
    int i,c,sum,sq,count;
    long long int n;
    scanf("%d",&t);
    while(t>0)
    {          count=0;
               scanf("%lld",&a);
               scanf("%lld",&b);
               while(a<=b)
               {
                  i=0;
                  sum=sq=0;
                  sprintf(str, "%lld", a);
                  while(str[i]!='\0')
                  {      c=str[i] -'0';
                         sum+=c;
                         c=c*c;
                         sq+=c;
                         i++;
                   }
	            if(IsPrime(sum) && IsPrime(sq))
	            count++;
	            
	
               a++;  
               }
               printf("%d\n",count);
              
    t--;
    }
    scanf("%d",&t);
    return 0;
}
