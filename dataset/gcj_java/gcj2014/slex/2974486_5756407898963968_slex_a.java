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
 
 
 public class A {
 	static final int THREADS = 1;
 	static class Sol implements Runnable{
 		
 		boolean started = false;
 		Scanner scan;
 		HashSet<Integer>H = new HashSet<>();
 		int caseN;
 		
 		int intLine(){
 			return parseInt(scan.nextLine());
 		}
 		
 		
 		String res = "";
 
 		void readInput() {
 			HashSet<Integer>T = new HashSet<>();
 			int r1 = scan.nextInt()-1;
 			for(int r =0;r<4;r++)for(int i=0;i<4;i++){
 				int x = scan.nextInt();
 				if(r==r1)T.add(x);
 			}
 			r1 = scan.nextInt()-1;
 			for(int r =0;r<4;r++)for(int i=0;i<4;i++){
 				int x = scan.nextInt();
 				if(r==r1 && T.contains(x))H.add(x);
 			}
 		}
 		
 		
 		public void run(){
 			if(H.size()==1)res= H.iterator().next()+"";
 			if(H.size()>1)res= "Bad magician!";
 			if(H.size()==0)res=  "Volunteer cheated!";
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
 		String cn = A.class.getName();
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
 
 
