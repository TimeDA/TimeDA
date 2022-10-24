package com.g0505.a;
 
 import java.io.BufferedReader;
 import java.io.File;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.IOException;
 import java.util.ArrayList;
 import java.util.Arrays;
 import java.util.Collections;
 import java.util.List;
 
 public class Problem {
 	public final String FILE_PATH = "C:/data/workspace/googleCodeJam2013/src/" + "com/g0505/a/";
 	// public final String FILE_BASE = "A-large";
 	public final String FILE_BASE = "A-small-attempt0";
 	public final String INPUT_FILE = FILE_PATH + FILE_BASE + ".in";
 	public final String OUTPUT_FILE = FILE_PATH + FILE_BASE + ".out";
 	
 	ArrayList<Test> testList = new ArrayList<Test>();
 	
 	public static void main(String[] args) {
 		try {
 			Problem p = new Problem();
 			p.init();
 			p.printResult();
 			p.end();
 		} catch (Exception e) {
 			e.printStackTrace();
 		}
 	}
 	
 	public void printResult() throws ProblemException {
 		long i = 1;
 		for (Test p : testList) {
 			prlong("Case #" + i + ": " + p.check());
 			i++;
 		}
 	}
 	
 	public static boolean flag = true;
 	FileWriter outputFile = null;
 	public void prlong(String str) throws ProblemException {
 		try {
 			// t@C̍폜At@C̐VKI[v
 			if (flag) {
 				flag = false;
 				File fw01 = new File(OUTPUT_FILE);
 				fw01.delete();
 				outputFile = new FileWriter(OUTPUT_FILE, true);
 			}
 			outputFile.write(str + "\r\n");
 			System.out.println(str);
 		} catch (IOException e) {
 				throw new ProblemException(e.getMessage(),e);
 		}
 	}
 	
 	public void end() throws ProblemException {
 		try {
 			outputFile.close();
 		} catch (IOException e) {
 			throw new ProblemException(e.getMessage(),e);
 		}
 	}
 	
 	public void init() throws ProblemException {
 		try {
 			FileReader in = new FileReader(INPUT_FILE);
 			BufferedReader br = new BufferedReader(in);
 			String line;
 			long testN = -1;
 			testN = Long.parseLong(br.readLine());
 			for (int i = 0; i < testN ; i++) {
 				line = br.readLine();
 				String a = line.split(" ")[0];
 				String n = line.split(" ")[1];
 				Test test = new Test(Long.parseLong(a), Long.parseLong(n));
 				line = br.readLine();
 				List<Integer> list = new ArrayList<Integer>();
 				for (String str : line.split(" ")) {
 					list.add(Integer.parseInt(str));
 				}
 				test.add(list);
 				testList.add(test);
 			}
 			br.close();
 			in.close();
 		} catch (IOException e) {
 			System.out.println(e);
 			throw new ProblemException(e.getMessage(),e);
 		}
 	}
 	
 	
 	public class Test {
 		
 		long a = 0;
 		long n = 0;
 		List<Integer> moteList;
 		
 		public Test (long r, long t) {
 			this.a = r;
 			this.n = t;
 		}
 		
 		public void add (List<Integer> moteList) {
 			this.moteList = moteList;
 			Collections.sort(moteList);
 		}
 		
 		public String check () {
 			for (int count = 0; count < 10000000; count++) {
 				boolean[] operator = new boolean[count];
 				while(true) {
 					long aa = a;
 					List<Integer> moteList2 = copy(moteList);
 					for (int i = 0; i < count; i++) {
 						while (true){
 							if (moteList2.size() == 0) {
 								return "" + (count - 1);
 							}
 							if (moteList2.get(0) < aa) {
 								aa += moteList2.get(0);
 								moteList2.remove(0);
 								continue;
 							}
 							break;
 						}
 						if (operator[i]) {
 							aa += aa - 1;
 						} else {
 							moteList2.remove(moteList2.size() - 1);
 						}
 					}
 					// count up
 					for (int i = 0; i < count; i ++) {
 						if (operator[i] == false) {
 							operator[i] = true;
 							break;
 						} else {
 							operator[i] = false;
 						}
 					}
 					// break? (all false)
 					boolean flag = true;
 					for (int i = 0; i < count ; i++) {
 						if (operator[i]) {
 							flag = false;
 							break;
 						}
 					}
 					if (flag) {
 						break;
 					}
 				}
 			}
 			return "" + this.toString();
 		}
 		
 		public List<Integer> copy(List<Integer> l) {
 			ArrayList<Integer> ret = new ArrayList<Integer>();
 			for (Integer i : l) {
 				ret.add(i);
 			}
 			return ret;
 		}
 		
 		@Override
 		public String toString() {
 			String list = " " + a + "," + n;
 			return list + moteList.get(0)+ moteList.get(1);
 		}
 	}
 	
 	public class ProblemException extends Exception {
 		private static final long serialVersionUID = 2080823058826051635L;
 		public ProblemException(String message) {
 			super(message);
 		}
 		public ProblemException(String message, Throwable e) {
 			super (message, e);
 		}
 	}
 	
 	/*
 	 * 
 Case #1: 1
 Case #2: 256
 Case #3: 4
 Case #4: 674
 Case #5: 461
 	 * 
 	 */
 }
