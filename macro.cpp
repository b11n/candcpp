#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
ifstream fin;
bool expanding;
int namtab_ptr=0;
int deftab_ptr=0;
struct namtab{
       char name[10];
       int start;
       int end;
       }namtab[20];

struct deftab{
     char label[10];
     char opcode[10];
     char operand[10];
     
     }deftab[100];

struct argtab{
       char name[10];
       int no;
       char formalparam[10][10];
       char actualparam[10][10];
       }argtab[20];

void processline(char label[],char opcode[],char operand[]);
void define(char name[],char t_operand[]);
void expand(char name[],char t_operand[]);
int searchnamtab(char opcode[]);

int main()
{   char label[10],opcode[10],operand[10];
    expanding=false;
    
    fin.open("macroin.txt",ios::in);
    while(!fin.eof())
    {        fin.getline(label,80,'\t');
             fin.getline(opcode,80,'\t');
             fin.getline(operand,80,'\n');
             
             //cout<<"Label:"<<label<<"\nOpcode:"<<opcode<<"\nOperand:"<<operand<<"\n\n";
            
             processline(label,opcode,operand);
      }
    
    cout<<"\n\nNamtab\n\nName\tStart\tEnd\n";
    for(int i=0;i<namtab_ptr;i++)
    cout<<namtab[i].name<<"\t"<<namtab[i].start<<"\t"<<namtab[i].end<<"\n";
    cout<<"\n\nArgtab\n\nName\tNo\tArgs\n";
    for(int i=0;i<namtab_ptr;i++)
    {cout<<argtab[i].name<<"\t"<<argtab[i].no<<"\t";
     for(int j=0;j<argtab[i].no;j++)
     cout<<argtab[i].formalparam[j]<<"\t";
     cout<<"\n";
     }
    cout<<"Deftab\n\n";
    for(int j=0;j<deftab_ptr;j++)
    cout<<j<<":"<<deftab[j].label<<"\t"<<deftab[j].opcode<<"\t"<<deftab[j].operand<<"\n";
    getch();
return 0;
}
              
void processline(char label[],char opcode[],char operand[])
{
    int found=searchnamtab(opcode);
    if(found==1)
         expand(opcode,operand);
    else if(strcmp(opcode,"MACRO")==0)
         define(label,operand);
    else
    cout<<label<<"\t"<<opcode<<"\t"<<operand<<"\n";
}                
                     
void define(char name[],char t_operand[])

{   
    char label[20],opcode[20],operand[20];
    strcpy(namtab[namtab_ptr].name,name);
    strcpy(argtab[namtab_ptr].name,name);
    namtab[namtab_ptr].start=deftab_ptr;
    char spl[20],arg[20][20];
    int i=0;
    int j=0;
    int k=0;
    while(i<=strlen(t_operand))
    {
     if(t_operand[i]==',' || t_operand[i]=='\0')
     {
      spl[j]='\0';
      strcpy(arg[k],spl);
      j=0;
      k++;
      }
      else
      {spl[j]=t_operand[i];
       j++;
       
      }
      i++;
     }  
     argtab[namtab_ptr].no=k;
     for(i=0;i<k;i++) 
     strcpy(argtab[namtab_ptr].formalparam[i],arg[i]);
    int level=1;
    char line[80];
    while(level>0)
    {
                  strcpy(line,"");
                  fin.getline(label,80,'\t');
                  fin.getline(opcode,80,'\t');
                  fin.getline(operand,80,'\n');
                  
                  
                  
                  if(strcmp(opcode,"MEND")==0)
                  {
                       break;
                       
                  }
                  strcpy(deftab[deftab_ptr].label,label);
                  strcpy(deftab[deftab_ptr].opcode,opcode);
                  strcpy(deftab[deftab_ptr].operand,operand);
                  deftab_ptr++;
    }
    namtab[namtab_ptr].end=(deftab_ptr-1);
    namtab_ptr++;
 }
 
 
void expand(char name[],char t_operand[])
 {  char spl[20],arg[20][20];
    int i=0;
    int j=0;
    int k=0;
    while(i<=strlen(t_operand))
    {
     if(t_operand[i]==',' || t_operand[i]=='\0')
     {
      spl[j]='\0';
      strcpy(arg[k],spl);
      j=0;
      k++;
      }
      else
      {spl[j]=t_operand[i];
       j++;
       
      }
      i++;
     }
     char temp[50];
     int l;
     for(l=0;l<namtab_ptr;l++)
      if(strcmp(namtab[l].name,name)==0)
      break; 
    for(i=0;i<k;i++) 
    strcpy(argtab[l].actualparam[i],arg[i]);
     
    for(i=0;i<namtab_ptr;i++)
    {if(strcmp(namtab[i].name,name)==0)
       {for(j=namtab[i].start;j<=namtab[i].end;j++)
        {for(k=0;k<argtab[i].no;k++)
          { if(strcmp(argtab[i].formalparam[k],deftab[j].operand)==0)
            { strcpy(temp,argtab[i].actualparam[k]);
              break;
            }
            strcpy(temp,deftab[j].operand);
          }
        
        cout<<deftab[j].label<<"\t"<<deftab[j].opcode<<"\t"<<temp<<"\n";
       }
       }
    }
 }
  
  
int searchnamtab(char opcode[])
{    
     for(int i=0;i<namtab_ptr;i++)
      {if(strcmp(namtab[i].name,opcode)==0)
       return 1;
       }
      
      return 0;
             
 }
