#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>


struct optab{
       char opcode[10];
       char mcode[10];
       };
       
void opcodesearch(char *opc)
            {                 int found=0;
                              ifstream fin;
                              optab op;
                              fin.open("optab.dat",ios::in|ios::binary);
                               while(!fin.eof())
            {
                             fin.read((char*)&op,sizeof(struct optab));
                             if(fin.eof()==1)
                             break;
                              if(strcmp(op.opcode,opc)==0)
                               {
                                found=1;
                                strcpy(opc,op.mcode);
                                break;
                                                                       
                               }
                             
                             }
                             if(found==0)
                             {
                             strcpy(opc,"NOTFOUND");
                             } 
                             }
int main()
{
    optab op;
    char ch='y';
    ofstream fout;
    fout.open("optab.dat",ios::out|ios::binary|ios::app);
    while(ch!='n')
    {
            cout<<"Enter Opcode:";
            cin>>op.opcode;
            cout<<"Enter Machine code";
            cin>>op.mcode;
            fout.write((char*)&op,sizeof(struct optab));
            cout<<"\n\nDo you wnt to continue?";
            cin>>ch;
                 
                 }
                fout.close();
               
            cout<<"contents of the optab is :\n";
            cout<<"MNEMONIC\tOPCODE\n";
            ifstream fin;
             fin.open("optab.dat",ios::in|ios::binary);
            while(!fin.eof())
            {
                             fin.read((char*)&op,sizeof(struct optab));
                             if(fin.eof()==1)
                             break;
                             cout<<op.opcode<<"\t"<<op.mcode<<"\n";
                             
                             }
              fin.close();               
            
        char str[10]="ADD";                      
        opcodesearch(str);
        cout<<str;
        strcpy(str,"HOW");
        opcodesearch(str);
        cout<<str;         
        getch();
        return 0;         
                 
}
       
