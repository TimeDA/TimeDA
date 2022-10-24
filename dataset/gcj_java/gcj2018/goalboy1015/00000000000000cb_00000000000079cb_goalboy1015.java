import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws Throwable {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String line = in.readLine();
		StringTokenizer st = new StringTokenizer(line);
		int T = Integer.parseInt(st.nextToken());

		for (int tc = 1; tc <= T; tc++) {
			line = in.readLine();
			st = new StringTokenizer(line);
			int N = Integer.parseInt(st.nextToken());

			line = in.readLine();
			st = new StringTokenizer(line);
			int[] v = new int[N];
			for (int i = 0; i < v.length; i++) {
				v[i] = Integer.parseInt(st.nextToken());
			}

			System.out.println("Case #" + tc + ": " + solve(v));
		}
	}

	static String solve(int[] v) {
		List<Integer> evens = new ArrayList<Integer>();
		List<Integer> odds = new ArrayList<Integer>();
		for (int i = 0; i < v.length; i++) {
			if (i % 2 == 0) {
				evens.add(v[i]);
			} else {
				odds.add(v[i]);
			}
		}

		Collections.sort(evens);
		Collections.sort(odds);

		int[] sorted = new int[v.length];
		for (int i = 0; i < sorted.length; i++) {
			if (i % 2 == 0) {
				sorted[i] = evens.get(i / 2);
			} else {
				sorted[i] = odds.get(i / 2);
			}

			if (i > 0 && sorted[i] < sorted[i - 1]) {
				return String.valueOf(i - 1);
			}
		}
		return "OK";
	}
}
