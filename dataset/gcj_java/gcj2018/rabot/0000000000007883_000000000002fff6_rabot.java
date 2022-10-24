import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(
				new BufferedReader(new InputStreamReader(System.in)));
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			int R = sc.nextInt();
			int B = sc.nextInt();
			int C = sc.nextInt();

			long[] M = new long[C];
			long[] S = new long[C];
			long[] P = new long[C];
			for (int c = 0; c < C; c++) {
				M[c] = sc.nextInt();
				S[c] = sc.nextInt();
				P[c] = sc.nextInt();
			}

			long mint = 0;
			long maxt = Long.MAX_VALUE;
			long curt = 0;
			long[] cnt = new long[C];
			while (maxt - mint > 1) {
				curt = (mint + maxt) / 2;

				for (int c = 0; c < C; c++) {
					if (curt < P[c]) {
						cnt[c] = 0;
					} else {
						cnt[c] = Math.min((curt - P[c]) / S[c], M[c]);
					}
				}
				Arrays.sort(cnt);

				long total = 0;
				for (int c = 0; c < R; c++) {
					total += cnt[C - c - 1];
					if (total >= B) {
						break;
					}
				}

				if (total >= B) {
					maxt = curt;
				} else {
					mint = curt;
				}
			}

			System.out.println("Case #" + (t + 1) + ": " + maxt);
		}
	}
}
