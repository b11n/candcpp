#include<iostream.h>
#include<conio.h>
#define size 10
char stack[size],input[size];
int sptr=-1,iptr=-1;
void push(char a[],int &ptr,char item)
{
     if(ptr<size-1)
     {ptr++;
      a[ptr]=item;
     }
     else
     cout<<"Stack Full\n";
}
char pop(char a[],int &ptr)
{    char temp;
     if(ptr<0)
     cout<<"Underflow";
     
     else
     {   temp=a[ptr];
         ptr--;
         return temp;
     }
     return '@';
}
void display(char a[],int ptr)
{    int i;
     if(ptr<0)
     cout<<"Underflow";
     else
     {for(i=0;i<=ptr;i++)
     cout<<a[i]<<"\t";
     
     cout<<"\n";
     }
}

int retno(char ch)
{
    if(ch=='i')
    return 0;
    else if(ch=='+')
    return 1;
    else if(ch=='*')
    return 2;
    else
    return 3;
}
int main()
{   char str[10];
    int m,n;
    cout<<"Enter String to be parsed\n";
    cin>>str;
    char ch,ch2,ch3;
    push(input,iptr,'$');
    for(int i=strlen(str)-1;i>=0;i--)
    push(input,iptr,str[i]);
    
    char ptable[4][4]={     {'-','>','>','>'},
                            {'<','>','<','>'},
                            {'<','>','>','>'},
                            {'<','<','<','-'} };
    char ops[4]={'i','+','*','$'};
    push(stack,sptr,'$');
   
    while(1)
    {
            cout<<input[iptr]<<"\n";
            cout<<stack[sptr]<<"\n";
            m=retno(input[iptr]);
            n=retno(stack[sptr]);
            
            
            ch3=ptable[n][m];
            cout<<m<<n<<ch3<<"\n";
            if(ch3=='<')
            {cout<<"Shift";
             ch=pop(input,iptr);
             push(stack,sptr,ch);
            }
            else if(ch3=='>')
            {ch=pop(stack,sptr);
             if(ch==i)
             ch2=reduce(ch);
            }
            else
            cout<<"else";
            
            
    }
    display(stack,sptr);
    display(input,iptr);
    getch();
}
