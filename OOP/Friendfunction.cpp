#include<iostream>

using namespace std;

class areaa
{
    double area;
    float r;
    public: 
    void getdata();
    friend void display(areaa a);
    void area1();
};

void areaa::getdata()
{
    cout<<"Enter the radius:"<<endl;
    cin>>r;
}

void areaa::area1()
{
    area=3.14*r*r;
}

void display(areaa a)
{
    cout<<"Area of circle is: "<<a.area<<endl;
}

int main()
{
    areaa a1;
    a1.getdata();
    a1.area1();
    display(a1);
    return 0;
}