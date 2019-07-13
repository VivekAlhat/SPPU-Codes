#include<iostream>
#include<string.h>
using namespace std;
class book
{
public:
    char author[20];
    char title[20];
    char publisher[20];
    double price;
    int stock;
public:
        book();
        void insertdata();
        void display();
        int search(char[],char[]);
        void nocopies(int);

};
book::book()
{

    char * author =new char[50];
    char * title =new char[50];
    char * publisher =new char[50];
    price=0;
    stock=0;
}

void book:: insertdata()
{

    cout<<"\nenter the author of the book:";
    cin>>author;
    cout<<"\nenter the title of the book:";
    cin>>title;
    cout<<"\nenter the publisher of the book:";
    cin>>publisher;
    cout<<"\nenter the price of the book:";
    cin>>price;
    cout<<"\nenter the stock of the book:";
    cin>>stock;

}

void book::display()
{

    cout<<"\n the author of the book is:";
    cout<<author;
    cout<<"\nthe title of the book is:";
    cout<<title;
    cout<<"\nthe publisher of the book is:";
    cout<<publisher;
    cout<<"\nthe price of the book is:";
    cout<<price;
    cout<<"\nthe stock available of the book is:";
    cout<<stock;


}

int book::search(char t[],char a[])
{
    if (strcmp(title,t)&& strcmp(author,a))
    {

        return 0;
    }
    else
    {
        return 1;
    }

}

void book::nocopies(int num)
{

    if(stock>num)
    {
        cout<<"\nthe stock of this book is available"<<" the price of"<<num<<"books will be"<<(price*num);

    }
    else
    {
        cout<<"\nthe stock required not available";

    }
}

int main()
{

    book b[100];

    int choice,x,n,i,copies;
    int key=0,flag=0;
    char key_title[50],key_author[50];

    do
    {
        cout<<"\n************book shop*************";
        cout<<"\n1. insert the details of the book:";
        cout<<"\n2. display the details of the book:";
        cout<<"\n3. search for the book:";
        cout<<"\nenter your choice:";
        cin>>choice;

        switch(choice)
        {

        case 1:
           cout<<"\n how many books do you want to enter ?";
           cin>>n;
           for(i=0;i<n;i++)
           {
               b[i].insertdata();
           }
           break;

        case 2:
            for(i=0;i<n;i++)
            {

                b[i].display();
            }
            break;

        case 3:
            cout<<"\n enter the title of the required book:";
            cin>>key_title;
            cout<<"\nenter the author of the required book:";
            cin>>key_author;
            for(i=0;i<n;i++)
            {

                if(b[i].search(key_title,key_author))
                {
                    flag=1;
                    b[i].display();
                }
                key=i;
            }

                if(flag==1)
                {
                    cout<<"\nbook is available:";

                }
                else
                {

                    cout<<"\nbook is not available:";

                }


                if(flag==1)
                {
                    cout<<"\npleease enter the copies of book required:";
                    cin>>copies;

                    b[key].nocopies(copies);
                }

                break;

                    default:
                    cout<<"\ninvalid choice:";

            }

            cout<<"\ndo you want to continue? press 1 if yes:";
            cin>>x;


        }while(x==1);




return 0;
}