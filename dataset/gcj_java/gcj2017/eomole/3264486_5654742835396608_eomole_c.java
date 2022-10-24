package gcj2017.qual;
 
 import java.util.*;
 
 public class C {
     long N, K;
 
     // parse
     public C(final Scanner sc) {
         N = sc.nextLong();
         K = sc.nextLong();
     }
 
     // solve
     @Override
     public String toString() {
         final TreeMap<Long, Long> map = new TreeMap<>();
         map.put(N, 1L);
         while(true) {
             final Map.Entry<Long, Long> e = map.pollLastEntry();
             final long max = e.getKey() / 2;
             final long min = e.getKey() - max - 1;
             if(e.getValue() >= K)
                 return String.format("%d %d", max, min);
             K -= e.getValue();
             map.put(max, map.getOrDefault(max, 0L) + e.getValue());
             map.put(min, map.getOrDefault(min, 0L) + e.getValue());
         }
     }
 
     // Template
     public static void main(String... args) throws Exception {
         try (final Scanner sc = new Scanner(System.in)) {
             final int T = sc.nextInt();
             final Object[] solvers = new Object[T];
             for (int i = 0; i < T; i++)
                 solvers[i] = new C(sc);
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
