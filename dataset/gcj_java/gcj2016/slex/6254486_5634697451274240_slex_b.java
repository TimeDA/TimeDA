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
 	
 	
 	int doit(String s){
 		if(!s.contains("-"))return 0;
 		int i=1;
 		while(i<s.length() &&s.charAt(i-1)==s.charAt(i))i++;
 		String ss="";
 		for(int j=0;j<i;j++){
 			if(s.charAt(0)=='-')ss+="+";
 			else ss+="-";
 		}
 		ss+= s.substring(i);
 		return 1+doit(ss);
 	}
 	
 	public String solve() {
 		String s = scan.next();
 		return ""+doit(s);
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
