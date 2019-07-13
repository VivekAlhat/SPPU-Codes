#include<iostream>

using namespace std;

class inline1
{
    public:
    inline double mul(double a,double b)
    {
        return(a*b);
    }

    inline double cube(double c)
    {
        return(c*c*c);
    }
};

int main(int argc, char const *argv[])
{
    inline1 obj;
    double a,b;
    cout<<"Enter the first value:"<<endl;
    cin>>a;
    cout<<"Enter the second value:"<<endl;
    cin>>b;
    cout<<"Multiplication is:"<<obj.mul(a,b);
    cout<<"Cube of first number is:"<<obj.cube(a);
    cout<<"Cube of second number is:"<<obj.cube(b);
    return 0;
}
