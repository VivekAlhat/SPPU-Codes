#include <iostream>
#include <graphics.h>

using namespace std;

int sign(int arg)
{
	if(arg>0)	
	{
		return 1;
	}
	else if (arg==0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int gd=DETECT,gm;
	char path[5]=" ";
	int x1,y1,x2,y2,dx,dy,x,y,e,temp,exchange;
	cout<<"Enter (x1,y1) co-ordinates:"<<endl;
	cin>>x1>>y1;
	cout<<"Enter (x2,y2) co-ordinates:"<<endl;
	cin>>x2>>y2;
	
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	
	x=x1;
	y=y1;
	
	int s1=sign(x2-x1);
	int s2=sign(y2-y1);
	
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		exchange=1;
	}
	else
	{
		exchange=0;
	}
	
	e=(2*dy)-dx;
	
	initgraph(&gd,&gm,path);
	for(int i=1;i<dx;i++)
	{
		putpixel(x,y,WHITE);
		while(e>0)
		{
			if(exchange==1)
			{
				x=x+s1;
			}
			else
			{
				y=y+s2;
			}
			e=e-(2*dx);
		}
		
		if(exchange==1)
		{
			y=y+s2;
		}
		else
		{
			x=x+s1;
		}
			e=e+(2*dy);
	}
	
	getch();
	closegraph();
}
