import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

// Solution
public class Solution {
	static Scanner in;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		outer:
		for(int T = ni(); T > 0;T--){
			int A = ni();
			for(int i = 1;i <= 5;i++){
				for(int j = 1;j <= 5;j++){
					boolean[][] filled = new boolean[3][3];
					int nf = 0;
					while(nf < 9){
						out.println((3*i) + " " + (3*j));
						out.flush();
						int x = ni(), y = ni();
						if(x == 0 && y == 0)continue outer;
						x -= (3*i-1);
						y -= (3*j-1);
						if(!filled[x][y]){
							filled[x][y] = true;
							nf++;
						}
					}
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
