import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			int P = sc.nextInt();
			Cookie[] cookies = new Cookie[N];
			for (int i = 0; i < cookies.length; i++) {
				int H = sc.nextInt();
				int W = sc.nextInt();
				cookies[i] = new Cookie(H, W);
			}

			System.out.println("Case #" + tc + ": " + solve(cookies, P));
		}

		sc.close();
	}

	static double solve(Cookie[] cookies, int P) {
		int base = 0;
		for (Cookie cookie : cookies) {
			base += (cookie.H + cookie.W) * 2;
		}

		int target = P - base;

		List<Range> ranges = new ArrayList<Range>();
		ranges.add(new Range(0, 0));
		for (Cookie cookie : cookies) {
			List<Range> nextRanges = new ArrayList<Range>();

			double lower = 2 * Math.min(cookie.H, cookie.W);
			double upper = 2 * (Math.sqrt(cookie.H * cookie.H + cookie.W * cookie.W));

			for (Range range : ranges) {
				nextRanges.add(range);
				nextRanges.add(range.add(lower, upper));
			}

			Collections.sort(nextRanges);

			nextRanges = merge(nextRanges);
			nextRanges = cut(nextRanges, target);

			ranges = nextRanges;
		}
		return base + ranges.get(ranges.size() - 1).right;
	}

	static List<Range> cut(List<Range> ranges, int target) {
		List<Range> result = new ArrayList<Range>();
		for (Range range : ranges) {
			if (range.left > target) {
				continue;
			} else {
				result.add(new Range(range.left, Math.min(target, range.right)));
			}
		}
		return result;
	}

	static List<Range> merge(List<Range> ranges) {
		List<Range> result = new ArrayList<Range>();
		double prevRight = -1;
		for (Range range : ranges) {
			if (range.right <= prevRight) {
				continue;
			} else if (range.left <= prevRight) {
				result.get(result.size() - 1).right = range.right;
				prevRight = range.right;
			} else {
				result.add(range);
				prevRight = range.right;
			}
		}
		return result;
	}
}

class Range implements Comparable<Range> {
	double left;
	double right;

	Range(double left, double right) {
		this.left = left;
		this.right = right;
	}

	@Override
	public int compareTo(Range other) {
		return Double.compare(left, other.left);
	}

	Range add(double lower, double upper) {
		return new Range(left + lower, right + upper);
	}
}

class Cookie {
	int H;
	int W;

	Cookie(int h, int w) {
		H = h;
		W = w;
	}
}