import static java.lang.Math.*;
 
 import java.io.BufferedInputStream;
 import java.io.BufferedOutputStream;
 import java.io.File;
 import java.io.FileInputStream;
 import java.io.InputStream;
 import java.io.PrintStream;
 import java.util.*;
 
 public class C {
 	Scanner scan;
 
 	public C(Scanner s) {
 		scan = s;
 	}
 	
 	int intLine(){
 		return Integer.parseInt(scan.nextLine());
 	}
 	
 	
 	public String solve() {
 		long n = scan.nextLong();
 		long k = scan.nextLong();
 		PriorityQueue<Long> Q = new PriorityQueue<>(new Comparator<Long>() {
 			@Override
 			public int compare(Long o1, Long o2) {
 				if(o1>o2)return -1;
 				else if(o1<o2)return 1;
 				return 0;
 			}
 		});
 		Q.add(n);
 		long l=0;long r=0;
 		for(long kk=0;kk<k;kk++){
 			n = Q.poll();
 			r = (n-1)/2;
 			if(n%2==1)l=r;
 			else l=r+1;
 			Q.add(l);Q.add(r);
 		}
 		return l+" "+r;
 	}
 	
 	
 	public static void main(String[] args) throws Exception{
 		Locale.setDefault(Locale.US);
 		String cn = C.class.getName();
 		String sampleName = cn+"-sample.in";
 		String smallName = cn+"-small-1-attempt0.in";
 		String largeName = cn+"-large.in";
 		String name = smallName;
 		String outName = name.substring(0, name.indexOf('.'))+".out";
 		InputStream in = new BufferedInputStream(new FileInputStream(name));
 		PrintStream out = new PrintStream(new File(outName));
 		//PrintStream out = System.out;
 		Scanner scan = new Scanner(in);
 		
 		int N = Integer.parseInt(scan.nextLine());
 		for(int c=1;c<=N;c++) {
 			String res = new C(scan).solve();
 			out.printf("Case #%d: %s\n",c, res);
 			if(out!=System.out)System.err.println(c + " done");
 		}
 		if(out!=System.out)System.err.println("All done");
 
 	}
 }
