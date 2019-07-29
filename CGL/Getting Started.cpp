#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
	int gd=DETECT, gm =VGAMAX;
	initgraph(&gd,&gm,NULL);
	//line(150,100,50,200);
	circle(300,220,200); //outer circle
	circle(300,220,202);
	circle(300,240,45);//nose
	circle(300,240,47);
	
	circle(390,135,40);//eye1
	circle(390,135,42);
	circle(220,135,40);//eye2
	circle(220,135,42);
	/*circle(500,200,70);
	circle(390,100,30);
	circle(590,100,30);*/
	
	arc(300,220,30,150,130);
	arc(300,220,30,150,132);
	//rectangle(100,200,300,400);
	//bar3d(100,200,300,400,50,1);
	
	getch();
	closegraph();
}

