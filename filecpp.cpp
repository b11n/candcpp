#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
void entercontent()
{ofstream fout;
 char ch;
 fout.open("data.txt");
 while(ch!='*')
 {
               ch=getchar();
               if(ch=='*')
               break;
               fout<<ch;
}
fout.close();
}
void removespace()
{ifstream fin;
 ofstream fout;
 char ch,ch2[80];
 int i,k,len;
 fout.open("data2.txt");
 fin.open("data.txt");
 while(!fin.eof())
 {
                  fin.getchar(ch);
                  if(fin.eof())
                  break;

 if(ch[i]!=' ')
 fout<<ch;
                           
                  
}  
fout.close();
fin.close();
}
void displaycontents(char str[])
{
 ifstream fin;
 char ch[80];
 fin.open(str);
 while(!fin.eof())
 {
                  fin.getline(ch,80);
                  if(fin.eof())
                  break;
                  puts(ch);
                  
 }
fin.close();     
}
int main()
{cout<<"enter contents into the file\n";
entercontent();
cout<<"Contents of file are\n";
displaycontents("data.txt");
getch();
removespace();
cout<<"\nContents of file after removing spaces are\n";
displaycontents("data2.txt");
getch();
return 0;
}
