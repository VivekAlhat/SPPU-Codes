#include <iostream>
#include <graphics.h>
using namespace std;

int x,y,dx,dy,len;

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

void solid(int x1,int y1,int x2,int y2)
{
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
	
	x=(x1+0.5);//*sign(x2-x1);
	y=(y1+0.5);//*sign(y2-y1);
	
	for(int i=1;i<=len;i++)
	{
		putpixel(x,y,WHITE);
		x+=dx;
		y+=dy;
	}
}

void dot(int x1,int y1,int x2,int y2,int mod)
{
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
	
	x=(x1+0.5);//*sign(x2-x1);
	y=(y1+0.5);//*sign(y2-y1);
	
	for(int j=1;j<=len;j++)
	{
		if((x%mod==0) && (y%mod==0))
		putpixel(x,y,WHITE);
		x+=dx;
		y+=dy;
	}
}

void dash(int x1,int y1,int x2,int y2,int mod)
{
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
	
	x=(x1+0.5);//*sign(x2-x1);
	y=(y1+0.5);//*sign(y2-y1);
	
	for(int k=1;k<=len;k++)
	{
		if((x%mod<5)||(y%mod==7))
		putpixel(x,y,WHITE);
		x+=dx;
		y+=dy;
	}
}

int main()
{
	int gd=DETECT,gm=VGAMAX;
	int x1,y1,x2,y2;
	cout<<"Enter line points:"<<endl;
	cin>>x1>>y1>>x2>>y2;
	initgraph(&gd,&gm,NULL);
	solid(x1,y1,x2,y2);

	y1+=10;
	y2+=10;
	
	for(int j=0;j<5;j++)
	{
		solid(x1,y1,x2,y2);
		y1++;
		y2++;
	}
	
	y1+=10;
	y2+=10;
	dot(x1,y1,x2,y2,5);
	
	y1+=10;
	y2+=10;
	dash(x1,y1,x2,y2,10);
	getch();
	closegraph();
}
