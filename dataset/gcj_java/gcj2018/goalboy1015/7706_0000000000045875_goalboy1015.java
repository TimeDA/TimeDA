import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			int[][] cells = new int[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cells[i][j] = sc.nextInt();
				}
			}

			System.out.println("Case #" + tc + ": " + solve(cells));
		}

		sc.close();
	}

	static int solve(int[][] cells) {
		int N = cells.length;

		int changeNum = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (isColAboveDup(cells, r, c, cells[r][c])) {
					for (int color = -N; color <= N; color++) {
						if (color != 0) {
							if (!isRowDup(cells, r, c, color) && !isColDup(cells, r, c, color)) {
								cells[r][c] = color;

								changeNum++;
								break;
							}
						}
					}
				}
			}

			for (int c = 0; c < N; c++) {
				if (isRowDup(cells, r, c, cells[r][c]) && isColDup(cells, r, c, cells[r][c])) {
					for (int color = -N; color <= N; color++) {
						if (color != 0) {
							if (!isRowDup(cells, r, c, color) && !isColDup(cells, r, c, color)) {
								cells[r][c] = color;

								changeNum++;
								break;
							}
						}
					}
				}
			}

			for (int c = 0; c < N; c++) {
				if (isRowDup(cells, r, c, cells[r][c])) {
					for (int color = -N; color <= N; color++) {
						if (color != 0) {
							if (!isRowDup(cells, r, c, color) && !isColDup(cells, r, c, color)) {
								cells[r][c] = color;

								changeNum++;
								break;
							}
						}
					}
				}
			}
		}
		return changeNum;
	}

	static boolean isRowDup(int[][] cells, int r, int c, int color) {
		int N = cells.length;
		for (int col = 0; col < N; col++) {
			if (col != c && cells[r][col] == color) {
				return true;
			}
		}
		return false;
	}

	static boolean isColDup(int[][] cells, int r, int c, int color) {
		int N = cells.length;
		for (int row = 0; row < N; row++) {
			if (row != r && cells[row][c] == color) {
				return true;
			}
		}
		return false;
	}

	static boolean isColAboveDup(int[][] cells, int r, int c, int color) {
		for (int row = 0; row < r; row++) {
			if (cells[row][c] == color) {
				return true;
			}
		}
		return false;
	}
}
