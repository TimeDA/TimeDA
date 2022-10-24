import java.io.*;
import java.util.*;

public class Solution {
	void solveTestcase(final Scanner in, final PrintWriter out) {
		double a = in.nextDouble();
		
//		double max = 0;
//		for (double r = 0.60; r < 0.64; r += 1e-7) {
//			if (area(Math.PI / 4, max, null) < area(Math.PI / 4, r, null)) {
//				max = r;
//			}
//		}
//		dump(max, Math.acos(0.6154796999918521), area(Math.PI / 4, max, null));
		
		double low = 0, high = Math.PI / 4 + 0.6154796999918521;
		for (int i = 0; i < 50; i++) {
			double mid = (low + high) / 2;
			double shadowArea = area(Math.min(Math.PI / 4, mid), Math.max(mid - Math.PI / 4, 0), null);
			if (shadowArea < a) low = mid;
			else high = mid;
		}
		
		{
			double mid = (low + high) / 2;
			area(Math.min(Math.PI / 4, mid), Math.max(mid - Math.PI / 4, 0), out);
		}
	}
	
	double area(double angle1, double angle2, final PrintWriter out) {
		double[][] mat = new double[][] {
			new double[] {0.5,0.0,0.0,},
			new double[] {0.0,0.5,0.0,},
			new double[] {0.0,0.0,0.5,},
		};
		double[][] rot1 = new double[][] {
			new double[] {Math.cos(angle1),-Math.sin(angle1),0.0,},
			new double[] {Math.sin(angle1),Math.cos(angle1),0.0,},
			new double[] {0.0,0.0,1.0,},
		};
		double[][] rot2 = new double[][] {
			new double[] {1.0,0.0,0.0,},
			new double[] {0.0,Math.cos(angle2),-Math.sin(angle2),},
			new double[] {0.0,Math.sin(angle2),Math.cos(angle2),},
		};
		mat = mulmat(rot2, mulmat(rot1, mat));
		List<Point> pts = new ArrayList<>();
		for (int i = 0; i < 8; i++) {
			double[][] pt = new double[3][1];
			for (int j = 0; j < 3; j++) {
				pt[j][0] = (i>>>j&1)*2-1;
			}
			pt = mulmat(mat, pt);
			pts.add(new Point(pt[0][0], pt[2][0]));
		}
		pts = GenConvexHull(pts);
		double area = Math.abs(new Polygon(pts.toArray(new Point[0])).area());
		if (out != null) {
			out.println();
			for (double[] row : mat) {
				for (int i = 0; i < row.length; i++) {
					if (i != 0) out.print(" ");
					out.printf("%.10f", row[i]);
				}
				out.println();
			}
//			dump(area, angle1, angle2);
		}
		
		return area;
	}
	
	public class Polygon {
		int n;
		Point[] ps;

		public Polygon(Point[] ps) {
			this.ps = ps;
			this.n = ps.length;
		}

		double area() {
			double res = 0;
			for (int i = 0; i < ps.length; i++) {
				final int j = (i+1)%ps.length;
				res += (ps[i].x-ps[j].x)*(ps[i].y+ps[j].y);
			}
			return res / 2;
		}
	}
	
