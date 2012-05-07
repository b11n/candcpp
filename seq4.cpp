#include<iostream>
char stack[101];
int top=-1;
void push(char x)
{if(top>=100)
 printf("Error\n");
 else
 {top++;
  stack[top]=x;
}
}
char pop()
{
     if(top<0)
     return '*';
     else
     {
      char temp=stack[top];
      top--;
      return temp;   
     }
}
int main()
{   int n; 
    char line[101];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    top=-1;
    scanf("%s",line);
    push(line[0]);
    int i=1;
    char x,y;
    
    while(line[i]!='\0' )
    {
  
    if(stack[top]=='a' && line[i]=='b')
    {x=pop();
     push('c');
    }
    else if(stack[top]=='a' && line[i]=='c')
    {x=pop();
     push('b');
    }
    else if(stack[top]=='b' && line[i]=='a')
    {x=pop();
     push('c');
    }
    else if(stack[top]=='b' && line[i]=='c')
    {x=pop();
     push('a');
    }
    else if(stack[top]=='c' && line[i]=='a')
    {x=pop();
     push('b');
    }
    else if(stack[top]=='c' && line[i]=='b')
    {x=pop();
     push('a');
    }
    else
     push(line[i]);
    
    i++;
    
    while(top>=1 && (stack[top]!=stack[top-1]))
    {x=pop();
     y=pop();
     //printf("X:%c Y:%c \n",x,y);
     if(x=='a')
     {if(y=='b')
      push('c');
      else
      push('b');
     }
     else if(x=='b')
     {if(y=='c')
      push('a');
      else
      push('c');
     }
     else if(x=='c')
     {if(y=='b')
      push('a');
      else
      push('b');
     }
     else
     {
         //do nothing;
     }
    }
    
    push('\0');
    //printf("%s\t%d\t%c\n",stack,top,stack[top-1]);
    x=pop();
}
 while(top>=1 && (stack[top]!=stack[top-1]))
    {y=pop();
     x=pop();
     //printf("X:%c Y:%c \n",x,y);
     if(x=='a')
     {if(y=='b')
      push('c');
      else
      push('b');
     }
     else if(x=='b')
     {if(y=='c')
      push('a');
      else
      push('c');
     }
     else if(x=='c')
     {if(y=='b')
      push('a');
      else
      push('b');
     }
     else
     {
         //do nothing;
     }
    }
push('\0');
printf("%d\n",top);
printf("%s\n",stack);
}
scanf("%d",n);
return 0;
}
     
