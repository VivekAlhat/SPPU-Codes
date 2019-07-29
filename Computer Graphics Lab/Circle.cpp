#include<iostream>
#include<graphics.h>
using namespace std;

void circ(int x,int y,int rad);

int main()
{
	int x,y,r;
	
	cout<<"Enter Center co-ordinates of circle : ";
	cin>>x>>y;
	cout<<"Enter radius of circle : ";
	cin>>r;
		
	circ(x,y,r);
	getch();
	closegraph();
	return 0;	
}

void circ(int x,int y,int r)
{
	float d;			
	int x1,y1;
	x1=0;
	y1=r;
	d=3-2*r;
	while(x1<=y1)
	{
		int gd=DETECT,gm=VGAMAX;
		initgraph(&gd,&gm,NULL);
		if(d<=0)
		{
			d=d + (4*x1) + 6;
		}
		else
		{
			d=d + 4*(x1-y1) + 10;
			y1--;
		}
		x1++;
		putpixel(x1+x,y1+y,WHITE);
		putpixel(x1+x,y-y1,WHITE);
		putpixel(x-x1,y1+y,WHITE);
		putpixel(x-x1,y-y1,WHITE);
		putpixel(x+y1,y+x1,WHITE);
		putpixel(x+y1,y-x1,WHITE);
		putpixel(x-y1,y+x1,WHITE);
		putpixel(x-y1,y-x1,WHITE);
	}
}
