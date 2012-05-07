#include "stdafx.h"
#include <graphics.h>
#include <conio.h>



int main()
{

int gd=DETECT, gm;
initgraph(&gd,&gm,"");

int x,y, j=250 ;

setbkcolor(WHITE);
setcolor(LIGHTBLUE);

outtextxy(3,5," I am so stupid hyong I am so stupid sorry sorry !!! ");	// output "line" text


x = getmaxx();
y = getmaxy();

x=j; 

line(j,0,x,y);

x = getmaxx();
y = getmaxy();

y=j; 

line(0,j,x,y);






/*void line(int x0, int y0, int x1, int y1)

{
POINT line[2];
line[0].x = x0;
line[0].y = y0;
line[1].x = x1;
line[1].y = y1;
drawpoly(2, (int*)&line);
}
*/ 


getch();

closegraph(); // escape graphic mode
return 0;
}
