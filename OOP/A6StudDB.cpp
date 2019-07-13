#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class student
{
    char *name, *class1, *div, *dob, *bggroup, *address, *licno;
    int roll, telephone, len;

  public:
    student();
    ~student();
    student(char *, char *, char *, char *, char *, char *, char *, int, int);
    static int counter;
    inline void getdata();
    inline void display();
    static void count();
};

int student::counter;

student::student()
{
    name = new char[30];
    class1 = new char[30];
    div = new char[30];
    dob = new char[30];
    bggroup = new char[30];
    address = new char[30];
    licno = new char[30];
    roll = 0;
    telephone = 0;
}

student::student(char *name, char *class1, char *div, char *dob, char *bggroup, char *address, char *licno, int roll, int telephone)
{
    len = strlen(name);
    this->name = new char[len + 1];
    strcpy(this->name, name);

    len = strlen(class1);
    this->class1 = new char[len + 1];
    strcpy(this->class1, class1);

    len = strlen(div);
    this->div = new char[len + 1];
    strcpy(this->div, div);

    len = strlen(dob);
    this->dob = new char[len + 1];
    strcpy(this->dob, dob);

    len = strlen(bggroup);
    this->bggroup = new char[len + 1];
    strcpy(this->bggroup, bggroup);

    len = strlen(address);
    this->address = new char[len + 1];
    strcpy(this->address, address);

    len = strlen(licno);
    this->licno = new char[len + 1];
    strcpy(this->licno, licno);

    this->roll = roll;
    this->telephone = telephone;
}

student::~student()
{
    delete name;
    delete class1;
    delete div;
    delete address;
    delete dob;
    delete licno;
    delete bggroup;
    roll = 0;
    telephone = 0;
    cout << "All the details have been deleted" << endl;
}

void student::count()
{
    counter++;
    cout << "Details of student " << counter << "\n";
}

void student::getdata()
{
    cout << "Enter name:" << endl;
    cin >> name;
    cout << "Enter class name:" << endl;
    cin >> class1;
    cout << "Enter division:" << endl;
    cin >> div;
    cout << "Enter date of birth:" << endl;
    cin >> dob;
    cout << "Enter blood group:" << endl;
    cin >> bggroup;
    cout << "Enter address:" << endl;
    cin >> address;
    cout << "Enter telephone:" << endl;
    cin >> telephone;
    cout << "Enter roll no:" << endl;
    cin >> roll;
}

void student::display()
{
    student::count();
    cout << "Name:" << name << endl;
    cout << "Class:" << class1 << endl;
    cout << "Division:" << div << endl;
    cout << "Date of birth:" << dob << endl;
    cout << "Blood group:" << bggroup << endl;
    cout << "Address:" << address << endl;
    cout << "Telephone:" << telephone << endl;
    cout << "Roll no:" << roll << endl;
}

int main()
{
    student s[20];
    int n;
    cout<<"How many students data you want to store?"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        s[i].getdata();
    }
    cout<<"Following are the details of the student:"<<endl;
    for(int i=0;i<n;i++)
    {
        s[i].display();
    }
    student s1("abc","se","se2","14feb","B+","pune","abc12",66,12345);
    s1.display();
    return 0;
}
