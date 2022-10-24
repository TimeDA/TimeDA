import java.io.File;
 import java.io.PrintStream;
 import java.util.ArrayList;
 import java.util.Scanner;
 
 public class B {
 	static final Boolean SAMPLE = false;
 	static final String PROBLEM = "B";
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
 			ArrayList<Integer> numbers = new ArrayList<Integer>();
 			for (int i = 0; i < N; i++) {
 				numbers.add(in.nextInt());
 			}
 
 			int minSwap = searchMinSwap(numbers);
 			out.println(minSwap);
 		}
 
 		out.close();
 		in.close();
 
 		System.out.println("finish!");
 	}
 
 	static int searchMinSwap(ArrayList<Integer> numbers) {
 		int minSwap = 0;
 		while (!numbers.isEmpty()) {
 			int minIndex = findMin(numbers);
 			minSwap += Math.min(minIndex, numbers.size() - 1 - minIndex);
 			numbers.remove(minIndex);
 		}
 		return minSwap;
 	}
 
 	static int findMin(ArrayList<Integer> numbers) {
 		int minIndex = 0;
 		for (int i = 0; i < numbers.size(); i++) {
 			if (numbers.get(i) < numbers.get(minIndex)) {
 				minIndex = i;
 			}
 		}
 		return minIndex;
 	}
 }
