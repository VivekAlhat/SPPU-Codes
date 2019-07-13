#include<iostream>
#include<exception>
#include<stdlib.h>

using namespace std;

class exc1:public exception 
{
    public: 
    const char *what() const throw()
    {
        return "User's age must be between 18-55";
    }
};

class exc2:public exception 
{
    public: 
    const char *what() const throw()
    {
        return "\nUser's income must be between 50000-100000";
    }
};

class exc3:public exception 
{
    public: 
    const char *what() const throw()
    {
        return "\nInvalid city";
    }
};

class exc4:public exception
{
    public: 
    const char *what() const throw()
    {
        return "\nUser must have a 4-wheeler vehicle";
    }
};

class user
{
    string city;
    double income;
    int vehicle,age;
    public: 
    void getdata()
    {
        cout<<"Enter age:"<<endl;
        cin>>age;
        cout<<"Enter city:"<<endl;
        cin>>city;
        cout<<"Enter income:"<<endl;
        cin>>income;
        cout<<"Enter vehicle(2 for 2 wheeler and 4 for 4 wheeler):"<<endl;
        cin>>vehicle;
    }
    void display()
    {
        if(age<18||age>55)
        {
            try
            {
                throw exc1();
            }
            catch (exc1 &a)
            {
                cout<<a.what()<<endl;
            }
        }

        if(income<50000||income>100000)
        {
            try
            {
                throw exc2();
            }
            catch(exc2 &a)
            {
                cout<<a.what()<<endl;
            }
        }

        if(city!="pune"&&city!="mumbai"&&city!="bangalore"&&city!="chennai")
        {
            try
            {
                throw exc3();
            }
            catch(exc3 &a)
            {
                cout<<a.what()<<endl;
            }
        }

        if(vehicle!=4)
        {
            try
            {
                throw exc4();
            }
            catch(exc4 &a)
            {
                cout<<a.what()<<endl;
            }
        }
        cout<<"AGE:"<<age<<endl;
        cout<<"INCOME:"<<income<<endl;
        cout<<"CITY:"<<city<<endl;
        cout<<"VEHICLE:"<<vehicle<<endl;
    }
};

int main()
{
    user u;
    u.getdata();
    u.display();
    return 0;
}