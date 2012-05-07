#include<iostream>
#include<string.h>
using namespace std;
long ctr=0;
struct list {
       char *str;
       list *link;
       };
list *prev,*next,*ptr,*start=NULL;
void add(char *s)
{   
     list *node;
     
     node = (list*)malloc(sizeof(list));
     node->link=NULL;
     node->str= (char *)malloc(sizeof(char) * (strlen(s)+1));
     strcpy(node->str,s);
     int flag=0;
     if(start==NULL)
     {start=node;
      ctr++;
     }
     else
     {   if(strcmp(start->str,s)>0)
         {node->link=start;
          start=node;
          ctr++;
          
         }
         
         else
         {
          prev=start;
          next=start->link;
          while(next!=NULL)
          {if(strcmp(prev->str,s)<0 && strcmp(next->str,s)>0 || strcmp(prev->str,s)==0 )
                            {               if(strcmp(prev->str,s)==0)
                                            {flag=1;
                                            break;
                                            }
                                            else
                                            {prev->link=node;
                                            node->link=next;
                                            ctr++;
                                            flag=1;
                                            break;
                                            }
                              }
           prev=next;
           next=next->link;
           
         }
         if(next==NULL && flag==0)
         {             if(!(strcmp(prev->str,s)==0))
                       {prev->link=node;
                       ctr++;
                       }
          }
      }
        
      
     }

   
}
void display(long n)
{    ptr=start;
     int i=1;
     while(i<n)
     {
      ptr=ptr->link;
      i++;
     }
     cout<<ptr->str<<"\n";
     }
int main()
{
int i,j,k,l,m;

    
    char one[2000];
    char two[2000];
    int runs;
    cin>>runs;
    for(k=0;k<runs;k++)
    {
    
    cin>>one;
    int len=strlen(one);
    for(i=0;i<len;i++)
    {
                      for(j=1;j<=len;j++)
                      {
                                        if(j+i<=len)
                                        {
                                                    
                                                    for(m=0,l=i;l<(j+i);l++,m++)
                                                    two[m]=one[l];
                                                    two[m]='\0';
                                                    add(two);
                                                                          
                                                    
                                        }
                      }
    }
    }
    int pos; 
    cin>>runs;
    for(i=0;i<runs;i++)
    {cin>>pos;
     if(pos<=ctr)
     display(pos);
     else
     cout<<"INVALID\n";
     }
    return 0;
}
