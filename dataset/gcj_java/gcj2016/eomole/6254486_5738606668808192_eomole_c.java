package gcj2016.qual;
 
 import java.io.PrintStream;
 import java.util.Arrays;
 import java.util.Scanner;
 import java.util.stream.Collectors;
 import java.util.stream.IntStream;
 
 public class C {
     private static final String name = "gcj/src/main/java/gcj2016/qual/C-small.out";
 
     public static void main(String... args) throws Exception {
         final boolean[] isComp = new boolean[1 << 16];
         for (int i = 2; i * i < isComp.length; i++)
             if (!isComp[i])
                 for (long j = i * i; j < isComp.length; j += i)
                     isComp[(int) j] = true;
         final int[] primes = IntStream.range(2, isComp.length).filter(i -> !isComp[i]).toArray();
         System.setOut(new PrintStream(name));
 
         try (final Scanner sc = new Scanner(System.in)) {
             final int T = sc.nextInt();
             final int N = sc.nextInt();
             int J = sc.nextInt();
             System.out.println("Case #1:");
             final String format = String.format("1%%%ds1", N - 2);
             loop:
             for (int i = 0; J > 0 && i < 1 << (N - 2); i++) {
                 final String jam = String.format(format, Integer.toBinaryString(i)).replace(" ", "0");
                 final long[] nt = new long[11];
                 for (int base = 2; base <= 10; base++) {
                     final long k = Long.parseLong(jam, base);
                     for (final int p : primes)
                         if (k <= p)
                             break;
                         else if (k % p == 0) {
                             nt[base] = k / p;
                             break;
                         }
                     if (nt[base] == 0)
                         continue loop;
                 }
                 final String result = jam + " " +
                         Arrays.stream(nt, 2, 11).mapToObj(Long::toString).collect(Collectors.joining(" "));
                 System.out.println(result);
                 debug(result);
                 J--;
             }
         }
     }
 
     private static void debug(Object... os) {
         System.err.println(Arrays.deepToString(os));
     }
 }
