package gcj2016.qual;
 
 import java.util.Arrays;
 import java.util.Iterator;
 import java.util.Scanner;
 
 public class A {
     private static final double EPS = 1e-12;
     private static final int INF = 1 << 20;
     private static final int[] di = {-1, 0, 0, 1};
     private static final int[] dj = {0, -1, 1, 0};
 
     private final int N;
 
     // parse
     public A(final Scanner sc) {
         N = sc.nextInt();
     }
 
     // solve
     @Override
     public String toString() {
         if(N == 0)
             return "INSOMNIA";
         int seen = 0;
         long num = 0;
         while(seen < 1023) {
             num += N;
             final char[] cs = Long.toString(num).toCharArray();
             for(final char c : cs)
                 seen |= 1 << c - '0';
         }
         return Long.toString(num);
     }
 
     // Template
     public static void main(String... args) throws Exception {
         try (final Scanner sc = new Scanner(System.in)) {
             final int T = sc.nextInt();
             final Object[] solvers = new Object[T];
             for (int i = 0; i < T; i++)
                 solvers[i] = new A(sc);
             final Iterator<String> results = Arrays.stream(solvers)
                     .map(s -> s.toString())
                     .iterator();
             for (int i = 1; i <= T; i++)
                 System.out.printf("Case #%s: %s\n", i, results.next());
         }
     }
 
     private static void debug(Object... os) {
         System.err.println(Arrays.deepToString(os));
     }
 }
