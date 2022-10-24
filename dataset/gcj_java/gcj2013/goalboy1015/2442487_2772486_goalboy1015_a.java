import java.io.File;
 import java.io.PrintStream;
 import java.util.PriorityQueue;
 import java.util.Scanner;
 import java.util.TreeMap;
 
 public class A {
 	static final Boolean SAMPLE = false;
 	static final String PROBLEM = "A";
 	static final String INPUT = "small";
 	static final String ID = "0";
 	static final String PATH = "C:\\software installation\\codejam-commandline-1.2-beta1\\source\\";
 
 	public static void main(String args[]) throws Throwable {
 		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
 				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
 		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
 				+ "-" + INPUT + "-" + ID + ".out");
 
 		int test = in.nextInt();
 		for (int t = 1; t <= test; t++) {
 			out.print("Case #" + t + ": ");
 
 			int stationNum = in.nextInt();
 			int M = in.nextInt();
 			TreeMap<Integer, Integer> beginStation2people = new TreeMap<Integer, Integer>();
 			TreeMap<Integer, Integer> endStation2people = new TreeMap<Integer, Integer>();
 			int less = 0;
 			for (int i = 0; i < M; i++) {
 				int begin = in.nextInt();
 				int end = in.nextInt();
 				int people = in.nextInt();
 
 				less += calcProfit(end - begin) * people;
 
 				addPeople(beginStation2people, begin, people);
 				addPeople(endStation2people, end, people);
 			}
 
 			int more = 0;
 			PriorityQueue<Integer> stationDiffs = new PriorityQueue<Integer>();
 			for (int i = 1; i <= stationNum; i++) {
 				int increase = beginStation2people.containsKey(i) ? beginStation2people
 						.get(i) : 0;
 				for (int j = 0; j < increase; j++) {
 					stationDiffs.offer(0);
 				}
 
 				int decrease = endStation2people.containsKey(i) ? endStation2people
 						.get(i) : 0;
 				for (int j = 0; j < decrease; j++) {
 					more += calcProfit(stationDiffs.poll());
 				}
 
 				PriorityQueue<Integer> nextStationDiffs = new PriorityQueue<Integer>();
 				for (int stationDiff : stationDiffs) {
 					nextStationDiffs.offer(stationDiff + 1);
 				}
 				stationDiffs = nextStationDiffs;
 			}
 
 			out.println((more - less) % 1000002013);
 		}
 
 		out.close();
 		in.close();
 
 		System.out.println("finish!");
 	}
 
 	static int calcProfit(int stationDiff) {
 		return stationDiff * (stationDiff + 1) / 2;
 	}
 
 	static void addPeople(TreeMap<Integer, Integer> station2people,
 			int station, int delta) {
 		if (!station2people.containsKey(station)) {
 			station2people.put(station, 0);
 		}
 		station2people.put(station, station2people.get(station) + delta);
 	}
 }
