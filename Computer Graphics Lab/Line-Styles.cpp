#include <iostream>
#include <graphics.h>

using namespace std;

void ddal(int x1,int y1,int x2,int y2)
{
	int delx,dely,len,x,y;
	//step 2
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

	//step 3
	if(delx>dely)
	{
		len=delx;
	}
	else
	{
		len=dely;
	}

	//step 4
	delx=(x2-x1)/len;
	dely=(y2-y1)/len;

	//step5
	x=x1+0.5;
	y=y1+0.5;

	for(int i=1;i<=len;i++)	
	{
		putpixel(x,y,WHITE);
		x=x+delx;
		y=y+dely;
	}
}

void dot(int x1,int y1,int x2,int y2,int mod)
{

	int delx,dely,len,x,y;

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

	//step 3
	if(delx>dely)
	{
		len=delx;
	}
	else
	{
		len=dely;
	}

	//step 4
	delx=(x2-x1)/len;
	dely=(y2-y1)/len;

	//step5
	x=x1+0.5;
	y=y1+0.5;
	
	//step 6
	
	for(int i=1;i<=len;i++)	
	{
		if(x%mod==0 && y%mod==0)
		
		putpixel(x,y,WHITE);
		x=x+delx;
		y=y+dely;
	}	

}

void dash(int x1,int y1,int x2,int y2,int mod)
{

	int delx,dely,len,x,y;

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

	//step 3
	if(delx>dely)
	{
		len=delx;
	}
	else
	{
		len=dely;
	}

	//step 4
	delx=(x2-x1)/len;
	dely=(y2-y1)/len;

	//step5
	x=x1+0.5;
	y=y1+0.5;
	
	//step 6
	
	for(int i=1;i<=len;i++)	
	{
		if((x%mod<5) || (x%mod==7))
		
		putpixel(x,y,WHITE);
		x=x+delx;
		y=y+dely;
	}	

}

int main()
{	
	int gd=DETECT, gm=VGAMAX;
	
	int x1,y1,x2,y2;
	int mod=5;
		
	cout<<"Enter the value of x1:"<<endl;
	cin>>x1;
	cout<<"Enter the value of y1:"<<endl;
	cin>>y1;
	cout<<"Enter the value of x2:"<<endl;
	cin>>x2;
	cout<<"Enter the value of y2:"<<endl;
	cin>>y2;
	
	initgraph(&gd,&gm,NULL);	
	ddal(x1,y1,x2,y2);
	
	y1=y1+10;
	
	dot(x1,y1,x2,y2,mod);

	y1=y1+10;

	for(int i=0;i<=5;i++)	
	{
		ddal(x1,y1,x2,y2);
		y1++;
		y2++;	
	}
	
	y1=y1+10;	
	mod=10;
	dash(x1,y1,x2,y2,mod);
	getch();
	closegraph();
}
