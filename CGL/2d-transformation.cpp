#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

void translate(int mat[2][3],int tx,int ty)
{
	mat[0][0]=mat[0][0]+tx;
	mat[1][0]=mat[1][0]+tx;
	mat[0][1]=mat[0][1]+tx;	
	mat[1][1]=mat[1][1]+ty;
	mat[0][2]=mat[0][2]+ty;
	mat[1][2]=mat[1][2]+ty;

	setcolor(RED);
	line(mat[0][0],mat[1][0],mat[0][1],mat[1][1]);
	line(mat[0][1],mat[1][1],mat[0][2],mat[1][2]);
	line(mat[0][2],mat[1][2],mat[0][0],mat[1][0]);
}

void scaling(int mat[2][3],int sx,int sy)
{
	mat[1][0]=mat[1][0]+sx;
	mat[0][1]=mat[0][1]+sx;	
	
	mat[0][2]=mat[0][2]+sy;
	mat[1][2]=mat[1][2]+sy;

	setcolor(RED);
	line(mat[0][0],mat[1][0],mat[0][1],mat[1][1]);
	line(mat[0][1],mat[1][1],mat[0][2],mat[1][2]);
	line(mat[0][2],mat[1][2],mat[0][0],mat[1][0]);
}

void rotate(int mat[2][3],int a)
{
	mat[0][0]=mat[0][0]*cos(a);
	mat[0][1]=mat[0][1]*(-1*sin(a));
	
	mat[1][0]=mat[1][0]*sin(a);
	mat[1][1]=mat[1][1]*cos(a);
		
	mat[2][0]=mat[2][0]*0;
	mat[2][1]=mat[2][1]*0;
	
	setcolor(RED);
	line(mat[0][0],mat[1][0],mat[0][1],mat[1][1]);
	line(mat[0][1],mat[1][1],mat[0][2],mat[1][2]);
	line(mat[0][2],mat[1][2],mat[0][0],mat[1][0]);
}

int main()
{
	int mat[2][3],tx,ty,sx,sy,a,angle;
	int choice;
	char ch;
	cout<<"Enter the topmost co-ordinates (x1/y1):"<<endl;
	cin>>mat[0][0]>>mat[1][0];

	cout<<"\nEnter the bottom-left co-ordinates (x2/y2):"<<endl;
	cin>>mat[0][1]>>mat[1][1];

	cout<<"\nEnter the bottom-right co-ordinates (x3/y3):"<<endl;
	cin>>mat[0][2]>>mat[1][2];

	int gd=DETECT,gm;
	char path[1]="";
	initgraph(&gd,&gm,path);

	setcolor(BLUE);
	line(mat[0][0],mat[1][0],mat[0][1],mat[1][1]);
	line(mat[0][1],mat[1][1],mat[0][2],mat[1][2]);
	line(mat[0][2],mat[1][2],mat[0][0],mat[1][0]);
	
	do
	{
		cout<<"1.Translate\n2.Scale\n3.Rotate\n4.Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter the x-y scale by which you want to translate :"<<endl;
				cin>>tx>>ty;
				translate(mat,tx,ty);
				break;
			case 2:	
				cout<<"\nEnter the x-y scale by which you want to scale :"<<endl;
				cin>>sx>>sy;
				scaling(mat,sx,sy);
				break;
			
			case 3:
				cout<<"Enter the angle of rotation:"<<endl;
				cin>>a;
				angle = a * (3.1416/180);
				rotate(mat,angle);
				break;	
					
			case 4:
				exit(0);
			
			default:
				cout<<"Invalid Choice"<<endl;
		}
			cout<<"Do you want to continue?(y/n)"<<endl;
			cin>>ch;
	}while(ch=='y' || ch=='Y');
	
	getch();
	return 0;
}

