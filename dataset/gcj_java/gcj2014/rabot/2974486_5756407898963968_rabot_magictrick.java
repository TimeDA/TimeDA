package qr2014;
 
 import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.math.BigInteger;
 import java.util.Arrays;
 import java.util.HashSet;
 import java.util.StringTokenizer;
 
 public class MagicTrick {
 	public static void main(String[] args) throws Exception {
 		String fileName = args[0];
 		MagicTrick obj = new MagicTrick();
 		obj.solve(fileName);
 	}
 
 	public void solve(String fileName) throws Exception {
 		BufferedReader br = new BufferedReader(new FileReader(fileName));
 		BufferedWriter bw = new BufferedWriter(
 				new FileWriter(fileName + ".out"));
 
 		int T = Integer.parseInt(br.readLine());
 		for (int i = 0; i < T; i++) {
 			int r1 = Integer.parseInt(br.readLine());
 			HashSet<Integer> hash = new HashSet<Integer>();
 			for (int j = 0; j < 4; j++) {
 				String str = br.readLine();
 				if (j + 1 == r1) {
 					StringTokenizer token = new StringTokenizer(str, " ");
 					for (int k = 0; k < 4; k++) {
 						hash.add(Integer.parseInt(token.nextToken()));
 					}
 				}
 			}
 
 			int r2 = Integer.parseInt(br.readLine());
 			int num = 0;
 			int ans = 0;
 			for (int j = 0; j < 4; j++) {
 				String str = br.readLine();
 				if (j + 1 == r2) {
 					StringTokenizer token = new StringTokenizer(str, " ");
 					for (int k = 0; k < 4; k++) {
 						int a = Integer.parseInt(token.nextToken());
 						if (hash.contains(a)) {
 							num++;
 							ans = a;
 						}
 					}
 				}
 			}
 
 			if (num == 1) {
 				bw.write("Case #" + (i + 1) + ": " + ans);
 			} else if (num == 0) {
 				bw.write("Case #" + (i + 1) + ": " + "Volunteer cheated!");
 			} else {
 				bw.write("Case #" + (i + 1) + ": " + "Bad magician!");
 			}
 			bw.write("\r\n");
 		}
 		bw.close();
 		br.close();
 	}
 
 	static BigInteger TWO = new BigInteger("2");
 
 	private BigInteger sqrt(BigInteger a) {
 		int x = a.toString().length();
 		BigInteger min = BigInteger.TEN.pow((x - 1) / 2);
 		BigInteger max = BigInteger.TEN.pow((x + 1) / 2);
 		while (max.subtract(min).subtract(BigInteger.ONE)
 				.compareTo(BigInteger.ZERO) > 0) {
 			BigInteger mid = min.add(max).divide(TWO);
 			BigInteger sqr = mid.multiply(mid);
 			if (sqr.compareTo(a) <= 0) {
 				min = mid;
 			} else {
 				max = mid;
 			}
 		}
 		return min;
 	}
 
 	private long count(BigInteger a) {
 		long cnt = 0;
 		if (a.compareTo(BigInteger.TEN) < 0) {
 			int i = a.intValue();
 			switch (i) {
 			case 0:
 				return 0;
 			case 1:
 				return 1;
 			case 2:
 				return 2;
 			case 3:
 				return 3;
 			default:
 				return 3;
 			}
 		} else {
 			cnt += 3;
 		}
 		String str = a.toString();
 		for (int i = 2; i <= str.length(); i++) {
 			if (i % 2 == 0) {
 				if (i == str.length() && str.charAt(0) <= '2') {
 					// 1***....***1
 					if (str.charAt(0) == '2') {
 						cnt += (1 << (i / 2 - 1));
 					} else {
 						boolean flg = false;
 						char[] tmp = new char[i];
 						long tmpCnt = 1;
 						for (int j = 0; j < i / 2; j++) {
 							if (flg) {
 								tmpCnt = (tmpCnt << 1) | 1;
 							} else {
 								char c = str.charAt(j);
 								switch (c) {
 								case '0':
 									tmp[j] = '0';
 									tmp[str.length() - j - 1] = '0';
 									tmpCnt = (tmpCnt << 1);
 									break;
 								case '1':
 									tmp[j] = '1';
 									tmp[str.length() - j - 1] = '1';
 									if (j != 0) {
 										tmpCnt = (tmpCnt << 1) | 1;
 									}
 									break;
 
 								default:
 									tmpCnt = (tmpCnt << 1) | 1;
 									flg = true;
 									break;
 								}
 							}
 						}
 						tmpCnt -= (1 << i / 2 - 1) - 1;
 						if (!flg) {
 							if (str.compareTo(new String(tmp)) < 0) {
 								tmpCnt -= 1;
 							}
 						}
 						cnt += tmpCnt;
 					}
 
 					// 2000....0002
 					char[] tmp = new char[i];
 					Arrays.fill(tmp, '0');
 					tmp[0] = '2';
 					tmp[i - 1] = '2';
 					if (str.compareTo(new String(tmp)) >= 0) {
 						cnt += 1;
 					}
 
 				} else {
 					cnt += (1 << (i / 2 - 1)) + 1;
 				}
 			} else if (i % 2 == 1) {
 				if (i == str.length() && str.charAt(0) <= '2') {
 					// 1***..0..***1, 1***..1..***1
 					if (str.charAt(0) == '2') {
 						cnt += (1 << (i / 2)) + i / 2;
 					} else {
 						boolean flg = false;
 						char[] tmp = new char[i];
 						long tmpCnt = 1;
 						for (int j = 0; j < i / 2; j++) {
 							if (flg) {
 								tmpCnt = (tmpCnt << 1) | 1;
 							} else {
 								char c = str.charAt(j);
 								switch (c) {
 								case '0':
 									tmp[j] = '0';
 									tmp[str.length() - j - 1] = '0';
 									tmpCnt = (tmpCnt << 1);
 									break;
 								case '1':
 									tmp[j] = '1';
 									tmp[str.length() - j - 1] = '1';
 									if (j != 0) {
 										tmpCnt = (tmpCnt << 1) | 1;
 									}
 									break;
 								default:
 									tmpCnt = (tmpCnt << 1) | 1;
 									flg = true;
 									break;
 								}
 							}
 						}
 						if (!flg) {
 							if (str.charAt(i / 2) == '0') {
 								tmp[i / 2] = '0';
 								tmpCnt = (tmpCnt << 1);
 								if (str.compareTo(new String(tmp)) < 0) {
 									tmpCnt -= 1;
 								}
 							} else if (str.charAt(i / 2) == '1') {
 								tmpCnt = (tmpCnt << 1) | 1;
 								tmp[i / 2] = '1';
 								if (str.compareTo(new String(tmp)) < 0) {
 									tmpCnt -= 1;
 								}
 							} else {
 								tmpCnt = (tmpCnt << 1) | 1;
 							}
 							if (str.compareTo(new String(tmp)) < 0) {
 								tmpCnt -= 1;
 							}
 						}
 						tmpCnt -= (1 << i / 2) - 1;
 						cnt += tmpCnt;
 
 						// 100100..2..001001
 						for (int j = 0; j < i / 2; j++) {
 							tmp = new char[i];
 							Arrays.fill(tmp, '0');
 							tmp[0] = '1';
 							tmp[i - 1] = '1';
 							tmp[i / 2] = '2';
 
 							tmp[j] = '1';
 							tmp[i - j - 1] = '1';
 
 							if (str.compareTo(new String(tmp)) >= 0) {
 								cnt += 1;
 							}
 						}
 					}
 
 					// 2000..0..0002
 					char[] tmp = new char[i];
 					Arrays.fill(tmp, '0');
 					tmp[0] = '2';
 					tmp[i - 1] = '2';
 					if (str.compareTo(new String(tmp)) >= 0) {
 						cnt += 1;
 					}
 
 					// 2000..1..0002
 					tmp[i / 2] = '1';
 					if (str.compareTo(new String(tmp)) >= 0) {
 						cnt += 1;
 					}
 
 				} else {
 					cnt += (1 << (i / 2)) + i / 2 + 2;
 				}
 			}
 		}
 		return cnt;
 	}
 }
