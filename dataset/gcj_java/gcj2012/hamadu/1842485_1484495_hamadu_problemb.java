import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileWriter;
 import java.io.IOException;
 import java.io.InputStreamReader;
 import java.util.Arrays;
 
 public class ProblemB {
 	
 	public static class Std implements Comparable<Std> {
 		int id;
 		long r;
 		long px = 0;
 		long py = 0;
 		Std(int _i, int _r) {
 			id = _i;
 			r = _r * 2;
 		}
 		@Override
 		public int compareTo(Std arg0) {
 			return Long.signum(arg0.r - r);
 		}
 	}
 	
 	public static boolean intersect(Std a, Std b) {
 		long dx = Math.abs((a.px + a.r) - (b.px + b.r));
 		long dy = Math.abs((a.py + a.r) - (b.py + b.r));
 		if (dx*dx + dy*dy <= (a.r + b.r) * (a.r + b.r)) {
 			return true;
 		}
 		return false;
 	}
 	
 	public static double[][] solve(int w, int h, int[] r) {
 		int n = r.length;
 		double[][] ret = new double[n][2];
 		Std[] std = new Std[n];
 		for (int i = 0 ; i < n ; i++) {
 			std[i] = new Std(i, r[i]);
 		}
 		Arrays.sort(std);
 		
 		
 		while (true) {
 			for (int i = 0 ; i < n ; i++) {
 				long pw = ((long)(Math.random() * w) - std[i].r);
 				long ph = ((long)(Math.random() * h) - std[i].r);
 				std[i].px = pw;
 				std[i].py = ph;
 			}
 			
 			boolean isok = true;
 			check: for (int i = 0 ; i < n ; i++) {
 				for (int j = i+1 ; j < n ; j++) {
 					if (intersect(std[i], std[j])) {
 						isok = false;
 						break check;
 					}
 				}
 			}
 			if (isok) {
 				break;
 			}
 		}
 		
 		
 		for (int i = 0 ; i < n ; i++) {
 			ret[std[i].id][0] = std[i].px + std[i].r;
 			ret[std[i].id][1] = std[i].py + std[i].r;
 		}
 		
 		return ret;
 	}
 	
 	public static void main(String[] args) throws IOException {
 		BufferedReader s = new BufferedReader(new InputStreamReader(System.in));
 		BufferedWriter w = new BufferedWriter(new FileWriter("./src/output.txt"));
 		int T = Integer.valueOf(s.readLine());
 		for (int t = 1 ; t <= T ; t++) {
 			String[] data = s.readLine().split(" ");
 			int n = Integer.valueOf(data[0]);
 			int l = Integer.valueOf(data[1]);			
 			int h = Integer.valueOf(data[2]);
 			int[] r = new int[n];
 			String[] line = s.readLine().split(" ");
 			for (int i = 0 ; i < n ; i++) {
 				r[i] = Integer.valueOf(line[i]);
 			}
 			double[][] d = solve(l, h, r);
 			
 			StringBuffer b = new StringBuffer();
 			b.append(d[0][0]).append(" ").append(d[0][1]);
 			for (int i = 1 ; i < d.length ; i++) {
 				b.append(" ").append(d[i][0]).append(" ").append(d[i][1]);
 			}
 			w.write("Case #" + t + ": " + b.toString());
 			w.newLine();
 		}
 		w.flush();
 		w.close();
 	}
 }