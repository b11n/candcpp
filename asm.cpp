#include<iostream.h>
void main()
{
int i=3,j=4,k;
asm{   //'{' this must be put immediate to the 'asm' key word else code showserrors
 mov ax,i;
 add ax,j;
 mov k,ax;
}
cout<<k;
}
