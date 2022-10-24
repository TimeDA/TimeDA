import java.util.Scanner;
 
 public class A {
 	public static void main(String[] args) {
 		Scanner sc = new Scanner(System.in);
 
 		int T = sc.nextInt();
 		for (int tc = 1; tc <= T; tc++) {
 			System.out.print("Case #" + tc + ": ");
 
 			String S = sc.next();
 			int K = sc.nextInt();
 			int result = solve(S, K, true);
 			System.out.println(result < 0 ? "IMPOSSIBLE" : result);
 		}
 
 		sc.close();
 	}
 
 	static int solve(String S, int K, boolean leftOrRight) {
 		int length = S.length();
 
 		if (length == 0) {
 			return 0;
 		}
 
 		if (S.charAt(0) == '+') {
 			return solve(S.substring(1), K, leftOrRight);
 		}
 		if (S.charAt(length - 1) == '+') {
 			return solve(S.substring(0, length - 1), K, leftOrRight);
 		}
 
 		if (length < K) {
 			return -1;
 		}
 
 		if (leftOrRight) {
 			int subResult = solve(flip(S.substring(0, K)) + S.substring(K), K, !leftOrRight);
 			return subResult < 0 ? -1 : (1 + subResult);
 		} else {
 			int subResult = solve(S.substring(0, length - K) + flip(S.substring(length - K)), K, !leftOrRight);
 			return subResult < 0 ? -1 : (1 + subResult);
 		}
 	}
 
 	static String flip(String s) {
 		char[] flipped = s.toCharArray();
 		for (int i = 0; i < flipped.length; i++) {
 			flipped[i] = flipped[i] == '+' ? '-' : '+';
 		}
 		return new String(flipped);
 	}
 }
