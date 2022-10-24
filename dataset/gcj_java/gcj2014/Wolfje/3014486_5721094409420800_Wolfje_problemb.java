import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.PrintWriter;
 import java.util.ArrayList;
 import java.util.Scanner;
 
 public class ProblemB {
 	String PROBLEM_ID = "problemB";
 
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
 		new ProblemB();
 	}
 
 	public ProblemB() throws Exception {
 		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
 		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
 				getOutFileName())));
 		Scanner scan = new Scanner(in);
 		int tests = scan.nextInt();
 		for (int test = 0; test < tests; test++) {
 			int n = scan.nextInt();
 			ArrayList<Integer> list = new ArrayList<Integer>();
 			for ( int i = 0; i < n; i++) list.add(scan.nextInt());
 			int answer = 0;
 			for ( int i = 0; i + 1 < n; i++) {
 				int smallest = Integer.MAX_VALUE;
 				int index = 0;
 				for ( int j = 0; j < list.size(); j++) {
 					if ( list.get(j) < smallest) {
 						smallest = list.get(j);
 						index = j;
 					}
 				}
 				int dist = Math.min(index, list.size()-1-index);
 				answer += dist;
 				ArrayList<Integer> next = new ArrayList<Integer>();
 				for ( int z: list ) {
 					if ( z != smallest) next.add(z);
 				}
 				list = next;
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
