import java.io.File;
 import java.io.PrintStream;
 import java.util.ArrayList;
 import java.util.Collections;
 import java.util.Scanner;
 
 public class A {
 	static final Boolean SAMPLE = false;
 	static final String PROBLEM = "A";
 	static final String INPUT = "small";
 	static final String ID = "0";
 	static final String PATH = "/Users/wangkai/Documents/software installer/codejam-commandline-1.2-beta1/source/";
 
 	public static void main(String[] args) throws Throwable {
 		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
 				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
 		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
 				+ "-" + INPUT + "-" + ID + ".out");
 
 		int test = in.nextInt();
 		for (int t = 1; t <= test; t++) {
 			out.print("Case #" + t + ": ");
 
 			int N = in.nextInt();
 			int X = in.nextInt();
 			ArrayList<Integer> sizes = new ArrayList<Integer>();
 			for (int i = 0; i < N; i++) {
 				sizes.add(in.nextInt());
 			}
 			Collections.sort(sizes);
 
 			int discNum = 0;
 			while (!sizes.isEmpty()) {
 				int remain = X;
 				for (int i = 0; i < 2; i++) {
 					int index = findLargest(sizes, remain);
 					if (index >= 0) {
 						remain -= sizes.remove(index);
 					} else {
 						break;
 					}
 				}
 				discNum++;
 			}
 			out.println(discNum);
 		}
 
 		out.close();
 		in.close();
 
 		System.out.println("finish!");
 	}
 
 	static int findLargest(ArrayList<Integer> sizes, int target) {
 		int index = Collections.binarySearch(sizes, target);
 		if (index >= 0) {
 			return index;
 		} else {
 			return -1 - index - 1;
 		}
 	}
 }
