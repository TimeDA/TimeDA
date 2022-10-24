package com.g0427.b;
 
 import java.io.BufferedReader;
 import java.io.File;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.IOException;
 import java.util.ArrayList;
 
 public class Problem {
 	public final String FILE_PATH = "C:/data/workspace/googleCodeJam2013/src/" + "com/g0427/b/";
 	// public final String FILE_BASE = "A-large";
 	public final String FILE_BASE = "B-small-attempt1";
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
 				String e = line.split(" ")[0];
 				String r = line.split(" ")[1];
 				String n = line.split(" ")[2];
 				Test test = new Test(Long.parseLong(e), Long.parseLong(r), Integer.parseInt(n));
 				line = br.readLine();
 				int j = 0;
 				for (String s : line.split(" ")) {
 					test.add(j, Integer.parseInt(s));
 					j++;
 				}
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
 		
 		int e = 0;
 		int r = 0;
 		int n = 0;
 		int[] list = null;
 		
 		public Test (long e, long r, int n) {
 			this.e = (int)e;
 			this.r = (int)r;
 			this.n = n;
 			list = new int[n];
 		}
 		
 		public void add(int j, int i) {
 			list[j] = i;
 		}
 		
 		public String check () {
 			int[] power = new int[n];
 			for (int i = 0; i < n; i ++) {
 				power[i] = 0;
 			}
 			
 			int maxN = 0;
 			for (int k = 0; k < 10000000; k++){
 				int value = 0;
 				int energy = e;
 				
 				// power count up
 				for (int i = 0; i < n; i ++) {
 					power[i] ++;
 					if (5 < power[i]) {
 						power[i] = 0;
 					} else {
 						break;
 					}
 				}
 				
 				for (int i = 0; i < n; i ++) {
 					if (energy < power[i]) {
 						value += energy * list[i];
 					} else {
 						value += power[i] * list[i];
 					}
 					energy -= power[i];
 					energy += r;
 					if (energy > e) {
 						energy = e;
 					}
 				}
 				if (maxN < value) {
 					maxN = value;
 				}
 			}
 			
 			return "" + maxN;
 		}
 		
 		
 		@Override
 		public String toString() {
 			String list = " " + e + "," + r;
 			return list;
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
