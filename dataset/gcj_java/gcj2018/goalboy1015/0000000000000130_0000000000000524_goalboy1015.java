import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int D = sc.nextInt();
			int N = sc.nextInt();

			double maxTime = 0;
			for (int i = 0; i < N; i++) {
				int K = sc.nextInt();
				int S = sc.nextInt();

				maxTime = Math.max(maxTime, (double) (D - K) / S);
			}

			double result = D / maxTime;
			System.out.println("Case #" + tc + ": " + result);
		}

		sc.close();
	}
}
