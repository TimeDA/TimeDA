import java.io.*;
 import java.util.*;
 import java.util.concurrent.Callable;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.Future;
 
 import static java.util.Arrays.deepToString;
 
 public class A implements Runnable {
     private static final char PROB = A.class.getSimpleName().charAt(0);
     private static int DEFAULT_PARARELL = 1;//Runtime.getRuntime().availableProcessors() + 1;
     private static File DIR = new File(".");
     private static boolean TEST_ALL = false;
 
     public static class Solver implements Callable<String> {
         private static final int MOD = 1_000_002_013;
 
         private final int N, M;
         private final Passenger[] ps;
 
         // parse
         public Solver(final Scanner sc) {
             N = sc.nextInt();
             M = sc.nextInt();
             ps = new Passenger[M];
             for (int i = 0; i < M; i++)
                 ps[i] = new Passenger(sc.nextInt(), sc.nextInt(), sc.nextInt());
             Arrays.sort(ps);
         }
 
         // solve
         @Override
         public String call() {
             final NavigableMap<Integer, Queue<Ticket>> map = new TreeMap<>();
             for (int i = 0; i < M; i++) {
                 if (!map.containsKey(ps[i].o))
                     map.put(ps[i].o, new PriorityQueue<Ticket>());
                 if (!map.containsKey(ps[i].e))
                     map.put(ps[i].e, new PriorityQueue<Ticket>());
             }
             long ans = 0;
             for (final Passenger p : ps) {
                 final Queue<Ticket> hold = new PriorityQueue<>(10, Collections.reverseOrder());
                 hold.offer(new Ticket(p.o, p.p));
                 for (final Map.Entry<Integer, Queue<Ticket>> e : map.subMap(p.o, p.e).entrySet()) {
                     final Queue<Ticket> que = e.getValue();
                     if (!que.isEmpty())
                         while (!que.isEmpty() && que.peek().compareTo(hold.peek()) < 0) {
                             final Ticket mine = hold.poll();
                             final Ticket yours = que.poll();
                             final int exchange = Math.min(mine.p, yours.p);
                             final int loss = mine.o - yours.o;
                             ans = (ans + 1L * loss * exchange % MOD * (p.e - e.getKey()) % MOD) % MOD;
                             if (mine.p > exchange)
                                 hold.offer(new Ticket(mine.o, mine.p - exchange));
                             if (yours.p > exchange)
                                 que.offer(new Ticket(yours.o, yours.p - exchange));
                             hold.offer(new Ticket(yours.o, exchange));
                         }
                 }
                 map.get(p.e).addAll(hold);
             }
             return "" + ans;
         }
 
         private static class Passenger implements Comparable<Passenger> {
             final int o, e, p;
 
             public Passenger(int o, int e, int p) {
                 this.o = o;
                 this.e = e;
                 this.p = p;
             }
 
             @Override
             public int compareTo(Passenger o) {
                 return this.o == o.o ? -this.e + o.e : this.o - o.o;
             }
 
             @Override
             public String toString() {
                 return "Passenger{" +
                         "o=" + o +
                         ", e=" + e +
                         ", p=" + p +
                         '}';
             }
         }
 
         private static class Ticket implements Comparable<Ticket> {
             final int o, p;
 
             public Ticket(int o, int p) {
                 this.o = o;
                 this.p = p;
             }
 
             @Override
             public int compareTo(Ticket o) {
                 return this.o - o.o;
             }
 
             @Override
             public String toString() {
                 return "Ticket{" +
                         "o=" + o +
                         ", p=" + p +
                         '}';
             }
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
