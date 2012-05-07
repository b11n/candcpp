#include<iostream>
#include<string.h>
using namespace std;
int main()
{   char dna[100000],virus[100000];
    int flag2,flag,len1,len2,runs,i,j,k,l,m,error;
    cin>>runs;
    for(i=0;i<runs;i++)
    {                  flag2=0;
                       cin>>dna;
                       cin>>virus;
                       len1=strlen(dna);
                       len2=strlen(virus);
                       j=0;
                       while(j<=len1-len2)
                       {error=0;
                        flag=0;
                        for(m=len2-1;m>=0;m--)
                        {
                         if(dna[j+m]!=virus[m])
                         error++;
                         if(error>1)
                         {
                          flag=1;
                          break;
                         }
                        }
                        if(flag==0)
                        {cout<<j<<" ";
                         flag2=1;
                        }
                        j++; 
                       }
                       if(flag2==0)
                       cout<<" ";
                       cout<<"\n";


    }
return 0;
}
