import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Solution {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		//int qq = Integer.MAX_VALUE;
		int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			pw.println("Case #" + casenum + ":");
			double goal = readDouble();
			double lhs = 0;
			double rhs = Math.PI/4;
			double choice = rhs;
			boolean good = false;
			for(int qqq = 0; qqq < ITER; qqq++) {
				double mid = (lhs+rhs)/2;
				double[] go = rangeTheta(mid);
				if(go[0] <= goal && goal <= go[1]) {
					good = true;
					choice = mid;
					break;
				}
				if(go[1] < goal) {
					lhs = mid;
				}
				else {
					rhs = mid;
				}
			}
			if(!good) {
				choice = lhs;
			}
			double[] go = rangeTheta(choice);
			double phiMin = go[2];
			double phiMax = go[3];
			for(int qqq = 0; qqq < ITER; qqq++) {
				double mid = (phiMin + phiMax)/2;
				if(check(choice, mid) < goal) {
					phiMin = mid;
				}
				else {
					phiMax = mid;
				}
			}
			print(choice, phiMin);
			print(choice+Math.PI/2, phiMin);
			print(choice, phiMin-Math.PI/2);
		}
		pw.close();
	}

	public static double check(double theta, double phi) {
		TreeSet<State> set = new TreeSet<State>();
		for(int x = -1; x <= 1; x += 2) {
			for(int y = -1; y <= 1; y += 2) {
				for(int z = -1; z <= 2; z += 2) {
					double thetaR = Math.atan2(y, x);
					double phiR = Math.asin(z / Math.sqrt(3));
					thetaR += theta;
					phiR += phi;
					double xx = Math.sqrt(3) * Math.cos(thetaR) * Math.cos(phiR) / 2;
					double zz = Math.sqrt(3) * Math.sin(phiR) / 2;
					set.add(new State(xx, zz));
				}
			}
		}
		ArrayList<State> up = new ArrayList<State>();
		ArrayList<State> dn = new ArrayList<State>();
		for(State curr: set)	{
			while (up.size() > 1 && area(up.get(up.size()-2), up.get(up.size()-1), curr) >= 0) 
				up.remove(up.size()-1);
			while (dn.size() > 1 && area(dn.get(dn.size()-2), dn.get(dn.size()-1), curr) <= 0) 
				dn.remove(dn.size()-1);
			up.add(curr);
			dn.add(curr);
		}
		ArrayList<State> hu = new ArrayList<State>();
		for(State s: dn)	{
			hu.add(s);
		}
		for(int i = up.size() - 2; i >= 1; i--)	{
			hu.add(up.get(i));
		}
		double ret = 0;
		for(int i = 0; i < hu.size(); i++) {
			int j = (i+1)%hu.size();
			ret += hu.get(i).x*hu.get(j).y - hu.get(i).y*hu.get(j).x;
		}
		return Math.abs(ret)/2;
	}
	public static double cross(State p, State q)   {
		return p.x*q.y-p.y*q.x;
	}
	public static double area(State a, State b, State c)	{
		return cross(a,b) + cross(b,c) + cross(c,a);
	}
	
	static class State implements Comparable<State> {
		public double x,y;
		public State(double a, double b)	{
			x=a;
			y=b;
		}
		public String toString()		{
			return x + " " + y;
		}
		public int compareTo(State s)	{
			if(y < s.y)
				return -1;
			else if(y > s.y)
				return 1;
			else if(x < s.x)
				return -1;
			else if(x > s.x)
				return 1;
			else
				return 0;
		}
	}
	
	public static void print(double theta, double phi) {
		double xx = Math.cos(phi) * Math.cos(theta);
		double yy = Math.cos(phi) * Math.sin(theta);
		double zz = Math.sin(phi);
		pw.println(.5*xx + " " + .5*yy + " " + .5*zz);
	}

	static final int ITER = 100;

	public static double[] rangeTheta(double theta) {
		double[] ret = new double[4];
		// min
		{
			double lhs = 0;
			double rhs = Math.PI/2;
			for(int i = 0; i < ITER; i++)  {
				double a = (2*lhs+rhs)/3;
				double b = (2*rhs+lhs)/3;
				if(check(theta, a) < check(theta, b)) {
					rhs = b;
				}
				else {
					lhs = a;
				}
			}
			ret[0] = check(theta, lhs);
			ret[2] = lhs;
		}
		// max
		{
			double lhs = 0;
			double rhs = Math.PI/4;
			for(int i = 0; i < ITER; i++)  {
				double a = (2*lhs+rhs)/3;
				double b = (2*rhs+lhs)/3;
				if(check(theta, a) > check(theta, b)) {
					rhs = b;
				}
				else {
					lhs = a;
				}
			}
			ret[1] = check(theta, lhs);
			ret[3] = lhs;
		}
		return ret;
	}

	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextLine() throws IOException  {
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(nextLine().trim());
		}
		return st.nextToken();
	}

}