import java.io.BufferedInputStream;
 import java.io.File;
 import java.io.FileInputStream;
 import java.io.InputStream;
 import java.io.OutputStream;
 import java.io.PrintStream;
 import java.util.*;
 
 
 
 import static java.lang.Math.*; 
 import static java.util.Arrays.*;
 import static java.lang.Integer.*;
 import static java.lang.Character.*;  
 
 
 public class D {
 	static final int THREADS = 1;
 	static class Sol implements Runnable{
 		
 		boolean started = false;
 		Scanner scan;
 		int caseN;
 		
 		int intLine(){
 			return parseInt(scan.nextLine());
 		}
 		
 		
 		String res = "";
 		int n;
 		double[]N;
 		double[]B;
 		void readInput() {
 			n = scan.nextInt();
 			N = new double[n];
 			B = new double[n];
 			for(int i=0;i<n;i++) {
 				N[i]=scan.nextDouble();
 			}
 			for(int i=0;i<n;i++)B[i]=scan.nextDouble();
 		}
 		
 		
 		public void run(){
 			this.res = "";
 			sort(N);sort(B);
 			int r1=n,r2=0;
 			int p1=0,p2=0;
 			while(p2<n) {
 				while(p2<n && B[p2]<N[p1])p2++;
 				if(p2<n){
 					r1--;
 					p2++;
 				}
 				p1++;
 			}
 			p1=0;p2=0;
 			while(p1<n){
 				while(p1<n && N[p1]<B[p2])p1++;
 				if(p1<n) {
 					r2++;
 				p1++;p2++;
 				}
 			}
 			res+=r2+" "+r1;
 			System.err.println(caseN+" finished");
 		}
 
 		void printResult(PrintStream out) {
 			out.format("Case #%d: %s\n",caseN+1, res);
 		}
 	}
 
     static Sol[] solvers;
     
     static synchronized Sol getNext() {
     	for(int i=0;i<solvers.length;i++) {
     		if(!solvers[i].started){
     			solvers[i].started = true;
     			return solvers[i];
     		}
     	}
     	return null;
     }
     
     static class Worker extends Thread {
     	public void run() {
     		while(true) {
     			Sol sol = getNext();
     			if (sol == null)break;
     			sol.run();
     		}
     	}
     }
     
 	public static void main(String[] args) throws Exception{
 		Locale.setDefault(Locale.US);
 		String cn = D.class.getName();
 		String sampleName = cn+"-sample.in";
 		String smallName = cn+"-small-attempt0.in";
 		String largeName = cn+"-large.in";
 		String name = smallName;
 		String outName = name.substring(0, name.indexOf('.'))+".out";
 		InputStream in = new BufferedInputStream(new FileInputStream(name));
 		PrintStream out = new PrintStream(new File(outName));
 		//PrintStream out = System.out;
 		Scanner scan = new Scanner(in);
 		
 		int N = parseInt(scan.nextLine());
 		solvers = new Sol[N];
 		for(int i=0;i<solvers.length;i++) {
 			solvers[i] = new Sol();
 			solvers[i].scan = scan;
 			solvers[i].caseN = i;
 			solvers[i].readInput();
 		}
 		Thread[]threads = new Thread[THREADS];
 		for(int i=0;i<threads.length;i++){
 			threads[i]=new Worker();
 			threads[i].start();
 		}
 		for(int i=0;i<threads.length;i++){
 			threads[i].join();
 		}
 
 		for(Sol s:solvers)s.printResult(out);
 		System.err.println("All done");
 		
 	}
 
 }
 
 
