package com.g0413.d;
 
 import java.io.BufferedReader;
 import java.io.File;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.IOException;
 import java.util.ArrayList;
 
 public class Problem {
 	public final String FILE_PATH = "C:/data/workspace/googleCodeJam2013/src/" + "com/g0413/d/";
 	// public final String FILE_BASE = "B-large";
 	public final String FILE_BASE = "D-small-attempt1";
 	// public final String FILE_BASE = "sample2";
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
 	
 	public static final long X = 1l;
 	public static final long O = -1l;
 	public static final long T = 0l;
 	public static final long N = 100;
 	
 	public void init() throws ProblemException {
 		try {
 			FileReader in = new FileReader(INPUT_FILE);
 			BufferedReader br = new BufferedReader(in);
 			long testN = -1;
 			testN = Long.parseLong(br.readLine());
 			for (int i = 0; i < testN ; i++) {
 				String line = br.readLine();
 				String[] line2 = line.split(" ");
 				int k = Integer.parseInt(line2[0]);
 				int n = Integer.parseInt(line2[1]);
 				Test test = new Test(k);
 				line2 = br.readLine().split(" ");
 				for (String s : line2) {
 					test.addStart(Integer.parseInt(s));
 				}
 				for (int j = 0; j < n; j++) {
 					line = br.readLine();
 					line2 = line.split(" ");
 					ArrayList<Integer> list = new ArrayList<Integer>();
 					int flag = 0;
 					for (String s : line2) {
 						flag++;
 						if (flag == 1 || flag == 2) {
 							continue;
 						}
 						list.add(Integer.parseInt(s));
 					}
 					test.add(j + 1, Integer.parseInt(line2[0]), list);
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
 		
 		private ArrayList<Integer> orgKeyList = new ArrayList<Integer>();
 		private ArrayList<Chest> orgChestList = new ArrayList<Chest>(); 
 		int keySize = 0;
 		
 		public Test (int keySize) {
 			this.keySize = keySize;
 		}
 		
 		public void addStart(int start) {
 			this.orgKeyList.add(start);
 		}
 
 		public void add(int id, int t, ArrayList<Integer> list) {
 			this.orgChestList.add(new Chest(id, t, list));
 		}
 		public String check () {
 			// ̐a{̐b@@KvȌc
 			for (int i = 1; i < keySize + 1; i++) {
 				int a = 0;
 				int b = 0;
 				int c = 0;
 				for (Integer j : orgKeyList) {
 					if (i == j) {
 						a++;
 					}
 				}
 				for (Chest chest : orgChestList) {
 					for (Integer j : chest.treasureList) {
 						if (i == j) {
 							b++;
 						}
 					}
 					if (i == chest.needKey) {
 						c++;
 					}
 				}
 				if (a + b < c) {
 					return "IMPOSSIBLE";
 				}
 			}
 			
 			ArrayList<Integer> ret = new ArrayList<Integer>();
 			ret = sub(keyCopy(orgKeyList), chestCopy(orgChestList), keySize);
 			if (ret == null) {
 				return "IMPOSSIBLE";
 			}
 			
 			String str = "" + ret.get(0);
 			boolean flag = false;
 			for (Integer i : ret) {
 				if (flag) {
 					str += " " + i ;
 				}
 				flag = true;
 			}
 			return str;
 		}
 		
 		public ArrayList<Integer> sub(ArrayList<Integer> keyList, ArrayList<Chest> chestList, int keySize) {
 			ArrayList<Integer> ret = new ArrayList<Integer>();
 			if (chestList.size() == 0) {
 				return ret;
 			}
 			
 			if (loopCheck (keyList, chestList, keySize)) {
 				return null;
 			}
 			
 			// for debug
 			{ 
 				int keys = 0;
 				for (Chest c : chestList) {
 					keys += c.treasureList.size();
 				}
 				/*
 				System.out.println("keyList=" + keyList.size() + ", chestList=" + chestList.size() + 
 						", keys=" + keys);
 						*/
 				
 			}
 			// for debug
 			
 			for (Chest chest : chestList) {
 				if (keyList.contains(chest.needKey)) {
 					ArrayList<Integer> tmpKeyList = keyCopy(keyList);
 					removeKey(tmpKeyList, chest.needKey);
 					for (Integer key : chest.treasureList) {
 						tmpKeyList.add(key);
 					}
 					ArrayList<Chest> tmpChestList = chestCopy(chestList);
 					removeChest(tmpChestList, chest.id);
 					ArrayList<Integer> subList = sub(tmpKeyList, tmpChestList, keySize);
 					if (subList != null) {
 						ret.add(chest.id);
 						ret.addAll(subList);
 						return ret;
 					}
 				}
 			}
 			return null;
 		}
 		
 		// _ȂƂtrueԂB
 		public boolean loopCheck(ArrayList<Integer> keyList, ArrayList<Chest> chestList, int keySize) {
 			if (keyList.size() == 0) {
 				return true;
 			}
 			
 			// ĂȂL[T
 			for (int i = 1; i < keySize + 1; i ++) {
 				// L[ĂB
 				if (keyList.contains(i)) {
 					continue;
 				}
 				// L[͕svB
 				boolean flag = true;
 				for (Chest chest : chestList) {
 					if (chest.needKey == i) {
 						flag = false;
 						break;
 					}
 				}
 				if (flag) {
 					continue;
 				}
 				// āA`FbN
 				int key = i;
 				flag = true;
 				for (int j = 0; j < keySize; j ++) {
 					int count = 0;
 					for (Chest chest : chestList) {
 						if (chest.treasureList.contains(key)) {
 							count ++;
 							key = chest.needKey;
 						}
 					}
 					if (count > 1) {
 						flag = false;
 						break;
 					}
 					if (keyList.contains(key)) {
 						flag = false;
 						break;
 					}
 				}
 				if (flag) {
 					return true;
 				}
 			}
 			return false;
 		}
 		
 		public void removeKey (ArrayList<Integer> keyList, int removeKey) {
 			for (int i = 0; i < keyList.size(); i++) {
 				if (keyList.get(i) == removeKey) {
 					keyList.remove(i);
 					return;
 				}
 			}
 			System.out.println("aaaaa!!!!!!!!");
 		}
 		
 		public ArrayList<Integer> keyCopy (ArrayList<Integer> list) {
 			ArrayList<Integer> ret = new ArrayList<Integer>();
 			for (Integer i : list){
 				ret.add(i);
 			}
 			return ret;
 		}
 		
 		public void removeChest(ArrayList<Chest> chestList, int id) {
 			for (int i = 0; i < chestList.size(); i++) {
 				if (chestList.get(i).id == id) {
 					chestList.remove(i);
 					return;
 				}
 			}
 		}
 		
 		public ArrayList<Chest> chestCopy (ArrayList<Chest> list) {
 			ArrayList<Chest> ret = new ArrayList<Chest> ();
 			for (Chest c : list) {
 				ArrayList<Integer> copyList = new ArrayList<Integer>();
 				for (Integer i : c.treasureList) {
 					copyList.add(i);
 				}
 				Chest cc = new Chest(c.id, c.needKey, copyList);
 				ret.add(cc);
 			}
 			return ret;
 		}
 		
 		@Override
 		public String toString() {
 			String ret = "";
 			for (Integer i : orgKeyList) {
 				ret += " " + i;
 			}
 			for (Chest c : orgChestList) {
 				ret += "(" + c + ")";
 			}
 			return ret;
 		}
 	}
 	
 	public class Chest {
 		int id = -1;
 		int needKey = -1;
 		ArrayList<Integer> treasureList = null;
 		public Chest(int id, int t, ArrayList<Integer> list) {
 			this.id = id;
 			this.needKey = t;
 			this.treasureList = list;
 		}
 		
 		@Override
 		public String toString() {
 			String str = "{" + id + "}" + "[" + needKey + "]";
 			for (Integer s : treasureList) {
 				str += " " + s;
 			}
 			return str;
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
