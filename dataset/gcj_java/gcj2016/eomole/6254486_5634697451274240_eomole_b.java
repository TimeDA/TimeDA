package gcj2016.qual;
 
 import java.util.Arrays;
 import java.util.Iterator;
 import java.util.Scanner;
 
 public class B {
     final char[] S;
 
     // parse
     public B(final Scanner sc) {
         S = (sc.next() + "+").toCharArray();
     }
 
     // solve
     @Override
     public String toString() {
         int cnt = 0;
         for(int i = 1; i < S.length; i++)
             if(S[i] != S[i - 1])
                 cnt++;
         return Integer.toString(cnt);
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
