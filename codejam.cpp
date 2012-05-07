#include<iostream.h>
#include<conio.h>
#include<fstream.h>
char key[26];
char map[27]="yhesocvxduiglbkrztnwjpfmaq";
int main()
{   char ch;
    char instr[1000],outstr[1000];
    int i,j,k;
    //cout<<"Input String\n";
    //gets(instr);
    for(i=0,ch='a';ch<='z';i++,ch++)
    key[i]=ch;
    cout<<"Successful key creation\n";
    for(i=0;i<26;i++)
    cout<<key[i];
    /*for(i=0;i<strlen(instr);i++)
    {for(j=0;j<26;j++)
     {if(instr[i]==key[j])
      {map[j]=outstr[i];
       k++;
       break;
       }
      }
     }*/
     
    ofstream fout;
    fout.open("codejamoutput.txt",ios::out);
    cout<<"\n";
    for(i=0;i<26;i++)
    cout<<map[i]; 
    cout<<"\n\n";
    fstream fin;
    fin.open("A-small-attempt8.in",ios::in);
    char temp[100];
    fin.getline(temp,'\n');
    int n=atoi(temp);
    cout<<n<<"\n";
    int l=1;
    fout<<"Case #"<<l<<": ";
    int count=0;
while(l<=n)
{fin.get(ch);
 if(fin.eof())
 break;
 if(ch==' ')
 {count++;
 fout<<" ";
 } 
 
 if(ch=='\n' || count ==100)
 {
             
             l++;
             if(l==31)
             break;
             fout<<"\n";
  fout<<"Case #"<<l<<": ";
  
  
  count=0;
 }
 else
 {
     for(j=0;j<26;j++)
      {if(ch==key[j])
      {fout<<map[j];
       count++;
      }
      }
     }
}

/*
{fin.getline(temp,100,'\n');
     if(fin.eof())
     break;
    fout<<"Case #"<<l<<": ";
    for(i=0;i<=strlen(temp);i++)
    {if(temp[i]==' ')
     fout<<" ";
     else
     {
     for(j=0;j<26;j++)
      {if(temp[i]==key[j])
      fout<<map[j];
      }
     }
     }
     l++;
     fout<<"\n";
} 
*/

fout.close();
getch();
return 0;
}
     
    
    
    
