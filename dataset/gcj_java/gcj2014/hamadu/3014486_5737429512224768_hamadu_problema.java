import java.io.PrintWriter;
 import java.util.Arrays;
 import java.util.HashSet;
 import java.util.Scanner;
 import java.util.Set;
 
 
 public class ProblemA {
 	/**
 	 * @param args
 	 */
 	public static void main(String[] args) {
 		Scanner in = new Scanner(System.in);
 		PrintWriter out = new PrintWriter(System.out);
 		
 		int T = in.nextInt();
 		for (int cn = 1 ; cn <= T ; cn++) {
 			int N = in.nextInt();
 			int X = in.nextInt();
 			int[] f = new int[N];
 			for (int i = 0 ; i < N ; i++) {
 				f[i] = in.nextInt();
 			}
 			out.println(String.format("Case #%d: %s", cn, solve(f, X)));
 		}
 		out.flush();
 	}
 	
 
 
 	private static Object solve(int[] f, int x) {
 		Arrays.sort(f);
 		
 		int n = f.length;
 		int count = 0;
 		
 		int head = 0;
 		int tail = n-1;
 		boolean[] done = new boolean[n];
 		while (head <= tail) {
 			if (head == tail) {
 				done[head] = true;
 				count++;
 				break;
 			}
 			int h = f[head];
 			while (head < tail && h + f[tail] > x) {
 				tail--;
 			}
 			done[head] = done[tail] = true;
 			head++;
 			tail--;
 			count++;
 		}
 		for (int i = 0 ; i < n ; i++) {
 			if (!done[i]) {
 				count++;
 			}
 		}
 		
 		
 		
 		
 		return count;
 	}
 
 
 
 	public static void debug(Object... o) {
 		System.err.println(Arrays.deepToString(o));
 	}
 }
