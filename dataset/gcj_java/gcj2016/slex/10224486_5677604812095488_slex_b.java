import static java.lang.Math.*;
 
 import java.io.BufferedInputStream;
 import java.io.BufferedOutputStream;
 import java.io.File;
 import java.io.FileInputStream;
 import java.io.InputStream;
 import java.io.PrintStream;
 import java.util.*;
 
 public class B {
 	Scanner scan;
 
 	public B(Scanner s) {
 		scan = s;
 	}
 	
 	int intLine(){
 		return Integer.parseInt(scan.nextLine());
 	}
 	
 	
 	public String solve() {
 		int n = scan.nextInt();
 		int k= scan.nextInt();
 		double[]P = new double[n];
 		for(int i=0;i<P.length;i++)P[i]=scan.nextDouble();
 		double res =0;
 		for(int m=0;m<(1<<n);m++){
 			if(Integer.bitCount(m)!=k)continue;
 			double[]A = new double[k/2+1];
 			A[0]=1;
 			for(int i=0;i<n;i++){
 				if((m&(1<<i))==0)continue;
 				double x = P[i];
 				double[]NA =new double[n];
 				for(int j=0;j<A.length;j++){
 					NA[j]=A[j]*(1-x);
 					if(j>0)NA[j]+=A[j-1]*x;
 				}
 				A = NA;
 			}
 			res = max(res, A[k/2]);
 		}
 		return ""+res;
 	}
 	
 	
 	public static void main(String[] args) throws Exception{
 		Locale.setDefault(Locale.US);
 		String cn = "src/"+B.class.getName();
 		String sampleName = cn+"-sample.in";
 		String smallName = cn+"-small-attempt0.in";
 		String largeName = cn+"-large.in";
 		
 		String name = smallName;
 		
 		String outName = name.substring(0, name.indexOf('.'))+".out";
 		InputStream in = new BufferedInputStream(new FileInputStream(name));
 		PrintStream out =null;
 		out = new PrintStream(new File(outName));
 		if(out==null) out = System.out;
 		Scanner scan = new Scanner(in);
 		
 		int N = Integer.parseInt(scan.nextLine());
 		for(int c=1;c<=N;c++) {
 			String res = new B(scan).solve();
 			out.printf("Case #%d: %s\n",c, res);
 			if(out!=System.out)System.err.println(c + " done");
 		}
 		if(out!=System.out)System.err.println("All done");
 		
 	}
 }
