import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 0; tc < T; tc++) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			sc.nextInt();

			int lower = A + 1;
			int upper = B;
			while (true) {
				int middle = (lower + upper) / 2;

				System.out.println(middle);
				System.out.flush();

				String message = sc.next();
				if (message.equals("CORRECT")) {
					break;
				} else if (message.equals("TOO_SMALL")) {
					lower = middle + 1;
				} else if (message.equals("TOO_BIG")) {
					upper = middle - 1;
				} else {
					System.exit(1);
				}
			}
		}

		sc.close();
	}
}
