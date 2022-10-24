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
			String s = in.nextLine();
			s = s.replace(" ", "");
			
			int count = 0;
			
			while (true) {
				int power = 1;
				int damage = 0;
				for (int j = 0; j < s.length(); j++) {
					if ('C' == s.charAt(j)) {
						power *= 2;
					} else {
						damage += power;
					}
				}
				// System.out.println("HP= " + n + ", damage=" + damage + ", power=" + power);
				if (n >= damage) {
					break;
				}
				
				String newS = s;
				try {
					int k = s.lastIndexOf("CS");
					if (k == -1) {
						count = -1;
						break;
					}
					newS = newS.substring(0, k) + "SC" + newS.substring(k + 2);
				}catch (Exception e) {
					count = -1;
					break;
				}
				if (newS.equals(s)) {
					count = -1;
					break;
				}
				// System.out.println(s + "->" + newS);
				s = newS;
				count ++;
			}
			if (count >= 0) {
				System.out.println("Case #" + i + ": " + count);
			} else {
				System.out.println("Case #" + i + ": " + "IMPOSSIBLE");
			}
			
		}
	}

}
