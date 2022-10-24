import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.PrintWriter;
 import java.util.Arrays;
 import java.util.Scanner;
 
 
 
 
 public class ProblemC {
 	String PROBLEM_ID = "problemC";
 
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
 		new ProblemC();
 	}
 
 	public ProblemC() throws Exception {
 		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
 		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
 				getOutFileName())));
 		Scanner scan = new Scanner(in);
 		int tests = scan.nextInt();
 		for (int test = 0; test < tests; test++) {
 			n = scan.nextInt();
 			a = new int[n];
 			for ( int i = 0; i < n; i++ ) a[i] = scan.nextInt();
 			b = new int[n];
 			for ( int i = 0; i < n; i++) b[i] = scan.nextInt();
 			x = new int[n];
 			answer = new int[n];
 			Arrays.fill(x, 0);
 			stop = false;
 			go(1);
 //			System.out.println(Arrays.toString(answer));
 			String z = "";
 			for ( int i = 0; i < n; i++) {
 				if ( i > 0) z += " ";
 				z += answer[i];
 			}
 					
 			String resultStr = String.format("Case #%d: %s", test + 1, z);
 			// add answer here
 			
 			System.out.println(resultStr);
 			out.println(resultStr);
 		}
 		out.close();
 		System.out.println("*** in file =  " + getInFileName());
 		System.out.println("*** out file = " + getOutFileName());
 	}
 	
 	int[] x;
 	int[] answer;
 	int n;
 	int[] a;
 	int[] b;
 	boolean stop;
 	
 	public void go(int k) {
 //		System.out.println("k = " + k);
 		if ( k > n ) {
 			if ( !stop ) {
 				for ( int i = 0; i< n; i++) 
 					answer[i] = x[i];
 			}
 			stop = true;
 			return;
 		}
 		
 		for ( int i = 0; i < n; i++) {
 			if ( x[i] > 0 ) continue;
 //			System.out.printf("try index %d\n", i);
 			int maxB = 0;
 			for ( int j = i+1; j< n; j++) {
 				if ( x[j] > 0 ) maxB = Math.max(maxB, b[j]);
 				
 			}
 //			okB |= (countB == 0 && b[i] == 1);
 			boolean okA = false;
 			int countA = 0;
 			int maxA = 0;
 			for ( int j = 0; j < i; j++) {
 //				okA |= (x[j] > 0 && a[j] + 1 == a[i]);
 //				if ( x[j] > 0 ) countA++;
 				if ( x[j] > 0) maxA = Math.max(maxA, a[j]);
 			}
 //			okA |= (countA == 0 && a[i] == 1);
 //			System.out.printf("ok A %s B %s k = %d\n", okA, okB, k);
 //			if ( okA && okB ) {
 			if ( a[i] == maxA + 1 && b[i] == maxB +1) {
 				x[i] = k;
 //				System.out.printf("place %d at index %d\n", k, i);
 				go(k+1);
 				x[i] = 0;
 			}
 		}
 	}
 	
 	
 }
