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
 			width = scan.nextInt();
 			height = scan.nextInt();
 			int buildings = scan.nextInt();
 			map = new int[width][height];
 			blocked = new boolean[width][height];
 			for ( int i = 0; i < buildings; i++) {
 				int x0 = scan.nextInt();
 				int y0 = scan.nextInt();
 				int x1 = scan.nextInt();
 				int y1 = scan.nextInt();
 				for ( int x = x0; x <= x1; x++ )
 					for ( int y = y0; y <= y1; y++) blocked[x][y] = true;
 			}
 //			System.out.println("aan het begin");
 //			printBlocked();
 			
 			int flows = 0;
 			for ( int startX = 0; startX < width; startX++) {
 				if ( blocked[startX][0] ) continue;
 				for ( int[] a: map) Arrays.fill(a, WHITE);
 //				System.out.println("attempt at "+startX);
 				if ( dfs(startX, 0, 0) ) {
 //					System.out.println("------ new blocked --- ");
 //					printBlocked();
 					flows++;
 				}
 			}
 			
 			String resultStr = String.format("Case #%d: %d", test + 1, flows);
 			// add answer here
 
 			System.out.println(resultStr);
 			out.println(resultStr);
 		}
 		out.close();
 		System.out.println("*** in file =  " + getInFileName());
 		System.out.println("*** out file = " + getOutFileName());
 	}
 	
 	int width, height;
 	int WHITE = 0, GREY = 1, BLACK = 2;
 	int[][] map;
 	boolean[][] blocked;
 	// N, E, S, W
 	int[] dx = new int[] { 0, 1, 0, -1};
 	int[] dy = new int[] { 1, 0, -1, 0 };
 	
 	
 	public boolean dfs(int x, int y, int inDir) {
 		if ( x < 0 || x >= width || y < 0 ) return false;
 		if ( y >= height) return true;
 		if ( blocked[x][y] || map[x][y] != WHITE ) return false;
 		map[x][y] = GREY;
 		for ( int i = -1; i <= 1; i++) {
 			int dir = (inDir + i + 4) % 4;
 			int nx = x + dx[dir];
 			int ny = y + dy[dir];
 			if ( dfs(nx, ny, dir) ) {
 //				System.out.printf("found solution, block (%d, %d)\n", x, y);
 				blocked[x][y] = true;
 				return true;
 			}
 		}
 		map[x][y] = BLACK;
 		return false;		
 	}
 	
 	void printBlocked() {
 		for ( int y = height - 1; y >= 0; y--) {
 			String s = "";
 			for ( int x = 0; x < width; x++) {
 				s += blocked[x][y] ? '#' : '.';
 			}
 			System.out.println(s);
 		}
 	}
 }
