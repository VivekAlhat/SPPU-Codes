#include<iostream>
#include<graphics.h>

using namespace std;

void translate(int p[2][3],int tx,int ty)
{
	p[0][0]=p[0][0]+tx;
	p[1][0]=p[1][0]+tx;
	p[0][1]=p[0][1]+tx;	
	p[1][1]=p[1][1]+ty;
	p[0][2]=p[0][2]+ty;
	p[1][2]=p[1][2]+ty;

	setcolor(RED);
	line(p[0][0],p[1][0],p[0][1],p[1][1]);
	line(p[0][1],p[1][1],p[0][2],p[1][2]);
	line(p[0][2],p[1][2],p[0][0],p[1][0]);
}

int main()
{

	int p[2][3],tx,ty;

	cout<<"Enter the top-pixel co-ordinates (x1/y1):"<<endl;
	cin>>p[0][0]>>p[1][0];

	cout<<"\nEnter the bottom-left co-ordinates (x2/y2):"<<endl;
	cin>>p[0][1]>>p[1][1];

	cout<<"\nEnter the bottom-right co-ordinates (x3/y3):"<<endl;
	cin>>p[0][2]>>p[1][2];

	cout<<"\nEnter the x-y scale by which you want to translate :"<<endl;
	cin>>tx>>ty;

	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);

	setcolor(GREEN);
	line(p[0][0],p[1][0],p[0][1],p[1][1]);
	line(p[0][1],p[1][1],p[0][2],p[1][2]);
	line(p[0][2],p[1][2],p[0][0],p[1][0]);

	translate(p,tx,ty);

	getch();
	return 0;
}
