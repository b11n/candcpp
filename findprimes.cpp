#include<iostream>
#include<math.h>
using namespace std;
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
    int i,count=0;
    for(i=1;i<1500;i++)
    {if(IsPrime(i))
    {cout<<i<<"\n";
     count++;

}

}
 cout<<"Count :"<<count;
    cin>>i;
return 0;
}
