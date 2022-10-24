package gcj2017.qual;
 
 import java.util.Arrays;
 import java.util.Iterator;
 import java.util.Scanner;
 
 public class B {
     long N;
 
     // parse
     public B(final Scanner sc) {
         N = sc.nextLong();
     }
 
     // solve
     @Override
     public String toString() {
         final char[] cs = Long.toString(N).toCharArray();
         int last = cs.length;
         for (int i = cs.length - 1; i > 0; i--)
             if (cs[i] < '0' || cs[i - 1] > cs[i]) {
                 last = i;
                 cs[i - 1]--;
             }
         for(int i = last; i < cs.length; i++)
             cs[i] = '9';
         return Long.toString(Long.parseLong(new String(cs)));
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
