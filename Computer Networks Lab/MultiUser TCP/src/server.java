import java.io.*;
import java.net.*;
import java.util.*;
public class server {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			ServerSocket ss = new ServerSocket(1030);
			Socket[] s = new Socket[100];
			for(int i=0;i<100;i++) {
				s[i] = ss.accept();
				Thread t = new Multiple(s[i]);
				t.start();
			}
			ss.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
}

class Multiple extends Thread {
	private Socket s;
	public Multiple(Socket i) {
		// TODO Auto-generated constructor stub
		s = i;
	}
	
	public void run() {
		try {
			Scanner sc = new Scanner(System.in);
			DataInputStream din = new DataInputStream(s.getInputStream());
			DataOutputStream dout = new DataOutputStream(s.getOutputStream());
			String name = din.readUTF();
			dout.writeUTF("Hello"+name);
			String str1="",str2="";
			while(!str1.equals("Bye")) {
				str1 = sc.next();
				dout.writeUTF(str1);
				str2 = din.readUTF();
				System.out.println(name+" says "+str2);
			}
			sc.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
	
}
