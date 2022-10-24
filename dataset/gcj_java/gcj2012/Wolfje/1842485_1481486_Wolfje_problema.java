import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.PrintWriter;
 import java.util.Arrays;
 import java.util.Scanner;
 
 import static java.lang.Math.*;
 
 public class ProblemA {
 	String PROBLEM_ID = "ProblemA";
 
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
 			n = scan.nextInt();
 			d = new int[n+2];
 			l = new int[n+2];
 			d[0] = 0;
 			l[0] = 1000000000;
 			for ( int i = 1; i <= n; i++) {
 				d[i] = scan.nextInt();
 				l[i] = scan.nextInt();
 			}
 			d[n+1] = scan.nextInt();
 			l[n+1] = 1000000000;
 			memo = new int[n+1][n+1];
 			for ( int[] a: memo) Arrays.fill(a, -1);
 			boolean ok = go(0, 1);
 			String resultStr = String.format("Case #%d: ", test + 1);
 			// add answer here
 			resultStr += ok ? "YES" : "NO";
 			System.out.println(resultStr);
 			out.println(resultStr);
 		}
 		out.close();
 		System.out.println("*** in file =  " + getInFileName());
 		System.out.println("*** out file = " + getOutFileName());
 	}
 	
 	int[] d, l;
 	int n;
 	int[][] memo;
 	boolean go(int index, int holding) {
 		if ( holding == n+1) return true;
 		if ( memo[index][holding] >= 0) return memo[index][holding] == 1;
 		boolean result = false;
 		int line = min(l[holding], d[holding]-d[index]);
 		for ( int next = holding + 1; next <= n+1; next++) {
 			if ( d[next] - d[holding] <= line) {
 				result |= go(holding, next);
 			}
 		}
 		memo[index][holding] = result ? 1 : 0;
 		return result;
 	}
 }
