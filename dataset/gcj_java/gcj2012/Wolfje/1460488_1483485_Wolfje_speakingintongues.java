import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.PrintWriter;
 import java.util.Arrays;
 import java.util.HashMap;
 import java.util.Scanner;
 
 import static java.lang.Math.*;
 
 public class SpeakingInTongues {
 	String PROBLEM_ID = "SpeakingInTongues";
 
 	enum TestType {
 		EXAMPLE, SMALL, LARGE
 	}
 
 //	TestType TYPE = TestType.EXAMPLE;
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
 		new SpeakingInTongues();
 	}
 
 	public SpeakingInTongues() throws Exception {
 		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
 		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
 				getOutFileName())));
 		HashMap<Character, Character> map = extract();
 		map.put('q', 'z');
 		map.put('z', 'q');
 		Scanner scan = new Scanner(in);
 		int tests = scan.nextInt();
 		scan.nextLine();
 		for (int test = 0; test < tests; test++) {
 			String input = scan.nextLine();
 			String resultStr = String.format("Case #%d: ", test + 1);
 			for ( int i = 0; i < input.length(); i++) {
 				char c = input.charAt(i);
 				resultStr += map.get(c);
 			}
 			// add answer here
 
 			System.out.println(resultStr);
 			out.println(resultStr);
 		}
 		out.close();
 		System.out.println("*** in file =  " + getInFileName());
 		System.out.println("*** out file = " + getOutFileName());
 	}
 	
 	String[] cipher = new String[] {
 		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
 		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
 		"de kr kd eoya kw aej tysr re ujdr lkgc jv"
 	};
 	
 	String[] plain = new String[] {
 			"our language is impossible to understand",
 			"there are twenty six factorial possibilities",
 			"so it is okay if you want to just give up"
 	};
 	
 	HashMap<Character, Character> extract() {
 		HashMap<Character, Character> result = new HashMap<Character, Character>();
 		for ( int i = 0; i < 3; i++) {
 			for ( int j = 0; j < cipher[i].length(); j++	) {
 				char a = cipher[i].charAt(j);
 				char b = plain[i].charAt(j);
 				result.put(a, b);
 			}
 		}
 		return result;
 	}
 }
 
