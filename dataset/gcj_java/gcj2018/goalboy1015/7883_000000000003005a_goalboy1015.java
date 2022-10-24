import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int R = sc.nextInt();
			int C = sc.nextInt();
			int H = sc.nextInt();
			int V = sc.nextInt();
			char[][] cells = new char[R][C];
			for (int r = 0; r < R; r++) {
				String line = sc.next();
				for (int c = 0; c < C; c++) {
					cells[r][c] = line.charAt(c);
				}
			}

			System.out.println("Case #" + tc + ": " + (solve(cells, H, V) ? "POSSIBLE" : "IMPOSSIBLE"));
		}

		sc.close();
	}

	static boolean solve(char[][] cells, int H, int V) {
		int R = cells.length;
		int C = cells[0].length;

		int[] rowCounts = new int[R];
		int[] colCounts = new int[C];
		int total = 0;
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (cells[r][c] == '@') {
					rowCounts[r]++;
					colCounts[c]++;
					total++;
				}
			}
		}

		if (total % ((H + 1) * (V + 1)) != 0) {
			return false;
		}

		int rowPart = total / (H + 1);
		int colPart = total / (V + 1);
		int unitPart = total / ((H + 1) * (V + 1));

		List<Integer> rowCuts = new ArrayList<Integer>();
		int sum = 0;
		for (int r = 0; r < R; r++) {
			sum += rowCounts[r];

			if (sum > rowPart) {
				return false;
			} else if (sum == rowPart) {
				rowCuts.add(r);
				sum = 0;
			}
		}

		List<Integer> colCuts = new ArrayList<Integer>();
		sum = 0;
		for (int c = 0; c < C; c++) {
			sum += colCounts[c];

			if (sum > colPart) {
				return false;
			} else if (sum == colPart) {
				colCuts.add(c);
				sum = 0;
			}
		}

		for (int i = 0; i < rowCuts.size(); i++) {
			int beginRow = i == 0 ? 0 : (rowCuts.get(i - 1) + 1);
			int endRow = rowCuts.get(i);
			for (int j = 0; j < colCuts.size(); j++) {
				int beginCol = j == 0 ? 0 : (colCuts.get(j - 1) + 1);
				int endCol = colCuts.get(j);

				int unit = 0;
				for (int r = beginRow; r <= endRow; r++) {
					for (int c = beginCol; c <= endCol; c++) {
						if (cells[r][c] == '@') {
							unit++;
						}
					}
				}
				if (unit != unitPart) {
					return false;
				}
			}
		}
		return true;
	}
}
