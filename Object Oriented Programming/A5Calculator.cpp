#include <iostream>

using namespace std;

class calculator
{
    int op1, op2, res;

  public:
    calculator();
    void getdata();
    void display();
    void add();
    void sub();
    void mul();
    void div();
    void mod();
};

calculator::calculator()
{
    op1 = op2 = res = 0;
}

void calculator::getdata()
{
    cout << "Enter the first operand:" << endl;
    cin >> op1;
    cout << "Enter the second operand:" << endl;
    cin >> op2;
}

void calculator::display()
{
    cout << "Operand 1: " << op1 << endl;
    cout << "Operand 2: " << op2 << endl;
}

void calculator::add()
{
    res = op1 + op2;
    cout << "Addition is: " << res << endl;
}

void calculator::sub()
{
    res = op1 - op2;
    cout << "Subtraction is: " << res << endl;
}

void calculator::mul()
{
    res = op1 * op2;
    cout << "Multiplication is: " << res << endl;
}

void calculator::div()
{
    res = op1 / op2;
    cout << "Division is: " << res << endl;
}

void calculator::mod()
{
    res = op1 % op2;
    cout << "Modulus is: " << res << endl;
}

int main()
{
    calculator c;
    int choice;
    char ch;
    do
    {
        cout << "-----SIMPLE CALCULATOR-----" << endl;
        cout << "1.Addition Operation" << endl;
        cout << "2.Subtraction Operation" << endl;
        cout << "3.Multiplication Operation" << endl;
        cout << "4.Division Operation" << endl;
        cout << "5.Modulus Operation" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            c.getdata();
            c.display();
            c.add();
            break;

        case 2:
            c.getdata();
            c.display();
            c.sub();
            break;

        case 3:
            c.getdata();
            c.display();
            c.mul();
            break;

        case 4:
            c.getdata();
            c.display();
            c.div();
            break;

        case 5:
            c.getdata();
            c.display();
            c.mod();
            break;

        case 6:
            exit(1);

        default:
            cout << "Invalid Option" << endl;
        }
        cout << "Do you want to continue? y or n" << endl;
        cin >> ch;
    } while (ch == 'y');
    return 0;
}