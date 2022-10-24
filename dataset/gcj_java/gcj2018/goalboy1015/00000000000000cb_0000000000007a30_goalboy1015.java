import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int A = sc.nextInt();

			int row;
			int col;
			if (A == 20) {
				row = 4;
				col = 5;
			} else {
				row = 10;
				col = 20;
			}

			boolean complete = false;
			boolean[][] visited = new boolean[row + 1][col + 1];
			for (int r = 1; r <= row; r++) {
				for (int c = 1; c <= col;) {
					if (visited[r][c]) {
						c++;
					} else {
						int centerR = Math.min(r + 1, row - 1);
						int centerC = Math.min(c + 1, col - 1);

						System.out.println(centerR + " " + centerC);
						System.out.flush();

						int actualR = sc.nextInt();
						int actualC = sc.nextInt();
						if (actualR == 0 && actualC == 0) {
							complete = true;
							break;
						} else if (actualR == -1 && actualC == -1) {
							System.exit(1);
						}

						visited[actualR][actualC] = true;
					}
				}

				if (complete) {
					break;
				}
			}
		}

		sc.close();
	}
}
