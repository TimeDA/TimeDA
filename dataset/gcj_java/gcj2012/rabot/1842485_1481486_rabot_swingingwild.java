package r2_2012;
 
 import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.math.BigInteger;
 import java.text.DecimalFormat;
 import java.util.Arrays;
 import java.util.StringTokenizer;
 
 public class SwingingWild {
 	public static void main(String[] args) throws Exception {
 		String fileName = args[0];
 		SwingingWild obj = new SwingingWild();
 		obj.solve(fileName);
 	}
 
 	public void solve(String fileName) throws Exception {
 		BufferedReader br = new BufferedReader(new FileReader(fileName));
 		BufferedWriter bw = new BufferedWriter(
 				new FileWriter(fileName + ".out"));
 
 		int T = Integer.parseInt(br.readLine());
 		for (int i = 0; i < T; i++) {
 			String str = br.readLine();
 			int N = Integer.parseInt(str);
 
 			long[] d = new long[N];
 			long[] l = new long[N];
 			for (int j = 0; j < N; j++) {
 				str = br.readLine();
 				StringTokenizer token = new StringTokenizer(str, " ");
 				d[j] = Long.parseLong(token.nextToken());
 				l[j] = Long.parseLong(token.nextToken());
 			}
 			long D = Long.parseLong(br.readLine());
 
 			long[] min = new long[N];
 			Arrays.fill(min, -1);
 			min[0] = 0;
 			boolean flg = false;
 			for (int j = 1; j < N; j++) {
 				for (int k = 0; k < j; k++) {
 					long tmpl = Math.min(d[k] - min[k], l[k]);
 					if (tmpl + d[k] >= d[j]) {
 						min[j] = d[k];
 						break;
 					}
 				}
 				if (min[j] == -1) {
 					break;
 				}
 			}
 			for (int j = 0; j < N; j++) {
 				if (min[j] == -1) {
 					break;
 				}
 				long tmpl = Math.min(d[j] - min[j], l[j]);
 				if (tmpl + d[j] >= D) {
 					flg = true;
 					break;
 				}
 			}
 
 			String ans = null;
 			if (flg) {
 				ans = "YES";
 			} else {
 				ans = "NO";
 			}
 
 			bw.write("Case #" + (i + 1) + ": " + ans);
 			bw.write("\r\n");
 		}
 		bw.close();
 		br.close();
 	}
 }
