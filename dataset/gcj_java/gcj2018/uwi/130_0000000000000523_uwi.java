import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

class A {
	static Scanner in;
	static PrintWriter out;
	static String INPUT = "";
	
	static int q(int h)
	{
		out.println(h);
		out.flush();
		String res = in.next();
		if(res.trim().equals("TOO_BIG"))return 1;
		if(res.trim().equals("TOO_SMALL"))return -1;
		if(res.trim().equals("CORRECT"))return 0;
		return 2;
//		throw new RuntimeException();
	}
	
	static void solve()
	{
		outer:
		for(int T = ni();T > 0;T--){
			int a = ni(), b = ni();
			int n = ni();
			// (a,b]
			while(true){
				int h = a+b+1>>1;
				int q = q(h);
				if(q == 2)continue outer;
				if(q == 1){
					b = h-1;
				}else if(q == -1){
					a = h;
				}else{
					break;
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception
	{
		long S = System.currentTimeMillis();
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G-S+"ms");
	}
	
	static int ni() { return Integer.parseInt(in.next()); }
	static void tr(Object... o) { if(!INPUT.isEmpty())System.out.println(Arrays.deepToString(o)); }
}
