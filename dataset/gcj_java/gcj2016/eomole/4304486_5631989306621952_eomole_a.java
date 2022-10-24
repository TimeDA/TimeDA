package gcj2016.r1a;
 
 import java.util.*;
 
 public class A {
 
     final char[] S;
     final TreeSet<String> set = new TreeSet<>();
 
     // parse
     public A(final Scanner sc) {
         S = sc.next().toCharArray();
     }
 
     // solve
     @Override
     public String toString() {
         go(0, "");
         return set.last();
     }
 
     void go(int idx, String s) {
         if(idx < S.length) {
             go(idx + 1, S[idx] + s);
             go(idx + 1, s + S[idx]);
         } else
             set.add(s);
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
