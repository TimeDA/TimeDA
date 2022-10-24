import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Solution {
	static int R = 0;
	static int C = 0;
	static int H = 0;
	static int V = 0;
	static String[] w = null;
	static int[] rc = null;
	static int[] cc = null;
	static int total = 0;

	static final String IMPOSSIBLE = "IMPOSSIBLE";
	static final String POSSIBLE = "POSSIBLE";

	public static void main(String[] args) {
		Scanner sc = new Scanner(
				new BufferedReader(new InputStreamReader(System.in)));
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			R = sc.nextInt();
			C = sc.nextInt();
			H = sc.nextInt();
			V = sc.nextInt();
			w = new String[R];
			for (int r = 0; r < R; r++) {
				w[r] = sc.next();
			}

			rc = new int[R];
			cc = new int[C];
			total = 0;
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					if (w[r].charAt(c) == '@') {
						rc[r]++;
						cc[c]++;
						total++;
					}
				}
			}

			if (total % ((H + 1) * (V + 1)) != 0) {
				System.out.println("Case #" + (t + 1) + ": " + IMPOSSIBLE);
				continue;
			}

			int p = total / ((H + 1) * (V + 1));
			int[] hcut = new int[H + 1];
			if (rech(0, p, hcut, 0)) {
				System.out.println("Case #" + (t + 1) + ": " +  POSSIBLE);
				continue;
			} else {
				System.out.println("Case #" + (t + 1) + ": " +  IMPOSSIBLE);
				continue;
			}
		}
	}

	static boolean rech(int cur, int p, int[] hcut, int hcnt) {
		if (hcnt >= H) {
			hcut[H] = R;
			return recv(0, p, 0, hcut);
		}
		int cnt = 0;
		for (int r = cur; r < R; r++) {
			cnt += rc[r];
			if (cnt == p * (V + 1)) {
				hcut[hcnt] = r + 1;
				if (rech(r + 1, p, hcut, hcnt + 1)) {
					return true;
				}
			} else if (cnt > p * (V + 1)) {
				return false;
			}
		}
		return false;
	}

	static boolean recv(int cur, int p, int vcnt, int[] hcut) {
		if (vcnt >= V) {
			return check(p, hcut, cur, C);
		}
		int cnt = 0;
		for (int c = cur; c < C; c++) {
			cnt += cc[c];
			if (cnt == p * (H + 1)) {
				if (!check(p, hcut, cur, c + 1)) {
					continue;
				}
				if (recv(c + 1, p, vcnt + 1, hcut)) {
					return true;
				}
			} else if (cnt > p * (H + 1)) {
				return false;
			}
		}
		return false;
	}

	static boolean check(int p, int[] hcut, int minc, int maxc) {
		for (int i = 0; i <= H; i++) {
			int minr = (i == 0) ? 0 : hcut[i - 1];
			int cnt = 0;
			for (int r = minr; r < hcut[i]; r++) {
				for (int c = minc; c < maxc; c++) {
					if (w[r].charAt(c) == '@') {
						cnt++;
					}
				}
			}
			if (cnt != p) {
				return false;
			}
		}
		return true;
	}
}
