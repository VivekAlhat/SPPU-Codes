import java.net.*;
import java.io.*;
import java.util.*;
public class client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Socket s = new Socket("localhost",4444);
			DataInputStream din = new DataInputStream(s.getInputStream());
			DataOutputStream dout = new DataOutputStream(s.getOutputStream());
			Scanner sc = new Scanner(System.in);
			String str1 = "", str2 = "";
			
			while(!str1.equals("Bye")) {
				str1 = sc.next();
				dout.writeUTF(str1);
				str2 = din.readUTF();
				System.out.println("Server says: "+str2);
			}
			s.close();
			dout.close();
			sc.close();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}

}
