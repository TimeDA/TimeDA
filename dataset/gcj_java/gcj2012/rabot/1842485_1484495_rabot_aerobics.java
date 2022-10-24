package r2_2012;
 
 import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.math.BigInteger;
 import java.text.DecimalFormat;
 import java.util.ArrayList;
 import java.util.Arrays;
 import java.util.StringTokenizer;
 
 public class Aerobics {
 	public static void main(String[] args) throws Exception {
 		String fileName = args[0];
 		Aerobics obj = new Aerobics();
 		obj.solve(fileName);
 	}
 
 	public void solve(String fileName) throws Exception {
 		BufferedReader br = new BufferedReader(new FileReader(fileName));
 		BufferedWriter bw = new BufferedWriter(
 				new FileWriter(fileName + ".out"));
 
 		int T = Integer.parseInt(br.readLine());
 		for (int i = 0; i < T; i++) {
 			String str = br.readLine();
 			StringTokenizer token = new StringTokenizer(str, " ");
 
 			int N = Integer.parseInt(token.nextToken());
 			long W = Long.parseLong(token.nextToken());
 			long L = Long.parseLong(token.nextToken());
 
 			long[] r = new long[N];
 			Student[] s = new Student[N];
 			str = br.readLine();
 			token = new StringTokenizer(str, " ");
 			for (int j = 0; j < N; j++) {
 				r[j] = Long.parseLong(token.nextToken());
 				s[j] = new Student(r[j], j);
 			}
 			Arrays.sort(s);
 
 			ArrayList<Point> list = new ArrayList<Point>();
 			long curx = 0;
 			long cury = 0;
 			for (int j = 0; j < N; j++) {
 				if (j == 0) {
 					list.add(new Point(0, s[0].r));
 					continue;
 				}
 				if (curx + s[j - 1].r + s[j].r <= W) {
 					s[j].x = curx + s[j - 1].r + s[j].r;
 					s[j].y = cury;
 					list.add(new Point(curx + s[j - 1].r, cury + s[j].r));
 					curx = s[j].x;
 					continue;
 				}
 				for (int k = list.size() - 1; k >= 0; k--) {
 					if (k != 0
 							&& list.get(k - 1).y - list.get(k).y < 2 * s[j].r) {
 						list.remove(k);
 						continue;
 					} else {
 						if (list.get(k).x == 0) {
 							s[j].x = 0;
 							s[j].y = list.get(k).y + s[j].r;
 							curx = 0;
 							cury = s[j].y;
 							list.remove(k);
 							list.add(new Point(0, s[j].y + s[j].r));
 						} else {
 							s[j].x = list.get(k).x + s[j].r;
 							s[j].y = list.get(k).y + s[j].r;
 							curx = s[j].x;
 							cury = s[j].y;
 							list.remove(k);
 							list.add(new Point(s[j].x - s[j].r, s[j].y + s[j].r));
 						}
 						break;
 					}
 				}
 			}
 			StringBuffer buf = new StringBuffer();
 			for (int j = 0; j < N; j++) {
 				for (int k = 0; k < N; k++) {
 					if (s[k].idx == j) {
 						if (j != 0) {
 							buf.append(" ");
 						}
 						buf.append(s[k].x);
 						buf.append(" ");
 						buf.append(s[k].y);
 						break;
 					}
 				}
 			}
 
 			bw.write("Case #" + (i + 1) + ": " + buf.toString());
 			bw.write("\r\n");
 		}
 		bw.close();
 		br.close();
 	}
 }
 
 class Student implements Comparable<Student> {
 	Long r = 0L;
 	Integer idx = 0;
 	long x = 0;
 	long y = 0;
 
 	Student(long r, int idx) {
 		this.r = r;
 		this.idx = idx;
 	}
 
 	@Override
 	public int compareTo(Student o) {
 		int tmp = this.r.compareTo(o.r);
 
 		return tmp == 0 ? this.idx.compareTo(o.idx) : -tmp;
 	}
 }
 
 class Point {
 	long x = 0;
 	long y = 0;
 
 	Point(long x, long y) {
 		this.x = x;
 		this.y = y;
 	}
 }
