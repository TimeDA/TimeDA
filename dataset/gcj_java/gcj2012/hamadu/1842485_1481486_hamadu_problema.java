import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileWriter;
 import java.io.IOException;
 import java.io.InputStreamReader;
 import java.util.Queue;
 import java.util.concurrent.ArrayBlockingQueue;
 
 public class ProblemA {
 	
 	public static String solve(long[] pos, long[] len, long di) {
 		int n = len.length;
 		long willgo = pos[1] * 2;
 		int grab = 1;
 		while (true) {
 			if (willgo >= di) {
 				return "YES";
 			}
 			int next = grab + 1;
 			int max = -1;
 			long maxnext = 0;
 			while (next < n && pos[next] <= willgo) {
 				long dist = -1;
 				if (pos[next] - pos[grab] < len[next]) {
 					dist = 2L * pos[next] - pos[grab];
 				} else {
 					dist = pos[next] + len[next];
 				}
 				if (maxnext < dist) {
 					maxnext = dist;
 					max = next;
 				}
 				next++;
 			}
 			if (max == -1) {
 				return "NO";
 			}
 			grab = max;
 			willgo = maxnext;
 		}
 	}
 	
 	public static void main(String[] args) throws IOException {
 		BufferedReader s = new BufferedReader(new InputStreamReader(System.in));
 		BufferedWriter w = new BufferedWriter(new FileWriter("./src/output.txt"));
 		int T = Integer.valueOf(s.readLine());
 		for (int t = 1 ; t <= T ; t++) {
 			int n = Integer.valueOf(s.readLine());
 			long[] pos = new long[n+1];
 			long[] len = new long[n+1];
 			for (int i = 1 ; i <= n ; i++) {
 				String[] line = s.readLine().split(" ");
 				pos[i] = Integer.valueOf(line[0]);
 				len[i] = Integer.valueOf(line[1]);
 			}
 			String res = solve(pos, len, Long.valueOf(s.readLine()));
 			w.write("Case #" + t + ": " + res);
 			w.newLine();
 		}
 		w.flush();
 		w.close();
 	}
 }