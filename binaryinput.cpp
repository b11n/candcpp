#include <stdio.h>
int main ()
{ char buffer [33];
  int x;
  scanf("%d",&x);
  x=x^10;
  printf("%d",x);
  scanf("%d",&x);
  
  return 0;
}
