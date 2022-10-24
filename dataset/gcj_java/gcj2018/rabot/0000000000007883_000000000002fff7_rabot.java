import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(
				new BufferedReader(new InputStreamReader(System.in)));
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			int N = sc.nextInt();
			long P = sc.nextInt();

			int[] W = new int[N];
			int[] H = new int[N];
			double[] min = new double[N];
			double[] max = new double[N];
			double e = 0;
			for (int n = 0; n < N; n++) {
				W[n] = sc.nextInt();
				H[n] = sc.nextInt();
				e += 2 * (W[n] + H[n]);
				
				min[n] = Math.min(W[n], H[n]);
				max[n] = Math.sqrt(W[n] * W[n] + H[n] * H[n]);
			}
			
			// assumes W[i] = W[j], H[i] = H[j]

			double ans = e;
			double minsum = 0;
			double maxsum = 0;
			for (int c = 0 ; c < N ; c++) {
				minsum += 2 * min[c];
				maxsum += 2 * max[c];
				if (e + minsum <= P) {
					double a = Math.min(e + maxsum, P);
					ans = Math.max(ans, a);
				}
			}
			
			DecimalFormat df = new DecimalFormat("#.0000000");
			System.out.println("Case #" + (t + 1) + ": " + df.format(ans));
		}
	}
}
