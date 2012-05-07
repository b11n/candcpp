#include<iostream>
int main()
{    
     long long  item,friendly,n;
     scanf("%lld", &n);
     scanf("%lld", &friendly);
     //cout<<"Friendly: "<<friendly<<"\n\n";
     //cout<<"N :"<<n<<"\n\n";
     long long i,j,f_no=0;
     long  factors[100000];
     long long items[100000];
     for(j=1;j<=friendly/2;j++)
     if(friendly%j==0)
     {
      factors[f_no]=j;
      printf("%lld\t",j);
      f_no++;
     }
    
     
     i=0;
  int flag=0;   
     while(i<n)
     {fscanf(stdin, "%lld", &item);
      items[i]=item;
     i++;
     }

     
     
     for(i=0;i<f_no;i++)
     { for(j=0;j<n;j++)
        if(items[j]%factors[i]==0)
        flag=1;
        else
        {flag=0;
         break;
         }
     if(flag==1)
    printf("%lld\t",factors[i]);
     }               
     
return 0;
}
