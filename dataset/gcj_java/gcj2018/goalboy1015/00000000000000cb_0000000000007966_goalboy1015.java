import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int D = sc.nextInt();
			String P = sc.next();

			System.out.println("Case #" + tc + ": " + solve(D, P));
		}

		sc.close();
	}

	static String solve(int D, String P) {
		StringBuilder s = new StringBuilder(P);
		int index = P.length() - 1;
		for (int i = 0;; i++) {
			if (computeDamage(s) <= D) {
				return String.valueOf(i);
			}

			while (true) {
				while (index >= 0 && s.charAt(index) != 'C') {
					index--;
				}

				if (index < 0) {
					return "IMPOSSIBLE";
				}

				if (index == s.length() - 1 || s.charAt(index + 1) == 'C') {
					index--;
				} else {
					char temp = s.charAt(index);
					s.setCharAt(index, s.charAt(index + 1));
					s.setCharAt(index + 1, temp);

					index++;

					break;
				}
			}
		}
	}

	static int computeDamage(StringBuilder s) {
		int beam = 1;
		int damage = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'C') {
				beam *= 2;
			} else {
				damage += beam;
			}
		}
		return damage;
	}
}
