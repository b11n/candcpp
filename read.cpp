#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
int main()
{
    ofstream fout;
    fout.open("macroin.txt",ios::out);
    char line[80];
    while(1)
    {gets(line);
     if(strcmp(line,"Q")==0)
     break;
     fout<<line;
     fout<<"\n";
     }
fout.close();
return 0;
}
