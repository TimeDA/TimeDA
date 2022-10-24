import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		Scanner sc = new Scanner(
				new BufferedReader(new InputStreamReader(System.in)));
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			int A = sc.nextInt();

			int FULL = 0b111111111;

			int x = 2;
			int y = 2;
			int flag = 0;
			while (true) {
				System.out.println(x + " " + y);
				System.out.flush();

				int rx = sc.nextInt();
				int ry = sc.nextInt();
				if (rx == 0 && ry == 0) {
					break;
				} else if (rx == -1 && ry == -1) {
					System.exit(0);
				}

				int pos = (rx - (x - 1)) * 3 + (ry - (y - 1));
				flag |= (1 << pos);

				if (flag == FULL) {
					x += 3;
					flag = 0;
				}
			}
		}
	}
}
