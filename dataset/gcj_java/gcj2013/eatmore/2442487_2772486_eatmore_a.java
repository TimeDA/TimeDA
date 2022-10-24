import static java.lang.Double.parseDouble;
 import static java.lang.Integer.parseInt;
 import static java.lang.Long.parseLong;
 import static java.lang.System.exit;
 import static java.math.BigInteger.ZERO;
 import static java.util.Arrays.sort;
 
 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;
 import java.io.OutputStreamWriter;
 import java.io.PrintWriter;
 import java.math.BigInteger;
 import java.util.ArrayList;
 import java.util.HashMap;
 import java.util.List;
 import java.util.Map;
 import java.util.StringTokenizer;
 
 public class A {
 	
 	static BufferedReader in;
 	static PrintWriter out;
 	static StringTokenizer tok;
 	static int test;
 	
 	static long cost(int n, int dist) {
 		return (long) dist * (2 * n - dist + 1) / 2;
 	}
 	
 	static void adjust(Map<Integer, Long> change, int at, int val) {
 		if (change.containsKey(at)) {
 			change.put(at, change.get(at) + val);
 		} else {
 			change.put(at, (long) val);
 		}
 	}
 	
 	static class People {
 		final int where;
 		long howMany;
 		
 		People(int where, long howMany) {
 			this.where = where;
 			this.howMany = howMany;
 		}
 	}
 	
 	static void solve() throws Exception {
 		int n = nextInt();
 		int m = nextInt();
 		Map<Integer, Long> change = new HashMap<>();
 		BigInteger ans = ZERO;
 		for (int i = 0; i < m; i++) {
 			int o = nextInt() - 1;
 			int e = nextInt() - 1;
 			int p = nextInt();
 			ans = ans.add(BigInteger.valueOf(cost(n, e - o)).multiply(BigInteger.valueOf(p)));
 			adjust(change, o, p);
 			adjust(change, e, -p);
 		}
 		Integer pos[] = (Integer[]) change.keySet().toArray(new Integer[change.size()]);
 		sort(pos);
 		List<People> people = new ArrayList<>();
 		for (int i: pos) {
 			long ch = change.get(i);
 			if (ch > 0) {
 				people.add(new People(i, ch));
 			} else {
 				while (ch < 0) {
 					People last = people.get(people.size() - 1);
 					if (last.howMany > -ch) {
 						ans = ans.subtract(BigInteger.valueOf(cost(n, i - last.where)).multiply(BigInteger.valueOf(-ch)));
 						last.howMany -= -ch;
 						ch = 0;
 					} else {
 						ans = ans.subtract(BigInteger.valueOf(cost(n, i - last.where)).multiply(BigInteger.valueOf(last.howMany)));
 						ch += last.howMany;
 						people.remove(people.size() - 1);
 					}
 				}
 			}
 		}
 		printCase();
 		out.println(ans);
 	}
 	
 	static void printCase() {
 		out.print("Case #" + test + ": ");
 	}
 	
 	static void printlnCase() {
 		out.println("Case #" + test + ":");
 	}
 	
 	static int nextInt() throws IOException {
 		return parseInt(next());
 	}
 
 	static long nextLong() throws IOException {
 		return parseLong(next());
 	}
 
 	static double nextDouble() throws IOException {
 		return parseDouble(next());
 	}
 
 	static String next() throws IOException {
 		while (tok == null || !tok.hasMoreTokens()) {
 			tok = new StringTokenizer(in.readLine());
 		}
 		return tok.nextToken();
 	}
 
 	public static void main(String[] args) {
 		try {
 			in = new BufferedReader(new InputStreamReader(System.in));
 			out = new PrintWriter(new OutputStreamWriter(System.out));
 			int tests = nextInt();
 			for (test = 1; test <= tests; test++) {
 				solve();
 			}
 			in.close();
 			out.close();
 		} catch (Throwable e) {
 			e.printStackTrace();
 			exit(1);
 		}
 	}
 }