#include<iostream>
using namespace std;

class set 
{
    int c,b,n,i,j,k;
    int setA[30],setB[30],setAB[30],setC[30],setD[30];
    public: 
    set();
    void getdata();
    void display();
    void either();
    void ocricket();
    void both();
    void obadminton();
    void none();
};

set::set()
{
    c=b=n=0;
    i=j=k=0;
}

void set::getdata()
{
    cout<<"Enter the total number of students in the class:"<<endl;
    cin>>n;

    cout<<"Enter the total number of students who play cricket:"<<endl;
    cin>>c;
    for(i=0;i<c;i++)
    {
        cout<<"Enter the roll number of "<<i+1<<" student:"<<endl;
        cin>>setA[i];
    }

    cout<<"Enter the total number of students who play badminton:"<<endl;
    cin>>b;
    for(j=0;j<b;j++)
    {
        cout<<"Enter the roll number of "<<j+1<<" student:"<<endl;
        cin>>setB[j];
    }
}

void set::display()
{
    cout<<"Total number of students in the class:"<<endl;
    cout<<n<<endl;

    cout<<"Total number of students who play cricket:"<<endl;
    for(i=0;i<c;i++)
    {
        cout<<setA[i]<<endl;
    }

    cout<<"Total number of students who play badminton:"<<endl;
    for(j=0;j<b;j++)
    {
        cout<<setB[j]<<endl;
    }
}

void set::both()
{
    cout<<"Students playing both the sports are:"<<endl;
    for(i=0;i<c;i++)
    {
        for(j=0;j<b;j++)
        {
            if(setB[j]==setA[i])
            {
                cout<<"\t"<<setA[i]<<endl;
            }
        }
    }
}

void set::ocricket()
{
    int flag=0;
    cout<<"Students who play only cricket are:"<<endl;
    for(i=0;i<c;i++)
    {
        for(j=0;j<b;j++)
        {
            if(setA[i]==setB[j])
            {
                flag=1;
            }
        }
            if(flag==0)
            {
                cout<<"\t"<<setA[i]<<endl;
            }
         flag=0;
    }
}

void set::obadminton()
{
    int flag=0;
    cout<<"Students who play only badminton are:"<<endl;
    for(j=0;j<b;j++)
    {
       for(i=0;i<c;i++)
        {
            if(setB[j]==setA[i])
            {
                flag=1;
            }
        }
            if(flag==0)
            {
                cout<<"\t"<<setB[j]<<endl;
            }
        flag=0;
    }
}

void set::either()
{
    int flag=0;
    for(i=0;i<c;i++)
    {
        setC[k]=setA[i];
        k++;
    }
    for(j=0;j<b;j++)
    {
        for(i=0;i<c;i++)
        {
            if(setB[j]==setA[i])
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            setC[k]=setB[j];
            k++;
        }
        flag=0;
    }
    cout<<"Students that play either cricket or badminton or both are:"<<endl;
    for(i=0;i<k;i++)
    {
        cout<<"\t"<<setC[i]<<endl;
    }
}

void set::none()
{
    cout<<"Students that play none of the sports are:"<<endl;
    for(i=0;i<c;i++)
    {
        for(j=0;j<b;j++)
        {
            int res=setB[j]-setA[i];
            cout<<res<<endl;
        }
    }
}

int main()
{
    set s;
    int choice;
    char ch;
    do
    {
        cout<<"----Set Theory----"<<endl;
        cout<<"1.Either cricket,badminton or both\n2.Both the sports\n3.Only cricket\n4.Only badminton\n5.Students who play none of the sports\n6.Exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: 
            s.getdata();
            s.display();
            s.either();
            break;

            case 2: 
            s.getdata();
            s.display();
            s.both();
            break;

            case 3: 
            s.getdata();
            s.display();
            s.ocricket();
            break;

            case 4: 
            s.getdata();
            s.display();
            s.obadminton();
            break;

            case 5:
            s.getdata();
            s.display();
            s.none();
            
            case 6:
            exit(EXIT_SUCCESS);

            default: 
            cout<<"Invaid choice"<<endl;
        }
        cout<<"Do you want to continue? y or n"<<endl;
        cin>>ch;
    }
    while(ch=='y');
return 0;
}
