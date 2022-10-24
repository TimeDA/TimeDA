package gcj2014r2;
 
 import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.util.HashSet;
 import java.util.StringTokenizer;
 
 public class TrieSharding {
 	public static void main(String[] args) throws Exception {
 		String fileName = args[0];
 		TrieSharding obj = new TrieSharding();
 		obj.solve(fileName);
 	}
 
 	public void solve(String fileName) throws Exception {
 		BufferedReader br = new BufferedReader(new FileReader(fileName));
 		BufferedWriter bw = new BufferedWriter(
 				new FileWriter(fileName + ".out"));
 
 		int T = Integer.parseInt(br.readLine());
 		for (int i = 0; i < T; i++) {
 			String str = br.readLine();
 			StringTokenizer token = new StringTokenizer(str, " ");
 			int M = Integer.parseInt(token.nextToken());
 			int N = Integer.parseInt(token.nextToken());
 
 			String[] S = new String[M];
 			for (int j = 0; j < M; j++) {
 				str = br.readLine();
 				S[j] = str;
 			}
 
 			int[] dist = new int[M];
 			dist[0] = -1;
 			int max = 0;
 			int cnt = 0;
 			HashSet<String>[] hash = new HashSet[N];
 			LOOP: while (true) {
 				for (int j = 0; j < M; j++) {
 					dist[j]++;
 					if (dist[j] < N) {
 						break;
 					}
 					dist[j] = 0;
 					if (j == M - 1) {
 						break LOOP;
 					}
 				}
 				for (int j = 0; j < N; j++) {
 					hash[j] = new HashSet<String>();
 				}
 				for (int j = 0; j < M; j++) {
 					for (int k = 0; k <= S[j].length(); k++) {
 						hash[dist[j]].add(S[j].substring(0, k));
 					}
 				}
 				int a = 0;
 				for (int j = 0; j < N; j++) {
 					if (hash[j].size() == 0) {
 						continue LOOP;
 					}
 					a += hash[j].size();
 				}
 				if (a > max) {
 					max = a;
 					cnt = 1;
 				} else if (a == max) {
 					cnt++;
 				}
 			}
 
 			bw.write("Case #" + (i + 1) + ": " + max + " " + cnt);
 			bw.write("\r\n");
 		}
 		bw.close();
 		br.close();
 	}
 }
