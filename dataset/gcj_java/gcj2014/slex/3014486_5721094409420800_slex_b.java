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
 
 
 public class B {
 	
 	Scanner scan;
 	public B(Scanner s) {
 		this.scan = s;
 	}
 	
 	int kt(int[]a, int[]b){
 		int res =0;
 		HashMap<Integer, Integer>H = new HashMap();
 		for(int i=0;i<b.length;i++)H.put(b[i], i);
 		for(int i=0;i<a.length;i++)for(int j=i+1;j<a.length;j++){
 			int i1  = H.get(a[i]);int i2 = H.get(a[j]);
 			if(i1>i2)res++;
 		}
 			
 		return res;
 	}
 	
 	int dist(int[]a, int[]b) {
 		int res =0;
 		for(int i=0;i<a.length;i++){
 			int j=i;
 			for(;j<b.length;j++){
 				if(b[j]==a[i])break;
 			}
 			while(j>i){
 				int t = b[j-1];b[j-1]=b[j];b[j]=t;
 				j--;res++;
 			}
 		}
 		return res;
 	}
 
 	public String solve() {
 		int n = scan.nextInt();
 		int[]a = new int[n];
 		int mval = -1;
 		int res = n*n;
 		for(int i=0;i<n;i++){
 			a[i]=scan.nextInt();
 			mval = max(mval, a[i]);
 		}
 		
 		PerInt per = new PerInt(n);
 		int perms = 0;
 		while(per.hasNext()) {
 			perms++;
 			int[] b = per.St;
 			int[] aa = new int[n];
 			for(int i=0;i<n;i++)aa[i]=a[b[i]];
 			boolean ok = true;
 			boolean past = false;
 			if(aa[0]==mval)past = true;
 			for(int i=0;i+1<n;i++) {
 				if(!past && aa[i+1]<aa[i]){ok = false;break;}
 				if(past && aa[i+1]>aa[i]){ok = false;break;}
 				if(aa[i+1]==mval)past = true;
 			}
 			if(!past){
 			//	System.err.println("Error");
 			}
 			if(ok){
 				int d = dist(a, aa.clone());
 				int d1 = kt(a, aa);
 				if(d!=d1){
 					System.err.println(d+" "+d1);
 				}
 				res = min(res, d);
 			}
 			per.next();
 		}
 		
 		if(perms != siln(n))System.err.println("ERRRRRRR");
 		if(res==n*n)System.err.println("ERROR");
 		return res+"";
 	}
 	
 	public static final long siln( long n ){
 		int x = 1;
 		while( n > 1){ x *= n; n--;}
 		return x;
 	}
 	int intLine(){
 		return parseInt(scan.nextLine());
 	}
 	public static void main(String[] args) throws Exception{
 		Locale.setDefault(Locale.US);
 		String cn = B.class.getName();
 		String sampleName = cn+"-sample.in";
 		String smallName = cn+"-small-attempt1.in";
 		String largeName = cn+"-large.in";
 		String name = smallName;
 		String outName = name.substring(0, name.indexOf('.'))+".out";
 		InputStream in = new BufferedInputStream(new FileInputStream(name));
 		PrintStream out = new PrintStream(new File(outName));
 		//PrintStream out = System.out;
 		Scanner scan = new Scanner(in);
 		
 		int N = parseInt(scan.nextLine());
 		for(int c=1;c<=N;c++) {
 			String res = new B(scan).solve();
 			out.printf("Case #%d: %s\n",c, res);
 			System.err.println(c + " done");
 		}
 		
 		System.err.println("All done");
 		
 	}
 	class PerInt {
 		int[] St;
 		public PerInt( int n){
 			St = new int[n];
 			for( int i = 0; i < St.length; i++ ) St[i] = i;
 		}
 		public int[] next(){		
 			int j = St.length - 1;
 			while( j > 0 && St[j] < St[j-1] )j--;
 			if( j > 0 ){
 				int k = j - 1;
 				int x = St[k];
 				j = St.length - 1;
 				while( St[j] < x) j--;
 				St[k] = St[j];
 				St[j] = x;
 				for( j = 0; j < (St.length-k)/2;j++ ){
 					x = St[k+1+j];
 					St[k+1+j] = St[St.length-1 -j];
 					St[St.length-j-1] = x;
 				}
 			}
 			else St = null;
 			return St;	
 		}
 		public boolean hasNext(){
 			return St != null;
 		}
 	}
 
 }
 
 
