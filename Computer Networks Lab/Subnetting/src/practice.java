import java.util.*;
public class practice {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String mask = null,ip,first,last;
		int firstOctet = 0;
		System.out.println("Enter IP: ");
		ip = sc.next();
		String[] ipParts = ip.split("\\.");
		firstOctet = Integer.parseInt(ipParts[0]);
		System.out.println(firstOctet);
		if(firstOctet <= 127) {
			mask = "255.0.0.0";
			System.out.println("Class A");
			System.out.println("Subnet Mask Is: "+mask);
		}
		else if(firstOctet >=128 && firstOctet<=191) {
			mask = "255.255.0.0";
			System.out.println("Class B");
			System.out.println("Subnet Mask Is: "+mask);
		}
		else if(firstOctet >=192 && firstOctet<=223) {
			mask = "255.255.255.0";
			System.out.println("Class C");
			System.out.println("Subnet Mask Is: "+mask);
		}
		else if(firstOctet >=224 && firstOctet<=239) {
			mask = "255.0.0.0";
			System.out.println("Class D");
			System.out.println("It is used for broadcasting.");
		}
		else if(firstOctet >=240 && firstOctet<=254) {
			mask = "255.0.0.0";
			System.out.println("Class E");
			System.out.println("It is reserved for government and future use");
		}
		
		first = "";
		last = "";
		String[] maskParts = mask.split("\\.");
		for(int i=0;i<4;i++) {
			int x= Integer.parseInt(ipParts[i]);
			int y= Integer.parseInt(maskParts[i]);
			int z= x & y;
			int w= z | (y^255);
			first += z+".";
			last += w+".";
		}
		System.out.println("First address is: "+first);
		System.out.println("Last address is: "+last);
		sc.close();
	}
}
