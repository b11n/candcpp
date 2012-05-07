#include<iostream.h>
#include<conio.h>
template <class T>
class demo{
      T x;
      public:
      demo()
      {cin>>x;
      }
      void add()
      {x=x+x;
      cout<<x;
      }
      };
      int main()
      {
          demo <int> obj;
          obj.add();
          demo <char> obj2;
          obj2.add();
          getch();
          return 0;
      }
