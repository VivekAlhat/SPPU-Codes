#include <iostream>
#include <string>

using namespace std;

class publication
{
    string title;
    float price;

  public:
    publication()
    {
        title = "";
        price = 0.0;
    }
    void getdata()
    {
        cout << "Enter the title:" << endl;
        cin >> title;
        cout << "Enter the price:" << endl;
        cin >> price;
    }
    void display()
    {
        try
        {
            if (title.length() <= 3)
            {
                throw title;
            }
            if (price < 0.0)
            {
                throw price;
            }
        }
        catch (string)
        {
            cout << "Title shouldn't be less than 3 characters." << endl;
            title = "";
        }
        catch (float f)
        {
            cout << "Price is invalid." << endl;
            price = 0.0;
        }
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class book : public publication
{
    int pgcount;

  public:
    book() : publication()
    {
        pgcount = 0;
    }
    void getdata()
    {
        publication::getdata();
        cout << "Enter the total number of pages." << endl;
        cin >> pgcount;
    }
    void display()
    {
        publication::display();
        try
        {
            if (pgcount < 0)
            {
                throw pgcount;
            }
        }
        catch (int a)
        {
            cout << "Page count is invalid." << endl;
            pgcount = 0;
        }
        cout << "Page count: " << pgcount << endl;
    }
};

class tape : public publication
{
    float duration;

  public:
    tape() : publication()
    {
        duration = 0.0;
    }
    void getdata()
    {
        publication::getdata();
        cout << "Enter the playtime:" << endl;
        cin >> duration;
    }
    void display()
    {
        publication::display();
        try
        {
            if (duration <= 0.0)
            {
                throw duration;
            }
        }
        catch (float f1)
        {
            cout << "Duration is invalid." << endl;
            duration = 0.0;
        }
        cout << "Playtime: " << duration << endl;
    }
};

int main(int argc, char const *argv[])
{
    book b;
    tape t;
    cout << "---BOOK DETAILS---" << endl;
    b.getdata();
    b.display();
    cout << "---TAPE DETAILS---" << endl;
    t.getdata();
    t.display();
    return 0;
}
