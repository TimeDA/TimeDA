import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.PrintWriter;
 import java.util.Scanner;
 import java.util.TreeSet;
 
 public class MagicTrick {
 	String PROBLEM_ID = "MagicTrick";
 
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
 		new MagicTrick();
 	}
 
 	public MagicTrick() throws Exception {
 		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
 		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
 				getOutFileName())));		
 		Scanner scan = new Scanner(in);
 		int tests = scan.nextInt();
 		for (int test = 0; test < tests; test++) {
 			int rowA = scan.nextInt();
 			int[][] mapA = new int[4][4];
 			for ( int r = 0; r < 4; r++)
 				for ( int c = 0; c < 4; c++) mapA[r][c] = scan.nextInt();
 			int rowB = scan.nextInt();
 			int[][] mapB = new int[4][4];
 			for ( int r = 0; r < 4; r++)
 				for ( int c = 0; c < 4; c++) mapB[r][c] = scan.nextInt();
 			TreeSet<Integer> candidates = new TreeSet<Integer>();
 			for ( int a: mapA[rowA - 1]) {
 				for ( int b: mapB[rowB -1]) if ( a == b ) candidates.add(a);
 			}
 			String resultStr = String.format("Case #%d: ", test + 1);
 			if ( candidates.size() == 0 ) {
 				resultStr += "Volunteer cheated!";
 			} else if ( candidates.size() == 1 ) {
 				resultStr += candidates.first();
 			} else {
 				resultStr += "Bad magician!";
 			}
 			System.out.println(resultStr);
 			out.println(resultStr);
 		}
 		out.close();
 	}
 }
