#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include "opcode.h"
struct symboltable{
       char symbol[20];
       int adr;
       };
struct intermediate{
		int loc;
		char label[10];
		char opcode[10];
		char oprand[10];
		}l1;
struct filedetails{
	char name[10];
	int start;
	int len;
	}f1;
symboltable s1;

int searchsymtab(char *sym)
{ifstream fin;
 fin.open("sicsymtab.dat",ios::in|ios::binary);
 int loc,found=0;
 while(!fin.eof())
 {fin.read((char*)&s1,sizeof(symboltable));
  if(fin.eof())
  break;
  if(strcmp(sym,s1.symbol)==0)
  {found=1;
   loc=s1.adr;
   return loc;
   break


   ;
  }
 }
fin.close();
if(found==0)
return (-1);
}
int count=0;
int count2=0;

void writetofile(char *str)
{cout<<str;
 int l=strlen(str);
 count=count+l;
 count2=count2+l;
 if(count==6 && count2 != 60)
 {cout<<"^";
 count=0;
 }
 if(count2==60)
 {count2=0;
  cout<<"\n";
  cout<<"T^";
 }

}
void writetofile(int x)
{int l;
cout<<x;
 if(x<10)
 l=1;
 else if(x<100)
 l=2;
 else if(x<1000)
 l=3;
 else if(x<10000)
 l=4;
 else
 l=0;
 count=count+l;
 count2=count2+l;
 if(count==6 && count2 != 60)
 {cout<<"^";
 count=0;
 }
 if(count2==60)
  {

  count2=0;
  cout<<"\n";
  cout<<"T^";
 }
}
int main()
{//clrscr();
 ifstream fin;
 ofstream fout;
fin.open("sicdetails.dat",ios::in|ios::binary);
 fin.read((char*)&f1,sizeof(filedetails));
 fin.close();
 cout<<"Program Name :"<<f1.name<<"\n";
 cout<<"Program Length: "<<f1.len<<"\n";
 cout<<"Intermediate file for sic.txt\n";

 fin.open("sicinter.dat",ios::in|ios::binary);
 while(!fin.eof())
 {fin.read((char*)&l1,sizeof(intermediate));
  if(fin.eof())
  break;
  cout<<l1.loc<<"\t"<<l1.label<<"\t"<<l1.opcode<<"\t"<<l1.oprand<<"\n";
 }
 fin.close();
 fout.open("sicobjectfile.txt",ios::out);
 cout<<"H^"<<f1.name<<"^"<<f1.start<<"^"<<f1.len<<"\nT^";

 char label[10],opcode[10],oprand[10],mopcode[10];
 int loc;
 char str[150];


 //pass two start
fin.open("sicinter.dat",ios::in|ios::binary);
while(!fin.eof())
 {fin.read((char*)&l1,sizeof(intermediate));
  if(fin.eof())
  break;
  int opradd;
  strcpy(label,l1.label);
  strcpy(opcode,l1.opcode);
  strcpy(mopcode,opcode);
  strcpy(oprand,l1.oprand);
  loc=l1.loc;
 if( strcmp(opcode,"START")!=0 && strcmp(opcode,"END")!=0 )
  {
   opcodesearch(mopcode);
   if(strcmp(mopcode,"NOTFOUND")!=0)
    {
     if(strlen(oprand)!=0)
      { int x=searchsymtab(oprand);
       if(x!=-1)
       {
	 opradd=x;
	 writetofile(mopcode);
	 writetofile(opradd);
       }
       else
       {
	 opradd=0;
       }
      }
     else
     {opradd=0;
      writetofile(mopcode);
      writetofile("0000");
     }

    }
   else if(strcmp(opcode,"BYTE")==0||strcmp(opcode,"WORD")==0)
   {
    if(strcmp(opcode,"BYTE")==0)
    {int temp[5];
     int i,k;
     k=0;
     for(i=2;oprand[i]!='\'';i++)
     {temp[k]=oprand[i];
      writetofile(temp[k]);
      k++;

     }

    }
    if(strcmp(opcode,"WORD")==0)
    {
     if(strlen(oprand)==1)
     writetofile("00000");
     else if(strlen(oprand)==2)
     writetofile("0000");
     else if(strlen(oprand)==3)
     writetofile("000");
     writetofile(oprand);
    }
   }

  }
}//pass two end


getch();
return 0;
}
