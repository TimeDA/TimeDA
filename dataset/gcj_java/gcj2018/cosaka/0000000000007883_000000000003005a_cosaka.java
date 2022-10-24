import java.util.*;

import java.io.*;
public class Solution {
	public static Scanner in;
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
		in = new Scanner(new BufferedReader(reader));
		int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
		for (int num = 1; num <= t; ++num) {
			task(num);
		}
	}
	
	public static void task(int num) {
		int r = in.nextInt();
		int c = in.nextInt();
		int h = in.nextInt();
		int v = in.nextInt();
		in.nextLine();
		boolean mass[][] = new boolean[r][c];
		int choco = 0;
		for (int j = 0; j < r; j++) {
			String s = in.nextLine();
			for (int k = 0; k < c; k++) {
				if (s.charAt(k) == '@') {
					mass[j][k] = true;
					choco ++;
				} else {
					mass[j][k] = false;
				}
			}
		}
		/*
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				if (mass[j][k]) {
					System.out.print("a");
				} else {
					System.out.print(".");
				}
			}
			System.out.println("");
		}
		*/
		if (choco % ((h+1) * (v+1)) != 0) {
			System.out.println("Case #" + num + ": " + "IMPOSSIBLE");
			return;
		}
		
		int need = choco / ((h+1) * (v+1));
		int needH = choco / (h+1);
		int needV = choco / (v+1);
		int count = 0;
		ArrayList<Integer> hList = new ArrayList<>();
		ArrayList<Integer> vList = new ArrayList<>();
		
		hList.add(0);
		vList.add(0);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (mass[i][j]) {
					count ++;
				}
			}
			if (needH < count) {
				System.out.println("Case #" + num + ": " + "IMPOSSIBLE");
				return;
			}
			if (needH == count) {
				hList.add(i + 1);
				count = 0;
			}
		}

		for (int j = 0; j < c; j++) {
			for (int i = 0; i < r; i++) {
				if (mass[i][j]) {
					count ++;
				}
			}
			if (needV < count) {
				System.out.println("Case #" + num + ": " + "IMPOSSIBLE");
				return;
			}
			if (needV == count) {
				vList.add(j + 1);
				count = 0;
			}
		}
		
		count = 0;
		// System.out.println("aaa" + hList.size() +"," + vList.size());
		for (int n = 0; n < hList.size() - 1; n++) {
			for (int m = 0; m < vList.size() - 1; m++) {
				for (int i = hList.get(n); i < hList.get(n+1); i++) {
					for (int j = vList.get(m); j < vList.get(m+1); j++) {
						if (mass[i][j]) {
							count ++;
						}
					}
				}
				if (need != count) {
					System.out.println("Case #" + num + ": " + "IMPOSSIBLE");
					return;
				}
				count = 0;
			}
		}
		System.out.println("Case #" + num + ": " + "POSSIBLE");
	}
}