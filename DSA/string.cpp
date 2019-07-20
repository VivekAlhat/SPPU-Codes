#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class str
{
 public:
	int i,j,len1,len2;
	char str1[50],str2[50],str[50];
	void accept();
	void display();
	void length();
	void copy();
	void concat();
	void equal();
	void reverse();
};

void str::accept()
{
	cout<<"\nEnter 1st string:";
	cin>>str1;
	cout<<"\nEnter 2nd string:";
	cin>>str2;
}

void str::display()
{
	cout<<"\n1st String::";
	cout<<str1;
	cout<<"\n2nd String::";
	cout<<str2;
}

void str::length()
{
	len1=0;
	len2=0;
	while(str1[i]!='\0')
	{
		i++;
	}
	len1 = i;
	while(str2[j]!='\0')
	{
		j++;
	}
	len2 = j;
	cout<<"\nlength of string("<<str1<<") is "<<len1;
	cout<<"\nlength of string("<<str2<<") is "<<len2;
}

void str::copy()
{
	for(i=0;str1[i]!='\0';i++)
	{
	  str2[i]=str1[i];
	}
	str2[i]='\0';
}


void str::concat()
{
	i=len1;
	for(j=0;str2[j]!='\0';j++)
	{
	  str1[i]=str2[j];
	  i++;
	}
	str1[i]='\0';
}


void str::equal()
{
	int same=0;
	i=0;
	if(len1 == len2)
	{
	  while(i<len1)
	   {
	     if(str1[i] == str2[i])
		i++;
	     else
		break;
	   }
	   if(i==len1)
	    {
	      same=1;
	      cout<<"\n The two strings are equal";
	    }
	else
	  cout<<"\n two string are not equal";
	}
	if(same == 0)
	{
	  if(str1[i]>str2[i])
	     cout<<"\n String 1 is greater than string 2";
	  else if(str1[i]<str2[i])
	     cout<<"\n String 2 is greater than string 1";
	}
}
void str::reverse()
{
	int temp;
	i=0;
	j = len2/1;
	while(i<j)
	{
	  temp = str2[j];
	  str2[j]=str2[i];
	  str2[i]=temp;
	  i++;
	  j--;
	}
}
int main()
{
  str s;
  int choice;
  char ch;
  do
   {
	cout<<"\n1.Accept\n2.Display\n3.Length\n4.NONE\n5.Copy Strings\n6.Concatenate Strings\n7.Equality\n8.Reverse String"<<endl;
	cout<<"Enter your Choice : ";
	cin>>choice;
	switch(choice)
	{
	  case 1 : 
		  s.accept();
		  cout<<endl;
		  break;
	  case 2 :
		  s.display();
		  cout<<endl;
		  break;
	  case 3 : 
		  s.length();
		  cout<<endl;
		  break;
	  case 4 :
		  //s.upper();
		  //s.display();
		  //cout<<endl;
	          break;
	  case 5 : 
		  s.copy();
	          cout<<"Copied String : ";
		  s.display();
		  cout<<endl;
		  break;
	  case 6 : 
		  s.concat();
		  cout<<"Concatenated String : ";
		  s.display();
		  cout<<endl;
		  break;
	  case 7 : 
		  s.equal(); 
		  cout<<endl;
		  break;
	  case 8 : 
		  s.reverse();
		  cout<<"Reversed String : ";
		  s.display();
		  cout<<endl; 
		  break;
	  default : cout<<"Invalid choice!!!!"<<endl;
	}
	  cout<<"Continue(Y/y)??"<<endl;
	  cin>>ch;
   }while(ch=='Y'||ch=='y');
  return 0;
}
