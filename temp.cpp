#include <dos.h> // For sleep()
#include <iostream.h> // For I/0
#include <windows.h> // FOR MessageBox() API
#include <conio.h>

#define MAX 10 // MAXIMUM STACK CONTENT

template <class T> // Using Templates so that any type of data can be
// stored in Stack without multiple defination of class
class stack
{

protected:

T arr[MAX]; // Contains all the Data

public:
T item,r;
int top; //Contains location of Topmost Data pushed onto Stack
stack() //Constructor
{
for(int i=0;i<MAX;i++)
{
arr[i]=NULL; //Initialises all Stack Contents to NULL
}

top=-1; //Sets the Top Location to -1 indicating an empty stack
}

void push(T a) // Push ie. Add Value Function
{
top++; // increment to by 1
if(top<MAX)
{
arr[top]=a; //If Stack is Vacant store Value in Array
}
else // Bug the User
{
MessageBox(0,"STACK IS FULL","STACK WARNING!",MB_ICONSTOP);
top--;
}
}

T pop() // Delete Item. Returns the deleted item
{
if(top==-1)
{
MessageBox(0,"STACK IS EMPTY","WARNING",MB_ICONSTOP);
return NULL;
}
else
{
T data=arr[top]; //Set Topmost Value in data
arr[top]=NULL; //Set Original Location to NULL
top--; // Decrement top by 1
return data; // Return deleted item
}
}
};


void main()
{
stack <int>a; // Create object of class a with int Template
int opt=1;
while (opt!=3)
{
clrscr();
cout<<" MAX STACK CAPACITY="<<((MAX-a.top)-1)<<"";
cout<<"1) Push Item";
cout<<"2) Pop Item";
cout<<"3) Exit";
cout<<"Option?";
cin>>opt;
switch(opt)
{
case 1:
cout<<"Which Number should be pushed?";
cin>>a.item;
a.push(a.item);
break;

case 2:
a.r=a.pop();
cout<<"Item popped from Stack is:"<<a.r<<endl;
sleep(2);
break;
}
}
}
