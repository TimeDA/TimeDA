package com.g0413.a;
 
 import java.io.BufferedReader;
 import java.io.File;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.IOException;
 import java.util.ArrayList;
 
 public class Problem {
 	public final String FILE_PATH = "C:/data/workspace/googleCodeJam2013/src/" + "com/g0413/a/";
 	// public final String FILE_BASE = "B-large-practice";
 	public final String FILE_BASE = "sample";
 	public final String INPUT_FILE = FILE_PATH + FILE_BASE + ".in";
 	public final String OUTPUT_FILE = FILE_PATH + FILE_BASE + ".txt";
 	
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
 	
 	public static final long X = 1l;
 	public static final long O = -1l;
 	public static final long T = 0l;
 	public static final long N = 100;
 	
 	public void init() throws ProblemException {
 		try {
 			FileReader in = new FileReader(INPUT_FILE);
 			BufferedReader br = new BufferedReader(in);
 			String line;
 			long testN = -1;
 			testN = Long.parseLong(br.readLine());
 			for (int i = 0; i < testN ; i++) {
 				long mass[][] = new long[4][4];
 				for (int n = 0; n < 4; n++) {
 					line = br.readLine();
 					for (int m = 0; m < 4; m++) {
 						String s = line.substring(m, m+1);
 						if ("X".equals(s)) {
 							mass[m][n] = X;
 						} else if ("O".equals(s)) {
 							mass[m][n] = O;
 						} else if ("T".equals(s)) {
 							mass[m][n] = T;
 						} else {
 							mass[m][n] = N;
 						}
 					}
 				}
 				Test test = new Test(mass);
 				testList.add(test);
 				try {
 					br.readLine();
 				} catch (Exception e) {
 					e.printStackTrace();
 				}
 			}
 			br.close();
 			in.close();
 		} catch (IOException e) {
 			System.out.println(e);
 			throw new ProblemException(e.getMessage(),e);
 		}
 	}
 	
 	
 	public class Test {
 		
 		private long mass[][] = new long [4][4];
 		
 		public Test (long mass[][]) {
 			this.mass = mass;
 		}
 		
 		public String check () {
 			for (int i = 0; i < 4; i ++){
 				long sum = 0;
 				for (int j = 0; j < 4; j++) {
 					sum += mass[i][j];
 				}
 				if (sum == 3 || sum == 4) {
 					return "X won";
 				}
 				if (sum == -3 || sum == -4) {
 					return "O won";
 				}
 			}
 			for (int j = 0; j < 4; j++) {
 				long sum = 0;
 				for (int i = 0; i < 4; i ++){
 					sum += mass[i][j];
 				}
 				if (sum == 3 || sum == 4) {
 					return "X won";
 				}
 				if (sum == -3 || sum == -4) {
 					return "O won";
 				}
 			}
 			{
 				long sum = 0;
 				for (int i = 0; i < 4; i++){
 					sum += mass[i][i];
 				}
 				if (sum == 3 || sum == 4) {
 					return "X won";
 				}
 				if (sum == -3 || sum == -4) {
 					return "O won";
 				}
 			}
 			{
 				long sum = 0;
 				for (int i = 0; i < 4; i++){
 					sum += mass[i][3-i];
 				}
 				if (sum == 3 || sum == 4) {
 					return "X won";
 				}
 				if (sum == -3 || sum == -4) {
 					return "O won";
 				}
 			}
 			{
 				long sum = 0;
 				for (int i = 0; i < 4; i++){
 					for (int j = 0; j < 4; j++){
 						sum += mass[i][j];
 					}
 				}
 				if (sum > 50) {
 					return "Game has not completed";
 				}
 			}
 			
 			return "Draw";
 			// return "" + this.toString();
 		}
 		
 		
 		@Override
 		public String toString() {
 			String list = " ";
 			for (int j = 0; j < 4; j++) {
 				for (int i = 0; i < 4; i++) {
 					list += mass[i][j] + ",";
 				}
 				list += "\n";
 			}
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
