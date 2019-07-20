#include <iostream>
#define SIZE 5
using namespace std;

class pizza
{
    int order[SIZE];
    int front = -1, rear = -1;

  public:
    bool isfull()
    {
        if ((front == 0) && (rear == (SIZE - 1)))
        {
            return true;
        }
        else if (front == (rear + 1))
        {
            return true;
        }
        return false;
    }

    bool isempty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void pending();
    void makepayment(int);
    void accept(int);
};

void pizza::accept(int x)
{
    if (isfull())
    {
        cout << "Sorry, all the orders are full." << endl;
    }
    else if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    order[rear] = x;
    cout << "Order made is: " << x << endl;
}

void pizza::makepayment(int n)
{
    int item;
    if (isempty())
    {
        cout << "Sorry, currently there are no orders." << endl;
    }
    else
    {
        cout << "Current orders are:" << endl;
        for (int i = 0; i < n; i++)
        {
            item = order[front];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % SIZE;
            }
            cout << "\t" << item;
        }
        cout << "\nTotal amount to pay is:" << n * 100 << endl;
        cout << "Thank you for visiting us." << endl;
    }
}

void pizza::pending()
{
    int temp;
    if (isempty())
    {
        cout << "There are no pending orders." << endl;
    }
    else
    {
        temp = front;
        while (temp != rear)
        {
            temp = (temp + 1) % SIZE;
        }
        cout << "\n"
             << order[temp] << endl;
    }
}

int main()
{
    pizza p1;
    int choice;
    char ch;
    int a, n;
    do
    {
        cout << "----Pizza Parlour----" << endl;
        cout << "1.Make order\n2.Make payment\n3.Pending orders\n4.Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "1.Veg pizza\n2.Margarita pizza" << endl;
            cout << "Which one?" << endl;
            cin >> a;
            p1.accept(a);
            break;

        case 2:
            cout << "How many pizza's do you want?" << endl;
            cin >> n;
            p1.makepayment(n);
            break;

        case 3:
            p1.pending();
            break;

        case 4:
            exit(EXIT_SUCCESS);

        default:
            cout << "Thank you." << endl;
        }
        cout << "continue? y or n" << endl;
        cin >> ch;
    } while (ch == 'y');
    return 0;
}
