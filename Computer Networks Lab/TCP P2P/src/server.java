import java.io.*;
import java.net.*;
import java.util.*;
public class server {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			ServerSocket ss = new ServerSocket(4444);
			Socket s = ss.accept();
			DataInputStream din = new DataInputStream(s.getInputStream());
			DataOutputStream dout = new DataOutputStream(s.getOutputStream());
			Scanner sc = new Scanner(System.in);
			String str1="", str2="";
			while(!str1.equals("Bye")) {
				str2 = din.readUTF();
				System.out.println("Client says: "+str2);
				str1 = sc.next();
				dout.writeUTF(str1);
			}
			s.close();
			dout.close();
			sc.close();
			ss.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
}
