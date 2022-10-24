
 import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.PrintWriter;
 import java.util.Scanner;
 
 public class CookieClickerAlpha {
 	String PROBLEM_ID = "CookieClickerAlpha";
 
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
 		new CookieClickerAlpha();
 	}
 
 	public CookieClickerAlpha() throws Exception {
 		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
 		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
 				getOutFileName())));
 		Scanner scan = new Scanner(in);
 		int tests = scan.nextInt();
 		for (int test = 0; test < tests; test++) {
 			double c = scan.nextDouble();
 			double f = scan.nextDouble();
 			double x = scan.nextDouble();
 			int farms = 0;
 			double best = x/2.0;
 			double time = 0.0;
 			while ( time < best && farms < 1000000) {
 				// complete
 				best = Math.min(best, time + x/(2.0+farms*f) );
 				time += c/(2.0+farms*f);
 				farms++;
 			}
 //			System.out.println("farms " + farms);
 			String resultStr = String.format("Case #%d: %.8f", test + 1, best);
 			// add answer here
 
 			System.out.println(resultStr);
 			out.println(resultStr);
 		}
 		out.close();
 		System.out.println("*** in file =  " + getInFileName());
 		System.out.println("*** out file = " + getOutFileName());
 	}
 }
 
