import java.io.*;
 import java.util.*;
 
 public class A {
 	private static String fileName = A.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
 	private static String inputFileName = fileName + ".in";
 	private static String outputFileName = fileName + ".out";
 	private static Scanner in;
 	private static PrintWriter out;
 	
 	final int M = 1000002013;
 
 	private void solve() {
 		int n = in.nextInt();
 		int m = in.nextInt();
 		int[] from = new int[m];
 		int[] to = new int[m];
 		int[] amount = new int[m];
 		Set<Integer> imp = new TreeSet<Integer>();
 		long honest = 0;
 		for (int i = 0; i < m; i++) {
 			from[i] = in.nextInt() - 1;
 			to[i] = in.nextInt() - 1;
 			amount[i] = in.nextInt();
 			imp.add(from[i]);
 			imp.add(to[i]);
 			int dist = to[i] - from[i];
 			long h = (n + n - dist + 1L) * dist / 2;
 			h %= M;
 			honest += amount[i] * h;
 			honest %= M;
 		}
 		long cheat = 0;
 		TreeMap<Integer, Long> people = new TreeMap<Integer, Long>();
 		for (int x : imp) {
 			long in = 0;
 			for (int i = 0; i < m; i++) {
 				if (from[i] == x) {
 					in += amount[i];
 				}
 			}
 			if (in > 0) {
 				people.put(x, in);
 			}
 			long out = 0;
 			for (int i = 0; i < m; i++) {
 				if (to[i] == x) {
 					out += amount[i];
 				}
 			}
 			while (out > 0) {
 				int y = people.lastKey();
 				long z = Math.min(out, people.get(y));
 				int dist = x - y;
 				long h = (n + n - dist + 1L) * dist / 2;
 				h %= M;
 				cheat += (z % M) * h;
 				cheat %= M;
 				out -= z;
 				z = people.get(y) - z;
 				if (z == 0) {
 					people.remove(y);
 				} else {
 					people.put(y, z);
 				}
 			}
 		}
 		if (!people.isEmpty()) {
 			throw new RuntimeException();
 		}
 		long ans = (honest - cheat) % M;
 		ans += M;
 		ans %= M;
 		out.println(ans);
 	}
 
 	public static void main(String[] args) throws IOException {
 		Locale.setDefault(Locale.US);
 		if (args.length >= 2) {
 			inputFileName = args[0];
 			outputFileName = args[1];
 		}
 		in = new Scanner(new File(inputFileName));
 		out = new PrintWriter(outputFileName);
 		int tests = in.nextInt();
 		in.nextLine();
 		for (int t = 1; t <= tests; t++) {
 			out.print("Case #" + t + ": ");
 			new A().solve();
 			System.out.println("Case #" + t + ": solved");
 		}
 		in.close();
 		out.close();
 	}
 }
