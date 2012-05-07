#include<iostream.h>
#include<conio.h>
#define MAX 10

template <class T>
class stack{    T arr[MAX];
                public:
                       int top;
                       void push(T item)
                       {if(top>=MAX)
                        cout<<"Stack overflow\n";
                        else
                        {
                            top++;
                            arr[top]=item;
                        
                        }
                        }
                        void pop()
                        {
                         if(top<0)
                         cout<<"Underflow\n";
                         else
                         {
                          cout<<"popped elemet is "<<arr[top];
                          top--;
                          
                          }
                          }
                          stack()
                          {top=-1;
                          }
                          void display()
                          {int i;
                               if(top<0)
                               cout<<"Underflow\n";
                          else
                              {for(i=0;i<=top;i++)
                              cout<<arr[i]<<"\t";
                              }
                           }
                          };
int main()
{stack<int> a;
 stack<float> b;
 int ch1,ch2;
 int x;
 float y;
 while(ch1!=3)
 {cout<<"1.Int 2.Float 3.quit\n";
  cin>>ch1;
           if(ch1==1)
                     {cout<<"1.Push 2.Pop 3.Display";
                                    cin>>ch2;
                                    if(ch2==1)
                       {
                        cout<<"enter item to be pushed";
                        cin>>x;
                        a.push(x);
                       }
                       if(ch2==2)
                       a.pop();
                       if(ch2==3)
                       a.display();
                       }
           if(ch1==2)
           {cout<<"1.Push 2.Pop 3.Display";
                      cin>>ch2;
                      if(ch2==1)
                       {
                       cout<<"enter item to be pushed";
                       cin>>y;
                       b.push(y);
                       }
                       if(ch2==2)
                       b.pop();
                       if(ch2==3)
                       b.display();
             }
}
return 0;
}
