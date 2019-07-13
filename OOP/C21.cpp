#include<iostream>
#include<stack>
#include<queue>
#include<stdlib.h>

using namespace std;

int main()
{
    stack<int> st;
    queue<int> qu;
    int choice,item;
    char ch;
    do
    {
        cout<<"1.Insert an element"<<endl;
        cout<<"2.Display an element"<<endl;
        cout<<"3.Delete an element"<<endl;
        cout<<"4.Display size"<<endl;
        cout<<"5.First element"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: 
            cout<<"Enter an element to be inserted"<<endl;
            cin>>item;
            st.push(item);
            qu.push(item);
            break;

            case 2:
            cout<<"Elements in the stack are"<<endl;
            if(!st.empty())
            {
                cout<<st.top()<<endl;
                st.pop();
            }
            cout<<"Elements in the queue are"<<endl;
            if(!qu.empty())
            {
                cout<<qu.front()<<endl;
                qu.pop();
            }
            break;

            case 3:
            item=st.top();
            st.pop();
            cout<<"Element deleted from stack is: "<<item<<endl;
            item=qu.front();
            qu.pop();
            cout<<"Element deleted from queue is: "<<item<<endl;
            break;

            case 4:
            cout<<"Size of the stack is: "<<st.size()<<endl;
            cout<<"Size of the queue is: "<<qu.size()<<endl;
            break;

            case 5: 
            cout<<"First element of the stack is:"<<endl;
            cout<<st.top()<<endl;
            cout<<"First element of the queue is:"<<endl;
            cout<<qu.front()<<endl;
            cout<<"Last element of the queue is:"<<endl;
            cout<<qu.back()<<endl;
            break;

            case 6:
            exit(1);
        }
        cout<<"Do you want to continue? y or n"<<endl;
        cin>>ch;
    }while(ch=='y');

    return 0;
}
