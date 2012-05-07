#include<iostream.h>
#include<conio.h>
#include<fstream.h>

int main()
{long i;
 ofstream fout;
 fout.open("gen.txt",ios::out);
 for(i=0;i<50000;i++)
 fout<<"ab";
getch();
return 0;
}
