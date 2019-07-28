#include <iostream>
#include <graphics.h>
#include <cstdlib>
using namespace std;

class tran{
	int val;
	public:
	void setval(int temp)
	{
		val=temp;
	}
	
	int disp()
	{
		return(val);
	}
	
	tran operator+(tran o)
	{
		tran t;
		t.val=val+o.val;
		return(t);
	}
};

class scale{
	int val;
	public:
	void setval(int temp)
	{
		val=temp;
	}
	
	int disp()
	{
		return(val);
	}
	
	scale operator*(scale o)
	{
		scale s;
		s.val=val*o.val;
		return(s);
	}
};

int main()
{
	int gd=DETECT,gm=VGAMAX;
	int x1,y1,x2,y2,x3,y3;
	int tx,ty,sx,sy,ch;
	char choice;
	tran t1,t2,t3,t4,t5,t6,t7,t8;
	scale s1,s2,s3,s4,s5,s6,s7,s8;
	
	cout<<"Enter x1/y1 :"<<endl;
	cin>>x1>>y1;
	cout<<"Enter x2/y2 :"<<endl;
	cin>>x2>>y2;
	cout<<"Enter x3/y3 :"<<endl;
	cin>>x3>>y3;
	
	initgraph(&gd,&gm,NULL);
	
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	
	do{
		cout<<"1.Translation\n2.Scaling\n3.Rotation\n4.Exit"<<endl<<"Enter your choice:"<<endl;
		cin>>ch;
	
		if(ch==1){
			cout<<"Enter tx/ty:"<<endl;
			cin>>tx>>ty;
		
			t1.setval(x1);
			t2.setval(y1);
			t3.setval(x2);
			t4.setval(y2);
			t5.setval(x3);
			t6.setval(y3);
			t7.setval(tx);
			t8.setval(ty);
			
			setcolor(BLUE);
			
			t1=t1+t7;
			t2=t2+t8;
			t3=t3+t7;
			t4=t4+t8;
			t5=t5+t7;
			t6=t6+t8;
			
			line(t1.disp(),t2.disp(),t3.disp(),t4.disp());
			line(t3.disp(),t4.disp(),t5.disp(),t6.disp());
			line(t5.disp(),t6.disp(),t1.disp(),t2.disp());
		}
		else if(ch==2){
			cout<<"Enter sx/sy:"<<endl;
			cin>>sx>>sy;
			
			s1.setval(x1);
	    		s2.setval(y1);
    			s3.setval(x2);
    			s4.setval(y2);
    			s5.setval(x3);
    			s6.setval(y3);
    	
    			line(x1,y1,x2,y2);
    			line(x2,y2,x3,y3);
    			line(x1,y1,x3,y3);
    	
     			s7.setval(sx);
     			s8.setval(sy);
    	
   			setcolor(GREEN);
   	
    			s1=s1*s7;
    			s2=s2*s8;
    			s3=s3*s7;
    			s4=s4*s8;
    			s5=s5*s7;
    			s6=s6*s8;
    	
     			line(s1.disp(),s2.disp(),s3.disp(),s4.disp());
     			line(s3.disp(),s4.disp(),s5.disp(),s6.disp());
     			line(s1.disp(),s2.disp(),s5.disp(),s6.disp());
		}
		else if(ch==3){
		}
		else if(ch==4){
			exit(0);
		}
		else{
			cout<<"Invalid Choice:"<<endl;
		}
		cout<<"Continue?"<<endl;
		cin>>choice;
	}while(choice=='y'||choice=='Y');
	getch();
	closegraph();
}
