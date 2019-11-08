#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, const char **argv){
	string ch,no,time,src,dest,protocol,len,info;
	int choice,cnt,i;
	choice=cnt=i=0;
	do{
		ifstream file("packets");
		cout<<"----- Packet Analyzer -----"<<endl;
		cout<<"1.IP\n2.TCP\n3.UDP\n4.Ethernet\n5.Exit\nEnter your choice:"<<endl;
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
				break;
	}while(file.good()){
			getline(file,no,',');
			getline(file,time,',');
			getline(file,src,',');
			getline(file,dest,',');
			getline(file,protocol,',');
			getline(file,len,',');
			getline(file,info,'\n');
			protocol = string(protocol,1,protocol.length()-2);
			
			if(protocol == ch || protocol == "Protocol"){
				cout <<i++;
				cout <<setw(15)<<left<<string(time,1,time.length()-2);	// -2 to remove succeeding addition character
				cout <<setw(30)<<left<<string(src,1,src.length()-2);	// 1 to remove preceding character
				cout <<setw(30)<<left<<string(dest,1,dest.length()-2);
				cout <<setw(8)<<internal<<protocol<<"      ";
				cout <<setw(12)<<left<<string(len,1,len.length()-2);
				cout <<string(info,1,info.length()-2)<<"\n";
				cnt++;
			}
		}
		file.close();
		cout<<"Count: "<<cnt<<endl;
	}while(choice<6);
	return 0;
}
