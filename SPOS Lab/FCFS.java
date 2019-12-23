import java.io.*;
import java.util.*;

class FCFS{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ar=0,bt=0,ct=0,tat=0,wt=0;
		Vector<Integer> proc = new Vector<Integer>(n);
		Vector<Integer> arrvl = new Vector<Integer>(n);
		Vector<Integer> burst = new Vector<Integer>(n);
		Vector<Integer> compl = new Vector<Integer>(n);
		Vector<Integer> trnt = new Vector<Integer>(n);
		Vector<Integer> waiting = new Vector<Integer>(n);
		for(int i=0;i<n;++i){
			proc.add(i);
		}
		//System.out.println(proc);
		
		//Prompt user to put arrival time and burst time
		for(int j=0;j<proc.size();++j){
			System.out.println("Arrival time for "+proc.get(j)+":");
			ar = sc.nextInt();
			arrvl.add(ar);
			System.out.println("Burst time for "+proc.get(j)+":");
			bt = sc.nextInt();
			burst.add(bt);
		}
		
		//Calculating completion time
		/*
			completion time of a process is calculated by summing up the burst times of current and previous processes.
		*/
		for(int k=0;k<proc.size();++k){
			ct += burst.get(k);
			compl.add(ct);
		}
		
		//Calculating turn around time
		/*
			turn around time = completion time - arrival time
		*/
		for(int l=0;l<proc.size();++l){
			tat = compl.get(l) - arrvl.get(l);
			trnt.add(tat);
		}
		
		//Calculating waiting time
		/*
			waiting time = turn around time - burst time
		*/	
		for(int m=0;m<proc.size();++m){
			wt = trnt.get(m) - burst.get(m);
			waiting.add(wt);
		}
		
		//Printing entire process table
		System.out.println("Process\tArrival\tBurst\tCompletion\tTurnAround\tWaiting");
		for(int p=0;p<proc.size();++p){
			System.out.println(proc.get(p)+"\t"+arrvl.get(p)+"\t"+burst.get(p)+"\t"+compl.get(p)+"\t\t"+trnt.get(p)+"\t\t"+waiting.get(p));
		}
		
		//Calculating average waiting time
		int sumw=0,avgw=0;
		for(Integer elem: waiting){
			sumw += waiting.get(elem);
		}
		avgw = sumw/waiting.size();
		System.out.println("Average waiting time: "+avgw);		
	}
}
