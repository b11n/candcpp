#include<conio.h>
#include<iostream.h>
#include<string.h>
class word{
           char str[40];
           public:
                  word()
                  {}
                  word(char temp[])
                  {strcpy(str,temp);
                  }
                  word operator-(word s)
                  {word temp;
                       strcat(str,s.str);
                       
                       strcpy(temp.str,str);
                       return temp;
                       }
                       void display()
                       {cout<<str;
                       }
                       
                  
                  };

int main()
{word p1("apple");
 word p2("ball");
 word p3=p1-p2;
 p3.display();
 getch();
 return 0;
}
