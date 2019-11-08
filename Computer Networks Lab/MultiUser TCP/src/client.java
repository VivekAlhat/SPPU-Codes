import java.io.*;
import java.net.*;
import java.util.*;
public class client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Scanner sc = new Scanner(System.in);
			Socket s = new Socket("localhost",1030);
			DataInputStream din = new DataInputStream(s.getInputStream());
			DataOutputStream dout = new DataOutputStream(s.getOutputStream());
			System.out.println("Enter your name: ");
			String name = sc.next();
			dout.writeUTF(name);
			String str1="", str2="";
			
			while(!str1.equals("Bye")) {
				str1=sc.next();
				dout.writeUTF(str1);
				str2=din.readUTF();
				System.out.println("Server Says: "+str2);
			}
			sc.close();
			s.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
}
