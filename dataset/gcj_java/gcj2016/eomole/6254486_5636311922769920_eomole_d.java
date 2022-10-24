package gcj2016.qual;
 
 import java.util.Arrays;
 import java.util.Iterator;
 import java.util.Scanner;
 import java.util.stream.Collectors;
 import java.util.stream.LongStream;
 
 public class D {
     final int K, C, S;
 
     // parse
     public D(final Scanner sc) {
         K = sc.nextInt();
         C = sc.nextInt();
         S = sc.nextInt();
     }
 
     // solve
     @Override
     public String toString() {
         if (S * C < K)
             return "IMPOSSIBLE";
         final long[] tiles = new long[S];
         for(int i = 0; i * C < S; i++) {
             long l = 0;
             for(int j = 0; j < C; j++) {
                 l *= K;
                 l += (i * C + j) % K;
             }
             tiles[i] = l + 1;
         }
         return Arrays.stream(tiles).filter(l -> l > 0).mapToObj(Long::toString).collect(Collectors.joining(" "));
     }
 
     // Template
     public static void main(String... args) throws Exception {
         try (final Scanner sc = new Scanner(System.in)) {
             final int T = sc.nextInt();
             final Object[] solvers = new Object[T];
             for (int i = 0; i < T; i++)
                 solvers[i] = new D(sc);
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
