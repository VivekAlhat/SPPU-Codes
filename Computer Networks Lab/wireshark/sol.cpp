#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	string ch,no,time,src,dest,protocol,len,info;
	int count,i,choice;
	i=choice=count=0;
	do{
		ifstream file("packets");
		cout<<endl;
		cout<<"----- Packet Analyzer -----"<<endl;
		cout<<"1.IP\n2.TCP\n3.UDP\n4.Ethernet\n5.Exit\nEnter you choice:"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				ch = "ICMPv6";
				break;
			case 2:
				ch = "TCP";
				break;
			case 3:
				ch = "UDP";
				break;
			case 4:
				ch = "ARP";
				break;
			case 5:
				exit(0);
			default:
				ch = "ARP";
		}while(file.good()){
			getline(file,no,',');
			getline(file,time,',');
			getline(file,src,',');
			getline(file,dest,',');
			getline(file,protocol,',');
			getline(file,len,',');
			getline(file,info,'\n');
			protocol = string(protocol,1,protocol.length()-2);
			
			if(protocol=="Protocol" || protocol == ch){
				cout<<setw(4)<<right<<i++;
				cout<<setw(8)<<left<<string(no,1,no.length()-2);
				cout<<setw(15)<<left<<string(time,1,time.length()-2);
				cout<<setw(15)<<left<<string(src,1,src.length()-2);
				cout<<setw(20)<<left<<string(dest,1,dest.length()-2);
				cout<<setw(15)<<left<<protocol;
				cout<<setw(20)<<left<<string(len,1,len.length()-2);
				cout<<setw(15)<<left<<string(info,1,info.length()-2)<<endl;
				count++;
			}
		}
		cout<<"Count: "<<count<<endl;
	}while(choice<6);
	return 0;
}
