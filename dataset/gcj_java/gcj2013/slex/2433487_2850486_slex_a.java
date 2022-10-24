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
 		int caseN;
 		
 		int intLine(){
 			return parseInt(scan.nextLine());
 		}
 		
 		
 		double res = 0;
 		long B;
 		long[]V;
 		int[]C;
 		int n;
 		void readInput() {
 			B = scan.nextLong();
 			n = scan.nextInt();
 			
 			TreeMap<Long, Integer>T = new TreeMap<Long, Integer>();
 			if(n < 37)T.put(0L, 37-n);
 			for(int i=0;i<n;i++) {
 				long x = scan.nextLong();
 				if(!T.containsKey(x))T.put(x,0);
 				T.put(x, T.get(x)+1);
 			}
 			V = new long[T.size()];
 			C = new int[T.size()];
 			int p =0;
 			for(long x:T.keySet()){
 				V[p]=x;
 				C[p++]=T.get(x);
 			}
 		}
 		
 		
 		public double solveBrut(){
 			double res = 0;
 			for(long bet = V[0]+1;bet<=2000;bet++){
 				long cost = 0;
 				int tot = 0;
 				for(int i=0;i<C.length;i++){
 					if(V[i] > bet)break;
 					cost += C[i]* (bet-V[i]);
 					tot += C[i];
 				}
 				double r = 0;
 				if(cost>B)break;
 				for(int i=0;i<C.length;i++){
 					if(V[i] > bet)break;
 					long add = bet - V[i];
 					
 					r += add * 36 * C[i];
 				}
 				r/=tot;
 				res = max(res,r-cost);
 			}
 			return res;
 		}
 		
 		public void run(){
 			this.res = solveBrut();/*
 			long total=0;
 			int toF = 0;
 			for(int i=0;i<C.length;i++){
 				if(V[i]!= 0){
 					long cost = V[i] * toF - total;
 					double r =0;
 					if(cost <=B){
 
 						for(int j =0;j<i;j++) {
 							double add = V[i]-V[j];
 							double p = C[j] * 1.0 / (toF+C[i]);
 							r += p * add * 36;
 						}
 						
 						
 						res = max(res, r - cost);
 					}
 				}
 				toF += C[i];
 				total += C[i]*V[i];
 			}
 			
 			total = 0;
 			toF = 0;
 			for(int i=0;i+1<C.length;i++){
 				toF += C[i];
 				total += C[i]*V[i];
 				long x = V[i+1]-1;
 				if(V[i]==V[i+1]-1)continue;
 				long mn = toF * (V[i]+1) - total;
 				if(mn > B)break;
 				long av = (B-mn)/toF;
 				x = min(x, av+V[i]+1);
 				long cost = toF * x - total;
 				double r =  0;
 				for(int j=0;j<=i;j++){
 					long add = x - V[i];
 					double p = C[i] * 1.0 / toF;
 					r += p * add * 36;
 				}
 				res = max(res, r-cost);
 			}
 			System.err.println(res +" "+solveBrut());*/
 			//System.err.println(caseN+" finished");
 		}
 
 		void printResult(PrintStream out) {
 			out.format("Case #%d: %f\n",caseN+1, res);
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
 		String smallName = cn+"-small-attempt5.in";
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
 
 
