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
			int a = in.nextInt();
			ArrayList<Mass> list = new ArrayList<>();
			Mass m = new Mass(100, 100);
			m.print();
			list.add(m);
			
			while(true) {
				m = new Mass(in.nextInt(), in.nextInt());
				// m = check(list, a);
				if (m.x + m.y == 0) {
					break;
				}
				list.add(m);
				m = check(list, a);
				m.print();
				if (m.x + m.y == 0) {
					break;
				}
				list.add(m);
			}
			
		}
	}
	
	public static Mass check(ArrayList<Mass> list, int a) {
		int maxX = Integer.MIN_VALUE;
		int maxY = Integer.MIN_VALUE;
		int minX = Integer.MAX_VALUE;
		int minY = Integer.MAX_VALUE;

		for (Mass m : list) {
			if (maxX < m.x) {
				maxX = m.x;
			}
			if (maxY < m.y) {
				maxY = m.y;
			}
			if (minX > m.x) {
				minX = m.x;
			}
			if (minY > m.y) {
				minY = m.y;
			}
		}

		// debug start
		/*
		System.out.println("---(" + minX + "," + maxX + ")(" + minY + "," + maxY + ")");
		for (int i = minX; i <= maxX; i++) {
			for (int j = minY; j <= maxY; j++) {
				Mass m = new Mass(i, j);
				if (!list.contains(m)) {
					System.out.print("x");
				} else {
					System.out.print("o");
				}
			}
			System.out.println("");
		}
		System.out.println("---");
		*/
		// debug end

		for (int i = minX; i <= maxX; i++) {
			for (int j = minY; j <= maxY; j++) {
				Mass m = new Mass(i, j);
				if (!list.contains(m)) {
					return m;
				}
			}
		}
		int x = maxX - minX + 1;
		int y = maxY - minY + 1;
		int area = x * y;
		if (area >= a) {
			System.out.println(list.size());
			return null;
		}
		if (x == 4 && y == 3) {
			return new Mass(maxX + 1, maxY);
		}
		if (x == 3 && y == 4) {
			return new Mass(maxX, maxY + 1);
		}
		if (x == 10) {
			return new Mass(maxX, maxY + 1);
		}
		if (y == 10) {
			return new Mass(maxX + 1, maxY);
		}
		
		if (x < y) {
			return new Mass(maxX + 1, maxY);
		} else {
			return new Mass(maxX, maxY + 1);
		}
	}
	
	public static class Mass {
		public int x, y;
		public Mass(int x, int y) {
			this.x = x;
			this.y = y;
		}
		public void print() {
			System.out.println(x + " " + y);
			System.out.flush();
		}
		public boolean isNg() {
			if (x == -1 && y == -1) {
				return true;
			}
			return false;
		}
		@Override
		public int hashCode() {
			final int prime = 3100;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Mass other = (Mass) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
	}
}
