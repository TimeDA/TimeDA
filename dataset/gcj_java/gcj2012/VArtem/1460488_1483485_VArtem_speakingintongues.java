import java.io.*;
 import java.util.*;
 
 public class SpeakingInTongues {
 
 	char[] map;
 	
 	void setMapping(String a, String b) {
 		for (int i = 0; i < a.length(); i++) {
 			if (Character.isLetter(a.charAt(i))) {
 				map[a.charAt(i) - 'a'] = b.charAt(i);
 			}
 		}
 	}
 	
 	void init() {
 		map = new char[26];
 		setMapping("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
 		setMapping("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
 		setMapping("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
 		setMapping("y qee", "a zoo");
 		boolean[] used = new boolean[26];
 		for (char c : map) {
 			if (Character.isLetter(c)) {
 				used[c - 'a'] = true;
 			}
 		}
 		
 		for (int i = 0; i < 26; i++) {
 			if (map[i] == 0) {
 				for (int j = 0; j < 26; j++) {
 					if (!used[j]) {
 						map[i] = (char) ('a' + j);
 					}
 				}
 			}
 		}
 		System.err.println(Arrays.toString(map));
 	}
 	
 	void solve() throws Exception {
 		String s = in.readLine();
 		for (char c : s.toCharArray()) {
 			if (Character.isLetter(c)) {
 				out.print(map[c - 'a']);
 			} else {
 				out.print(c);
 			}
 		}
 		out.println();
 	}
 
 	void run() {
 		try {
 			in = new BufferedReader(new FileReader("input.txt"));
 			out = new PrintWriter("output.txt");
 			
 			init();
 			int tests = nextInt();
 			for (int i = 0; i < tests; i++) {
 				out.print("Case #" + (i + 1) + ": ");
 				solve();
 			}
 			out.close();
 		} catch (Exception e) {
 			e.printStackTrace();
 			System.exit(1);
 		}
 	}
 
 	BufferedReader in;
 	StringTokenizer st;
 	PrintWriter out;
 	final String filename = new String("SpeakingInTongues").toLowerCase();
 
 	String nextToken() throws Exception {
 		while (st == null || !st.hasMoreTokens())
 			st = new StringTokenizer(in.readLine());
 		return st.nextToken();
 	}
 
 	int nextInt() throws Exception {
 		return Integer.parseInt(nextToken());
 	}
 
 	long nextLong() throws Exception {
 		return Long.parseLong(nextToken());
 	}
 
 	double nextDouble() throws Exception {
 		return Double.parseDouble(nextToken());
 	}
 
 	public static void main(String[] args) {
 		new SpeakingInTongues().run();
 	}
 
 }
