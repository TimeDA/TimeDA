package gcj2016.r2;
 
 import java.util.Arrays;
 import java.util.Iterator;
 import java.util.Scanner;
 
 public class A_BF {
     final int N, R, P, S;
     private static final String impossible = "IMPOSSIBLE";
     private static final char[] moves = "RPS".toCharArray();
 
     // parse
     public A_BF(final Scanner sc) {
         N = sc.nextInt();
         R = sc.nextInt();
         P = sc.nextInt();
         S = sc.nextInt();
     }
 
     String min = "~";
 
     // solve
     @Override
     public String toString() {
         final int[] res = new int[1 << N];
         search(0, new int[]{R, P, S}, res);
         if (min.equals("~"))
             return impossible;
         else
             return min;
     }
 
     void search(int idx, int[] nums, int[] arr) {
         if (idx == arr.length)
             check(arr);
         else
             for (int i = 0; i < nums.length; i++)
                 if (nums[i] > 0) {
                     nums[i]--;
                     arr[idx] = i;
                     search(idx + 1, nums, arr);
                     nums[i]++;
                 }
     }
 
     void check(int[] arr) {
         final int[] a = Arrays.copyOf(arr, arr.length);
         for (int n = a.length; n > 1; n >>= 1)
             for (int i = 0; i < n; i += 2)
                 if (a[i] == a[i + 1])
                     return;
                 else if ((a[i + 1] - a[i] + 3) % 3 == 1)
                     a[i / 2] = a[i + 1];
                 else
                     a[i / 2] = a[i];
         final StringBuilder sb = new StringBuilder();
         for (int i = 0; i < arr.length; i++)
             sb.append(moves[arr[i]]);
         final String s = sb.toString();
         if (s.compareTo(min) < 0)
             min = s;
     }
 
     // Template
     public static void main(String... args) throws Exception {
         try (final Scanner sc = new Scanner(System.in)) {
             final int T = sc.nextInt();
             final Object[] solvers = new Object[T];
             for (int i = 0; i < T; i++)
                 solvers[i] = new A_BF(sc);
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
