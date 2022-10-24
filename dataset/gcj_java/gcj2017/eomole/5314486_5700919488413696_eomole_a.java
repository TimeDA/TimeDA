package gcj2017.r2;
 
 import java.util.Arrays;
 import java.util.Iterator;
 import java.util.Scanner;
 
 public class A {
     int N, P, G[];
 
     // parse
     public A(final Scanner sc) {
         N = sc.nextInt();
         P = sc.nextInt();
         G = new int[N];
         for (int i = 0; i < N; i++)
             G[i] = sc.nextInt();
     }
 
     // solve
     @Override
     public String toString() {
         final int[] cnt = new int[P];
         for (int i = 0; i < N; i++)
             cnt[G[i] % P]++;
         switch (P) {
             case 2:
                 return Integer.toString(cnt[0] + cnt[1] / 2 + cnt[1] % 2);
             case 3: {
                 int ans = cnt[0];
                 int min = Math.min(cnt[1], cnt[2]);
                 ans += min;
                 int res = cnt[1] + cnt[2] - 2 * min;
                 ans += res / 3 + (res % 3 > 0 ? 1 : 0);
                 return Integer.toString(ans);
             }
             case 4:
             default:
                 throw null;
         }
     }
 
     // Template
     public static void main(String... args) throws Exception {
         try (final Scanner sc = new Scanner(System.in)) {
             final int T = sc.nextInt();
             final Object[] solvers = new Object[T];
             for (int i = 0; i < T; i++)
                 solvers[i] = new A(sc);
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
