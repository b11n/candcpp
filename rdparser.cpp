#include<iostream.h>
#include<conio.h>
char str[20];
int ptr=0;
int T();
int E1();
int T1();
int F();
int E()
{
    int flag=0;
    flag=T();
    if(flag==1)
    flag=E1();
    if(flag==1)
    return 1;
    else 
    return 0;
}
int T()
{
    int flag=0;
    flag=F();
    if(flag==1)
    flag=T1();
    if(flag==1)
    return 1;
    else
    return 0;
}
int F()
{   int flag;
    if(str[ptr]=='(')
    {
                     ptr++;
                     flag=E();
                     if(flag==1 && str[ptr]==')')
                     {
                                ptr++;
                                return 1;
                     }
                     else
                     return 0;
     }
     else if(str[ptr]>='a' && str[ptr]<='z')
     {                     ptr++;
                           return 1;
                           }
     else 
     return 0;
}
int E1()
{
     int flag;
     if(str[ptr]=='+')
     {
                      ptr++;
                      flag=T();
                      if(flag==1)
                      flag=E1();
                      if(flag==1)
                      return 1;
                      else 
                      return 0;
     }
     else
     {
         if(str[ptr]==')' || str[ptr]=='\0')
         return 1;
         else
         return 0;
     }
}
int T1()
{int flag;
     if(str[ptr]=='+')
     {
                      ptr++;
                      flag=F();
                      if(flag==1)
                      flag=T1();
                      if(flag==1)
                      return 1;
                      else 
                      return 0;
     }
      else
     {
         if(str[ptr]==')' || str[ptr]=='+' || str[ptr]=='\0')
         return 1;
         else
         return 0;
     }                
                                
}
int main()
{
    cout<<"Enter String\n";
    cin>>str;
    int flag=E();
    if(flag==1)
    cout<<"ACCEPTED\n";
    else 
    cout<<"Not Accepted";
getch();
return 0;
}
                    
