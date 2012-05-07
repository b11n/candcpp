#include<iostream.h>
#include<conio.h>
struct prod{
       char lhs;
       char rhs[20];
       }production[20];

int nop;
char list[20];
int no_list=0;
char follow[20][10];

void findfirst(char X,int n)
{
     
}
int main()
{ 
    int i,n;
    
    cout<<"Enter number of productions\n";
    cin>>nop;
    n=nop;
    for(i=0;i<n;i++)
    {
                    cout<<"Enter LHS for production no "<<i+1;
                    cin>>production[i].lhs;
                    cout<<"Enter RHS for production no "<<i+1;
                    cin>>production[i].rhs;
                    }
    cout<<"\nProductions are\n";
    for(i=0;i<n;i++)
    cout<<production[i].lhs<<"->"<<production[i].rhs<<"\n";
    
    //char follow[10][10];

    for(i=0;i<nop;i++)
    {
     if(production[i].lhs>='A' && production[i].lhs<='Z')
      { list[no_list]=production[i].lhs;
        no_list++;
        }             
      } 
    cout<<"Terminals are\n";
    for(i=0;i<no_list;i++)
    {
                               cout<<list[i]<<"\n";
                               findfirst(list[i],i);
    }
    getch();
    return 0;
}

     
