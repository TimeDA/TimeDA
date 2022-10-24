package com.g0428.a;
 
 import java.io.BufferedReader;
 import java.io.File;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.IOException;
 import java.util.ArrayList;
 import java.util.Comparator;
 
 public class Problem {
 	// private final String FILE_PATH = "C:/data/workspace/googleCodeJam2012/src/com/g0419/a/";
 	private final String CURRENT_DIR = 
 			new File(".").getAbsoluteFile().getParent() + "\\" + "src" + "\\" +
 			this.getClass().getPackage().getName().replace(".", "\\") + "\\";
 	// public final String INPUT_FILE = FILE_PATH + "A-large.in";
 	private final String INPUT_FILE = CURRENT_DIR + "A-small-attempt0.in";
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
 				
 				Test test = new Test(line.split(" "), br.readLine().split(" "));
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
 		long a = 0;
 		long b = 0;
 		ArrayList<Double> p = new ArrayList<Double>(); 
 		
 		/**
 		 *  ͂ɍ킹ďCB
 		 */
 		public Test (String[] str1, String [] str2) {
 			this.a = Long.parseLong(str1[0]);
 			this.b = Long.parseLong(str1[1]);
 			for (String str : str2) {
 				p.add(Double.parseDouble(str));
 			}
 		}
 		
 		/**
 		 *  ɃASYSSB
 		 */
 		public String check () {
 			// TODO
 			
 			double minRet = b + 2;
 			for (int backspace = 0; backspace <= a; backspace ++) {
 				double correct = 1;
 				for (int c = 0; c < (a - backspace); c++){
 					correct *= p.get(c);
 				}
 				double ret1 = backspace * 2 + b - a + 1;
 				double ret2 = (1 - correct) * (b + 1);
 				double ret = ret1 + ret2;
 				System.out.println("corret=" + correct);
 				System.out.println("ret=" + ret + ",ret1=" + ret1 + ",ret2=" + ret2);
 				if (ret < minRet) {
 					minRet = ret;
 				}
 			}
 			
 			return "" + String.format("%.6f", minRet);
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
 			for (double ppp : p) {
 				list += ppp + ",";
 			}
 			return "(" + a + "," + b + ")" + list;
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
 	
 	/**
 	 * NX𗘗p͂B
 	 */
 	public class Dummy {
 		int a;
 		int b;
 		public Dummy(int a, int b) {
 			this.a = a;
 			this.b = b;
 		}
 	}
 }
