#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

void koch(int x1,int y1,int x2,int y2,int itr)
{
	float angle=60*M_PI/180;
	int x3,y3,x4,y4,x,y;
	
	x3=(2*x1+x2)/3;
	y3=(2*y1+y2)/3;
	x4=(x1+2*x2)/3;
	y4=(y1+2*y2)/3;
	
	x=x3+(x4-x3)*cos(angle)+(y4-y3)*sin(angle);
	y=y3-(x4-x3)*sin(angle)+(y4-y3)*cos(angle);
	
	if(itr>0)
	{
		koch(x1,y1,x3,y3,itr-1);
		koch(x3,y3,x,y,itr-1);
		koch(x,y,x4,y4,itr-1);
		koch(x4,y4,x2,y2,itr-1);
	}
	else
	{
		line(x1,y1,x3,y3);
		line(x3,y3,x,y);
		line(x,y,x4,y4);
		line(x4,y4,x2,y2);
	}
}

int main()
{
	int gd=DETECT,gm=VGAMAX;
	int x1,y1,x2,y2,x3,y3;
	cout<<"Enter points:"<<endl;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	initgraph(&gd,&gm,NULL);
	koch(x1,y1,x2,y2,8);
	koch(x2,y2,x3,y3,8);
	koch(x3,y3,x1,y1,8);
	getch();
	closegraph();
}
