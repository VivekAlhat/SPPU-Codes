#include<iostream>
#include<graphics.h>
using namespace std;
void dda(float a,float b,float c,float d)
{
	
	float x1=a,x2=c,y1=b,y2=d,x,y,dx,dy,l;
	int  i=0;
	dx=abs(x2-x1);
	dy=abs(y2-y1);

	if(dx>dy)
		l=dx;
	else
		l=dy;
	
	dx=(x2-x1)/l;
	dy=(y2-y1)/l;

	x=x1+0.5;
	y=y1+0.5;


	while(i<l)
	{
		putpixel(x,y,RED);
		x=x+dx;
		y=y+dy;
		i++;
	}

}
void bl(float a,float b,float c,float d)
{
	float x1=a,x2=c,y1=b,y2=d,x,y,dx,dy,e,temp;
	int i,ex=0,s1,s2;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	
	x=x1;
	y=y1;
	
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		ex=1;
	}	
	if(dx<0)
		s1=0;
	else
		s1=1;
		
	if(dy<0)
		s2=0;
	else
		s2=1;
		
		
	e=2*dy-dx;
	
	for(i=0;i<dx;i++)
	{
		putpixel(x,y,RED);
		while(e>0)
		{
			if(ex==1)
				x=x+s1;
			else
				y=y+s2;
			e=e-2*dx;	
		}
		
	
	if(ex==1)
		y=y+s2;
	else
		x=x+s1;
	
	 e=e+2*dy;
	}
	
}
int main()
{
	 float x1,x2,y1,y2,x,y,dx,dy,l;
	 int gd=DETECT,gm=VGAMAX,i=0;
	cout<<"enter the first point:"<<" ";
	cin>>x1;
	cin>>y1;
	cout<<"enter the second point:"<<" ";
	cin>>x2;
	cin>>y2;
	
	initgraph(&gd,&gm,NULL);
	//outside rectangle using dda algorithm
	dda(x1,y1,x1,y2);
	dda(x1,y2,x2,y2);
	dda(x2,y2,x2,y1);
	dda(x2,y1,x1,y1);
	//diamond using dda algorithm
	float x3=(x1+x2)/2,y3=(y1+y2)/2;
	dda(x3,y1,x1,y3);
	dda(x1,y3,x3,y2);
	dda(x3,y2,x2,y3);
	dda(x2,y3,x3,y1);
	//inner rectangle using bresenhem algorithm
	float x4=(x3+x1)/2,y4=(y1+y3)/2,x5=(x2+x3)/2,y5=(y2+y3)/2;
	bl(x4,y4,x5,y4);
	bl(x4,y4,x4,y5);
	bl(x5,y4,x5,y5);
	bl(x4,y5,x5,y5);
getch();
closegraph();
return 0;
}
