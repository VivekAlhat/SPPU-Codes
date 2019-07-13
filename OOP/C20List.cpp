#include<iostream>
#include<list>
#include<iterator>

using namespace std;

int main()
{
    list<int> l1,l2;
    list<int>::iterator it;
    int choice,item,i;
    char ch;
    do
    {
        cout<<"----List using STL----"<<endl;
        cout<<"1.Insert element in the list"<<endl;
        cout<<"2.Insert element at a specific position in the list"<<endl;
        cout<<"3.Check if list is empty"<<endl;
        cout<<"4.Sort the list"<<endl;
        cout<<"5.Delete repeated elements in the list"<<endl;
        cout<<"6.Reverse the list"<<endl;
        cout<<"7.Merge the list"<<endl;
        cout<<"8.Display the list"<<endl;
        cout<<"9.Exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: 
            cout<<"Enter the element in the list:"<<endl;
            cin>>item;
            l1.push_back(item);
            break;

            case 2:
            int pos;
            cout<<"Enter the position in the list:"<<endl;
            cin>>pos;
            cout<<"Enter the element:"<<endl;
            cin>>item;
            for(i=0;i<=pos;i++)
            {
                ++it;
                l1.insert(it,item);
            }
            break;

            case 3: 
            if(l1.empty())
            {
                cout<<"List is empty"<<endl;
            }
            else
            {
                cout<<"List isn't empty"<<endl;
            }
            break;

            case 4:
            l1.sort();
            break;

            case 5: 
            l1.unique();
            break;

            case 6:
            l1.reverse();
            break;

            case 7: 
            cout<<"Enter the elements of the second list:"<<endl;
            cin>>item;
            l2.push_back(item);
            l1.merge(l2);
            break;

            case 8:
            cout<<"Elements of the list are:"<<endl;
            for(it=l1.begin();it!=l1.end();it++)
            {
                cout<<*it<<endl;
            }
            break;

            case 9: 
            exit(EXIT_SUCCESS);

            default: 
            cout<<"Invalid Option"<<endl;
        }
        cout<<"Continue? y or n"<<endl;
        cin>>ch;
    }while(ch=='y');

    return 0;
}
