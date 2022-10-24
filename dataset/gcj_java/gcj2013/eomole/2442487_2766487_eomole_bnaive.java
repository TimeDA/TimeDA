import java.io.*;
 import java.util.ArrayList;
 import java.util.List;
 import java.util.Scanner;
 import java.util.concurrent.Callable;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.Future;
 
 import static java.util.Arrays.deepToString;
 
 public class Bnaive implements Runnable {
     private static final char PROB = Bnaive.class.getSimpleName().charAt(0);
     private static int DEFAULT_PARARELL = Runtime.getRuntime().availableProcessors() + 1;
     private static File DIR = new File(".");
     private static boolean TEST_ALL = false;
 
     public static class Solver implements Callable<String> {
         private final int N;
         private final long P;
 
 
         // parse
         public Solver(final Scanner sc) {
             N = sc.nextInt();
             P = sc.nextLong();
         }
 
         // solve
         @Override
         public String call() {
             return String.format("%d %d", win(N, P), (1L << N) - win(N, (1L << N) - P) - 2);
         }
 
         private static String decode(long N, long l) {
             final StringBuilder sb = new StringBuilder();
             for (int i = 0; i < N; i++, l >>= 1)
                 sb.append((l & 1) > 0 ? 'L' : 'W');
             return sb.reverse().toString();
         }
 
 
         private static long win(final long N, final long P) {
             if(P == 1L << N)
                 return P - 1;
             final String s = decode(N, P - 1);
             int lose = 0;
             while(lose < s.length() && s.charAt(lose) == 'L')
                 lose++;
             lose++;
             return Math.min((1L << lose) - 2, P - 1);
         }
 
     }
 
     // Template
     @Override
     public void run() {
         final ExecutorService es = Executors.newFixedThreadPool(DEFAULT_PARARELL);
         try (final Scanner sc = new Scanner(System.in)) {
             final List<Future<String>> list = new ArrayList<>();
             final int T = sc.nextInt();
             sc.nextLine();
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
                 new Bnaive().run();
             }
         } else {
             final String input = seekInputFile();
             debug("INPUT", input);
             if (input != null) {
                 System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR, input))));
                 System.setOut(new PrintStream(input + ".out"));
             } else
                 DEFAULT_PARARELL = 1;
             new Bnaive().run();
         }
     }
 
     private static String seekInputFile() {
         final String[] names = new String[]{PROB + "-large-practice-2.in", PROB + "-large-practice-1.in",
                 PROB + "-large-practice.in", PROB + "-large-2.in", PROB + "-large-1.in", PROB + "-large.in",
                 PROB + "-small-practice-2.in", PROB + "-small-practice-1.in", PROB + "-small-practice.in"};
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
         final String[] names = new String[]{PROB + "-large-practice-2.in", PROB + "-large-practice-1.in",
                 PROB + "-large-practice.in", PROB + "-large-2.in", PROB + "-large-1.in", PROB + "-large.in",
                 PROB + "-small-practice-2.in", PROB + "-small-practice-1.in", PROB + "-small-practice.in"};
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
