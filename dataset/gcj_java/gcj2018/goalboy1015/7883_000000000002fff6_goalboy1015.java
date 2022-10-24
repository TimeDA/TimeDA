import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int R = sc.nextInt();
			int B = sc.nextInt();
			int C = sc.nextInt();
			Cashier[] cashiers = new Cashier[C];
			for (int i = 0; i < cashiers.length; i++) {
				int M = sc.nextInt();
				int S = sc.nextInt();
				int P = sc.nextInt();
				cashiers[i] = new Cashier(M, S, P);
			}

			System.out.println("Case #" + tc + ": " + solve(R, B, cashiers));
		}

		sc.close();
	}

	static long solve(int R, int B, Cashier[] cashiers) {
		long upper = 0;
		for (Cashier cashier : cashiers) {
			upper = Math.max(upper, (long) cashier.M * cashier.S + cashier.P);
		}

		long lower = 0;
		long result = -1;
		while (lower <= upper) {
			long middle = (lower + upper) / 2;

			if (check(R, B, cashiers, middle)) {
				result = middle;

				upper = middle - 1;
			} else {
				lower = middle + 1;
			}
		}
		return result;
	}

	static boolean check(int R, int B, Cashier[] cashiers, long time) {
		List<Long> bitNums = new ArrayList<Long>();
		for (Cashier cashier : cashiers) {
			bitNums.add(Math.min(cashier.M, Math.max(0, (time - cashier.P) / cashier.S)));
		}

		Collections.sort(bitNums, Collections.reverseOrder());
		long total = 0;
		for (int i = 0; i < R; i++) {
			total += bitNums.get(i);
		}
		return total >= B;
	}
}

class Cashier {
	int M;
	int S;
	int P;

	Cashier(int m, int s, int p) {
		M = m;
		S = s;
		P = p;
	}
}