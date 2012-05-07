#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
void tohex(int x,char res[])
{    int i,k=0;
     char ch;
     int temp1,temp2;
     char temp[10];
     while(x>0)
     {
     temp2=x%16;
     if(temp2<10)
     {for(i=0,ch='0';i<10;i++,ch++)
      if(i==temp2)
      {temp[k]=ch;
     k++;
      }
     }
     if(temp2>=10)
     {for(i=10,ch='A';i<16;i++,ch++)
      if(i==temp2)
      {temp[k]=ch;
       k++;
      }
     }
     
     x=x/16;
     }
     temp[k]='\0';
     strrev(temp);
     strcpy(res,temp);
     cout<<temp<<"\n";
     
}
int main()
{    char word[20];
     ifstream fin;
     fin.open("input.txt",ios::in);
     while(!fin.eof())
     {
                      fin.getline(word,80,'\t');
                      
                      cout<<word<<"\n";
                      if(fin.eof())
                      break;
                    }
                     char res[20]; 
     tohex(1000,res);
     cout<<res;
     getch();
return 0;
}
