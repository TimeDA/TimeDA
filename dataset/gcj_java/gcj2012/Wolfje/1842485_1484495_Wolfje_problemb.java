import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.PrintWriter;
 import java.util.ArrayList;
 import java.util.Arrays;
 import java.util.Scanner;
 
 import static java.lang.Math.*;
 
 public class ProblemB {
 	String PROBLEM_ID = "ProblemB";
 
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
 			int width = scan.nextInt();
 			int height = scan.nextInt();
 			int[] r = new int[n];
 			for ( int i = 0; i < n; i++ ) {
 				r[i] = scan.nextInt();
 			}
 //			Arrays.sort(r);
 			ArrayList<Person> people = new ArrayList<Person>();
 			
 			people.add(new Person(0, 0, r[0]));
 			int lastY = 0;
 			int maxRange = 100000;
 			for ( int i = 1; i < n; i++) {
 //				System.out.printf("place person %d\n", i);
 				int placeX = fit(people, lastY, r[i], width);
 				if ( placeX < 0) {
 					int lb = lastY;
 					int ub = lb + 2*maxRange+1;
 					while ( lb + 1 < ub) {
 						int mid = (lb+ub)/2;
 						placeX = fit(people, mid, r[i], width);
 						if ( placeX < 0 | placeX > width) lb = mid;
 						else ub = mid;
 					}
 					placeX = fit(people, ub, r[i], width);
 					lastY = ub;
 				}
 				people.add(new Person(placeX, lastY, r[i]));
 			}
 			
 			String resultStr = String.format("Case #%d:", test + 1);
 			// add answer here
 			for ( Person p: people) resultStr += String.format(" %s", p);
 			System.out.println(resultStr);
 			boolean ok = verify(people, width, height);
 			if ( !ok)
 				System.out.printf("ok? %s\n", ok);
 			out.println(resultStr);
 		}
 		out.close();
 		System.out.println("*** in file =  " + getInFileName());
 		System.out.println("*** out file = " + getOutFileName());
 	}
 	
 	boolean verify(ArrayList<Person> people, int width, int height) {
 		int n = people.size();
 		for (int i = 0; i < n; i++) {
 			Person a = people.get(i);
 			if ( a.x < 0 | a.x > width | a.y < 0 | a.y > height) {
 				System.out.println("outside mat " + a);
 				return false;
 			}
 			for ( int j = i + 1; j < n; j++) {
 				Person b = people.get(j);
 				long dx = a.x - b.x;
 				long dy = a.y - b.y;
 				long range = a.r + b.r;
 				if ( dx*dx + dy*dy < range*range) {
 					System.out.printf("%d person a %s\n", i,a);
 					System.out.printf("%dperson b %s\n", j, b);
 					System.out.printf("%d vs %d\n", dx*dx + dy*dy, range*range);
 					return false;
 				}
 			}
 		}
 		return true;
 	}
 	
 	int fit(ArrayList<Person> placed, int y, int range, long maxX) {
 //		System.out.printf("------------- try y = %d range %d\n", y, range);
 //		for ( Person p: placed ) System.out.println(p);
 		int n = placed.size();
 		SweepEvent[] events = new SweepEvent[2*n];
 		for ( int i = 0; i < n; i++) {
 			Person p = placed.get(i);
 			long dy = y - p.y;
 			long totalR = range + p.r;
 			long slack = totalR*totalR - dy*dy;
 			long mindx = 0;
 			if ( slack > 0) {
 				mindx = round(sqrt(slack));
 				if ( mindx*mindx +dy*dy < slack) mindx++;
 			}
 			mindx += 1;
 //			System.out.printf("i = %d mindx = %d\n", i, mindx);
 			events[2*i] = new SweepEvent(p.x - (int)mindx, true);
 			events[2*i+1] = new SweepEvent(p.x+ (int)mindx, false);
 //			System.out.println("enter " + events[2*i]);
 //			System.out.println("exit " + events[2*i+1]);
 		}
 		Arrays.sort(events);
 		
 		
 		int thickness = 0;
 		for ( SweepEvent e: events) {
 			if ( e.enter) thickness++;
 			else {
 				thickness--;
 				if ( thickness == 0 && e.x >= 0 && e.x <= maxX) return e.x;
 			}
 		}
 		return -1;
 	}
 	
 	public class Person {
 		int x, y, r;
 		public Person(int x, int y, int r) {
 			this.x = x;
 			this.y = y;
 			this.r = r;
 		}
 		
 		public String toString() {
 			return String.format("%d %d", x, y);
 		}
 		
 	}
 	
 	public class SweepEvent implements Comparable<SweepEvent> {
 		int x;
 		boolean enter;
 
 		public SweepEvent(int x, boolean enter ) {
 			this.x = x;
 			this.enter = enter;
 		}
 
 		public int compareTo( SweepEvent other ) {
 			if ( x != other.x) return x - other.x;
 			if ( enter ) return -1;
 			if ( other.enter) return 1;
 			return 0;
 		}
 		
 		public String toString() {
 			return String.format("x = %d enter %s", x, enter);
 		}
 	}
 	
 }
