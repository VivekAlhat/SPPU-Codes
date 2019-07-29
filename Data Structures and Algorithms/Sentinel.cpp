#include<iostream>
using namespace std;

class sentinel
{
    int a[30],n,i;
    public: 
    bool sentinelsearch(int key);
    void getdata();
    void display();
};

void sentinel::getdata()
{
    cout << "Enter the total number of students:" << endl;
    cin >> n;
    cout << "Enter the roll numbers of the present students:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void sentinel::display()
{
    cout << "Following are the roll numbers of the students:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}

bool sentinel::sentinelsearch(int key)
{
    a[n]=key;
    for(i=0;a[i]!=key;i++)
    {
        //does nothing
    }
    if(i<n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int key;
    sentinel s;
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
    return 0;
}
