import java.io.*;
 import java.util.*;
 import java.util.concurrent.*;
 import java.math.*;
 
 import static java.lang.Math.*;
 import static java.lang.Character.*;
 import static java.util.Arrays.*;
 import static java.util.Collections.*;
 import static java.math.BigInteger.*;
 
 public class A implements Runnable {
 	private static final char PROB = A.class.getSimpleName().charAt(0);
 	private static int DEFAULT_PARARELL = Runtime.getRuntime().availableProcessors() + 1;
 	private static File DIR = new File(".");
 	private static boolean TEST_ALL = false;
 
 	public static class Solver implements Callable<String> {
 		private static char[] vowels = "aeiou".toCharArray();
 		private final char[] name;
 		private final int n;
 
 		// parse
 		public Solver(final Scanner sc) {
 			name = sc.next().toCharArray();
 			n = sc.nextInt();
 		}
 
 		// solve
 		@Override
 		public String call() {
 			final boolean[] isConsonant = new boolean[name.length];
 			fill(isConsonant, true);
 			for (int i = 0; i < name.length; i++)
 				for (final char c : vowels)
 					isConsonant[i] &= name[i] != c;
 			final boolean[] ends = new boolean[name.length + 1];
 			for (int i = 0, j = 0, k = 0; i < name.length;) {
 				while (j < name.length && k < n) {
 					if (isConsonant[j])
 						k++;
 					else
 						k = 0;
 					j++;
 				}
 				if (k == n) {
 					i = j - --k;
 					ends[j] = true;
 				}
 				if (j == name.length)
 					break;
 			}
 			final int[] near = new int[name.length + 1];
 			for (int i = 1; i <= name.length; i++)
 				near[i] = ends[i] ? i - n + 1 : near[i - 1];
 			long ans = 0L;
 			for (int i = 0; i <= name.length; i++)
 				ans += near[i];
 
 			return "" + ans;
 		}
 	}
 
 	// Template
 	@Override
 	public void run() {
 		final ExecutorService es = Executors.newFixedThreadPool(DEFAULT_PARARELL);
 		try (final Scanner sc = new Scanner(System.in)) {
 			final List<Future<String>> list = new ArrayList<>();
 			final int T = sc.nextInt();
 			for (int i = 0; i < T; i++)
 				list.add(es.submit(new Solver(sc)));
 			for (int t = 1; t <= T; t++) {
 				debugf("Case #%s%n", t);
 				System.out.printf("Case #%s: %s%n", t, list.get(t - 1).get());
 				System.gc();
 			}
 			debug("done.");
 		} catch (Exception e) {
 			e.printStackTrace();
 		}
 		es.shutdown();
 	}
 
 	public static void main(String... args) throws IOException {
 		if (TEST_ALL) {
 			for (final String input : seekInputFiles()) {
 				debug("INPUT", input);
 				System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR, input))));
 				System.setOut(new PrintStream(input + ".out"));
 				new A().run();
 			}
 		} else {
 			final String input = seekInputFile();
 			debug("INPUT", input);
 			if (input != null) {
 				System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR, input))));
 				System.setOut(new PrintStream(input + ".out"));
 			} else
 				DEFAULT_PARARELL = 1;
 			new A().run();
 		}
 	}
 
 	private static String seekInputFile() {
 		final String[] names = new String[] { PROB + "-large-practice-2.in", PROB + "-large-practice-1.in",
 				PROB + "-large-practice.in", PROB + "-large-2.in", PROB + "-large-1.in", PROB + "-large.in",
 				PROB + "-small-practice-2.in", PROB + "-small-practice-1.in", PROB + "-small-practice.in" };
 		for (final String s : names)
 			if (new File(DIR, s).exists())
 				return s;
 		for (int k = 2; k >= 0; k--) {
 			int max = -1;
 			for (int i = 0; new File(DIR, PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + i + ".in").exists(); i++)
 				max = i;
 			if (max >= 0)
 				return PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + max + ".in";
 		}
 		return null;
 	}
 
 	private static List<String> seekInputFiles() {
 		final List<String> ret = new ArrayList<>();
 		final String[] names = new String[] { PROB + "-large-practice-2.in", PROB + "-large-practice-1.in",
 				PROB + "-large-practice.in", PROB + "-large-2.in", PROB + "-large-1.in", PROB + "-large.in",
 				PROB + "-small-practice-2.in", PROB + "-small-practice-1.in", PROB + "-small-practice.in" };
 		for (final String s : names)
 			if (new File(DIR, s).exists())
 				ret.add(s);
 		for (int k = 2; k >= 0; k--) {
 			int max = -1;
 			for (int i = 0; new File(DIR, PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + i + ".in").exists(); i++)
 				max = i;
 			if (max >= 0)
 				ret.add(PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + max + ".in");
 		}
 		return ret;
 	}
 
 	private static void debugf(String format, Object... os) {
 		System.err.printf(format, os);
 	}
 
 	private static void debug(Object... os) {
 		System.err.println(deepToString(os));
 	}
 }
