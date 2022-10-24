package com.g0506.c;
 
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
 	private final String INPUT_FILE = CURRENT_DIR + "C-small-attempt1.in";
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
 				Test test = new Test(br.readLine().split(" "),
 						br.readLine().split(" "));
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
 		ArrayList<Type> aList = new ArrayList<Type>();
 		ArrayList<Type> bList = new ArrayList<Type>();
 		
 		/**
 		 *  ͂ɍ킹ďCB
 		 */
 		public Test (String[] list1, String[] list2) {
 			for (int i = 0; i < list1.length / 2; i++) {
 				Type t = new Type(Long.parseLong(list1[i*2]),
 						Long.parseLong(list1[i*2+1]));
 				aList.add(t);
 			}
 			for (int i = 0; i < list2.length / 2; i++) {
 				Type t = new Type(Long.parseLong(list2[i*2]),
 						Long.parseLong(list2[i*2+1]));
 				bList.add(t);
 			}
 		}
 		
 		/**
 		 *  ɃASYSSB
 		 */
 		public String check () {
 			// TODO
 			long gift = 0;
 			while (true) {
 				System.out.println("" + this);
 				int executeType = 0;
 				long minLoss = Long.MAX_VALUE;
 				long removeN = 0;
 				int aCounter = 0;
 				int bCounter = 0;
 				for (int i = 0; i < 100; i ++) {
 					long aN = 0;
 					long bN = 0;
 					long aLoss = 0;
 					int aCounterTmp = 0;
 					int bCounterTmp = 0;
 					for (Type t : aList) {
 						if (i == t.getType()) {
 							aN = t.getN();
 							break;
 						}
 						aLoss += t.getN();
 						aCounterTmp ++;
 					}
 					long bLoss = 0;
 					for (Type t : bList) {
 						if (i == t.getType()) {
 							bN = t.getN();
 							break;
 						}
 						bLoss += t.getN();
 						bCounterTmp ++;
 					}
 					long tmp = Math.min(aLoss, bLoss);
 					if (0 < aCounterTmp && aCounterTmp < aList.size() &&
 							tmp < aList.get(aCounterTmp - 1).getN()) {
 						aLoss -= (aList.get(aCounterTmp - 1).getN() - tmp);
 					}
 					if (0 < bCounterTmp && bCounterTmp < bList.size() &&
 							tmp < bList.get(bCounterTmp - 1).getN()) {
 						bLoss -= (bList.get(bCounterTmp - 1).getN() - tmp);
 					}
 					
 					if (aLoss + bLoss < minLoss) {
 						minLoss = aLoss + bLoss;
 						executeType = i;
 						removeN = Math.min(aN, bN);
 						aCounter = aCounterTmp;
 						bCounter = bCounterTmp;
 					}
 				}
 				if (removeN == 0) {
 					break;
 				}
 				
 				gift += removeN;
 				
 				System.out.println("executeType=" + executeType +
 						", Loss=" + minLoss +
 						", remove=" + removeN +
 						", gift=" + gift);
 				
 				Type type = null;
 				for (int i = 0; i < aCounter; i ++) {
 					type = aList.remove(0);
 				}
 				aList.get(0).remove(removeN);
 				if (type != null) {
 					type.remove(removeN);
 					aList.add(0, type);
 				}
 				
 				type = null;
 				for (int i = 0; i < bCounter; i ++) {
 					type = bList.remove(0);
 				}
 				bList.get(0).remove(removeN);
 				if (type != null) {
 					type.remove(removeN);
 					bList.add(0, type);
 				}
 				
 				boolean flag;
 				flag = true;
 				while (flag) {
 					flag = false;
 					for (Type t : aList) {
 						if (t.getN() <= 0) {
 							aList.remove(t);
 							flag = true;
 							break;
 						}
 					}
 				}
 				flag = true;
 				while (flag) {
 					flag = false;
 					for (Type t : bList) {
 						if (t.getN() <= 0) {
 							bList.remove(t);
 							flag = true;
 							break;
 						}
 					}
 				}
 			}
 			
 			return "" + gift;
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
 			String list = "a=";
 			for (Type type : aList) {
 				list += type;
 			}
 			list += ", b=";
 			for (Type type : bList) {
 				list += type;
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
 	/*
 	public class LevelComparator implements Comparator<Type> {
 		public int compare(Type o1, Level o2) {
 			return (int)(- o1.getB() + o2.getB());
 		}
 	}
 	*/
 	
 	/**
 	 * NX𗘗p͂B
 	 */
 	public class Type {
 		long n;
 		long type;
 		public Type(long n, long type) {
 			this.n = n;
 			this.type = type;
 		}
 		long getN () {
 			return n;
 		}
 		void remove(long hoge) {
 			n -= hoge;
 		}
 		long getType() {
 			return type;
 		}
 		public String toString() {
 			return "[" + n + "," + type + "]";
 		}
 	}
 	
 	/*
 	 * note:
 	 * _ȉ̐
 	 * String.format("%.6f", ans);
 	 * 
 	 * 
 	 */
 }
