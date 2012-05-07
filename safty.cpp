#include<conio.h>
#include<iostream.h>
int main()
{int i,j,AVAIL[3],MAX[5][3],ALLOC[5][3],NEED[5][3];
 cout<<"Enter Max\n";
 for(i=0;i<5;i++)
 for(j=0;j<3;j++)
 cin>>MAX[i][j];
 
  cout<<"Enter Alloc\n";
 for(i=0;i<5;i++)
 for(j=0;j<3;j++)
 {cin>>ALLOC[i][j];
  NEED[i][j]=MAX[i][j]-ALLOC[i][j];
}

cout<<"NEED=\n";
 for(i=0;i<5;i++)
 {for(j=0;j<3;j++)
  cout<<NEED[i][j]<<" ";
  cout<<"\n";
}
cout<<"Enter Available\n";
for(i=0;i<3;i++)
cin>>AVAIL[i];
int k,FINISH[5];
for(i=0;i<5;i++)
FINISH[i]=0;
int flag;
while(1)
{
        for(i=0;i<5;i++)
        {  flag=1;
                         for(j=0;j<3;j++)
                         {if(NEED[i][j]>AVAIL[j])
                          {flag=0;
                          break;
                          }
                           }
                           if(FINISH[i]==0&&flag==1)
                           {cout<<i;
                            FINISH[i]=1;
                            for(k=0;k<3;k++)
                            AVAIL[k]+=ALLOC[i][k];
                            }
                            }
}

 getch();
 return 0; 
}
