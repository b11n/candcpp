#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
class student{
                int no;
                char name[20];
                public:
                       void getdata()
                       {cout<<"Enter name\n";
                        cin>>name;
                        cout<<"Enter number\n";
                        cin>>no;
                        }
                        int getno()
                        {return no;
                        }
                        void putdata()
                        {cout<<"Name :"<<name<<endl;
                         cout<<"No   :"<<no<<endl;
                         }
                         };
void enterdata()
{
     ofstream fout;
     fout.open("database.dat",ios::out|ios::binary|ios::app);
     student temp;
     char ch;
     while(ch!='n')
     {temp.getdata();
      fout.write((char*)&temp,sizeof(class student));
      cout<<"Do you want to continue ? ";
      cin>>ch;
      }
      fout.close();
}
void search()
{cout<<"Enter no";
 int no;
 cin>>no;
 ifstream fin;
 student temp;
 fin.open("database.dat",ios::in|ios::binary);
 while(!fin.eof())
 {fin.read((char*)&temp,sizeof(class student));
  if(fin.eof())
  break;
  if(no==temp.getno())
  {cout<<"Found,Details\n";
   temp.putdata();
  }
}
fin.close();
}

void replacerec()
{cout<<"Enter no";
 int no;
 cin>>no;
 fstream fin;
 int flag=0;
 student temp;
 long int pos=sizeof(class student);
 pos=0-pos;
 fin.open("database.dat",ios::out|ios::in|ios::binary);
 while(!fin.eof())
 {fin.read((char*)&temp,sizeof(class student));
  if(fin.eof())
  break;
  if(no==temp.getno())
  {cout<<"Found,Details\n";
   temp.putdata();
   cout<<"enter new details\n";
   temp.getdata();
   fin.seekp(pos,ios::cur);
   fin.write((char*)&temp,sizeof(class student));
   cout<<"success\n";
   fin.close();
   break;
 }
}

}
 


  
  int main()
  {int ch;
  while(ch!=3)
  {cout<<"\n1.enter\n2.search\n3.quit\n4.replace\n";
  cin>>ch;
  switch(ch)
  {case 1:enterdata();
  break;
  case 2:search();
  break;
  case 4:replacerec();
       break;
  case 3:break;
}
}
return 0;
}
              
