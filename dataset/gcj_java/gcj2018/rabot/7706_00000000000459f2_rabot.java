import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(
				new BufferedReader(new InputStreamReader(System.in)));
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			int C = sc.nextInt();
			int[] B = new int[C];
			for (int c = 0 ; c < C ; c++ ) {
				B[c] = sc.nextInt();
			}
			
			if (B[0] == 0 || B[C - 1] == 0) {
				System.out.println("Case #" + (t + 1) + ": IMPOSSIBLE");
				continue;
			}
			char[][] lines = new char[C + 1][C];
			for (int i = 0 ; i < C ; i++ ) {
				Arrays.fill(lines[i], '.');
			}
			int max = -1;
			int cur = 0;
			for (int i = 0 ; i < C ; i++) {
				if (B[i] == 0) {
					continue;
				}
				if (cur < i) {
					for (int j = 0 ; j < i - cur ; j++ ) {
						lines[j + 1][i - 1 - j] = '\\';
						max = Math.max(max, j);
					}
				}
				if (i < cur + B[i] - 1) {
					for (int j = 0 ; j < (cur + B[i] - 1) - i ; j++ ) {
						lines[j + 1][i + 1 + j] = '/';
						max = Math.max(max, j);
					}
				}
				cur += B[i];
			}
			System.out.println("Case #" + (t + 1) + ": " + (max + 2));
			for (int i = max + 1 ; i >= 0 ; i--) {
				System.out.println(new String(lines[i]));
			}
		}
	}
}
