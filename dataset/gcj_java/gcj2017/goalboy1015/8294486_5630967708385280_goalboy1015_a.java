import java.util.Scanner;
 
 public class A {
 	public static void main(String[] args) {
 		Scanner sc = new Scanner(System.in);
 
 		int T = sc.nextInt();
 		for (int tc = 1; tc <= T; tc++) {
 			System.out.print("Case #" + tc + ": ");
 
 			int D = sc.nextInt();
 			int N = sc.nextInt();
 			int[] K = new int[N];
 			int[] S = new int[N];
 			for (int i = 0; i < N; i++) {
 				K[i] = sc.nextInt();
 				S[i] = sc.nextInt();
 			}
 
 			System.out.println(solve(D, K, S));
 		}
 
 		sc.close();
 	}
 
 	static double solve(int D, int[] K, int[] S) {
 		double maxTime = 0;
 		for (int i = 0; i < K.length; i++) {
 			maxTime = Math.max(maxTime, ((double) (D - K[i])) / S[i]);
 		}
 		return D / maxTime;
 	}
 }
