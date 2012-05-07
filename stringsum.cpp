#include<iostream>
#include<string.h>
using namespace std;
int main()
{   long long int no,i;
    char str[20];
    
    cin>>no;
    for(i=0;i<no;i++);
    sprintf(str, "%lld", no);
    int sum2,sum=0;
    sum2=0;
    i=0;
    while(str[i]!='\0')
    {
     sum+= str[i]-'0';
     sum2+=(str[i]-'0')*(str[i]-'0');
     i++;
    }
    cout<<"Sum :"<<sum<<" Sum2 :"<<sum2;
    cin>>sum;
return 0;
}
