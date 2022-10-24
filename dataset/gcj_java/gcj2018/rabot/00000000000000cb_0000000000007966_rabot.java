import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		Scanner sc = new Scanner(
				new BufferedReader(new InputStreamReader(System.in)));
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			int D = sc.nextInt();
			String P = sc.next();

			char[] p = P.toCharArray();

			int cnt = 0;
			int dmg = 0;
			int strength = 1;
			for (int j = 0; j < p.length; j++) {
				switch (p[j]) {
				case 'C':
					strength = strength * 2;
					break;
				case 'S':
					dmg += strength;
					cnt++;
					break;
				default:
					break;
				}
			}
			System.out.print("Case #" + (i + 1) + ": ");
			if (D < cnt) {
				System.out.println("IMPOSSIBLE");
				continue;
			}
			int ans = 0;
			while (D < dmg && ans < 1000000) {
				int curStrength = strength;
				for (int j = p.length - 1 ; j >= 1 ; j-- ) {
					if (p[j] == 'C') {
						curStrength = curStrength / 2;
					} else if (p[j] == 'S') {
						if (p[j-1] == 'C') {
							p[j-1] = 'S';
							p[j] = 'C';
							dmg -= curStrength / 2;
							ans++;
							break;
						}
					}
				}
			}
			if ( ans < 1000000) {
				System.out.println(ans);
			} else {
				System.out.println("IMPOSSIBLE");
			}
		}
	}
}
