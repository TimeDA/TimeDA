package gcj2017.r2;
 
 import java.util.Arrays;
 import java.util.Iterator;
 import java.util.Scanner;
 
 public class B {
     int N, C, M, P[], B[];
 
     // parse
     public B(final Scanner sc) {
         N = sc.nextInt();
         C = sc.nextInt();
         M = sc.nextInt();
         P = new int[M];
         B = new int[M];
         for (int i = 0; i < M; i++) {
             P[i] = sc.nextInt() - 1;
             B[i] = sc.nextInt() - 1;
         }
     }
 
     // solve
     @Override
     public String toString() {
         if (C > 2)
             return "null";
         int[] head = new int[2];
         int[] tail = new int[2];
         for (int i = 0; i < M; i++)
             if (P[i] == 0)
                 head[B[i]]++;
             else
                 tail[B[i]]++;
         int rides = 0;
         for (int i = 0; i < 2; i++) {
             int d = Math.min(head[i], tail[i ^ 1]);
             rides += d;
             head[i] -= d;
             tail[i^ 1] -= d;
         }
         rides += head[0] + head[1] + Math.max(tail[0], tail[1]);
         int[] cnt = new int[N];
         for (int i = 0; i < M; i++)
             cnt[P[i]]++;
         int promotes = 0;
         for (int i : cnt)
             promotes += Math.max(i - rides, 0);
         return String.format("%d %d", rides, promotes);
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
