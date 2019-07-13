#include<iostream>

using namespace std;

class complex
{
    float x,y;
    public: 
    complex()
    {
        x=y=0.0;
    }
    complex (float a,float b)
    {
        x=a;
        y=b;
    }

    friend ostream &operator<<(ostream &out,complex &t);
    friend istream &operator>>(istream &in,complex &t);

    complex operator+(complex &t)
    {
        complex t1;
        t1.x=x+t.x;
        t1.y=y+t.y;
        return t1;
    }
    complex operator*(complex &t)
    {
        complex t1;
        t1.x=(x*t.x)-(y*t.y);
        t1.y=(x*t.y)+(y*t.x);
        return t1;
    }
};

ostream &operator<<(ostream &out,complex &t)
{
    out<<t.x<<"+"<<t.y<<"i"<<endl;
    return out;
}

istream &operator>>(istream &in,complex &t)
{
    in>>t.x>>t.y;
    return in;
}

int main()
{
    complex a,b,res;
    int choice;
    char ch;
    cout<<"Enter real and imaginary part of expression 1:"<<endl;
    cin>>a;
    cout<<"Enter real and imaginary part of expression 2:"<<endl;
    cin>>b;
    cout<<"Expression 1:"<<a<<endl;
    cout<<"Expression 2:"<<b<<endl;
    do
    {
        cout<<"----Operator Overloading----"<<endl;
        cout<<"1.addition\n2.multiplication\n3.exit"<<endl;
        cout<<"Choice:"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            res=a+b;
            cout<<res<<endl;
            break;

            case 2:
            res=a*b;
            cout<<res<<endl;
            break;

            case 3:
            exit(EXIT_SUCCESS);

            default: 
            cout<<"Invalid"<<endl;
        }
        cout<<"continue? y or n"<<endl;
        cin>>ch;
    }while(ch=='y');
return 0;
}
