#include<iostream.h>
#include<conio.h>
int main()
{int *p;
int i,j;

p=new int[3];

 for(j=0;j<3;j++)
 { *(p+j)=j*10   ;
      cout<<*(p+j)<<"\n";      
}       
getch();
return 0;

}
