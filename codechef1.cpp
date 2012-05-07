#include<stdio.h>
int main()
{
    int with;
    float bal;
    scanf("%d",&with);
    scanf("%f",&bal);
    if(bal-with>=0.5 && with%5==0)
    printf("%4.2f",(float)(bal-with-0.5));
    else 
    printf("%4.2f",bal);
return 0;
}
    
