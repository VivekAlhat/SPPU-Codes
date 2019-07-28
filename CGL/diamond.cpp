#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void dda(int x1,int y1,int x2,int y2)
{
	int dx,dy,len,x,y;
	
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	
	if(dx>dy){
		len=dx;
	}
	else{
		len=dy;
	}
	
	dx=(x2-x1)/len;
	dy=(y2-y1)/len;
	
	x=x1+0.5;
	y=y1+0.5;
	
	for(int i=1;i<=len;i++)
	{
		putpixel(x,y,WHITE);
		x+=dx;
		y+=dy;
	}
}

int main()
{
	int gd=DETECT,gm=VGAMAX,x1,y1,x2,y2;
	cout<<"Enter points:"<<endl;
	cin>>x1>>y1>>x2>>y2;
	initgraph(&gd,&gm,NULL);
	
	dda(x1,y1,x1,y2);
	dda(x1,y2,x2,y2);
	dda(x2,y2,x2,y1);
	dda(x2,y1,x1,y1);
	
	int x3,y3;
	x3=(x1+x2)/2;
	y3=(y1+y2)/2;
	dda(x3,y1,x1,y3);
	dda(x1,y3,x3,y2);
	dda(x3,y2,x2,y3);
	dda(x2,y3,x3,y1);
	
	int x4,y4,x5,y5;
	x4=(x1+x3)/2;
	y4=(y1+y3)/2;
	x5=(x2+x3)/2;
	y5=(y2+y3)/2;
	dda(x4,y4,x4,y5);
	dda(x4,y5,x5,y5);
	dda(x5,y5,x5,y4);
	dda(x5,y4,x4,y4);
	getch();
	closegraph();
}
