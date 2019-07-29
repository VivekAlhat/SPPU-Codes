#include <iostream>

using namespace std;

class test
{
    float avg;
    int i, j, n, sum, k;
    int dsa[50], cnt[30], rno[30];

  public:
    test();
    void getdata();
    void display();
    void absent();
    void average();
    void h_l_score();
    void frequency();
};

test::test()
{
    i = j = n = 0;
    sum = k = avg = 0;
}

void test::frequency()
{
    // find the max frequency using linear traversal
    int counter = 0;
    int max_count = 1, res = dsa[0], curr_count = 1;
    for (int i = 1; i < n; i++)
    {
        if (dsa[i] == dsa[i - 1])
        {
            curr_count++;
            counter++;
        }
        else
        {
            if (curr_count > max_count)
            {
                max_count = curr_count;
                res = dsa[i - 1];
            }
            curr_count = 1;
        }
    }
    // If last element is most frequent
    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = dsa[n - 1];
    }
    cout << "Maximum frequent score is " << res << " scored by " << counter << " students" << endl;
}

void test::getdata()
{
    cout << "How many student's data do you want to store?" << endl;
    cin >> n;
    cout << "Enter the marks of the student:" << endl;
    cout << "Please enter -1 for the absent students" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Enter the marks for roll no:\n"
             << i + 1 << endl;
        cin >> dsa[i];
    }
}

void test::display()
{
    cout << "Marks of the students are:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Roll number:" << i + 1 << endl;
        cout << "Marks:" << dsa[i] << endl;
    }
}

void test::average()
{
    int p = 0;
    for (i = 0; i < n; i++)
    {
        if (dsa[i] != -1)
        {
            sum = sum + dsa[i];
            p++;
        }
    }
    avg = sum / p;
    cout << "Average of the class is:\n"
         << avg << endl;
}

void test::absent()
{
    int count = 0;
    cout << "Following students were absent for the test:" << endl;
    for (i = 0; i < n; i++)
    {
        if (dsa[i] == -1)
        {
            cout << i + 1 << " absent" << endl;
            count++;
        }
    }
    cout << "Total " << count << " students were absent for the test" << endl;
}

void test::h_l_score()
{
    int min = 0;
    int max = 0;
    int rno = 0;
    int i = 0;
    max = dsa[i];
    for (i = 0; i < n; i++)
    {
        if (dsa[i] == -1)
        {
        }
        else if (dsa[i] >= max)
        {
            max = dsa[i];
            rno = i;
        }
    }
    cout << "The highest score " << max << " scored by roll no: " << rno + 1 << endl;

    rno = 0;
    int j = 0;
    min = dsa[j];
    for (j = 0; j < n; j++)
    {
        if (dsa[j] == -1)
        {
        }
        else if (dsa[j] <= min)
        {
            min = dsa[j];
            rno = j;
        }
    }
    cout << "The lowest score " << min << " scored by roll no: " << rno + 1 << endl;
}

int main()
{
    test t;
    t.getdata();
    t.display();
    t.absent();
    t.h_l_score();
    t.average();
    t.frequency();
    return 0;
}