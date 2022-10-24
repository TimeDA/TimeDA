package qr2013;
 
 import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.util.StringTokenizer;
 
 public class Lawnmower {
 	public static void main(String[] args) throws Exception {
 		String fileName = args[0];
 		Lawnmower obj = new Lawnmower();
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
 			int M = Integer.parseInt(token.nextToken());
 
 			int[][] board = new int[N][M];
 			int[] xmax = new int[N];
 			int[] ymax = new int[M];
 
 			for (int j = 0; j < N; j++) {
 				str = br.readLine();
 				token = new StringTokenizer(str, " ");
 				for (int k = 0; k < M; k++) {
 					board[j][k] = Integer.parseInt(token.nextToken());
 					xmax[j] = Math.max(xmax[j], board[j][k]);
 					ymax[k] = Math.max(ymax[k], board[j][k]);
 				}
 			}
 
 			boolean flg = true;
 			for (int j = 0; j < N; j++) {
 				for (int k = 0; k < M; k++) {
 					if (!(board[j][k] == xmax[j] || board[j][k] == ymax[k])) {
 						flg = false;
 						break;
 					}
 				}
 			}
 
 			bw.write("Case #" + (i + 1) + ": ");
 			if (flg) {
 				bw.write("YES");
 			} else {
 				bw.write("NO");
 			}
 			bw.write("\r\n");
 		}
 		bw.close();
 		br.close();
 	}
 }
