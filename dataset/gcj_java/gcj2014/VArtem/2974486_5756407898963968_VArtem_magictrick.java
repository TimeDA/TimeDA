import java.io.*;
 import java.util.*;
 
 public class MagicTrick {
 
 	FastScanner in;
 	PrintWriter out;
 
 	void solve() {
 		int mask = getMask() & getMask();
 		if (mask == 0) {
 			out.println("Volunteer cheated!");
 		} else if (Integer.bitCount(mask) > 1) {
 			out.println("Bad magician!");
 		} else {
 			out.println(31 - Integer.numberOfLeadingZeros(mask));
 		}
 	}
 
 	private int getMask() {
 		int row = in.nextInt() - 1;
 		int mask = 0;
 		for (int i = 0; i < 4; i++) {
 			for (int j = 0; j < 4; j++) {
 				int val = in.nextInt();
 				if (i == row) {
 					mask |= 1 << val;
 				}
 			}
 		}
 		return mask;
 	}
 
 	void run() {
 		try {
 			in = new FastScanner("input.txt");
 			out = new PrintWriter("output.txt");
 			int T = in.nextInt();
 			for (int i = 1; i <= T; i++) {
 				long time = System.currentTimeMillis();
 				out.printf("Case #%d: ", i);
 				solve();
 				System.err.println("Test #" + i + " done in " + (System.currentTimeMillis() - time)
 						+ " ms");
 			}
 			out.close();
 		} catch (Exception e) {
 			e.printStackTrace();
 		}
 	}
 
 	class FastScanner {
 		BufferedReader br;
 		StringTokenizer st;
 
 		public FastScanner(String s) {
 			try {
 				br = new BufferedReader(new FileReader(s));
 			} catch (FileNotFoundException e) {
 				// TODO Auto-generated catch block
 				e.printStackTrace();
 			}
 		}
 
 		String nextToken() {
 			while (st == null || !st.hasMoreElements()) {
 				try {
 					st = new StringTokenizer(br.readLine());
 				} catch (IOException e) {
 					// TODO Auto-generated catch block
 					e.printStackTrace();
 				}
 			}
 			return st.nextToken();
 		}
 
 		int nextInt() {
 			return Integer.parseInt(nextToken());
 		}
 
 		long nextLong() {
 			return Long.parseLong(nextToken());
 		}
 
 		double nextDouble() {
 			return Double.parseDouble(nextToken());
 		}
 	}
 
 	public static void main(String[] args) {
 		new MagicTrick().run();
 	}
 }
