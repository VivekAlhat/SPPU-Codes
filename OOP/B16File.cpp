#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    char name[30];
    string data;
    ofstream fout;
    cout<<"Enter the name for file:"<<endl;
    cin>>name;
    fout.open(name);

    if(!fout)
    {
        cout<<"Error opening in file"<<endl;
        exit(1);
    }

    cout<<"File writing operation"<<endl;
    cout<<"Press ctrl+z to abort writing to the file"<<endl;
    while(getline(cin,data))
    {
        if(data=="^z")
        break;
        fout<<data<<endl;
    }
    fout.close();

    ifstream fin;
    fin.open(name);
    if(!fin)
    {
        cout<<"Error opening in file"<<endl;
        exit(1);
    }

    if(fin)
    {
        fin>>data;
    }
    cout<<data;

    fin.close();
    return 0;
}