#include <iostream>
#include <graphics.h>

int mat[4][2];
void line(float x2,float y2)
{
	line(mat[0][0],mat[0][1],x2,y2);
	mat[0][0]=x2;
	mat[0][1]=y2;
}

void bez(float xb,float yb,float xc,float yc,float xd,float yd,int n)
{
	float xab,yab,xbc,ybc,xcd,ycd;
	float xabc,yabc,xbcd,ybcd;
	float xabcd,yabcd;
	if(n==0)
	{
		line(xb,yb);
		line(xc,yc);
		line(xd,yd);
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
		bez(xab,yab,xabc,yabc,xabcd,yabcd,n);
		bez(xbcd,ybcd,xcd,ycd,xd,yd,n);
	}
}

int main()
{
	int gd=DETECT,gm=VGAMAX;
	initgraph(&gd,&gm,NULL);
	mat[0][0]=100;
	mat[0][1]=150;
	bez(100,50,200,50,150,250,8);
	mat[0][0]=200;
	mat[0][1]=150;
	bez(150,80,220,70,180,270,8);
	getch();
	closegraph();
}
