#include <iostream>

using namespace std;

class sort
{
    float m[50];
    int n, i, j;

  public:
    void getdata();
    void display();
    void bubble();
    void selection();
};

void sort::getdata()
{
    cout << "How many student's data do you want to store?" << endl;
    cin >> n;
    cout << "Enter the percentage:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> m[i];
    }
}

void sort::display()
{
    cout << "Entered percentages are:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << m[i] << endl;
    }
}

void sort::bubble()
{
    float temp;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n - 1) - i; j++)
        {
            if (m[j] > m[j + 1])
            {
                temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }
    cout << "The top five scorers are:" << endl;
    for (i = n - 1; i >= (n - 5); i--)
    {
        cout << m[i] << endl;
    }
}

void sort::selection()
{
    float temp;
    int min = 0;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (m[j] < m[min])
            {
                min = j;
            }
        }
        temp = m[i];
        m[i] = m[min];
        m[min] = temp;
    }
    cout << "The top five scorers are:" << endl;
    for (i = n - 1; i >= (n - 5); i--)
    {
        cout << m[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    sort s;
    int choice;
    char ch;
    do
    {
        cout << "----Sorting----" << endl;
        cout << "1.Bubble sort\n2.Selection sort\n3.Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.getdata();
            s.display();
            s.bubble();
            break;

        case 2:
            s.getdata();
            s.display();
            s.selection();
            break;

        case 3:
            exit(EXIT_SUCCESS);
            break;

        default:
            cout << "Invalid Choice" << endl;
        }
    } while (ch == 'y');
    return 0;
}
