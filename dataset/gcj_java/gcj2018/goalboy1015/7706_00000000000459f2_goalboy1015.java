import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int C = sc.nextInt();
			int[] balls = new int[C];
			for (int i = 0; i < balls.length; i++) {
				balls[i] = sc.nextInt();
			}

			System.out.print("Case #" + tc + ": ");

			if (balls[0] == 0 || balls[balls.length - 1] == 0) {
				System.out.println("IMPOSSIBLE");
			} else {
				int[] leftSums = new int[C];
				int leftSum = 0;
				for (int i = 0; i < leftSums.length; i++) {
					leftSums[i] = leftSum;
					leftSum += balls[i];
				}

				int[] currents = new int[C];
				Arrays.fill(currents, 1);

				List<String> rows = new ArrayList<String>();
				while (true) {
					StringBuilder sb = new StringBuilder();

					int[] nexts = new int[C];

					int left = 0;
					for (int i = 0; i < C; i++) {
						if (left < leftSums[i]) {
							sb.append('/');

							nexts[i - 1] += currents[i];
						} else if (left + currents[i] <= leftSums[i] + balls[i]) {
							sb.append('.');

							nexts[i] += currents[i];
						} else {
							sb.append('\\');

							nexts[i + 1] += currents[i];
						}

						left += currents[i];
					}

					currents = nexts;

					String row = sb.toString();
					rows.add(row);

					if (row.chars().allMatch(ch -> ch == '.')) {
						break;
					}
				}

				System.out.println(rows.size());
				rows.stream().forEach(System.out::println);
			}
		}

		sc.close();
	}
}
