#include<stdio.h>
int main()
{
    char c,a[18],b[18],query[11];
    int i,n,q;
    bool 
    scanf("%d",&n);
    scanf("%d",&q);
    scanf("%s",a);
    scanf("%s",b);
    fflush(stdin);
    while( q > 0 )
    {
           i=0;
           do
           {c=getchar();
            query[i]=c;
            i++;
            }while(c!='\n');
           query[i]='\0';
           
           if(query[0]=='s')
           {if(query[4]=='a')
             a[query[6]-'0']=query[8];
            else
             b[query[6]-'0']=query[8];
           }
           
           else
           {
           }
           
           q--;
           fflush(stdin);
    }
    return 0;
}
    
