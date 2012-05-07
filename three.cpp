#include<iostream.h>
#include<conio.h>
#include <windows.h> 
int main()
{
    int i,j,k;
    char ch;
    int A[10][10][10];
    for(i=0;i<2;i++)
    {
                    for(j=0;j<2;j++)
                    {
                                    for(k=0;k<2;k++)
                                    {
                                                    cout<<"Do you want to enter in["<<i<<"]["<<j<<"]["<<k<<"]\n";
                                                    cin>>ch;
                                                    if(ch=='y')
                                                    {cout<<"Enter ["<<i<<"]["<<j<<"]["<<k<<"]\n";
                                                     cin>>A[i][j][k];
                                                    }
                                                    else
                                                    A[i][j][k]=0;
                                    }
                    }
    }
    
    
     for(i=0;i<2;i++)
    {
                    for(j=0;j<2;j++)
                    {
                                    for(k=0;k<2;k++)
                                    {cout<<A[i][j][k]<<",";
                                    }
                                    cout<<"\t";
                    }
                    cout<<"\n";
    }
    system("%windir%\explorer.exe");
        getch();  
    return 0;
}

                     
