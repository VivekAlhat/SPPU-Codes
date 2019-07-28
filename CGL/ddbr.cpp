#include <iostream>
#include <graphics.h>
#include <math.h>
#include <cstdlib>
using namespace std;

class pixel{
	public:
		int x1,y1,x2,y2,x,y,dx,dy,len,err=0,excg,s1,s2,temp;
		public:
			int sign(int arg)	
			{
				if(arg>0)
				{
					return 1;
				}
				else if(arg==0)
				{
					return 0;
				}
				else
				{
					return -1;
				}
			}
};

class draw:public pixel
{
	public:
		void drawl(int x1,int y1,int x2,int y2,int color);
		void drawl(int x1,int y1,int x2,int y2);
};

void draw::drawl(int x1,int y1,int x2,int y2,int color)
{
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	
	if(dx>dy)
	{
		len=dx;
	}
	else
	{
		len=dy;
	}
	
	s1=sign(dx);
	s2=sign(dy);
	
	dx=(x2-x1)/len;
	dy=(y2-y1)/len;
	
	x=(x1+0.5);
	y=(y1+0.5);
	
	for(int i=1;i<=len;i++)	
	{
		putpixel(x,y,color);
		x+=dx;
		y+=dy;
	}
}

void draw::drawl(int x1,int y1,int x2,int y2)
{
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	
	x=x1;
	y=y1;
	
	if(dy>dx)	
	{
		temp=dx;
		dx=dy;
		dy=temp;
		excg=1;
	}
	else
	{
		excg=0;
	}
	
	s1=sign(x2-x1);
	s2=sign(y2-y1);
	
	err=2*dy-dx;
	
	for(int j=1;j<=dx;j++)
	{
		putpixel(x,y,RED);
		while(err>0)
		{
			if(excg==1)
			{
				x=x+s1;
			}
			else
			{
				y=y+s2;
			}
			err=err-2*dx;
		}
		if(excg==1)
		{
			y=y+s2;
		}
		else
		{
			x=x+s1;
		}
		err=err+2*dy;
	}
}

int main()
{
	draw d;
	int gd=DETECT,gm=VGAMAX;
	int x1,y1,x2,y2,ch;
	char choice;
	cout<<"Enter line co-ordinates:"<<endl;
	cin>>x1>>y1>>x2>>y2;
	initgraph(&gd,&gm,NULL);
	d.drawl(x1,y1,x2,y2);
	/*do{
		cout<<"1.DDA\n2.Bresenham\n3.Exit"<<endl<<"Enter your choice:"<<endl;
		cin>>ch;
		if(ch==1)
		{
			initgraph(&gd,&gm,NULL);
			d.drawl(WHITE);
		}
		else if(ch==2)
		{
			initgraph(&gd,&gm,NULL);
			d.drawl();
		}
		else if(ch==3)
		{
			exit(0);
		}
		else
		{
			cout<<"Invalid choice."<<endl;
		}
		cout<<"Continue?"<<endl;
		cin>>choice;
	}while(choice=='y'||choice=='Y');
	*/
	getch();
	closegraph();
}
