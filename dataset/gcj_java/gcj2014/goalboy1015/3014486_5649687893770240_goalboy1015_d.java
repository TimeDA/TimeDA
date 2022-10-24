import java.io.File;
 import java.io.PrintStream;
 import java.util.ArrayList;
 import java.util.HashMap;
 import java.util.HashSet;
 import java.util.Scanner;
 
 public class D {
 	static final Boolean SAMPLE = false;
 	static final String PROBLEM = "D";
 	static final String INPUT = "small";
 	static final String ID = "0";
 	static final String PATH = "/Users/wangkai/Documents/software installer/codejam-commandline-1.2-beta1/source/";
 
 	@SuppressWarnings("unchecked")
 	public static void main(String[] args) throws Throwable {
 		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
 				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
 		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
 				+ "-" + INPUT + "-" + ID + ".out");
 
 		int test = in.nextInt();
 		for (int t = 1; t <= test; t++) {
 			out.print("Case #" + t + ": ");
 
 			int M = in.nextInt();
 			int N = in.nextInt();
 			String[] words = new String[M];
 			for (int i = 0; i < M; i++) {
 				words[i] = in.next();
 			}
 
 			HashMap<Integer, Integer> node2count = new HashMap<Integer, Integer>();
 			ArrayList<String>[] servers = new ArrayList[N];
 			for (int i = 0; i < N; i++) {
 				servers[i] = new ArrayList<String>();
 			}
 			buildNode2count(servers, words, node2count, 0);
 
 			int maxNode = -1;
 			for (int node : node2count.keySet()) {
 				if (node > maxNode) {
 					maxNode = node;
 				}
 			}
 
 			out.println(maxNode + " " + node2count.get(maxNode));
 		}
 
 		out.close();
 		in.close();
 
 		System.out.println("finish!");
 	}
 
 	static void buildNode2count(ArrayList<String>[] servers, String[] words,
 			HashMap<Integer, Integer> node2count, int index) {
 		if (index == words.length) {
 			if (!hasEmptyServer(servers)) {
 				int totalNode = 0;
 				for (ArrayList<String> server : servers) {
 					totalNode += computeNode(server);
 				}
 				increase(node2count, totalNode);
 			}
 			return;
 		}
 		for (int i = 0; i < servers.length; i++) {
 			servers[i].add(words[index]);
 			buildNode2count(servers, words, node2count, index + 1);
 			servers[i].remove(servers[i].size() - 1);
 		}
 	}
 
 	static boolean hasEmptyServer(ArrayList<String>[] servers) {
 		for (ArrayList<String> server : servers) {
 			if (server.isEmpty()) {
 				return true;
 			}
 		}
 		return false;
 	}
 
 	static void increase(HashMap<Integer, Integer> node2count, int node) {
 		if (!node2count.containsKey(node)) {
 			node2count.put(node, 0);
 		}
 		node2count.put(node, node2count.get(node) + 1);
 	}
 
 	static int computeNode(ArrayList<String> server) {
 		HashSet<String> prefixSet = new HashSet<String>();
 		for (String word : server) {
 			for (int i = 0; i <= word.length(); i++) {
 				prefixSet.add(word.substring(0, i));
 			}
 		}
 		return prefixSet.size();
 	}
 }
