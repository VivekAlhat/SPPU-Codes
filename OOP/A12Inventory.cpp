#include <iostream>
#include <string.h>

using namespace std;

class inventory
{
    char author[50];
    char title[50];
    char publisher[50];
    int stock, price;

  public:
    inventory()
    {
        char *author = new char[50];
        char *title = new char[50];
        char *publisher = new char[50];
        stock = price = 0;
    }
    void getdata();
    void display();
    int search(char[], char[]);
    void nocopies(int);
};

void inventory::getdata()
{
    cout << "Enter title:" << endl;
    cin >> title;
    cout << "Enter author:" << endl;
    cin >> author;
    cout << "Enter publisher:" << endl;
    cin >> publisher;
    cout << "Enter price:" << endl;
    cin >> price;
    cout << "Enter total books:" << endl;
    cin >> stock;
}

void inventory::display()
{
    cout << "Title:\t" << title << endl;
    cout << "Author:\t" << author << endl;
    cout << "Publisher:\t" << publisher << endl;
    cout << "Price:\t" << price << endl;
    cout << "Stock:\t" << stock << endl;
}

int inventory::search(char t[], char a[])
{
    if (strcmp(title, t) && strcmp(author, a))
    {
        return 0;
    }
    return 1;
}

void inventory::nocopies(int num)
{
    if (stock >= num)
    {
        cout << "Books are available." << endl;
        cout << "Price of " << num << " books are " << (price * num) << endl;
    }
    else
    {
        cout << "Books aren't available." << endl;
    }
}

int main()
{
    inventory b[100];
    int choice, key = 0, flag = 0;
    int i, j, n;
    char key_title[50], key_author[50];
    char ch;
    do
    {
        cout << "----BOOK INVENTORY----" << endl;
        cout << "1.Add a book\n2.Display details\n3.Search a book\n4.Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "How many books do you want to store?" << endl;
            cin >> n;
            for (i = 0; i < n; i++)
            {
                b[i].getdata();
            }
            break;

        case 2:
            for (i = 0; i < n; i++)
            {
                b[i].display();
            }
            break;

        case 3:
            cout << "Enter the title:" << endl;
            cin >> key_title;
            cout << "Enter the author:" << endl;
            cin >> key_author;
            for (i = 0; i < n; i++)
            {
                if (b[i].search(key_title, key_author))
                {
                    flag = 1;
                    key = i;
                    b[i].display();
                }
            }
            if (flag == 1)
            {
                cout << "Books are available." << endl;
            }
            else
            {
                cout << "Books aren't available." << endl;
            }

            if (flag == 1)
            {
                cout << "How many books do you want?" << endl;
                cin >> j;
                for (i = 0; i < n; i++)
                {
                    b[key].nocopies(j);
                }
            }
            break;

        case 4:
            exit(1);
        }
        cout << "Do you want to continue?" << endl;
        cin >> ch;
    } while (ch == 'y');
    return 0;
}