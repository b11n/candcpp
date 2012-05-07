#include<iostream>
#include<string.h>
int main()
{char line[100001];
 char temp[100000];
 long no,i,j,k,l,sum=0;
 scanf("%d",&no);


 
 for(l=0;l<no;l++)
 { scanf("%s", line);
  sum=0;
 //printf("%l",strlen(line));                
 for(i=0;i<strlen(line);i++)
 { k=0;
   
   for(j=i;j<strlen(line);j++)
    {if(line[j]==line[k])
     k++;
     else
     break;
    }
    sum+=k;
    
}
 printf("%u\n",sum);
}

 return 0;
}
