import java.util.*;
import java.net.*;
public class lookup {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		InetAddress inetaddress = null;
		System.out.println("1.URL to IP\n2.IP to URL\n3.Exit");
		System.out.println("Enter your choice: ");
		int choice = sc.nextInt();
		switch(choice) {
			case 1:
				System.out.println("Enter the URL: ");
				String url = sc.next();
				try {
					inetaddress = InetAddress.getByName(url);	//Get IP address
				} catch (UnknownHostException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				System.out.println("IP address of "+url+" is "+inetaddress);
				break;
			case 2:
				System.out.println("Enter the IP address: ");
				String IP = null;
				IP = sc.next();
				try {
					InetAddress host = InetAddress.getByName(IP);	//Get IP address
					System.out.println(host.getHostName());	//Get hostname via IP address
				} catch (UnknownHostException e) {
					e.printStackTrace();
				}
				break;
			case 3:
				System.exit(0);
				break;
			default:
				System.out.println("Invalid Choice.");
		}
		sc.close();
	}
}
