import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.PrintWriter;
 import java.util.Arrays;
 import java.util.Scanner;
 
 import static java.lang.Math.*;
 
 public class ProblemA {
 	String PROBLEM_ID = "problemA";
 
 	enum TestType {
 		EXAMPLE, SMALL, LARGE
 	}
 
 //	 TestType TYPE = TestType.EXAMPLE;
 	 TestType TYPE = TestType.SMALL;
 //	TestType TYPE = TestType.LARGE;
 
 	public String getFileName() {
 		String result = PROBLEM_ID + "_";
 		switch (TYPE) {
 		case EXAMPLE:
 			result += "example";
 			break;
 		case SMALL:
 			result += "small";
 			break;
 		case LARGE:
 			result += "large";
 			break;
 		}
 		return result;
 	}
 
 	public String getInFileName() {
 		return getFileName() + ".in";
 	}
 
 	public String getOutFileName() {
 		return getFileName() + ".out";
 	}
 
 	public static void main(String[] args) throws Exception {
 		new ProblemA();
 	}
 
 	public ProblemA() throws Exception {
 		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
 		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
 				getOutFileName())));
 		Scanner scan = new Scanner(in);
 		int tests = scan.nextInt();
 		for (int test = 0; test < tests; test++) {
 			int n = scan.nextInt();
 			int cap = scan.nextInt();
 			int[] sizes = new int[n];
 			for ( int i = 0; i < n; i++) sizes[i] = scan.nextInt();
 			Arrays.sort(sizes);
 			int left = 0;
 			int right = n - 1;
 			int answer = 0;
 			while ( left <= right) {
 				if ( sizes[right] + sizes[left] <= cap) {
 					right--;
 					left++;
 					answer++;
 				} else {
 					right--;
 					answer++;
 				}
 			}
 			String resultStr = String.format("Case #%d: %d", test + 1, answer);
 			// add answer here
 
 			System.out.println(resultStr);
 			out.println(resultStr);
 		}
 		out.close();
 		System.out.println("*** in file =  " + getInFileName());
 		System.out.println("*** out file = " + getOutFileName());
 	}
 }
