#include <stdio.h>
int main ()
{
  int count,a,b,i,j,k,runs;
  char buffer [33];
  scanf ("%d",&runs);
  for(i=0;i<runs;i++)
  {scanf ("%d",&a);
   scanf ("%d",&b);
   count=0;
   for(j=a;j<=b;j++)
   {
                     sprintf(buffer,"%x",j);
                     for(k=0;buffer[k]!='\0';k++)
                     if(buffer[k]=='1' || buffer[k]=='2' || buffer[k]=='4' || buffer[k]=='8')
                     count++;
                     else if(buffer[k]=='3' || buffer[k]=='5' || buffer[k]=='6' || buffer[k]=='9' || buffer[k]=='a' || buffer[k]=='c')
                     count+=2;
                     else if(buffer[k]=='7' || buffer[k]=='b' || buffer[k]=='d' || buffer[k]=='e')
                     count+=3;
                     else if(buffer[k]=='f')
                     count+=4;
                     else
                     count+=0;
   }
  printf("%d\n",count);
}
  return 0;
}
