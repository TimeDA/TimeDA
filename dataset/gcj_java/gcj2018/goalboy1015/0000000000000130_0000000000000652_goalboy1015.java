import java.util.Scanner;
import java.util.SortedMap;
import java.util.TreeMap;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			long N = sc.nextLong();
			long K = sc.nextLong();

			SortedMap<Long, Long> length2count = new TreeMap<Long, Long>();
			length2count.put(N, 1L);
			long remain = K;
			while (true) {
				long maxLength = length2count.lastKey();
				long count = length2count.remove(maxLength);

				long nextMinLength = (maxLength - 1) / 2;
				long nextMaxLength = maxLength - 1 - nextMinLength;

				if (remain <= count) {
					System.out.println("Case #" + tc + ": " + nextMaxLength + " " + nextMinLength);

					break;
				}

				remain -= count;
				increase(length2count, nextMinLength, count);
				increase(length2count, nextMaxLength, count);
			}
		}

		sc.close();
	}

	static void increase(SortedMap<Long, Long> length2count, long length, long delta) {
		length2count.put(length, length2count.getOrDefault(length, 0L) + delta);
	}
}
