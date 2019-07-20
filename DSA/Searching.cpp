#include <iostream>
using namespace std;

class search
{
    int roll[50];
    int n, key, i;

  public:
    void getdata();
    void display();
    bool linearsearch(int key);
    bool binarysearch(int key);
    bool sentinelsearch(int key);
    bool fibonaccisearch(int key);
    int fibonacci(int j);
};

void search::getdata()
{
    cout << "Enter the total number of students:" << endl;
    cin >> n;
    cout << "Enter the roll numbers of the present students:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> roll[i];
    }
}

void search::display()
{
    cout << "Following are the roll numbers of the students:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << roll[i] << endl;
    }
}

bool search::linearsearch(int key)
{
    for (i = 0; i < n; i++)
    {
        if (roll[i] == key)
        {
            return true;
        }
        return false;
    }
}

bool search::binarysearch(int key)
{
    int low = 0;
    int mid;
    int high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == roll[mid])
        {
            return true;
        }
        if (key < roll[mid])
        {
            high = mid - 1; //left half
        }
        else
        {
            low = mid + 1; //right half
        }
        return false;
    }
}

bool search::sentinelsearch(int key)
{
    int i;
    roll[n] = key;
    for (i = 0; roll[i] != key; i++)
    {
        //Does nothing
    }

    if (i < n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int search::fibonacci(int j)
{
    if (j == 0)
    {
        return 0;
    }
    if (j == 1)
    {
        return 1;
    }
    else
    {
        return (fibonacci(j - 1) + fibonacci(j - 2));
    }
}

bool search::fibonaccisearch(int key)
{
    int f1, f2, j, mid;
    j = 1;
    while (fibonacci(j) <= n)
        j++;

    f1 = fibonacci(j - 2);
    f2 = fibonacci(j - 3);
    mid = n - f1 + 1;
    while (key != roll[mid])
    {
        if (key > roll[mid])
        {
            if (f1 == 1)
                break;
            mid = mid + f2;
            f1 = f1 - f2;
            f2 = f2 - f1;
        }
        else
        {
            if (f2 == 0)
                break;
            mid = mid - f2;
        int temp = f1 - f2;
            f1 = f2;
            f2 = temp;
        }
    }
    if (roll[mid] == key)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    search s;
    int choice, key = 0;
    char ch;
    do
    {
        cout << "1.Linear search\n2.Binary search\n3.Sentinel search\n4.Fibonacci search\n5.Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.getdata();
            s.display();
            cout << "Enter the roll no to be searched:" << endl;
            cin >> key;
            if (s.linearsearch(key))
            {
                cout << "Student has attended the program." << endl;
            }
            else
            {
                cout << "Student has not attended the program." << endl;
            }
            break;

        case 2:
            s.getdata();
            s.display();
            cout << "Enter the roll no to be searched:" << endl;
            cin >> key;
            if (s.binarysearch(key))
            {
                cout << "Student has attended the program." << endl;
            }
            else
            {
                cout << "Student has not attended the program." << endl;
            }
            break;

        case 3:
            s.getdata();
            s.display();
            cout << "Enter the roll no to be searched:" << endl;
            cin >> key;
            if (s.sentinelsearch(key))
            {
                cout << "Student has attended the program." << endl;
            }
            else
            {
                cout << "Student has not attended the program." << endl;
            }
            break;

        case 4:
            s.getdata();
            s.display();
            cout << "Enter the roll no to be searched:" << endl;
            cin >> key;
            if (s.fibonaccisearch(key))
            {
                cout << "Student has attended the program." << endl;
            }   
            else
            {
                cout << "Student has not attended the program." << endl;
            }
            break;

        case 5:
            exit(EXIT_SUCCESS);
            break;

        default:
            cout << "Invalid Choice" << endl;
        }
        cout << "Do you want to continue? y or n" << endl;
        cin >> ch;
    } while (ch == 'y');
    return 0;
}
