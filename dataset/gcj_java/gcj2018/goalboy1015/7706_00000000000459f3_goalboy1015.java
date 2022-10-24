import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int R = sc.nextInt();
			int B = sc.nextInt();

			System.out.println("Case #" + tc + ": " + solve(R, B));
		}

		sc.close();
	}

	static int solve(int R, int B) {
		int ways[][] = new int[R + 1][B + 1];
		for (int r = 0; r <= R; r++) {
			for (int b = 0; b <= B; b++) {
				if (r + b == 0) {
					continue;
				}

				int[][] nextWays = new int[R + 1][B + 1];

				for (int i = 0; i <= R; i++) {
					for (int j = 0; j <= B; j++) {
						nextWays[i][j] = ways[i][j];
					}
				}

				for (int i = 0; i + r <= R; i++) {
					for (int j = 0; j + b <= B; j++) {
						nextWays[i + r][j + b] = Math.max(nextWays[i + r][j + b], ways[i][j] + 1);
					}
				}

				ways = nextWays;
			}
		}

		return ways[R][B];
	}
}
