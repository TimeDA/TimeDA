import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		Scanner sc = new Scanner(
				new BufferedReader(new InputStreamReader(System.in)));
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			int N = sc.nextInt();

			int[][] V = new int[2][];
			V[0] = new int[(N + 1) / 2];
			V[1] = new int[N / 2];

			for (int j = 0; j < N; j++) {
				V[j % 2][j / 2] = sc.nextInt();
			}

			Arrays.sort(V[0]);
			Arrays.sort(V[1]);

			int ans = -1;
			for (int j = 0; j < N - 1; j++) {
				if (V[j % 2][j / 2] > V[(j + 1) % 2][(j + 1) / 2]) {
					ans = j;
					break;
				}
			}

			System.out.print("Case #" + (i + 1) + ": ");
			if (ans >= 0) {
				System.out.println(ans);
			} else {
				System.out.println("OK");
			}
		}
	}
}
