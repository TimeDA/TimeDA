import java.util.HashSet;
 import java.util.Scanner;
 import java.util.Set;
 import java.util.stream.IntStream;
 
 public class D {
 	public static void main(String[] args) {
 		Scanner sc = new Scanner(System.in);
 
 		int T = sc.nextInt();
 		for (int tc = 1; tc <= T; tc++) {
 			System.out.print("Case #" + tc + ": ");
 
 			int N = sc.nextInt();
 			int[][] cells = new int[N][N];
 			int M = sc.nextInt();
 			for (int i = 0; i < M; i++) {
 				char type = sc.next().charAt(0);
 				int r = sc.nextInt() - 1;
 				int c = sc.nextInt() - 1;
 				cells[r][c] = encode(type);
 			}
 
 			int[][] filled = solve(cells);
 			int point = 0;
 			int changeNum = 0;
 			StringBuilder arrangement = new StringBuilder();
 			for (int r = 0; r < N; r++) {
 				for (int c = 0; c < N; c++) {
 					int value = filled[r][c];
 
 					if (value == 1 || value == 2) {
 						point++;
 					} else if (value == 3) {
 						point += 2;
 					}
 
 					if (value != cells[r][c]) {
 						changeNum++;
 
 						arrangement.append(String.format("%c %d %d\n", decode(value), r + 1, c + 1));
 					}
 				}
 			}
 			System.out.println(point + " " + changeNum);
 			System.out.print(arrangement);
 		}
 
 		sc.close();
 	}
 
 	static int encode(char type) {
 		if (type == '+') {
 			return 1;
 		} else if (type == 'x') {
 			return 2;
 		} else {
 			return 3;
 		}
 	}
 
 	static char decode(int value) {
 		if (value == 1) {
 			return '+';
 		} else if (value == 2) {
 			return 'x';
 		} else {
 			return 'o';
 		}
 	}
 
 	static int[][] solve(int[][] cells) {
 		int N = cells.length;
 
 		int[][] filled = new int[N][N];
 
 		for (int i = 0; i < N; i++) {
 			filled[0][i] += 1;
 		}
 		for (int i = 1; i < N - 1; i++) {
 			filled[N - 1][i] += 1;
 		}
 
 		Set<Integer> rows = IntStream.range(0, N).collect(HashSet<Integer>::new, Set<Integer>::add,
 				Set<Integer>::addAll);
 		Set<Integer> cols = IntStream.range(0, N).collect(HashSet<Integer>::new, Set<Integer>::add,
 				Set<Integer>::addAll);
 		for (int i = 0; i < N; i++) {
 			if (cells[0][i] == 2 || cells[0][i] == 3) {
 				filled[0][i] += 2;
 
 				rows.remove(0);
 				cols.remove(i);
 			}
 		}
 
 		while (!rows.isEmpty()) {
 			int r = rows.iterator().next();
 			int c = cols.iterator().next();
 
 			filled[r][c] += 2;
 
 			rows.remove(r);
 			cols.remove(c);
 		}
 
 		return filled;
 	}
 }
