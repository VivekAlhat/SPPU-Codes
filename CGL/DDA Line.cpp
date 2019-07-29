#include <iostream>
#include <graphics.h>
using namespace std;

int main()
{
	int gd= DETECT, gm;	//Graphics function
	int x1,y1,x2,y2,x,y;
	int dx,dy;
	int length;
	
	char path[5]=" ";
	
	cout<<"Enter the x1:"<<flush;
	cin>>x1;
	cout<<"\nEnter the y1:"<<flush;
	cin>>y1;
	cout<<"\nEnter the x2:"<<flush;
	cin>>x2;
	cout<<"\nEnter the y2:"<<flush;
	cin>>y2;
	
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	
	if(dx>dy)	
	{
		length=dx;
	}
	else
	{
		length=dy;
	}
	
	dx=(x2-x1)/length;
	dy=(y2-y1)/length;
	
	x=(x1+0.5);
	y=(y1+0.5);
	
	initgraph(&gd,&gm,path);
	
	for(int i=1;i<=length;i++)
	{
		putpixel(x,y,WHITE);
		x+=dx;
		y+=dy;
	}
	
	getch();
	closegraph();
}