	static double[][] mulmat(double[][] a, double[][] b) {
		assert(a[0].length == b.length);
		
		final int n = a.length;
		final int v = b.length;
		final int m = b[0].length;
		
		double[][] res = new double[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				for(int k = 0; k < v; k++)
				res[i][j] += a[i][k] * b[k][j];
		
		return res;
	}
	
	private static boolean LeftRotate(List<Point> ps, int len) {
		int i = len - 2;
		double x1 = ps.get(i - 1).x, x2 = ps.get(i).x, x3 = ps.get(i + 1).x,
				y1 = ps.get(i - 1).y, y2 = ps.get(i).y, y3 = ps.get(i + 1).y;
		Double cp = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
		return cp >= 0;
	}

	static List<Point> GenConvexHull(List<Point> ps) {
		if (ps.size() < 3) return ps;

		Collections.sort(ps);
		int ul = 0;
		final List<Point> upper = new ArrayList<Point>(ps.size());
		for(int i = 0; i < ps.size(); i++) {
			upper.add(null);
		}

		upper.set(ul++, ps.get(0));
		upper.set(ul++, ps.get(1));
		for (int i = 2; i < ps.size(); i++) {
			upper.set(ul++, ps.get(i));
			while (ul >= 3 && LeftRotate(upper, ul)) {
				upper.set(ul - 2, upper.get(ul - 1));
				ul--;
			}
		}

		int ll = 0;
		final List<Point> lower = new ArrayList<Point>(ps.size());
		for(int i = 0; i < ps.size(); i++) {
			lower.add(null);
		}

		lower.set(ll++, ps.get(ps.size() - 1));
		lower.set(ll++, ps.get(ps.size() - 2));
		for (int i = ps.size() - 3; i >= 0; i--) {
			lower.set(ll++, ps.get(i));
			while (ll >= 3 && LeftRotate(lower, ll)) {
				lower.set(ll - 2, lower.get(ll - 1));
				ll--;
			}
		}

		final List<Point> res = new ArrayList<Point>(ul + ll - 2);
		for(int i = 0; i < ul; i++) res.add(upper.get(i));
		for(int i = 0; i < ll; i++) res.add(lower.get(i));
		return res;
	}

	public static class Pair<T1 extends Comparable<T1>, T2 extends Comparable<T2>>
	implements Comparable<Pair<T1, T2>>
	{
		public T1 x;
		public T2 y;

		public Pair(T1 t1, T2 t2) {
			x = t1;
			y = t2;
		}

		@Override
		public int compareTo(final Pair<T1, T2> arg0) {
			final Pair<T1, T2> p = arg0;
			final int cmp = x.compareTo(p.x);
			return cmp != 0 ? cmp : y.compareTo(p.y);
		}
		
		@Override
		public String toString() {
			return "(" + x + "," + y + ")";
		}
	}
	
	public static class Point implements Comparable<Point> {
		public double x, y;
		public Point() { }
		public Point(double xx, double yy) { x = xx; y = yy; }
		public Point(Point p) { this(p.x, p.y); }
		public Point rotate(final double theta) {
			final double a = x, b = y;
			x = a * Math.cos(theta) - b * Math.sin(theta);
			y = a * Math.sin(theta) + b * Math.cos(theta);
			return this;
		}
		public Point addM(Point p) { return addM(p.x, p.y); }
		public Point addM(double x, double y) {
			this.x += x;
			this.y += y;
			return this;
		}
		public Point add(Point p) { return add(p.x, p.y); }
		public Point add(double x, double y) {
			return new Point(this).addM(x, y);
		}
		public Point subM(Point p) { return subM(p.x, p.y); }
		public Point subM(double x, double y) {
			this.x -= x;
			this.y -= y;
			return this;
		}
		public Point sub(Point p) { return sub(p.x, p.y); }
		public Point sub(double x, double y) {
			return new Point(this).subM(x, y);
		}
		public Point mulM(double d) {
			x *= d;
			y *= d;
			return this;
		}
		public Point mul(double d) {
			return new Point(this).mulM(d);
		}
		public Point divM(double v) {
			this.x /= v;
			this.y /= v;
			return this;
		}
		public Point div(double v) {
			return new Point(this).divM(v);
		}

		public static double dist(Point a, Point b) { return a.sub(b).abs(); }
		public static double cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
		public static double dot(Point a, Point b) { return a.x*b.x + a.y*b.y; }
		public double dot(Point p) { return dot(this, p); }

		public double norm() { return x*x+y*y; }
		public double abs() { return Math.sqrt(norm()); }

		// spaghetti source
		static int ccw(Point a, Point b, Point c) {
			b=b.sub(a); c=c.sub(a);
			if (cross(b, c) > 0)   return +1;		// counter clockwise
			if (cross(b, c) < 0)   return -1;		// clockwise
			if (dot(b, c) < 0)     return +2;		// c--a--b on line
			if (b.norm() < c.norm()) return -2;		// a--b--c on line
			return 0;								// a--c--b on line
		}

		// spaghetti source
		static boolean intersectSS(Point[] p, Point[] q) {
			return ccw(p[0], p[1], q[0]) * ccw(p[0], p[1], q[1]) <= 0 &&
					ccw(q[0], q[1], p[0]) * ccw(q[0], q[1], p[1]) <= 0;
		}

		static boolean intersectSS(Point p1, Point p2, Point q1, Point q2) {
			return ccw(p1, p2, q1) * ccw(p1, p2, q2) <= 0 &&
					ccw(q1, q2, p1) * ccw(q1, q2, p2) <= 0;
		}
		
		public String toString() {
			return "(" + x + "," + y + ")";
		}
		
		@Override
		public int compareTo(Point o) {
			final int cmp = Double.compare(x, o.x);
			return cmp != 0 ? cmp : Double.compare(y, o.y);
		}
		
		public Point copy() {
			return new Point(this);
		}
	}
	
	void solve() {
		try (final PrintWriter out = new PrintWriter(System.out)) {
			try (final Scanner in = new Scanner(System.in)) {
				int t = in.nextInt();
				for (int i = 0; i < t; i++) {
					out.printf("Case #%d: ", i+1);
					solveTestcase(in, out);
				}
			}
		}
	}

	public static void main(String[] args) {
		new Solution().solve();
	}
	
	static int gcd(int n, int r) { return r == 0 ? n : gcd(r, n%r); }
	static long gcd(long n, long r) { return r == 0 ? n : gcd(r, n%r); }
	
	static <T> void swap(T[] x, int i, int j) { T t = x[i]; x[i] = x[j]; x[j] = t; }
	static void swap(int[] x, int i, int j) { int t = x[i]; x[i] = x[j]; x[j] = t; }
	static void swap(char[] x, int i, int j) { char t = x[i]; x[i] = x[j]; x[j] = t; }

	void printArrayLn(PrintWriter out, int[] xs) { for(int i = 0; i < xs.length; i++) out.print(xs[i] + (i==xs.length-1?"\n":" ")); }
	void printArrayLn(PrintWriter out, long[] xs) { for(int i = 0; i < xs.length; i++) out.print(xs[i] + (i==xs.length-1?"\n":" ")); }
	
	static void dump(Object... o) { System.err.println(Arrays.deepToString(o)); }
}
