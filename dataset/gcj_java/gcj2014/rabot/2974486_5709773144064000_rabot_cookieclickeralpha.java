package qr2014;
 
 import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.math.BigInteger;
 import java.util.Arrays;
 import java.util.HashSet;
 import java.util.StringTokenizer;
 
 public class CookieClickerAlpha {
 	public static void main(String[] args) throws Exception {
 		String fileName = args[0];
 		CookieClickerAlpha obj = new CookieClickerAlpha();
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
 			double C = Double.parseDouble(token.nextToken());
 			double F = Double.parseDouble(token.nextToken());
 			double X = Double.parseDouble(token.nextToken());
 
 			double t = 0;
 			double a = 2;
 			double min = 1000000;
 			if (C < X) {
 				while (true) {
 					min = Math.min(min, t + X / a);
 					t += C / a;
 					a += F;
 					if (t >= min) {
 						break;
 					}
 				}
 			} else {
 				min = X / a;
 			}
 
 			bw.write("Case #" + (i + 1) + ": " + min);
 			bw.write("\r\n");
 		}
 		bw.close();
 		br.close();
 	}
 }
