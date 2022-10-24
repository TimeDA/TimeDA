package gcj2014r2;
 
 import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.util.Arrays;
 import java.util.StringTokenizer;
 
 public class DataPacking {
 	public static void main(String[] args) throws Exception {
 		String fileName = args[0];
 		DataPacking obj = new DataPacking();
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
 			int N = Integer.parseInt(token.nextToken());
 			int X = Integer.parseInt(token.nextToken());
 
 			str = br.readLine();
 			StringTokenizer token2 = new StringTokenizer(str," ");
 			int[] S = new int[N];
 			for (int j = 0 ; j < N ; j++) {
 				S[j] = Integer.parseInt(token2.nextToken());
 			}
 			Arrays.sort(S);
 
 			int cur_a = 0;
 			int cur_b = N-1;
 			int cnt = 0;
 			while (cur_a < N && cur_b >= 0 && cur_a <= cur_b) {
 				cnt++;
 				if (cur_a >= cur_b) {
 					break;
 				}
 				if (S[cur_a] + S[cur_b] <= X) {
 					cur_a++;
 				}
 				cur_b--;
 			}
 
 			bw.write("Case #" + (i + 1) + ": " + cnt);
 			bw.write("\r\n");
 		}
 		bw.close();
 		br.close();
 	}
 }
