#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<iomanip.h>
int main()
{   char line[80],spl[20],arg[20][20];
    int i=0,j=0,k;
    k=0;
    strcpy(line,"ARG1,ARG2,ARG3");
    while(i<=strlen(line))
    {
     if(line[i]==',' || line[i]=='\0')
     {
      cout<<"Comma or End";
      spl[j]='\0';
      strcpy(arg[k],spl);
      j=0;
      k++;
      }
      else
      {spl[j]=line[i];
       j++;
       
      }
      i++;
     }  
     for(i=0;i<k;i++) 
     cout<<arg[i]<<"\n";
     getch();
return 0;
}
