package gcj2017.qual;
 
 import java.util.Arrays;
 import java.util.Iterator;
 import java.util.Scanner;
 
 public class A {
     char[] S;
     int K;
 
     // parse
     public A(final Scanner sc) {
         S = sc.next().toCharArray();
         K = sc.nextInt();
     }
 
     // solve
     @Override
     public String toString() {
         int ans = 0;
         for (int i = 0; i <= S.length - K; i++)
             if (S[i] == '-') {
                 for (int j = 0; j < K; j++)
                     S[i + j] = S[i + j] == '-' ? '+' : '-';
                 ans++;
             }
         for(final char c : S)
             if(c == '-')
                 return "IMPOSSIBLE";
         return Integer.toString(ans);
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
