import java.util.Arrays;
 import java.util.Iterator;
 import java.util.Scanner;
 import java.util.stream.IntStream;
 
 public class B {
     private final int N, A[];
 
     private static final int[] fac = new int[11];
 
     static {
         fac[0] = 1;
         for (int i = 1; i <= 10; i++)
             fac[i] = fac[i - 1] * i;
     }
 
     // parse
     public B(final Scanner sc) {
         N = sc.nextInt();
         A = new int[N];
         for (int i = 0; i < N; i++)
             A[i] = sc.nextInt();
     }
 
     // solve
     @Override
     public String toString() {
         final int[] is = IntStream.range(0, N).toArray();
         final int[] p = new int[N];
         final int[] inv = new int[N];
         int min = Integer.MAX_VALUE;
 
         do {
             Arrays.setAll(p, i -> A[is[i]]);
             if (isUpDown(p)) {
                 for (int i = 0; i < N; i++)
                     inv[is[i]] = i;
                 int cnt = 0;
                 for (int i = 0; i < N; i++)
                     for (int j = 1; j < N - i; j++)
                         if (inv[j - 1] < inv[j]) {
                             swap(inv, j - 1, j);
                             cnt++;
                         }
                 min = Math.min(min, cnt);
             }
         } while (nextPermutation(is));
 
         return "" + min;
     }
 
     static boolean isUpDown(final int[] is) {
         int i = 1;
         while (i < is.length && is[i - 1] < is[i])
             i++;
         while (i < is.length && is[i - 1] > is[i])
             i++;
         return i == is.length;
     }
 
     static boolean nextPermutation(final int[] is) {
         final int n = is.length;
         for (int i = n - 1; i > 0; i--) {
             if (is[i - 1] < is[i]) {
                 int j = n;
                 while (is[i - 1] >= is[--j])
                     ;
                 swap(is, i - 1, j);
                 rev(is, i, n);
                 return true;
             }
         }
         rev(is, 0, n);
         return false;
     }
 
     static void swap(final int[] is, final int i, final int j) {
         int t = is[i];
         is[i] = is[j];
         is[j] = t;
     }
 
     static void rev(final int[] is, int s, int t) {
         while (s < --t)
             swap(is, s++, t);
     }
 
     // Template
     public static void main(String... args) throws Exception {
         try (final Scanner sc = new Scanner(System.in)) {
             final int T = sc.nextInt();
             final Object[] solvers = new Object[T];
             for (int i = 0; i < T; i++)
                 solvers[i] = new B(sc);
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
