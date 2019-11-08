import java.net.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
public class server {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			@SuppressWarnings("resource")
			Scanner sc = new Scanner(System.in).useDelimiter("\n");
			DatagramSocket s = new DatagramSocket(2050);
			InetAddress addr1 = InetAddress.getByName("192.168.2.6");
			InetAddress addr2 = InetAddress.getByName("192.168.2.6");
			InetAddress addr3 = InetAddress.getByName("192.168.2.6");
			String str1="",str2="";
			
			while(!str1.equals("Bye")) {
				byte[] buf1 = new byte[20];
				byte[] buf2 = new byte[20];
				
				DatagramPacket p1 = new DatagramPacket(buf1, buf1.length);
				s.receive(p1);
				buf1 = p1.getData();
				str2 = new String(buf1,StandardCharsets.UTF_8);
				System.out.println("Client Says:"+str2);
				
				str1 = sc.next();
				buf2 = str1.getBytes();
				DatagramPacket p2 = new DatagramPacket(buf2, buf2.length,addr1,2040);
				s.send(p2);
				DatagramPacket p3 = new DatagramPacket(buf2, buf2.length,addr2,2040);
				s.send(p3);
				DatagramPacket p4 = new DatagramPacket(buf2, buf2.length,addr3,2040);
				s.send(p4);
			}
			s.close();
			sc.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
}
