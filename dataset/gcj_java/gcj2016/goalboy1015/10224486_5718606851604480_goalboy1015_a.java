import java.util.HashMap;
 import java.util.Map;
 import java.util.Scanner;
 
 public class A {
 	static Map<State, String> state2result = new HashMap<State, String>();
 
 	public static void main(String[] args) {
 		for (String sequence : new String[] { "R", "P", "S" }) {
 			for (int N = 0; N <= 3; N++) {
 				int rNum = getNum(sequence, 'R');
 				int pNum = getNum(sequence, 'P');
 				int sNum = getNum(sequence, 'S');
 				State state = new State(rNum, pNum, sNum);
 
 				String minSequence = adjust(sequence);
 				if (!state2result.containsKey(state) || state2result.get(state).compareTo(minSequence) > 0) {
 					state2result.put(state, minSequence);
 				}
 
 				sequence = expand(sequence);
 			}
 		}
 
 		Scanner sc = new Scanner(System.in);
 
 		int T = sc.nextInt();
 		for (int tc = 1; tc <= T; tc++) {
 			System.out.print("Case #" + tc + ": ");
 
 			int N = sc.nextInt();
 			int R = sc.nextInt();
 			int P = sc.nextInt();
 			int S = sc.nextInt();
 
 			State state = new State(R, P, S);
 			if (state2result.containsKey(state)) {
 				System.out.println(state2result.get(state));
 			} else {
 				System.out.println("IMPOSSIBLE");
 			}
 		}
 
 		sc.close();
 	}
 
 	static String adjust(String s) {
 		// System.out.println("from " + s);
 		for (int i = 2; i <= s.length(); i *= 2) {
 			String nextS = "";
 			for (int j = 0; j + i <= s.length(); j += i) {
 				int half = i / 2;
 				String left = s.substring(j, j + half);
 				String right = s.substring(j + half, j + i);
 
 				String lr = left + right;
 				String rl = right + left;
 
 				String min = lr.compareTo(rl) < 0 ? lr : rl;
 
 				nextS += min;
 			}
 			s = nextS;
 		}
 		// System.out.println("to " + s);
 		return s;
 	}
 
 	static int getNum(String s, char target) {
 		return (int) (s.chars().filter(ch -> ch == target).count());
 	}
 
 	static String expand(String sequence) {
 		StringBuilder sb = new StringBuilder();
 		for (int i = 0; i < sequence.length(); i++) {
 			char ch = sequence.charAt(i);
 			if (ch == 'P') {
 				sb.append("PR");
 			} else if (ch == 'R') {
 				sb.append("RS");
 			} else {
 				sb.append("SP");
 			}
 		}
 		return sb.toString();
 	}
 }
 
 class State {
 	int r;
 	int p;
 	int s;
 
 	State(int r, int p, int s) {
 		this.r = r;
 		this.p = p;
 		this.s = s;
 	}
 
 	@Override
 	public int hashCode() {
 		return r * p * s;
 	}
 
 	@Override
 	public boolean equals(Object obj) {
 		State other = (State) obj;
 		return r == other.r && p == other.p && s == other.s;
 	}
 }