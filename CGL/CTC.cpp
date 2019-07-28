#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

class shape
{
	int d,p,q;
	float len,x,y,dx,dy;
	public:
		void dline(float x1,float y1,float x2,float y2);
		void dcirc(int pc,int qc,int r);
		int sign(int x,int y);
};

int shape::sign(int x,int y)
{
	if((x-y)>=0)
	return 1;
	else 
	return -1;
}

void shape::dcirc(int pc,int qc,int r)
{
	p=0;
	q=r;
	
	d=3-2*r;
	
	do{
		putpixel(pc+p,qc+q,WHITE);
		putpixel(pc+q,qc+p,RED);
		putpixel(pc+q,qc-p,WHITE);
		putpixel(pc+p,qc-q,RED);
		putpixel(pc-p,qc-q,WHITE);
		putpixel(pc-q,qc-p,RED);
		putpixel(pc-q,qc+p,WHITE);
		putpixel(pc-p,qc+q,RED);
		
		if(d<=0)
		{
			d=d+4*p+6;
		}
		else
		{
			d=d+4*(p-q)+10;
			q--;
		}
		p++;
	}while(p<q);
}

void shape::dline(float x1,float y1,float x2,float y2)
{
	int i=1;
	
	dx=abs(x2-x1);
	dy=abs(y2-y1); 	
	
	if(dx>dy){
		len=dx;
	}
	else{
		len=dy;
	}
	
	int s1=sign(x2,x1);
	int s2=sign(y2,y1);
	
	dx=(x2-x1)/len;
	dy=(y2-y1)/len;
	
	x=x1+0.5*s1;
	y=y1+0.5*s2;
	
	while(i<=len)
	{
		putpixel(floor(x),floor(y),WHITE);
		x=x+dx;
		y=y+dy;
		i++;
	}
}

void calc(float x[],float y[],int pc,int qc,int r)
{
	x[0]=pc-r*cos((30*M_PI)/180);
	y[0]=qc+r*sin((30*M_PI)/180);
	x[1]=pc+r*cos((30*M_PI)/180);
	y[1]=qc+r*sin((30*M_PI)/180);
	x[2]=pc;
	y[2]=qc-r;
}

int main()
{
	shape s;
	int gd=DETECT,gm=VGAMAX;
	int j,r,pc,qc;
	float x[3];
	float y[3];
	cout<<"Enter the centre points:"<<endl;
	cin>>pc>>qc;
	cout<<"Enter the radius:"<<endl;
	cin>>r;
	calc(x,y,pc,qc,r);
	initgraph(&gd,&gm,NULL);
	s.dcirc(pc,qc,r);
	for(j=0;j<3-1;j++)
	s.dline(x[j],y[j],x[j+1],y[j+1]);
	s.dline(x[j],y[j],x[0],y[0]);
	s.dcirc(pc,qc,r/2);
	delay(5000);
	getch();
	closegraph();
}
