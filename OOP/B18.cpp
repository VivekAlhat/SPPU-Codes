#include<iostream>
using namespace std;
template <typename T>
void selsort(T a[],int n)
{
    T temp;
    int i,j;
    int min = 0;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    cout<<"Sorted list is:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}
template <typename T1>
void bubsort(T1 a[],int n)
{
    int i,j;
    T1 temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-1)-i;j++)
        {
            if(a[j]>a[j+1])
            {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            }
        }
    }
    cout<<"Sorted list is:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}

int main()
{
    int choice,n,i;
    char ch;
    int b[50];
    float c[50];
    do
    {
        cout<<"1.Selection sort on integer array using template"<<endl;
        cout<<"2.Selection sort on float array using template"<<endl;
        cout<<"3.Bubble sort on integer array using template"<<endl;
        cout<<"4.Bubble sort on float array using template"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: 
            cout<<"How many elements do you want to sort?"<<endl;
            cin>>n;
            cout<<"Enter the "<<n<<" elements"<<endl;
            for(i=0;i<n;i++)
            {
                cin>>b[i];
            }
            cout<<"Elements before sorting are:"<<endl;
            for(i=0;i<n;i++)
            {
                cout<<b[i]<<endl;
            }
            selsort<int>(b,n);
            break;

            case 2: 
            cout<<"How many elements do you want to sort?"<<endl;
            cin>>n;
            cout<<"Enter the "<<n<<" elements"<<endl;
            for(i=0;i<n;i++)
            {
                cin>>c[i];
            }
            cout<<"Elements before sorting are:"<<endl;
            for(i=0;i<n;i++)
            {
                cout<<c[i]<<endl;
            }
            selsort<float>(c,n);
            break;

            case 3: 
            cout<<"How many elements do you want to sort?"<<endl;
            cin>>n;
            cout<<"Enter the "<<n<<" elements"<<endl;
            for(i=0;i<n;i++)
            {
                cin>>b[i];
            }
            cout<<"Elements before sorting are:"<<endl;
            for(i=0;i<n;i++)
            {
                cout<<b[i]<<endl;
            }
            bubsort<int>(b,n);
            break;

            case 4: 
            cout<<"How many elements do you want to sort?"<<endl;
            cin>>n;
            cout<<"Enter the "<<n<<" elements"<<endl;
            for(i=0;i<n;i++)
            {
                cin>>c[i];                
            }
            cout<<"Elements before sorting are:"<<endl;
            for(i=0;i<n;i++)
            {
                cout<<c[i]<<endl;
            }
            bubsort<float>(c,n);
            break;

            default: 
            cout<<"Try again"<<endl;
        }
        cout<<"Continue? y or n"<<endl;
        cin>>ch;
    }while(ch=='y');
    return 0;
}