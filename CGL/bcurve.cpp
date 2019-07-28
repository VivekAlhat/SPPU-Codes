#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

int mat[4][3];
void line1(float x2,float y2)
{
	line(mat[0][0],mat[0][1],x2,y2);
	mat[0][0]=x2;
	mat[0][1]=y2;
}

void bcurve(float xb,float yb,float xc,float yc,float xd,float yd,int n)
{
	float xab,yab,xbc,ybc,xcd,ycd;
	float xabc,yabc,xbcd,ybcd;
	float xabcd,yabcd;
	
	if(n==0){
		line1(xb,yb);
		line1(xc,yc);
		line1(xd,yd);
	}
	else{
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
		bcurve(xab,yab,xabc,yabc,xabcd,yabcd,n);
		bcurve(xbcd,ybcd,xcd,ycd,xd,yd,n);
	}
}

int main()
{
	int gd=DETECT,gm=VGAMAX;
	initgraph(&gd,&gm,NULL);
	mat[0][0]=100;
	mat[0][1]=250;
	bcurve(100,50,150,80,190,250,4);
	mat[0][0]=150;
	mat[0][1]=250;
	bcurve(50,100,80,150,180,200,4);
	getch();
	closegraph();
}
