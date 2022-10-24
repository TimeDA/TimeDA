package com.g0505.a;
 
 import java.io.BufferedReader;
 import java.io.File;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.IOException;
 import java.util.ArrayList;
 import java.util.Collections;
 import java.util.Comparator;
 
 public class Problem {
 	// private final String FILE_PATH = "C:/data/workspace/googleCodeJam2012/src/com/g0419/a/";
 	private final String CURRENT_DIR = 
 			new File(".").getAbsoluteFile().getParent() + "\\" + "src" + "\\" +
 			this.getClass().getPackage().getName().replace(".", "\\") + "\\";
 	// private final String INPUT_FILE = CURRENT_DIR + "A-large-practice.in";
 	private final String INPUT_FILE = CURRENT_DIR + "A-small-attempt2.in";
 	private final String OUTPUT_FILE = 
 			INPUT_FILE.substring(0, INPUT_FILE.lastIndexOf('.')) + ".txt";
 	
 	long testN = -1;
 	ArrayList<Test> testList = new ArrayList<Test>();
 	
 	public static void main(String[] args) {
 		Problem p = new Problem();
 		p.init();
 		p.printResult();
 	}
 	
 	/**
 	 * t@Co͂ƂB͂܂GȂB
 	 */
 	public void printResult() {
 		System.out.println("========================");
 		try {
 			FileWriter outputFile = new FileWriter(OUTPUT_FILE, false);
 			long i = 1;
 			for (Test p : testList) {
 				String str = "Case #" + i + ": " + p.check();
 				outputFile.write(str + "\r\n");
 				System.out.println(str);
 				i++;
 			}
 			outputFile.close();
 		} catch (IOException e) {
 			e.printStackTrace();
 		}
 	}
 	
 	/**
 	 * ͎BŏɏCB
 	 * 1₪1s̏ꍇ͏CsvB
 	 */
 	public void init() {
 		try {
 			FileReader in = new FileReader(INPUT_FILE);
 			BufferedReader br = new BufferedReader(in);
 			String line;
 			testN = Long.parseLong(br.readLine());
 			while ((line = br.readLine()) != null) {
 				System.out.println(line);
 				
 				Test test = new Test(line.split(" "));
 				testList.add(test);
 			}
 			br.close();
 			in.close();
 		} catch (IOException e) {
 			e.printStackTrace();
 		}
 	}
 	
 	/**
 	 * ̓ASY
 	 */
 	public class Test {
 		ArrayList<Long> s = new ArrayList<Long>();
 		
 		/**
 		 *  ͂ɍ킹ďCB
 		 */
 		public Test (String[] strList) {
 			for (int i = 1; i < strList.length; i++) {
 				s.add(Long.parseLong(strList[i]));
 			}
 		}
 		
 		/**
 		 *  ɃASYSSB
 		 */
 		public String check () {
 			// TODO
 			
 			boolean errorFlg = true;
 			
 			String list = "";
 			long allSum = -1;
 			while (errorFlg) {
 				list = "";
 				long sum = 0;
 				long size = 0;
 				for (Long l : s) {
 					if (l > -1) {
 						sum += l;
 						size ++;
 					}
 				}
 				if (allSum < 0) {
 					allSum = sum;
 				}
 				
 				// System.out.println("sum=" + sum);
 				errorFlg = false;
 				for (int i = 0; i < s.size(); i++) {
 					if (i > 0){
 						list += " ";
 					}
 					if (s.get(i) > -1) {
 						// System.out.println("allSum=" + allSum + ",sum=" + sum + ",size=" + size);
 						double ans = ((((double)allSum + sum) / size) - s.get(i)) / allSum * 100;
 						if (ans < 0) {
 							errorFlg = true;
 						}
 						list += String.format("%.6f", ans);
 					} else {
 						list += "0.000000";
 					}
 				}
 				if (errorFlg) {
 					// System.out.println("c=" + list);
 					s = replaceNull (s);
 				}
 			}
 			return "" + list;
 		}
 
 		/**
 		 * Max-2ɒuB
 		 */
 		private ArrayList<Long> replaceNull (ArrayList<Long> list) {
 			ArrayList<Long> ret = new ArrayList<Long>();
 			Long maxL = list.get(0);
 			for (Long l : list) {
 				if (maxL < l) {
 					maxL = l;
 				}
 			}
 			
 			boolean flag = true;
 			for (Long l : list) {
 				if (l > -1 && flag && l.equals(maxL)) {
 					ret.add(-2l);
 					flag = false;
 				} else {
 					ret.add(l);
 				}
 			}
 			// System.out.println("list " + list.size() + "==" + ret.size());
 			return ret;
 		}
 		
 		/**
 		 * Ԃ֐
 		 */
 		private long keta (long k) {
 			if (k == 0){
 				return 0;
 			} else {
 				return keta(k / 10) + 1;
 			}
 		}
 		/**
 		 * KԂ֐
 		 * n^k
 		 */
 		private long kaijo (long n, long k) {
 			if (k == 0) {
 				return 1;
 			} else {
 				return kaijo(k - 1, n) * n;
 			}
 		}
 		
 		@Override
 		public String toString() {
 			String list = " ";
 			for (Long str : s) {
 				list += str + ",";
 			}
 			return list;
 		}
 	}
 	
 	/**
 	 * ȃ\[g͂B
 	 * gF
 	 * java.util.Collections.sort(list); // ʂ̃\[g͂ŏ\B
 	 * java.util.Collections.sort(list, new TestComparator()); // ȃ\[g͂
 	 */
 	public class TestComparator implements Comparator<Long> {
 		public int compare(Long o1, Long o2) {
 			return (int)(- o1 + o2);
 		}
 	}
 	public class LevelComparator implements Comparator<Level> {
 		public int compare(Level o1, Level o2) {
 			return (int)(- o1.getB() + o2.getB());
 		}
 	}
 	
 	/**
 	 * NX𗘗p͂B
 	 */
 	public class Level {
 		Long a;
 		Long b;
 		public Level(Long a, Long b) {
 			this.a = a;
 			this.b = b;
 		}
 		long getA () {
 			return a;
 		}
 		void setA () {
 			a = -1l;
 		}
 		long getB() {
 			return b;
 		}
 	}
 }
