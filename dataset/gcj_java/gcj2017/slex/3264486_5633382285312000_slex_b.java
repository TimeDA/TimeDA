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
 		char[]s = scan.next().toCharArray();
 		for(int i=s.length-2;i>=0;i--){
 			if(s[i]>s[i+1]){
 				s[i]--;
 				for(int j=i+1;j<s.length;j++)s[j]='9';
 			}
 		}
 		long r = Long.parseLong(new String(s));
 		return ""+r;
 	}
 	
 	
 	public static void main(String[] args) throws Exception{
 		Locale.setDefault(Locale.US);
 		String cn = B.class.getName();
 		String sampleName = cn+"-sample.in";
 		String smallName = cn+"-small-attempt0.in";
 		String largeName = cn+"-large.in";
 		String name = smallName;
 		String outName = name.substring(0, name.indexOf('.'))+".out";
 		InputStream in = new BufferedInputStream(new FileInputStream(name));
 		PrintStream out = new PrintStream(new File(outName));
 		//PrintStream out = System.out;
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
