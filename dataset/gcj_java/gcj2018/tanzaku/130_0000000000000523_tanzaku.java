import java.io.PrintWriter;
import java.util.Scanner;

public class Solution {
	void solveTestcase(final Scanner in, final PrintWriter out) {
		int a = in.nextInt() + 1;
		int b = in.nextInt() + 1;
		int n = in.nextInt();
		while (true) {
			int mid = (a + b) / 2;
			out.println(mid);
			out.flush();
			final char[] c = in.next().toCharArray();
			if (c[4] == 'B') {
				b = mid;
			} else if (c[4] == 'S') {
				a = mid;
			} else {
				break;
			}
		}
	}
	
	void solve() {
		try (final PrintWriter out = new PrintWriter(System.out)) {
			try (final Scanner in = new Scanner(System.in)) {
				int t = in.nextInt();
				while (t-- > 0) {
					solveTestcase(in, out);
				}
			}
		}
	}

	public static void main(String[] args) {
		new Solution().solve();
	}

}
