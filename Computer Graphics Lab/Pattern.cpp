#include <iostream>
#include <graphics.h>

using namespace std;

void dda(int x1,int y1,int x2,int y2);

int main()
{
	int gd=DETECT, gm=VGAMAX;
	initgraph(&gd,&gm,NULL);
	int x1,y1,x2,y2;
	
	cout<<"Enter the value of x1:"<<endl;
	cin>>x1;
	cout<<"Enter the value of y1:"<<endl;
	cin>>y1;
	cout<<"Enter the value of x2:"<<endl;
	cin>>x2;
	cout<<"Enter the value of y2:"<<endl;
	cin>>y2;
	
	dda(x1,y1,x2,y1);
	dda(x2,y1,x2,y2);
	dda(x2,y2,x1,y2);
	dda(x1,y2,x1,y1);
	
	getch();
	closegraph();	
}

void dda(int x1,int y1,int x2,int y2)
{
	float delx=0,dely=0,len,x=0,y=0;
	delx=x2-x1;
	if(delx<0)
	{
		delx=delx*(-1);
	}

	dely=y2-y1;
	if(dely<0);
	{
		dely=dely*(-1);
	}

	if(delx>dely)
	{
		len=delx;
	}
	else
	{
		len=dely;
	}

	delx=(x2-x1)/len;
	dely=(y2-y1)/len;

	x=x1+0.5;
	y=y1+0.5;
	
	for(int i=1;i<=len;i++)	
	{
		putpixel(round(x),round(y),WHITE);
		x=x+delx;
		y=y+dely;
	}
}
