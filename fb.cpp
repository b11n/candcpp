#include<iostream>
using namespace std;
int c;
int warr[1000],barr[1000];
float calcp(int co)
{   float temp,sum=0;
    for(int i=0;i<co;i++)
    {
            
    temp=(warr[i]/(warr[i]+(float)barr[i]));
     sum=sum+temp;
    }
    sum=sum/co;
    return (sum*100);
}
int main()
{
    int j,i,t,c,b,p,wctr=0;
    float t_p;
    int b_no=0;
    int le_flag=0;
    cin>>t;
    for(i=0;i<t;i++)
    {wctr=0;
     b_no=0;
     cin>>c;
     for(j=0;j<c;j++)
     {warr[j]=0;
      barr[j]=0;
     }
     cin>>b;
     cin>>p;
     
     while(b>0)
      {barr[b_no]++;
       b_no++;
       if(b_no==c)
       {b_no=0;
        le_flag=1;
       }
       b--;
      }
      if(le_flag!=1)
      for(j=b_no;j<c;j++)
      {warr[j]++;
       wctr++;
      }
      b_no=0;
      t_p=0;
      //for(j=0;j<c;j++)
      //cout<<warr[j]<<"\t";
      //cout<<"\n";
      //for(j=0;j<c;j++)
      //cout<<barr[j]<<"\t";
      
      
      while(t_p<p)
      {t_p=calcp(c);
      
       if(t_p<p)
       {warr[b_no]++;
        b_no++;
        wctr++;
       }
       if(b_no==c)
       b_no=0;
      for(j=0;j<c;j++)
      cout<<warr[j]<<"\t";
      cout<<"\n";
      for(j=0;j<c;j++)
      cout<<barr[j]<<"\t";
      cout<<"\n";
      cin>>i;
      }
      
      cout<<wctr<<"\n";
     }
      cin>>i;
      return 0;
}
