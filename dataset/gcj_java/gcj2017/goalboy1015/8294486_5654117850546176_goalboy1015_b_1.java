import java.util.Scanner;
 
 public class B_1 {
 	public static void main(String[] args) {
 		Scanner sc = new Scanner(System.in);
 
 		int T = sc.nextInt();
 		for (int tc = 1; tc <= T; tc++) {
 			System.out.print("Case #" + tc + ": ");
 
 			sc.nextInt();
 			int R = sc.nextInt();
 			sc.nextInt();
 			int Y = sc.nextInt();
 			sc.nextInt();
 			int B = sc.nextInt();
 			sc.nextInt();
 
 			System.out.println(solve(R, 'R', Y, 'Y', B, 'B'));
 		}
 
 		sc.close();
 	}
 
 	static String solve(int A, char a, int B, char b, int C, char c) {
 		if (A < B) {
 			return solve(B, b, A, a, C, c);
 		}
 		if (A < C) {
 			return solve(C, c, A, a, B, b);
 		}
 
 		if (A > B + C) {
 			return "IMPOSSIBLE";
 		}
 
 		String result = "";
 		for (int i = 0; i < A; i++) {
 			if (i < B) {
 				result += b;
 			}
 
 			if (i >= A - C) {
 				result += c;
 			}
 
 			result += a;
 		}
 		return result;
 	}
 }