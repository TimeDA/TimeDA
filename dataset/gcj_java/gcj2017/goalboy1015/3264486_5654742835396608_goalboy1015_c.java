import java.util.Scanner;
 
 public class C {
 	public static void main(String[] args) {
 		Scanner sc = new Scanner(System.in);
 
 		int T = sc.nextInt();
 		for (int tc = 1; tc <= T; tc++) {
 			System.out.print("Case #" + tc + ": ");
 
 			int N = sc.nextInt();
 			int K = sc.nextInt();
 			int[] result = solve(N, K);
 			System.out.println(result[0] + " " + result[1]);
 		}
 
 		sc.close();
 	}
 
 	static int[] solve(int N, int K) {
 		int[] counts = new int[N + 1];
 		counts[N] = 1;
 
 		int size = N;
 		int left = -1;
 		int right = -1;
 		for (int i = 0; i < K; i++) {
 			while (counts[size] == 0) {
 				size--;
 			}
 
 			left = (size - 1) / 2;
 			right = size - 1 - left;
 
 			counts[size]--;
 			counts[left]++;
 			counts[right]++;
 		}
 		return new int[] { right, left };
 	}
 }
