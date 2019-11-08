#include <iostream>
using namespace std;

int main(){
	string msg,crc,encoded="";
	cout<<"Enter the data:"<<endl;
	getline(cin,msg);
	cout<<"Enter polynomial:"<<endl;
	getline(cin,crc);
	int m = msg.length();
	int n = crc.length();
	
	encoded += msg;
	for(int i=1;i<=n-1;i++){
		encoded += '0';
	}
	
	for(int i=0;i<=encoded.length()-n;){
		for(int j=0;j<n;j++)
			encoded[i+j] = encoded[i+j] == crc[j] ? '0':'1';
		for(;i<encoded.length() && encoded[i]!='1';i++);
	}
	
	cout<<"Redundant bits:"<<encoded.substr(encoded.length()-n+1)	<<endl;
	cout<<"Frame:"<<msg+encoded.substr(encoded.length()-n+1)<<endl;
	return 0;
}
