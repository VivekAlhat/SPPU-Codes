#include <iostream>
#include <graphics.h>
using namespace std;

class pixel
{
	public:
	int x,y,d;
};

class circ:public pixel
{
	public:
		void draw(int xc,int yc,int rad);
};

void circ::draw(int xc,int yc,int rad)
{
	x=0;
	y=rad;
	
	d=3-2*rad;
	
	do{
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc+y,yc+x,RED);
		putpixel(xc+y,yc-x,WHITE);
		putpixel(xc+x,yc-y,RED);
		putpixel(xc-x,yc-y,WHITE);
		putpixel(xc-y,yc-x,RED);
		putpixel(xc-y,yc+x,WHITE);
		putpixel(xc-x,yc+y,RED);
		
		if(d<=0)
		{
			d+=4*x+6;
		}
		else
		{
			d+=4*(x-y)+10;
			y--;
		}
		x++;
	}while(x<y);
}

int main()
{
	int gd=DETECT,gm=VGAMAX;
	circ c;
	int xc,yc,rad;
	cout<<"Enter center:"<<endl;
	cin>>xc>>yc;
	cout<<"Enter radius:"<<endl;
	cin>>rad;
	initgraph(&gd,&gm,NULL);
	c.draw(xc,yc,rad);
	getch();
	closegraph();
}
