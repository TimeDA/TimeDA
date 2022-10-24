import java.util.Scanner;
 
 public class A {
 	public static void main(String[] args) {
 		Scanner sc = new Scanner(System.in);
 
 		int T = sc.nextInt();
 		for (int tc = 1; tc <= T; tc++) {
 			System.out.println("Case #" + tc + ":");
 
 			int R = sc.nextInt();
 			int C = sc.nextInt();
 			char[][] grids = new char[R][C];
 			for (int i = 0; i < R; i++) {
 				String line = sc.next();
 				for (int j = 0; j < C; j++) {
 					grids[i][j] = line.charAt(j);
 				}
 			}
 
 			fill(grids);
 
 			for (int i = 0; i < R; i++) {
 				for (int j = 0; j < C; j++) {
 					System.out.print(grids[i][j]);
 				}
 				System.out.println();
 			}
 		}
 
 		sc.close();
 	}
 
 	static void fill(char[][] grids) {
 		int R = grids.length;
 		int C = grids[0].length;
 
 		for (int i = 0; i < R; i++) {
 			if (hasFilled(grids[i])) {
 				int startIndex = 0;
 				char last = 0;
 				for (int j = 0; j < C; j++) {
 					if (grids[i][j] != '?') {
 						for (int k = startIndex; k < j; k++) {
 							grids[i][k] = grids[i][j];
 						}
 						last = grids[i][j];
 						startIndex = j + 1;
 					}
 				}
 
 				for (int j = startIndex; j < C; j++) {
 					grids[i][j] = last;
 				}
 			}
 		}
 
 		int startRow = 0;
 		int lastSrc = -1;
 		for (int i = 0; i < R; i++) {
 			if (grids[i][0] != '?') {
 				for (int k = startRow; k < i; k++) {
 					copyRow(grids, i, k);
 				}
 				lastSrc = i;
 				startRow = i + 1;
 			}
 		}
 		for (int k = startRow; k < R; k++) {
 			copyRow(grids, lastSrc, k);
 		}
 	}
 
 	static void copyRow(char[][] grids, int src, int dest) {
 		for (int i = 0; i < grids[0].length; i++) {
 			grids[dest][i] = grids[src][i];
 		}
 	}
 
 	static boolean hasFilled(char[] row) {
 		for (int i = 0; i < row.length; i++) {
 			if (row[i] != '?') {
 				return true;
 			}
 		}
 		return false;
 	}
 }
