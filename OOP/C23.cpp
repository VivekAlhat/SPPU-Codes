#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int> dq;
    deque<int>::iterator it;
    int choice,item;
    char ch;
    do
    {
        cout<<"1.Insert element at front:"<<endl;
        cout<<"2.Insert element at rear:"<<endl;
        cout<<"3.Display element at front:"<<endl;
        cout<<"4.Display element at rear:"<<endl;
        cout<<"5.Display size:"<<endl;
        cout<<"6.Delete element at front:"<<endl;
        cout<<"7.Delete element at rear:"<<endl;
        cout<<"8.Display dequeue"<<endl;
        cout<<"9.Exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: 
            cout<<"Enter the value to be inserted:"<<endl;
            cin>>item;
            dq.push_front(item);
            break;

            case 2: 
            cout<<"Enter the value to be inserted:"<<endl;
            cin>>item;
            dq.push_back(item);
            break;

            case 3:
            cout<<"The element at the front is:"<<endl;
            cout<<dq.front()<<endl;
            break;

            case 4: 
            cout<<"The element at the rear is:"<<endl;
            cout<<dq.back()<<endl;
            break;

            case 5:
            cout<<"The size of the dequeue is: "<<dq.size();
            break;

            case 6: 
            item=dq.front();
            dq.pop_front();
            cout<<"The element deleted is:"<<item<<endl;
            break;

            case 7: 
            item=dq.back();
            dq.pop_back();
            cout<<"The element deleted is:"<<item<<endl;
            break;

            case 8: 
            cout<<"Elements in the dequeue are:"<<endl;
            for(it=dq.begin();it!=dq.end();it++)
            {
                cout<<"\t"<<*it<<endl;
            }
            break;

            case 9: 
            exit(1);
        }
        cout<<"Continue? y or n"<<endl;
        cin>>ch;
    }while(ch=='y');

    return 0;
}
