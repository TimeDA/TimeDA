import java.io.BufferedInputStream;
 import java.io.FileInputStream;
 import java.io.InputStream;
 import java.util.*;
 
 import static java.lang.Math.*; 
 import static java.util.Arrays.*;
 import static java.lang.Integer.*;
 import static java.lang.Character.*;  
 
 
 
 public class A {
 
 	Scanner scan;
 	InputStream in;
 	int[]d;
 	int[]l;
 	int D;
 	HashMap<Long, Boolean>H = new HashMap<Long, Boolean>();
 	boolean can(int p, int len){
 		long m = ((long)p)<<32;
 		m+=len;
 		if(H.containsKey(m))return H.get(m);
 		if(len >= D-d[p]) return true;
 		for(int i=p+1;i<l.length;i++){
 			if(d[i]-d[p]<=len){
 				int x = min(d[i]-d[p], l[i]);
 				if(can(i,x)){
 					H.put(m, true);
 					return true;
 				}
 			} //else break;
 		}
 		H.put(m, false);
 		return false;
 	}
 	int intLine(){
 		return parseInt(scan.nextLine());
 	}
 	
 	String solve(){
 		long res=0;
 		int n = scan.nextInt();
 		d = new int[n];
 		l = new int[n];
 		for(int i=0;i<n;i++){
 			d[i]=scan.nextInt();
 			l[i]=scan.nextInt();
 		}
 		H.clear();
 		D =scan.nextInt();
 		int len = d[0];
 		int c =0;
 		return can(0,d[0])?"YES":"NO";
 		
 	}
 	
 	void solveAll(){
 		int N = parseInt(scan.nextLine());
 		for(int i=0;i<N;i++){
 			String r =solve();
 			System.out.format("Case #%d: %s\n",i+1,r);
 		}
 	}
 	
 	A() throws Exception{
 		String cn = A.class.getName();
 		String sampleName = cn+"-sample.in";
 		String smallName = cn+"-small-attempt1.in";
 		String largeName = cn+"-large.in";
 		InputStream in = new BufferedInputStream(new FileInputStream(smallName));
 		scan = new Scanner(in);
 	}
 	
 	public static void main(String[] args) throws Exception{
 	    Locale.setDefault(Locale.US); 
 	    new A().solveAll();
 	}
 
 }
