package gcj2016.r2;
 
 import java.util.Arrays;
 import java.util.Iterator;
 import java.util.Scanner;
 
 public class B {
     private static final double EPS = 1e-12;
 
     final int N, K;
     final double[] P;
 
     // parse
     public B(final Scanner sc) {
         N = sc.nextInt();
         K = sc.nextInt();
         P = new double[N];
         for (int i = 0; i < N; i++)
             P[i] = sc.nextDouble();
     }
 
     // solve
     @Override
     public String toString() {
         double max = 0;
         final int[] ms = new int[K];
         for (int mask = 0; mask < 1 << N; mask++)
             if (Integer.bitCount(mask) == K) {
                 for (int i = 1, j = 0, k = 0; i <= mask; i <<= 1, j++)
                     if ((mask & i) > 0)
                         ms[k++] = j;
                 double p = 0;
                 for (int ag = 0; ag < 1 << K; ag++)
                     if (Integer.bitCount(ag) == K / 2) {
                         double q = 1;
                         for (int i = 0; i < K; i++)
                             if ((ag & 1 << i) > 0)
                                 q *= P[ms[i]];
                             else
                                 q *= 1 - P[ms[i]];
                         p += q;
                     }
                 max = Math.max(max, p);
             }
         return Double.toString(max);
     }
 
     // Template
     public static void main(String... args) throws Exception {
         try (final Scanner sc = new Scanner(System.in)) {
             final int T = sc.nextInt();
             final Object[] solvers = new Object[T];
             for (int i = 0; i < T; i++)
                 solvers[i] = new B(sc);
             final Iterator<String> results = Arrays.stream(solvers)
                     .map(Object::toString)
                     .iterator();
             for (int i = 1; i <= T; i++)
                 System.out.printf("Case #%s: %s\n", i, results.next());
         }
     }
 
     private static void debug(Object... os) {
         System.err.println(Arrays.deepToString(os));
     }
 }
