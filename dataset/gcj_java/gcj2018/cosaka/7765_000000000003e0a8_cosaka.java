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
			System.out.println("Case #" + num + ": " + task(num));
		}
	}
	
	public static String task(int num) {
		int n = in.nextInt();
		ArrayList<Integer> wList = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			wList.add(in.nextInt());
		}

		int i = 0;
		while (true) {
			ArrayList<ArrayList<Integer>> wListList = new ArrayList<>();
			wListList = getter((ArrayList<Integer>)wList.clone(), i);
			for (ArrayList<Integer> wList2 : wListList) {
				boolean success = true;
				int sum = 0;
				for (Integer w : wList2) {
					if (sum > w * 6) {
						success = false;
					}
					sum += w;
				}
				if (success) {
					return "" + wList2.size();
				}
			}
			i ++;
			// System.out.println("48");
		}
	}

	public static ArrayList<ArrayList<Integer>> getter (ArrayList<Integer> wList, int i) {
		if (i == 0) {
			ArrayList<ArrayList<Integer>> hoge = new ArrayList<>();
			hoge.add(wList);
			return hoge;
		}
		ArrayList<ArrayList<Integer>> wListList2 = new ArrayList<>();
		for (int j = 0; j < wList.size(); j++) {
			ArrayList<Integer> wList2 = (ArrayList<Integer>) wList.clone();
			wList2.remove(j);
			wListList2.addAll(getter(wList2, i - 1));
		}
		return wListList2;
	}
}
