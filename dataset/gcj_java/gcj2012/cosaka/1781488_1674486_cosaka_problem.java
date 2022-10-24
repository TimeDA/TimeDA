package com.g0506.a;
 
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
 				int n = Integer.parseInt(line);
 				ArrayList<String[]> list = new ArrayList<String[]>();
 				for (int i = 0; i < n; i++) {
 					list.add(br.readLine().split(" "));
 				}
 				Test test = new Test(list);
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
 		ArrayList<ArrayList<Integer>> sListList = new ArrayList<ArrayList<Integer>>();
 		
 		/**
 		 *  ͂ɍ킹ďCB
 		 */
 		public Test (ArrayList<String[]> strList) {
 			for (String[] str: strList) {
 				ArrayList<Integer> iList = new ArrayList<Integer>();
 				
 				for (int i = 0; i < Integer.parseInt(str[0]); i ++) {
 					iList.add(Integer.parseInt(str[i + 1]));
 				}
 				sListList.add(iList);
 			}
 		}
 		
 		/**
 		 *  ɃASYSSB
 		 */
 		public String check () {
 			// TODO
 			// System.out.println("" + this);
 			ArrayList<ArrayList<Integer>> newSListList = new ArrayList<ArrayList<Integer>>();
 
 			int size = sListList.size();
 			for (int i = 0; i < size; i++) {
 				newSListList.add(new ArrayList<Integer> ());
 			}
 			
 			boolean flag = true;
 			
 			while (flag) {
 				flag = false;
 				Integer counter = 1;
 				for (ArrayList<Integer> sList : sListList){
 					if (sList.size() == 0) {
 						Integer counterTmp = 1;
 						for (ArrayList<Integer> sListTmp : sListList){
 							if (sListTmp.contains((Object)counter)) {
 								sListTmp.remove((Object)counter);
 								
 								for (Integer i : newSListList.get(counter - 1)) {
 									if (newSListList.get(counterTmp - 1).contains((Object)i)) {
 										return "Yes";
 									}
 									newSListList.get(counterTmp - 1).add(i);
 								}
 								if (newSListList.get(counterTmp - 1).contains((Object)counter)) {
 									return "Yes";
 								}
 								newSListList.get(counterTmp - 1).add(counter);
 								flag = true;
 							}
 							counterTmp ++;
 						}
 						sList.add(-1);
 					}
 					counter ++;
 				}
 			}
 			
 			// System.out.println("" + toString2(newSListList));
 			return "No";
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
 			for (ArrayList<Integer> str : sListList) {
 				list += "[";
 				for (Integer i : str) {
 					list += i + ",";
 				}
 				list += "]";
 			}
 			return list;
 		}
 		
 		public String toString2(ArrayList<ArrayList<Integer>> newSListList) {
 			String list = " ";
 			for (ArrayList<Integer> str : newSListList) {
 				list += "[";
 				for (Integer i : str) {
 					list += i + ",";
 				}
 				list += "]";
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
 	
 	/*
 	 * note:
 	 * _ȉ̐
 	 * String.format("%.6f", ans);
 	 * 
 	 * 
 	 */
 }
