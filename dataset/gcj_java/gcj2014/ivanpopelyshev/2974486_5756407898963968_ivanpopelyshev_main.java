import java.io.*;
 
 import java.awt.geom.Point2D;
 import java.text.*;
 import java.math.*;
 import java.util.*;
 
 public class Main implements Runnable {
 
 	final String problem = "A";
 	// final String filename = problem + "-sample";
 
 	final String filename = problem + "-small-attempt0";
 
 	// final String filename= problem+"-small-attempt1";
 	// final String filename= problem+"-large";
 
 	public void solve() throws Exception {
 		int row1 = iread();
 		int[][] field1 = new int[4][4];
 		for (int i = 0; i < 4; i++)
 			for (int j = 0; j < 4; j++)
 				field1[i][j] = iread();
 
 		int row2 = iread();
 		int[][] field2 = new int[4][4];
 		for (int i = 0; i < 4; i++)
 			for (int j = 0; j < 4; j++)
 				field2[i][j] = iread();
 
 		row1--;
 		row2--;
 		int ans = -1, number = 0;
 		for (int i = 0; i < 4; i++)
 			for (int j = 0; j < 4; j++)
 				if (field1[row1][i] == field2[row2][j]) {
 					ans = field1[row1][i];
 					number++;
 				}
 		if (number == 0)
 			out.write("Volunteer cheated!");
 		else if (number > 1)
 			out.write("Bad magician!");
 		else
 			out.write(ans + "");
 
 	}
 
 	public void solve_gcj() throws Exception {
 		int tests = iread();
 		for (int test = 1; test <= tests; test++) {
 			out.write("Case #" + test + ": ");
 			solve();
 			out.write("\n");
 		}
 	}
 
 	public void run() {
 		try {
 			// in = new BufferedReader(new InputStreamReader(System.in));
 			// out = new BufferedWriter(new OutputStreamWriter(System.out));
 			in = new BufferedReader(new FileReader(filename + ".in"));
 			out = new BufferedWriter(new FileWriter(filename + ".out"));
 			solve_gcj();
 			out.flush();
 		} catch (Exception e) {
 			e.printStackTrace();
 			System.exit(1);
 		}
 	}
 
 	public int iread() throws Exception {
 		return Integer.parseInt(readword());
 	}
 
 	public double dread() throws Exception {
 		return Double.parseDouble(readword());
 	}
 
 	public long lread() throws Exception {
 		return Long.parseLong(readword());
 	}
 
 	BufferedReader in;
 
 	BufferedWriter out;
 
 	public String readword() throws IOException {
 		StringBuilder b = new StringBuilder();
 		int c;
 		c = in.read();
 		while (c >= 0 && c <= ' ')
 			c = in.read();
 		if (c < 0)
 			return "";
 		while (c > ' ') {
 			b.append((char) c);
 			c = in.read();
 		}
 		return b.toString();
 	}
 
 	public static void main(String[] args) {
 		try {
 			Locale.setDefault(Locale.US);
 		} catch (Exception e) {
 
 		}
 		new Thread(new Main()).start();
 		// new Thread(null, new Main(), "1", 1<<25).start();
 	}
 }