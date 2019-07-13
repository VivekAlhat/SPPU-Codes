#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class telephone
{
    char name[20];
    long int number;

  public:
    void getdata()
    {
        cout << "Enter name:" << endl;
        cin >> name;
        cout << "Enter telephone no:" << endl;
        cin >> number;
    }
    void display()
    {
        cout << "Name:\t" << name << endl;
        cout << "Tele No:\t" << number << endl;
    }
    int search(long int num)
    {
        if (number == num)
        {
            cout << "Record found." << endl;
            cout << "Name:\t" << name << endl;
            cout << "Tele No:\t" << number << endl;
        }
        else
        {
            cout << "No record found" << endl;
        }
    }
    int srch(char n[])
    {
        if (strcmp(name, n))
        {
            cout << "Record found." << endl;
            cout << "Name:\t" << name << endl;
            cout << "Tele No:\t" << number << endl;
        }
        else
        {
            cout << "No record found" << endl;
        }
    }
};

int main()
{
    telephone t;
    fstream f;
    int choice, i, n, flag = 0;
    long int number;
    char ch;
    char name[100], fname[50];

    cout << "Enter name for file:" << endl;
    cin >> fname;
    f.open(fname);
    do
    {
        cout << "1.Enter data" << endl;
        cout << "2.Display data" << endl;
        cout << "3.Search using number" << endl;
        cout << "4.Search using name" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            f.open(fname);
            cout << "How many entries you want to add?" << endl;
            cin >> n;
            for (i = 0; i < n; i++)
            {
                t.getdata();
                f.write((char *)&t, sizeof(t));
            }
            f.close();
            break;

        case 2:
            f.open(fname);
            cout << "Telephone Directory:" << endl;
            while (f)
            {
                f.read((char *)&t, sizeof(t));
                t.display();
            }
            f.close();
            break;

        case 3:
            f.open(fname);
            cout << "Enter the number:" << endl;
            cin >> number;
            flag = 0;
            while (f)
            {
                f.read((char *)&t, sizeof(t));
                if (t.search(number))
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "No such record" << endl;
            }
            f.close();
            break;

        case 4:
            f.open(fname);
            cout << "Enter the name:" << endl;
            cin >> name;
            flag = 0;
            while (f)
            {
                f.read((char *)&t, sizeof(t));
                if (t.srch(name))
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "No such record" << endl;
            }
            f.close();
            break;

        case 5:
            exit(0);

        default:
            cout << "Invalid Choice" << endl;
        }
        cout << "Do you wish to continue? y or n" << endl;
        cin >> ch;
    } while (ch == 'y');
    return 0;
}