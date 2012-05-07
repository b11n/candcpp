#include<iostream.h>
#include<conio.h>
#include<string.h>

char nfa[10][10][10];
char dfa[10][10][10];
char state[10],symbol[10];
int n_state,n_symbol;
int flag=0;
int len;
char temp[10][10];
int templn=0;




int main()
{
    int i,j,k;
    cout<<"Enter No of States";
    cin>>n_state;
    cout<<"Enter States\n";
    for(i=0;i<n_state;i++)
    cin>>state[i];
    cout<<"Enter No of Symbols";
    cin>>n_symbol;
    cout<<"Enter Symbols\n";
    for(i=0;i<n_symbol;i++)
    cin>>symbol[i];
    cout<<"Enter the nfa table\n";
    for(i=0;i<n_state;i++)
    {
                    for(j=0;j<n_symbol;j++)
                    {cout<<"Enter transitions for state "<<state[i]<<" "<<"symbol "<<symbol[j]<<" :";
                     cin>>nfa[i][j];
                    }
    }
    cout<<"The NFA table is\n\t";
    for(j=0;j<n_symbol;j++)
    cout<<symbol[j]<<"\t";
    cout<<"\n";
    cout<<"---------------\n";
    for(i=0;i<n_state;i++)
    {                cout<<state[i]<<"|\t ";     
                    for(j=0;j<n_symbol;j++)
                    {
                     cout<<nfa[i][j]<<"\t";
                    }
                    cout<<"\n";
    }

    
getch();
return 0;
}


