import java.io.*;
import java.util.*;
public class subnet {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String mask,ip,first,last;
		int firstOctet=0;
		mask=ip=null;
		System.out.println("Enter the IP address: ");
		ip = sc.next();
		String[] ipParts = ip.split("\\.");
		firstOctet = Integer.parseInt(ipParts[0]);
//		System.out.println(firstOctet);
		
		if(firstOctet<=127) {
			mask = "255.0.0.0";
			System.out.println("Class A");
			System.out.println("Subnet mask is: "+mask);
		}
		else if(firstOctet>=128 && firstOctet<=191) {
			mask = "255.255.0.0";
			System.out.println("Class B");
			System.out.println("Subnet mask is: "+mask);
		}
		else if(firstOctet>=192 && firstOctet<=223) {
			mask = "255.255.255.0";
			System.out.println("Class C");
			System.out.println("Subnet mask is: "+mask);
		}
		else if(firstOctet>=224 && firstOctet<=239) {
			mask = "255.0.0.0";
			System.out.println("Class D, It is used for multicasting.");
		}
		else if(firstOctet>=240 && firstOctet<=254) {
			mask = "255.0.0.0";
			System.out.println("Class E, It is reserved for government and experimental use.");
		}
		
		first = "";
		last = "";
		String[] maskParts = mask.split("\\.");
		
		for(int i=0;i<4;i++) {
			int x = Integer.parseInt(ipParts[i]);	//IP address
			int y = Integer.parseInt(maskParts[i]);	//Mask
			int z = x & y;	//Network Address
			int w = z | (y^255);	//Host Address
			first += z + ".";
			last += w + ".";
		}
		System.out.println("First address: "+first);
		System.out.println("Last address: "+last);
		sc.close();
	}
}
