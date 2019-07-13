#include <iostream>

using namespace std;

namespace name1
{
    void print()
    {
        cout<<"1"<<endl;
    }
}

namespace name2
{
   void print()
    {
        cout<<"2"<<endl;
    }
}

int main() 
{
    name1::print();
    name2::print();
    return 0;
}