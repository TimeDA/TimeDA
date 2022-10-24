import java.util.*;

import java.io.*;
public class Solution {
	
	public static void main(String[] args) {
		String TASK = "src/" + Solution.class.getSimpleName();
		String filename = TASK + ".in";
		Reader reader = null;
		try {
			reader = new FileReader(filename);
		} catch (FileNotFoundException e) {
			// e.printStackTrace();
			reader = new InputStreamReader(System.in);
		}
		Scanner in = new Scanner(new BufferedReader(reader));
		int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
		for (int i = 1; i <= t; ++i) {
			double y = in.nextDouble();
			// System.out.println("y=" + y);
			double diff2 = 8.0d - 4 * y * y;
			double diff = Math.sqrt(diff2);
			if (Double.isNaN(diff)) {
				diff = 0;
			}
			double a = y / 4.0d + diff / 8.0d;
			double b = y / 4.0d - diff / 8.0d;
			
			System.out.println("Case #" + i + ":");
			System.out.println(a + " " + b + " 0");
			System.out.println(-b + " " + a + " 0");
			System.out.println("0 0 0.5");
		}
	}

}
