#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class cir
{
	int r,x,y,d;
	public:
void draw(int xc,int yc,int r);
};

void cir::draw(int xc,int yc,int r)
{
	x=0;
	y=r;
	d=3-2*r;
	do
	{
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc+y,yc+x,BLUE);
		putpixel(xc+y,yc-x,WHITE);
		putpixel(xc+x,yc-y,BLUE);
		putpixel(xc-x,yc-y,WHITE);
		putpixel(xc-y,yc-x,BLUE);
		putpixel(xc-y,yc+x,WHITE);
		putpixel(xc-x,yc+y,BLUE);

		if(d<0)
		{
			d=d+4*x+6;
		}
		else
		{
			d=d+4*(x-y)+10;
			y=y-1;
		}
		x=x+1; 
	}while(x<y);
	
}

class dda
{
public:
int s1,s2;
float x,y,len,dx,dy;
float calclen(float dx,float dy)
{
	if(dx>dy)
	return dx;
	else
	return dy;
}

int sign(int x,int y)
{
	if((x-y)>=0)
	return 1;
	else 
	return -1;
}

void draw(float x1,float y1,float x2,float y2);
};

void dda::draw(float x1,float y1,float x2,float y2)
{
	int i=1;
	dx=abs(x2-x1);
	dy=abs(y2-y1); 	
	len=calclen(dx,dy);
	s1=sign(x2,x1);
	s2=sign(y2,y1);
	dx=(x2-x1)/len;
	dy=(y2-y1)/len;
	x=x1+0.5*s1;
	y=y1+0.5*s2;
	while(i<=len)
	{
		putpixel(floor(x),floor(y),15);
		x=x+dx;
		y=y+dy;
		i++;
	}
}

void calc(float x[],float y[],int xc,int yc,int r)
{
x[0]=xc-r*cos((30*M_PI)/180);
y[0]=yc+r*sin((30*M_PI)/180);
x[1]=xc+r*cos((30*M_PI)/180);
y[1]=yc+r*sin((30*M_PI)/180);
x[2]=xc;
y[2]=yc-r;
}

int main()
{
	cir c;
	dda d1;
	int xc,yc,r,i;
	float x[3],y[3];
	cout<<"Enter center co-ordinate(x/y): ";
	cin>>xc>>yc;
	cout<<"Enter radius of outer circle: ";
	cin>>r;
	calc(x,y,xc,yc,r);
	int gd=DETECT,gm=VGAMAX;
	initgraph(&gd,&gm,NULL);
	c.draw(xc,yc,r);
	for(i=0;i<3-1;i++)
	d1.draw(x[i],y[i],x[i+1],y[i+1]);
	d1.draw(x[i],y[i],x[0],y[0]);
	c.draw(xc,yc,r/2);
	delay(5000);
	getch();
	closegraph();
}

