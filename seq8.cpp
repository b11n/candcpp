#include<iostream>
using namespace std;
int main()
{int no;
 long xpt[100000];
 long ypt[100000];
 long k,i,q,on,tw,th,fo;
 scanf("%d",&no);
 for(i=0;i<no;i++)
 {scanf("%d",&xpt[i]);
  scanf("%d",&ypt[i]);
 }
 scanf("%d",&q);
 char c;
 k=0;
 int a,b;
 while(k<q)
 {
  cin>>c;
  scanf("%ld",&a);
  scanf("%ld",&b);
  if(c=='X')
{
      

      for(i=a-1;i<b;i++)
      {
           ypt[i]=-(ypt[i]);           
      }
}
  else if(c=='Y')
  {
      
      
      for(i=a-1;i<b;i++)
      {
           xypt[i]=-(xpt[i]);           
      }
   }
  else
  {
     
     on=tw=th=fo=0;
     for(i=a-1;i<b;i++)
     {if(xpt[i]>0 && ypt[i]>0)
      on++;
      else if(xpt[i]<0 && ypt[i]>0)
      tw++;
      else if(xpt[i]<0 && ypt[i]<0)
      th++;
      else
      fo++;
      }
      printf("%d %ld %ld %ld\n",on,tw,th,fo);
}
  
  k++;
 } 

 return 0;
}
