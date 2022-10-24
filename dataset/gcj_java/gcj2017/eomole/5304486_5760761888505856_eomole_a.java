package gcj2017.r1a;
 
 import java.util.Arrays;
 import java.util.Iterator;
 import java.util.Scanner;
 
 public class A {
     int R, C;
     char[][] map;
 
     // parse
     public A(final Scanner sc) {
         R = sc.nextInt();
         C = sc.nextInt();
         map = new char[R][];
         for (int i = 0; i < R; i++)
             map[i] = sc.next().toCharArray();
     }
 
     // solve
     @Override
     public String toString() {
         final char[] empty = new char[C];
         Arrays.fill(empty, '?');
         char[] prev = empty;
         for(int i = 0; i < R; i++) {
             process(prev, map[i]);
             prev = map[i];
         }
         for(int i = R - 1; i >= 0; i--) {
             process(prev, map[i]);
             prev = map[i];
         }
         final StringBuilder sb = new StringBuilder();
         for(final char[] line: map)
             sb.append(line).append('\n');
         return sb.toString();
     }
 
     private void process(final char[] pline, final char[] line) {
         if (hasInitial(line)) {
             char prev = '?';
             for (int i = 0; i < C; i++)
                 if (line[i] == '?')
                     line[i] = prev;
                 else
                     prev = line[i];
             for (int i = C - 1; i >= 0; i--)
                 if (line[i] == '?')
                     line[i] = prev;
                 else
                     prev = line[i];
         } else {
             for (int i = 0; i < C; i++)
                 line[i] = pline[i];
         }
     }
 
     private boolean hasInitial(final char[] cs) {
         for (final char c : cs)
             if (c != '?')
                 return true;
         return false;
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
                 System.out.printf("Case #%s:\n%s", i, results.next());
         }
     }
 
     private static void debug(Object... os) {
         System.err.println(Arrays.deepToString(os));
     }
 }
