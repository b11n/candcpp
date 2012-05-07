#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream.h>
using namespace std;
int main()
{char line[100001];
 char test[100000],temp[100000];
 string x;
 ofstream fout;
 fout.open("seq3out.txt",ios::out);
 long error;
 int no;
 long n,len1,len2,i,j,k,l,sum=0;
 scanf("%d", &no);
 for(n=0;n<no;n++)
 {
 scanf("%s", line);
 scanf("%s", test);

 len1=strlen(line);
 //printf("Len 1:%d\n",len1);
 len2=strlen(test);
 //printf("Len 2:%d\n",len2);
 for(i=0;i<=(len1-len2);i++)
 {
   for(j=0;j<len2;j++)
   {
    temp[k]=line[i+k];
    k++;
   }
   temp[k]='\0';
   k=0;
   //printf("%s\n",temp);
   error=0;
   while(k<len2)
   {
     if(temp[k]!=test[k])
     error++; 
      //printf("%u",error);
     k++;          
   }
   if(error<2)
   //printf("%u ",i);
   fout<<i;
   k=0;
  }
  //printf("\n");
  fout<<"\n";
  getline(cin,x);
}
  
  scanf("%s", test);
  return 0;
   
 }
