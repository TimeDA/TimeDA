import java.util.Scanner;
 
 public class B {
 	public static void main(String[] args) {
 		Scanner sc = new Scanner(System.in);
 
 		int T = sc.nextInt();
 		for (int tc = 1; tc <= T; tc++) {
 			System.out.print("Case #" + tc + ": ");
 
 			String N = sc.next();
 			System.out.println(solve(N));
 		}
 
 		sc.close();
 	}
 
 	static String solve(String N) {
 		int length = N.length();
 
 		String allOnes = repeat('1', length);
 		if (Long.parseLong(N) < Long.parseLong(allOnes)) {
 			return repeat('9', length - 1);
 		}
 
 		StringBuilder result = new StringBuilder();
 		for (int i = 0; i < length; i++) {
 			if (i > 0 && N.charAt(i) < N.charAt(i - 1)) {
 				while (result.length() > 1
 						&& result.charAt(result.length() - 1) == result.charAt(result.length() - 2)) {
 					result.deleteCharAt(result.length() - 1);
 				}
 
 				result.setCharAt(result.length() - 1, (char) (result.charAt(result.length() - 1) - 1));
 				result.append(repeat('9', length - result.length()));
 
 				break;
 			} else {
 				result.append(N.charAt(i));
 			}
 		}
 		return result.toString();
 	}
 
 	static String repeat(char ch, int count) {
 		StringBuilder result = new StringBuilder();
 		for (int i = 0; i < count; i++) {
 			result.append(ch);
 		}
 		return result.toString();
 	}
 }
