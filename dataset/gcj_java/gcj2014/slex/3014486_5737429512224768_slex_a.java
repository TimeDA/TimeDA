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
 	
 	Scanner scan;
 	public A(Scanner s) {
 		this.scan = s;
 	}
 
 	public String solve() {
 		int n = scan.nextInt();
 		int M = scan.nextInt();
 		int[]A = new int[n];
 		for(int i=0;i<n;i++)A[i]=scan.nextInt();
 		sort(A);
 		for(int x = (n+1)/2;x<=n;x++){
 			boolean ok = true;
 			int dbl =n-x;
 			int a = 0;
 			int b = 2*dbl-1;
 			while(a<b){
 				if(A[a]+A[b]>M)ok = false;
 				a++;b--;
 			}
 			if(ok)return ""+x;
 		}
 		return "error";
 	}
 	int intLine(){
 		return parseInt(scan.nextLine());
 	}
 	public static void main(String[] args) throws Exception{
 		Locale.setDefault(Locale.US);
 		String cn = A.class.getName();
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
 			String res = new A(scan).solve();
 			out.printf("Case #%d: %s\n",c, res);
 			System.err.println(c + " done");
 		}
 		
 		System.err.println("All done");
 		
 	}
 
 }
 
 
