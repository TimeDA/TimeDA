package gcj2014r2;
 
 import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.util.ArrayList;
 import java.util.StringTokenizer;
 
 public class DontBreakTheNile {
 	public static void main(String[] args) throws Exception {
 		String fileName = args[0];
 		DontBreakTheNile obj = new DontBreakTheNile();
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
 			int W = Integer.parseInt(token.nextToken());
 			int H = Integer.parseInt(token.nextToken());
 			int B = Integer.parseInt(token.nextToken());
 
 			int[] X0 = new int[B];
 			int[] X1 = new int[B];
 			int[] Y0 = new int[B];
 			int[] Y1 = new int[B];
 			for (int j = 0; j < B; j++) {
 				str = br.readLine();
 				StringTokenizer token2 = new StringTokenizer(str, " ");
 				X0[j] = Integer.parseInt(token2.nextToken());
 				Y0[j] = Integer.parseInt(token2.nextToken());
 				X1[j] = Integer.parseInt(token2.nextToken());
 				Y1[j] = Integer.parseInt(token2.nextToken());
 			}
 
 			int[][] riv = new int[W + 2][H];
 			for (int b = 0; b < B; b++) {
 				for (int x = X0[b]; x <= X1[b]; x++) {
 					for (int y = Y0[b]; y <= Y1[b]; y++) {
 						riv[x + 1][y] = -1;
 					}
 				}
 			}
 			for (int y = 0; y < H; y++) {
 				riv[0][y] = -1;
 				riv[W + 1][y] = -1;
 			}
 
 			int cnt = 0;
 			for (int j = 1; j <= W; j++) {
 				if (riv[j][0] != 0) {
 					continue;
 				}
 				int x = j;
 				int y = 0;
 				ArrayList<int[]> step = new ArrayList();
 				LOOP:while (true) {
 					step.add(new int[] { x, y });
 					if (y == H - 1) {
 						cnt++;
 						break;
 					}
 					if (riv[x - 1][y] == 0) {
 						riv[x - 1][y] = j;
 						x = x - 1;
 						continue;
 					} else if (riv[x][y + 1] == 0) {
 						riv[x][y + 1] = j;
 						y = y + 1;
 						continue;
 					} else if (riv[x + 1][y] == 0) {
 						riv[x + 1][y] = j;
 						x = x + 1;
 						continue;
 					} else if (y != 0 && riv[x][y - 1] == 0) {
 						riv[x][y - 1] = j;
 						y = y - 1;
 						continue;
 					}
 					for (int k = step.size() - 1; k >= 0; k--) {
 						int a = step.get(k)[0];
 						int b = step.get(k)[1];
 						step.remove(k);
 						if (riv[a - 1][b] == 0 || riv[a + 1][b] == 0
 								|| riv[a][b + 1] == 0
 								|| (b != 0 && riv[a][b - 1] == 0)) {
 							x = a;
 							y = b;
 							continue LOOP;
 						}
 					}
 					break;
 				}
 			}
 			bw.write("Case #" + (i + 1) + ": " + cnt);
 			bw.write("\r\n");
 		}
 		bw.close();
 		br.close();
 	}
 }
