package gcj2014r2;
 
 import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.util.Arrays;
 import java.util.StringTokenizer;
 
 public class UpAndDown {
 	public static void main(String[] args) throws Exception {
 		String fileName = args[0];
 		UpAndDown obj = new UpAndDown();
 		obj.solve(fileName);
 	}
 
 	public void solve(String fileName) throws Exception {
 		BufferedReader br = new BufferedReader(new FileReader(fileName));
 		BufferedWriter bw = new BufferedWriter(
 				new FileWriter(fileName + ".out"));
 
 		int T = Integer.parseInt(br.readLine());
 		for (int i = 0; i < T; i++) {
 			String str = br.readLine();
 			int N = Integer.parseInt(str);
 
 			str = br.readLine();
 			StringTokenizer token = new StringTokenizer(str, " ");
 			int[] A = new int[N];
 			int[] B = new int[N];
 			for (int j = 0; j < N; j++) {
 				A[j] = Integer.parseInt(token.nextToken());
 				B[j] = A[j];
 			}
 			Arrays.sort(B);
 
 			int cur_a = 0;
 			int cur_b = N - 1;
 			int cnt = 0;
 			for (int j = 0; j < N; j++) {
 				int pos = -1;
 				for (int k = 0; k < N; k++) {
 					if (B[j] == A[k]) {
 						pos = k;
 						break;
 					}
 				}
 				if (pos - cur_a > cur_b - pos) {
 					for (int k = pos; k < cur_b; k++) {
 						int tmp = A[k];
 						A[k] = A[k + 1];
 						A[k + 1] = tmp;
 						cnt++;
 					}
 					cur_b--;
 				} else {
 					for (int k = pos; k > cur_a; k--) {
 						int tmp = A[k];
 						A[k] = A[k - 1];
 						A[k - 1] = tmp;
 						cnt++;
 					}
 					cur_a++;
 				}
 			}
 
 			bw.write("Case #" + (i + 1) + ": " + cnt);
 			bw.write("\r\n");
 			//for (int j = 0 ; j < N ; j++) {
 			//	bw.write(Integer.toString(A[j]));
 			//	bw.write(" ");
 			//}
 			//bw.write("\r\n");
 		}
 		bw.close();
 		br.close();
 	}
 }
