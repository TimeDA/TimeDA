import java.io.*;
 import java.util.*;
 import java.util.concurrent.*;
 import java.math.*;
 import java.net.URL;
 import java.nio.charset.Charset;
 
 import static java.lang.Math.*;
 import static java.lang.Character.*;
 import static java.util.Arrays.*;
 import static java.util.Collections.*;
 import static java.math.BigInteger.*;
 
 public class C implements Runnable {
 	private static final char PROB = C.class.getSimpleName().charAt(0);
 	private static final boolean isPractice = false;
 	private static final Mode mode = Mode.SMALL;
 
 	private static class Solver implements Callable<String> {
 		private static final int states;
 		private static final int[][] table;
 		private static final boolean[] isEnd;
 
 		// shared table
 		static {
 			try {
 				for (final String word : java.nio.file.Files.readAllLines(
 						new File("garbled_email_dictionary.txt").toPath(), Charset.forName("ascii")))
 					State.TOP.put(word);
 				states = State.nid;
 				table = new int[states][26];
 				isEnd = new boolean[states];
 				for (int i = 0; i < states; i++) {
 					final State s = State.states.get(i);
 					isEnd[i] = s.isEnd;
 					for (int j = 0; j < 26; j++)
 						table[i][j] = s.nexts[j] == null ? -1 : s.nexts[j].id;
 				}
 				State.states.clear();
 				for (int j = 0; j < 26; j++)
 					State.TOP.nexts[j] = null;
 			} catch (IOException e) {
 				e.printStackTrace();
 				throw new RuntimeException(e);
 			}
 		}
 
 		public static class State {
 			private static final List<State> states = new ArrayList<>();
 			private static int nid = 0;
 			private final int id = nid++;
 			private final State[] nexts = new State[26];
 			private boolean isEnd = false;
 			public static final State TOP = new State();
 
 			public State() {
 				states.add(this);
 			}
 
 			public void put(final String s) {
 				if (s.isEmpty())
 					isEnd = true;
 				else {
 					final int c = s.charAt(0) - 'a';
 					if (nexts[c] == null)
 						nexts[c] = new State();
 					nexts[c].put(s.substring(1));
 				}
 			}
 		}
 
 		private final char[] cs;
 		private static final int maxDist = 4;
 		private static final int INF = 4000;
 
 		// parse
 		public Solver(final Scanner sc) {
 			cs = sc.next().toCharArray();
 		}
 
 		// solve
 		@Override
 		public String call() {
 			final int top = 0;
 			int[][] min = new int[states][maxDist + 1];
 			for (int i = 0; i < states; i++)
 				for (int j = 0; j <= maxDist; j++)
 					min[i][j] = INF;
 			min[top][maxDist] = 0;
 			int[][] buf = new int[states][maxDist + 1];
 			for (int k = 0; k < cs.length; k++) {
 				int[][] nmin = buf;
 				for (int i = 0; i < states; i++)
 					for (int j = 0; j <= maxDist; j++)
 						nmin[i][j] = INF;
 				for (int i = 0; i < states; i++) {
 					final int next = table[i][cs[k] - 'a'];
 					if (next >= 0) {
 						for (int j = 0; j < maxDist; j++)
 							nmin[next][j + 1] = Math.min(min[i][j], nmin[next][j + 1]);
 						nmin[next][maxDist] = Math.min(min[i][maxDist], nmin[next][maxDist]);
 					}
 					for(int j = 0; j < 26; j++) {
 						final int jnext = table[i][j];
 						if(jnext >= 0)
 							nmin[jnext][0] = Math.min(nmin[jnext][0], min[i][maxDist] + 1);
 					}
 					if (isEnd[i]) {
 						final int tnext = table[top][cs[k] - 'a'];
 						if (tnext >= 0) {
 							for (int j = 0; j < maxDist; j++)
 								nmin[tnext][j + 1] = Math.min(min[i][j], nmin[tnext][j + 1]);
 							nmin[tnext][maxDist] = Math.min(min[i][maxDist], nmin[tnext][maxDist]);
 						}
 						for(int j = 0; j < 26; j++) {
 							final int jnext = table[top][j];
 							if(jnext >= 0)
 								nmin[jnext][0] = Math.min(nmin[jnext][0], min[i][maxDist] + 1);
 						}
 					}
 				}
 				buf = min;
 				min = nmin;
 			}
 
 			int ans = cs.length;
 			for (int i = 0; i < states; i++)
 				if (isEnd[i])
 					for (int j = 0; j <= maxDist; j++)
 						ans = min(ans, min[i][j]);
 
 			return "" + ans;
 		}
 	}
 
 	// Template
 	@Override
 	public void run() {
 		debug(Solver.states);
 		try (final Scanner sc = new Scanner(System.in)) {
 			final List<Future<String>> list = new ArrayList<>();
 			final int T = sc.nextInt();
 			for (int i = 0; i < T; i++)
 				list.add(es.submit(new Solver(sc)));
 			for (int t = 1; t <= T; t++) {
 				debugf("Case #%s%n", t);
 				System.out.printf("Case #%s: %s%n", t, list.get(t - 1).get());
 			}
 			debug("done.");
 		} catch (Exception e) {
 			e.printStackTrace();
 		}
 	}
 
 	public static void main(String... args) {
 		final C t = new C();
 		switch (mode) {
 		case SAMPLE:
 			t.run();
 			break;
 		case SMALL: {
 			String in = PROB + "-small" + (isPractice ? "-practice" : "-attempt" + 0) + ".in";
 			String out = PROB + "-small.out";
 			if (!isPractice)
 				for (int i = 1; new File(PROB + "-small" + "-attempt" + i + ".in").exists(); i++)
 					in = PROB + "-small" + "-attempt" + i + ".in";
 			try {
 				System.setIn(new BufferedInputStream(new FileInputStream(in)));
 				System.setOut(new PrintStream(out));
 				t.run();
 			} catch (Exception e) {
 				e.printStackTrace();
 				System.exit(0);
 			}
 			break;
 		}
 		case SMALL_ALL: {
 			try {
 				if (!isPractice)
 					for (int i = 0; new File(PROB + "-small" + "-attempt" + i + ".in").exists(); i++) {
 						final String in = PROB + "-small" + "-attempt" + i + ".in";
 						System.setIn(new BufferedInputStream(new FileInputStream(in)));
 						t.run();
 					}
 				else {
 					System.setIn(new BufferedInputStream(new FileInputStream(PROB + "-small-practice.in")));
 					t.run();
 				}
 			} catch (Exception e) {
 				e.printStackTrace();
 				System.exit(0);
 			}
 			break;
 		}
 		case LARGE: {
 			try {
 				final String in = PROB + "-large" + (isPractice ? "-practice" : "") + ".in";
 				final String out = PROB + "-large.out";
 				System.setIn(new BufferedInputStream(new FileInputStream(in)));
 				System.setOut(new PrintStream(out));
 				t.run();
 			} catch (Exception e) {
 				e.printStackTrace();
 				System.exit(0);
 			}
 			break;
 		}
 		case LARGE1: {
 			try {
 				final String in = PROB + "-large" + (isPractice ? "-practice" : "") + "-1.in";
 				final String out = PROB + "-large-1.out";
 				System.setIn(new BufferedInputStream(new FileInputStream(in)));
 				System.setOut(new PrintStream(out));
 				t.run();
 			} catch (Exception e) {
 				e.printStackTrace();
 				System.exit(0);
 			}
 			break;
 		}
 		case LARGE2: {
 			try {
 				final String in = PROB + "-large" + (isPractice ? "-practice" : "") + "-2.in";
 				final String out = PROB + "-large-2.out";
 				System.setIn(new BufferedInputStream(new FileInputStream(in)));
 				System.setOut(new PrintStream(out));
 				t.run();
 			} catch (Exception e) {
 				e.printStackTrace();
 				System.exit(0);
 			}
 			break;
 		}
 		default:
 			throw null;
 		}
 		es.shutdown();
 	}
 
 	private static final int DEFAULT_PARARELL = mode == Mode.SAMPLE ? 1
 			: 3;
 	private static final ExecutorService es = Executors.newFixedThreadPool(DEFAULT_PARARELL);
 
 	private static enum Mode {
 		SAMPLE, SMALL, SMALL_ALL, LARGE, LARGE1, LARGE2
 	}
 
 	private static void debugf(String format, Object... os) {
 		System.err.printf(format, os);
 	}
 
 	private static void debug(Object... os) {
 		System.err.println(deepToString(os));
 	}
 }
