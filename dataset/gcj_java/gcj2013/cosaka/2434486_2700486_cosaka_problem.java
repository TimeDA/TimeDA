package com.g0505.b;
 
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
 	public final String FILE_PATH = "C:/data/workspace/googleCodeJam2013/src/" + "com/g0505/b/";
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
 				String n = line.split(" ")[0];
 				String x = line.split(" ")[1];
 				String y = line.split(" ")[2];
 				Test test = new Test(Long.parseLong(n), Long.parseLong(x), Long.parseLong(y));
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
 		
 		int n = 0;
 		int x = 0;
 		int y = 0;
 		
 		public Test (long n, long x, long y) {
 			this.n = (int)n;
 			this.x = (int)x;
 			this.y = (int)y;
 		}
 		
 		public String check () {
 			int xx = Math.abs(x);
 			int yy = Math.abs(y);
 			if (n == 0) {
 				return "0.0";
 			} else if (n == 1) {
 				if (xx + yy < 1) {
 					return "1.0";
 				} else {
 					return "0.0";
 				}
 			} else if (1 < n && n < 6) {
 				if (xx + yy < 1) {
 					return "1.0";
 				}
 				if (xx + yy > 3) {
 					return "0.0";
 				}
 				// TODO
 				int nn = n - 1;
 				int max = 2;
 				boolean [] chance = new boolean[n];
 				
 				int success = 0;
 				int failure = 0;
 				while (true){
 					int get = 0;
 					int notGet = 0;
 					for (int i = 0; i < nn; i ++) {
 						if ((chance[i] || notGet == max) && get < max) {
 							get ++;
 						} else {
 							notGet ++;
 						}
 					}
 					//System.out.println("yy=" + yy + ", get=" + get);
 					if (yy < get){
 						success ++;
 					} else {
 						failure ++;
 					}
 					for (int i = 0; i < nn; i++) {
 						if (chance[i] == false) {
 							chance[i] = true;
 							break;
 						} else {
 							chance[i] = false;
 						}
 					}
 					boolean flag = true;
 					for (int i = 0; i < nn; i++) {
 						if (chance[i]) {
 							flag = false;
 							break;
 						}
 					}
 					if (flag){
 						break;
 					}
 				}
 				//System.out.println("nn=" + nn + ", success=" + success + ", failure=" + failure);
 				return "" + ((float) success / (failure + success));
 			} else if (n == 6) {
 				if (xx + yy < 3) {
 					return "1.0";
 				} else {
 					return "0.0";
 				}
 			} else if (6 < n && n < 15) {
 				if (xx + yy < 3) {
 					return "1.0";
 				}
 				if (xx + yy > 5) {
 					return "0.0";
 				}
 				// TODO
 				int nn = n - 6;
 				int max = 4;
 				boolean [] chance = new boolean[nn];
 				
 				int success = 0;
 				int failure = 0;
 				while (true){
 					int get = 0;
 					int notGet = 0;
 					for (int i = 0; i < nn; i ++) {
 						if ((chance[i] || notGet == max) && get < max) {
 							get ++;
 						} else {
 							notGet ++;
 						}
 					}
 					//System.out.println("yy=" + yy + ", get=" + get);
 					if (yy < get){
 						success ++;
 					} else {
 						failure ++;
 					}
 					for (int i = 0; i < nn; i++) {
 						if (chance[i] == false) {
 							chance[i] = true;
 							break;
 						} else {
 							chance[i] = false;
 						}
 					}
 					boolean flag = true;
 					for (int i = 0; i < nn; i++) {
 						if (chance[i]) {
 							flag = false;
 							break;
 						}
 					}
 					if (flag){
 						break;
 					}
 				}
 				//System.out.println("nn=" + nn + ", success=" + success + ", failure=" + failure);
 				return "" + ((float) success / (failure + success));
 			} else if (n == 15) {
 				if (xx + yy < 5) {
 					return "1.0";
 				} else {
 					return "0.0";
 				}
 			} else {
 				if (xx + yy < 5) {
 					return "1.0";
 				}
 				if (xx + yy > 7) {
 					return "0.0";
 				}
 				// TODO
 				// TODO
 				int nn = n - 15;
 				int max = 6;
 				boolean [] chance = new boolean[nn];
 				
 				int success = 0;
 				int failure = 0;
 				while (true){
 					int get = 0;
 					int notGet = 0;
 					for (int i = 0; i < nn; i ++) {
 						if ((chance[i] || notGet == max) && get < max) {
 							get ++;
 						} else {
 							notGet ++;
 						}
 					}
 					//System.out.println("yy=" + yy + ", get=" + get);
 					if (yy < get){
 						success ++;
 					} else {
 						failure ++;
 					}
 					for (int i = 0; i < nn; i++) {
 						if (chance[i] == false) {
 							chance[i] = true;
 							break;
 						} else {
 							chance[i] = false;
 						}
 					}
 					boolean flag = true;
 					for (int i = 0; i < nn; i++) {
 						if (chance[i]) {
 							flag = false;
 							break;
 						}
 					}
 					if (flag){
 						break;
 					}
 				}
 				//System.out.println("nn=" + nn + ", success=" + success + ", failure=" + failure);
 				return "" + ((float) success / (failure + success));
 			}
 		}
 		
 		@Override
 		public String toString() {
 			String list = " " + n + "," + x + "," + y;
 			return list + "";
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
