#include<iostream.h>
#include<conio.h>
int main()
{
int i=3,j=4,k;
asm{
 mov ax,i;
 add ax,j;
 mov k,ax;
}
cout<<k;
getch();
return 0;

}
