#include<iostream.h>
#include<conio.h>
class box{
        
          int x;
          public:
                 void put()
                 {cout<<"="<<x<<"\n";
                 }
                 box(int t2)
                 {
                  x=t2;
                  }
          
                  /*box operator +(box temp)
                  {box b1(0);
                  b1.x=x+temp.x;
                  return(b1);
                  }*/
                  void operator ++(int)
                  {x++;
                  
                   }
               
                  };
                 int main()
                 {
                     box a(10);
                     box b(20);
                     box c(0);
                     //c=a+b;
                     //c.put();
                     //c=a+b+b+a;
                     //c.put();
                     a++;
                     a.put();
                     getch();
                     return 0;
                     }
