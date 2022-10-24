package r2_2013;
 
 import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.math.BigInteger;
 import java.util.ArrayList;
 import java.util.StringTokenizer;
 
 public class TicketSwapping {
 	public static void main(String[] args) throws Exception {
 		String fileName = args[0];
 		TicketSwapping obj = new TicketSwapping();
 		obj.solve(fileName);
 	}
 
 	public void solve(String fileName) throws Exception {
 		BufferedReader br = new BufferedReader(new FileReader(fileName));
 		BufferedWriter bw = new BufferedWriter(
 				new FileWriter(fileName + ".out"));
 
 		int T = Integer.parseInt(br.readLine());
 		for (int t = 0; t < T; t++) {
 			String str = br.readLine();
 			StringTokenizer token = new StringTokenizer(str);
 			long N = Long.parseLong(token.nextToken());
 			int M = Integer.parseInt(token.nextToken());
 
 			long[] o = new long[M];
 			long[] e = new long[M];
 			long[] p = new long[M];
 			BigInteger total = BigInteger.ZERO;
 			ArrayList<long[]> in = new ArrayList<long[]>();
 			ArrayList<long[]> out = new ArrayList<long[]>();
 			for (int m = 0; m < M; m++) {
 				str = br.readLine();
 				token = new StringTokenizer(str);
 				o[m] = Long.parseLong(token.nextToken());
 				e[m] = Long.parseLong(token.nextToken());
 				p[m] = Long.parseLong(token.nextToken());
 				boolean flg = false;
 				for (int k = 0; k < in.size(); k++) {
 					if (in.get(k)[0] <= o[m]) {
 						continue;
 					}
 					in.add(k, new long[] { o[m], p[m] });
 					flg = true;
 					break;
 				}
 				if (!flg) {
 					in.add(new long[] { o[m], p[m] });
 				}
 				flg = false;
 				for (int k = 0; k < out.size(); k++) {
 					if (out.get(k)[0] <= e[m]) {
 						continue;
 					}
 					out.add(k, new long[] { e[m], p[m] });
 					flg = true;
 					break;
 				}
 				if (!flg) {
 					out.add(new long[] { e[m], p[m] });
 				}
 				BigInteger subtot = cost(e[m] - o[m], N).multiply(
 						new BigInteger(Long.toString(p[m])));
 				total = total.add(subtot);
 			}
 
 			int ipos = 0;
 			int opos = 0;
 			long[] curi = in.get(0);
 			long[] curo = out.get(0);
 			BigInteger pay = BigInteger.ZERO;
 			while (curi != null || curo != null) {
 				if (curi != null && curi[0] <= curo[0]) {
 					ipos++;
 					if (ipos < in.size()) {
 						curi = in.get(ipos);
 					} else {
 						curi = null;
 					}
 					continue;
 				}
 
 				for (int k = ipos - 1; k >= 0; k--) {
 					long[] tmp = in.get(k);
 					if (tmp[1] == 0) {
 						continue;
 					}
 					if (tmp[1] <= curo[1]) {
 						BigInteger subtot = cost(curo[0] - tmp[0],N).multiply(new BigInteger(Long.toString(tmp[1])));
 						pay = pay.add(subtot);
 						curo[1] -= tmp[1];
 						tmp[1] = 0;
 						continue;
 					} else {
 						BigInteger subtot = cost(curo[0] - tmp[0],N).multiply(new BigInteger(Long.toString(curo[1])));
 						pay = pay.add(subtot);
 						tmp[1] -= curo[1];
 						curo[1] = 0;
 						break;
 					}
 				}
 				opos++;
 				if (opos < out.size()) {
 					curo = out.get(opos);
 				} else {
 					curo = null;
 				}
 			}
 
 			BigInteger loss = total.subtract(pay);
 			BigInteger ans = loss.mod(new BigInteger("1000002013"));
 
 			bw.write("Case #" + (t + 1) + ": " + ans.toString());
 			bw.write("\r\n");
 		}
 		bw.close();
 		br.close();
 	}
 
 	static final BigInteger TWO = new BigInteger("2");
 
 	private BigInteger cost(long dist, long N) {
 		BigInteger bdist = new BigInteger(Long.toString(dist));
 		return (TWO.multiply(new BigInteger(Long.toString(N))).subtract(bdist)
 				.add(BigInteger.ONE)).multiply(bdist).divide(TWO);
 	}
 
 }
