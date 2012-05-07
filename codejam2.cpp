#include<iostream>
#include<conio>
#include<fstream>
#include<math>
int diff(int a,int b,int c)
{
    if(abs(a-b)>2 ||abs(b-c)>2 ||abs(a-c)>2)
    return 3;
    if(abs(a-b)=2 ||abs(b-c)=2 ||abs(a-c)=2)
    return 2;
    else
    return 1;
}
int main()
{    int test,t=0;
     char ch;
     ifstream fin;
     fin.open("inp3.txt",ios::in);
     int temp2=0;
     int nos=0,bench;
     fin>>test;
     int act,spl=0;
     int s,no,total,first,second,third;
     while(t<test)                 
      {fin>>no;
       fin>>s;
       fin>>bench;
       for(int i=0;i<no;i++)
       {
        fin>>total;
        first=total/3;
        second=bench;
        third=total-(second+first);
        cout<<first<<"+"<<second<<"+"<<third<<"\t";
        if(first>=bench)
        nos++;
        
        else if(diff(first,second,third)<=2 )
        {
             nos++;
             }
        else
        {//do nothing
        }
        
       }
       cout<<" "<<nos+s<<"\n";
       nos=0;
       t++;                           
      }                
     getch();
     return 0;
}
