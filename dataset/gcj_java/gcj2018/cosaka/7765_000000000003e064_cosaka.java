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
		int n = in.nextInt();
		int l = in.nextInt();
		ArrayList<String> list = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			String str = in.next();
			if (!list.contains(str)) {
				list.add(str);
			}
			// System.out.println("str=[" + str + "]");
		}
		/*
		if (n == 1) {
			System.out.println("Case #" + num + ": " + "-");
			return;
		}
		*/

		int[][] count = new int[l][26];
		for (String str : list) {
			for (int i = 0; i < l; i++) {
				int c = str.charAt(i) - 65;
				count[i][c]++;
			}
		}
		int ccc = 1;
		String ret = "";
		int ccMax = 0;
		int ccMaxWord = -100;
		for (int i = 0; i < l; i++) {
			int cc = 0;
			int min = Integer.MAX_VALUE;
			int minWord = 0;
			for (int j = 0; j < 26; j ++) {
				if (count[i][j] > 0) {
					cc ++;
					if (count[i][j] < min) {
						min = count[i][j];
						minWord = j;
					}
				}
			}
			if (ccMax < cc) {
				ccMax = cc;
				ccMaxWord = i;
			}
			ret += String.valueOf((char)(minWord + 65));
			ccc *= cc;
		}
		if (ccc <= list.size()) {
			System.out.println("Case #" + num + ": " + "-");
			return;
		}
		
		if (!list.contains(ret)) {
			System.out.println("Case #" + num + ": " + ret);
			return;
		}
		{
			String preRet = ret.substring(0, ccMaxWord);
			String postRet = ret.substring(ccMaxWord + 1, l);
			for (int j = 0; j < 26; j++) {
				if (0 < count[ccMaxWord][j]) {
					String ret2 = preRet + String.valueOf((char)(j + 65)) + postRet;
					if (!list.contains(ret2)) {
						System.out.println("Case #" + num + ": " + ret2);
						return;
					}
				}
			}
		}
		for (int i = 0; i < l; i++) {
			String preRet = ret.substring(0, i);
			String postRet = ret.substring(i + 1, l);
			for (int j = 0; j < 26; j++) {
				if (0 < count[i][j]) {
					String ret2 = preRet + String.valueOf((char)(j + 65)) + postRet;
					if (!list.contains(ret2)) {
						System.out.println("Case #" + num + ": " + ret2);
						return;
					}
				}
			}
		}
	}
}
