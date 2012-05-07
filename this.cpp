#include<iostream.h>
#include<conio.h>
#include<string.h>
class person{int age;
             char name[10];
             public:
                    person greater(person x)
                    {if(x.age>age)
                     return x;
                     else
                     return *this;
                     }
                     void display()
                     {cout<<name<<endl<<age<<endl;
                     }
                     person()
                     {
                     }
                     person(int x,char name1[])
                     {strcpy(name,name1);
                      age=x;
                      }
                     };
int main()
{person p1(110,"abc");
person p2(12,"def");
cout<<"endlp1=";
p1.display();
cout<<"endlp2=";
p2.display();
cout<<"endl Greater=";
 person p3;
 p3=p1.greater(p2);
 p3.display();
 getch();
 return 0;
}
