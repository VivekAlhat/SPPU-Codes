#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

int mat[4][2];
void line1(float x2,float y2)
{
	line(mat[0][0],mat[0][1],x2,y2);
	mat[0][0]=x2;
	mat[0][1]=y2;
}

void wcurve(float xb,float yb,float xc,float yc,float xd,float yd,int n)
{
	float xab,yab,xbc,ybc,xcd,ycd;
	float xabc,yabc,xbcd,ybcd;
	float xabcd,yabcd;
	if(n==0)
	{
		line1(xb,yb);
		line1(xc,yc);
		line1(xd,yd);
	}
	else
	{
		xab=(mat[0][0]+xb)/2;
		yab=(mat[0][1]+yb)/2;
		xbc=(xb+xc)/2;
		ybc=(yb+yc)/2;
		xcd=(xc+xd)/2;
		ycd=(yc+yd)/2;
		xabc=(xab+xbc)/2;
		yabc=(yab+ybc)/2;
		xbcd=(xbc+xcd)/2;
		ybcd=(ybc+ycd)/2;
		xabcd=(xabc+xbcd)/2;
		yabcd=(yabc+ybcd)/2;
		n--;
		wcurve(xab,yab,xabc,yabc,xabcd,yabcd,n);
		wcurve(xbcd,ybcd,xcd,ycd,xd,yd,n);
	}
}

int main()
{
	int gd=DETECT,gm=VGAMAX;
	initgraph(&gd,&gm,NULL);
	mat[0][0]=100;
	mat[0][1]=200;
	wcurve(100,50,150,100,200,250,8);
	mat[0][0]=200;
	mat[0][1]=300;
	wcurve(200,150,220,180,250,250,8);
	getch();
	closegraph();
}
