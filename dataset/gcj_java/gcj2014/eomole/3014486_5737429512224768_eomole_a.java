import java.util.*;
 import java.util.stream.Stream;
 
 public class A {
     private final int N, X, S[];
 
     // parse
     public A(final Scanner sc) {
         N = sc.nextInt();
         X = sc.nextInt();
         S = new int[N];
         for (int i = 0; i < N; i++)
             S[i] = sc.nextInt();
         Arrays.sort(S);
     }
 
     // solve
     @Override
     public String toString() {
         final Deque<Integer> deq = new ArrayDeque<>();
         for (final int s : S)
             deq.offerLast(s);
         int ans = 0;
         while (!deq.isEmpty()) {
             final int max = deq.pollLast();
             if (!deq.isEmpty() && deq.peekFirst() + max <= X)
                 deq.pollFirst();
             ans++;
         }
 
         return "" + ans;
     }
 
     // Template
     public static void main(String... args) throws Exception {
         try (final Scanner sc = new Scanner(System.in)) {
             final int T = sc.nextInt();
             final Object[] solvers = new Object[T];
             for (int i = 0; i < T; i++)
                 solvers[i] = new A(sc);
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
