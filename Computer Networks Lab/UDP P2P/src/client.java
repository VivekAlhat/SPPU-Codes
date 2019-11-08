import java.net.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
public class client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			@SuppressWarnings("resource")
			Scanner sc = new Scanner(System.in).useDelimiter("\n");
			DatagramSocket s = new DatagramSocket(1080);
			InetAddress addr = InetAddress.getLocalHost();
			String str1="",str2="";
			while(!str1.equals("Bye")) {
				byte[] buf1 = new byte[20];
				byte[] buf2 = new byte[20];
				str1 = sc.next();
				buf1 = str1.getBytes();
				DatagramPacket p1 = new DatagramPacket(buf1, buf1.length,addr,1090);
				s.send(p1);
				
				DatagramPacket p2 = new DatagramPacket(buf2, buf2.length);
				s.receive(p2);
				buf2 = p2.getData();
				str2 = new String(buf2,StandardCharsets.UTF_8);
				System.out.println("Server Says:"+str2);
			}
			s.close();
			sc.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
}
