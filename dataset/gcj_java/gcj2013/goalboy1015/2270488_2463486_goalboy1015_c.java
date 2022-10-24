import java.io.File;
 import java.io.PrintStream;
 import java.util.Scanner;
 
 public class C {
 	static final Boolean SAMPLE = false;
 	static final String PROBLEM = "C";
 	static final String INPUT = "small";
 	static final String ID = "0";
 	static final String PATH = "C:\\software installation\\codejam-commandline-1.2-beta1\\source\\";
 
 	public static void main(String args[]) throws Throwable {
 		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
 				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
 		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
 				+ "-" + INPUT + "-" + ID + ".out");
 
 		int test = in.nextInt();
 		for (int t = 1; t <= test; t++) {
 			out.print("Case #" + t + ": ");
 
 			long begin = in.nextLong();
 			long end = in.nextLong();
 			int count = 0;
 			for (long i = 1;; i++) {
 				long square = i * i;
 				if (square < begin) {
 					continue;
 				} else if (square > end) {
 					break;
 				}
 				if (isPalindrome(i) && isPalindrome(square)) {
 					count++;
 				}
 			}
 			out.println(count);
 		}
 
 		out.close();
 		in.close();
 
 		System.out.println("finish!");
 	}
 
 	static boolean isPalindrome(long number) {
 		String str = number + "";
 		for (int i = 0; i < str.length() - 1 - i; i++) {
 			if (str.charAt(i) != str.charAt(str.length() - 1 - i)) {
 				return false;
 			}
 		}
 		return true;
 	}
 }
