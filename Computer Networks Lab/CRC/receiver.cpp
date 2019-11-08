#include <iostream>
using namespace std;

int main(){
	string encoded,crc;
	cout<<"Enter the dataframe:"<<endl;
	getline(cin,encoded);
	cout<<"Enter the polynomial:"<<endl;
	getline(cin,crc);
	int m=encoded.length();
	int n=crc.length();
	
	for(int i=0;i<m-n;){
		for(int j=0;j<n;j++)
			encoded[i+j] = encoded[i+j]==crc[j] ?'0':'1';
		for(;i<m && encoded[i]!='1';i++);
	}
	
	for(char i: encoded.substr(m-n)){
		if(i!='0'){
			cout<<"Error in communication"<<endl;
			return 0;
		}
	}
	cout<<"Transmission Successful"<<endl;
	return 0;
}
