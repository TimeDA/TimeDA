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
 	
 	Scanner scan;
 	public D(Scanner s) {
 		this.scan = s;
 	}
 
 	int nodes(ArrayList<String>A){
 		HashSet<String>H = new HashSet<>();
 		for(String s:A){
 			for(int i=1;i<=s.length();i++)H.add(s.substring(0,i));
 		}
 		return H.size()+1;
 	}
 	
 	public String solve() {
 		int m = scan.nextInt();
 		int n = scan.nextInt();
 		String[]A = new String[m];
 		for(int i=0;i<m;i++)A[i]=scan.next();
 		int p =1;for(int i=0;i<m;i++)p*=n;
 		int mx = 0;
 		int mc =0;
 
 		for(int x = 0;x<p;x++){
 			ArrayList<String>all = new ArrayList<>();
 			String xs = Integer.toString(x, n);
 			while(xs.length()<m)xs='0'+xs;
 			//System.out.println(xs);
 			boolean ok = true;
 			int r =0;
 			for(int i=0;i<n;i++){
 				ArrayList<String> B = new ArrayList<>();
 				for(int j=0;j<m;j++){
 					if(xs.charAt(j)=='0'+i)B.add(A[j]);
 				}
 				if(B.size()==0){ok =false;break;}
 				all.addAll(B);
 				r+=nodes(B);
 			}
 			if(!ok)continue;
 			if(all.size()!=m){
 				System.err.println("ERROR");
 			}
 			if(r==mx)mc++;
 			if(r>mx){
 				mx = r;mc=1;
 			}
 		}
 		return mx+" "+mc;
 	}
 	int intLine(){
 		return parseInt(scan.nextLine());
 	}
 	public static void main(String[] args) throws Exception{
 		Locale.setDefault(Locale.US);
 		String cn = D.class.getName();
 		String sampleName = cn+"-sample.in";
 		String smallName = cn+"-small-attempt1.in";
 		String largeName = cn+"-large.in";
 		String name = smallName;
 		String outName = name.substring(0, name.indexOf('.'))+".out2";
 		InputStream in = new BufferedInputStream(new FileInputStream(name));
 		PrintStream out = new PrintStream(new File(outName));
 		//PrintStream out = System.out;
 		Scanner scan = new Scanner(in);
 		
 		int N = parseInt(scan.nextLine());
 		for(int c=1;c<=N;c++) {
 			String res = new D(scan).solve();
 			out.printf("Case #%d: %s\n",c, res);
 			System.err.println(c + " done");
 		}
 		
 		System.err.println("All done");
 		
 	}
 
 }
 
 
