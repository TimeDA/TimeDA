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
			int n = in.nextInt();
			ArrayList<Integer> listA = new ArrayList<>();
			ArrayList<Integer> listB = new ArrayList<>();
			boolean flag = true;
			for (int j = 0; j < n; j++) {
				if (flag) {
					listA.add(in.nextInt());
				} else {
					listB.add(in.nextInt());
				}
				flag = !flag;
			}
			Collections.sort(listA);
			Collections.sort(listB);
			// System.out.println("a,b" + listA.size() + "," + listB.size());

			int m = 0;
			int j = 0;
			flag = true;
			for (j = 0; j < n; j++) {
				int p;
				if (flag) {
					p = listA.remove(0);
				} else {
					p = listB.remove(0);
				}
				// System.out.print("[" + p + "]");
				if (m > p) {
					break;
				}
				m = p;
				flag = !flag;
			}
			if (j == n) {
				System.out.println("Case #" + i + ": " + "OK");
			} else {
				System.out.println("Case #" + i + ": " + (j - 1));
			}
			
		}
	}

}
