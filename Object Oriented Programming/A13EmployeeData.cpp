//multiple inheritance means we derive one child class from multiple parent classes

#include <iostream>

using namespace std;

class personal
{
    string name, dob, address;
    long int telephone;

  public:
    void getdata()
    {
        cout << "Enter name:" << endl;
        cin >> name;
        cout << "Enter date of birth:" << endl;
        cin >> dob;
        cout << "Enter address:" << endl;
        cin >> address;
        cout << "Enter telephone:" << endl;
        cin >> telephone;
    }
    void display()
    {
        cout << "NAME\t\tDATE OF BIRTH\t\tADDRESS\t\tTELEPHONE" << endl;
        cout << name << "\t" << dob << "\t" << address << "\t" << telephone << endl;
    }
};

class academic
{
    string qualification, college;
    int passyear;

  public:
    void getata()
    {
        cout << "Enter college:" << endl;
        cin >> college;
        cout << "Enter qualification:" << endl;
        cin >> qualification;
        cout << "Enter passing year:" << endl;
        cin >> passyear;
    }
    void display()
    {
        cout << "COLLEGE\t\tQUALIFICATION\t\tPASSING YEAR" << endl;
        cout << college << "\t" << qualification << "\t" << passyear << endl;
    }
};

class professional
{
    string post, company;
    int joinyear;

  public:
    void getata()
    {
        cout << "Enter Company:" << endl;
        cin >> company;
        cout << "Enter Job Post:" << endl;
        cin >> post;
        cout << "Enter joining year:" << endl;
        cin >> joinyear;
    }
    void display()
    {
        cout << "COMPANY\t\tJOB POST\t\tJOINING YEAR" << endl;
        cout << company << "\t" << post << "\t" << joinyear << endl;
    }
};

class resume : public personal, academic, professional
{
    string rname;

  public:
    void getdata()
    {
        cout << "Enter resume name:" << endl;
        cin >> rname;
        personal::getdata();
        academic::getata();
        professional::getata();
    }
    void display()
    {
        cout << "RESUME:\t" << rname << endl;
        personal::display();
        academic::display();
        professional::display();
    }
};

int main(int argc, char const *argv[])
{
    resume r;
    r.getdata();
    r.display();
    return 0;
}
