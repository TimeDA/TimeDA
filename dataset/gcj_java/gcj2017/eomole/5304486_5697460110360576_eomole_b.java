package gcj2017.r1a;
 
 import java.util.Arrays;
 import java.util.Iterator;
 import java.util.Scanner;
 
 public class B {
     static final double EPS = 1e-9;
     int N, P;
     int[] R;
     int[][] Q;
 
     // parse
     public B(final Scanner sc) {
         N = sc.nextInt();
         P = sc.nextInt();
         R = new int[N];
         for (int i = 0; i < N; i++)
             R[i] = sc.nextInt();
         Q = new int[N][P];
         for (int i = 0; i < N; i++)
             for (int j = 0; j < P; j++)
                 Q[i][j] = sc.nextInt();
     }
 
     // solve
     @Override
     public String toString() {
         for (int i = 0; i < N; i++)
             Arrays.sort(Q[i]);
         final int[][] max = new int[N][P];
         final int[][] min = new int[N][P];
         for (int i = 0; i < N; i++)
             for (int j = 0; j < P; j++) {
                 final double d = 1. * Q[i][j] / R[i];
                 max[i][j] = (int) Math.floor(d / 0.9 + EPS);
                 min[i][j] = (int) Math.ceil(d / 1.1 - EPS);
             }
         int ans = 0;
         final int[] idx = new int[N];
         loop:
         for (int i = 0; i < P; i++)
             if (min[0][i] <= max[0][i]) {
                 for (int j = 1; j < N; j++) {
                     while (idx[j] < P && max[j][idx[j]] < min[0][i])
                         idx[j]++;
                     if (idx[j] >= P)
                         break loop;
                     if (min[j][idx[j]] > max[0][i])
                         continue loop;
                 }
                 ans++;
                 for (int j = 1; j < N; j++)
                     idx[j]++;
             }
         return Integer.toString(ans);
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
