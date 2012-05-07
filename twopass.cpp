#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
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
		};
intermediate l1;
struct filedetails{
	char name[10];
	int start;
	int len;
	}f1;

symboltable symtab[100];
int s_count=0;

void insert_symtab(char *t_sym,int t_adr)
{

			strcpy(symtab[s_count].symbol,t_sym);
			symtab[s_count].adr=t_adr;
			s_count++;

}
int search_symtab(char *t_sym)
{    int found=0;
     for(int i=0;i<s_count;i++)
     {
	     if(strcmp(symtab[i].symbol,t_sym)==0)
	     {
	     found=1;
	     break;
	     }
     }
     return(found);
}
int main()
{//clrscr();
ifstream fp;
ofstream fout;
fout.open("sicinter.dat",ios::binary|ios::out);
fp.open("sic.txt",ios::in);
char word[20];
char label[10];
char opcode[10];
char t_opcode[10];
char oprand[10];
int start_add=0;
int locctr=0;
int k,i=0;
fp.getline(word,80,'\t');
while(!fp.eof())
{

 i++;
 if(i==1)
 {if(word[0]=='\n')
  for(k=0;k<=strlen(word);k++)
  word[k]=word[k+1];
  strcpy(label,word);
 // cout<<"LABEL  "<<label<<"\n";
 // cout<<"Label Length"<<strlen(label)<<"\n";

 }
 if(i==2)
 {strcpy(opcode,word);
 //cout<<"OPCODE "<<opcode<<"\n";
 strcpy(t_opcode,opcode);
 }
 if(i==3)
 {strcpy(oprand,word);
 //cout<<"OPRAND "<<oprand<<"\n";
 int x=atoi(oprand);
 //cout<<x<<"\n\n";
//cout<<locctr<<"\t"<<label<<"\t"<<opcode<<"\t"<<oprand<<"\n";
l1.loc=locctr;
strcpy(l1.label,label);
strcpy(l1.opcode,opcode);
strcpy(l1.oprand,oprand);
fout.write((char*)&l1,sizeof(struct intermediate));

 //First Pass Start
 if(strcmp(opcode,"START")==0 && strlen(oprand)!=0)//if opcode=start
 {
      start_add=x;
      locctr=x;
      strcpy(f1.name,label);
 }
 if(strlen(label)!=0) //if symbol
   { int t=search_symtab(label);
     if(t==1)
     {cout<<"Duplication Error for "<<label<<"\n";
      exit(0);
     }
     else
     {
      insert_symtab(label,locctr);
     }


  }//end if symbol

 opcodesearch(t_opcode);
 if(strcmp(t_opcode,"NOTFOUND")!=0)//found
   locctr+=3;
 else
 {if(strcmp(opcode,"WORD")==0)
    locctr+=3;

  else if(strcmp(opcode,"RESW")==0)
    locctr=locctr+(3*x);


 else if(strcmp(opcode,"RESB")==0)
    locctr+=x;
 else if(strcmp(opcode,"BYTE")==0)
    locctr=locctr+((strlen(oprand))-3);
 else if(strcmp(opcode,"START")==0 || strcmp(opcode,"END")==0)
 {locctr+=0;
 }
 else
   cout<<"Invalied Opcode "<<opcode<<"\n";
   }


 i=0;

 }

 fp.getline(word,80,'\t');
}
 fp.close();
 fout.close();

 ifstream fin;
 fin.open("sicinter.dat",ios::in|ios::binary);
 while(!fin.eof())
 {fin.read((char*)&l1,sizeof(intermediate));
  if(fin.eof())
  break;
  cout<<l1.loc<<"\t"<<l1.label<<"\t"<<l1.opcode<<"\t"<<l1.oprand<<"\n";
 }
 fin.close();

 fout.open("sicsymtab.dat",ios::out|ios::binary);
 cout<<"\n\nSYMTAB\n";
 symboltable s1;
 for(i=0;i<s_count;i++)
 {  s1=symtab[i];
   //cout<<s1.symbol<<"\t"<<s1.adr<<"\n";

  fout.write((char*)&s1,sizeof(symboltable));
 }
 fout.close();

 fin.open("sicsymtab.dat",ios::in|ios::binary);
 while(!fin.eof())
 {fin.read((char*)&s1,sizeof(symboltable));
  if(fin.eof())
  break;
  cout<<s1.symbol<<"\t"<<s1.adr<<"\n";
 }
 fin.close();
 f1.start=start_add;
 f1.len=locctr-start_add;
 cout<<"Program Name :"<<f1.name<<"\n";
 cout<<"Program Length: "<<f1.len;
 fout.open("sicdetails.dat",ios::out|ios::binary);
 fout.write((char*)&f1,sizeof(filedetails));
 fout.close();
 getch();
 return 0;

}


