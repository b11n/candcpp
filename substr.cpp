#include<iostream>
#include<string.h>
using namespace std;
char S[100000][2000];
int n=0;
int searchstr(char s[])
{
    for(int i=0;i<n;i++)
    {if(strcmp(s,S[i])==0)
     return 1;
    }
    return 0;
}

int main()
{   int i,j,k,l,m;

    
    char one[2000];
    char two[2000];
    int runs;
    cin>>runs;
    for(k=0;k<runs;k++)
    {
    
    cin>>one;
    int len=strlen(one);
    for(i=0;i<len;i++)
    {
                      for(j=1;j<=len;j++)
                      {
                                        if(j+i<=len)
                                        {
                                                    
                                                    for(m=0,l=i;l<(j+i);l++,m++)
                                                    two[m]=one[l];
                                                    two[m]='\0';
                                                    if(searchstr(two)!=1)
                                                    {
                                                      strcpy(S[n],two);
                                                      n++;                    
                                                    }
                                        }
                      }
    }
    }
    
  char temp[2000];

	  for(int j=1;j<n;j++)
	  {
		  strcpy(temp,S[j]);
		  i=j-1;		  

		   while(strcmp(S[i],temp)>0 && i>=0)
		  {
			  strcpy(S[i+1],S[i]);
			  i--;
		  }  ;

		  
		  strcpy(S[i+1],temp);
	  }


 int pos; 
 cin>>runs;
 for(i=0;i<runs;i++)
 {cin>>pos;
  if(pos<=n)
  cout<<S[pos-1]<<"\n";
  else
  cout<<"INVALID\n";
}
cin>>i;
 return 0;
}
