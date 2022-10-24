import java.util.Arrays;
import java.util.Scanner;

class TroubleSort {
    static String solve(int N, int[] V) {
        final int[] odds = new int[N / 2];
        final int[] evens = new int[(N + 1) / 2];
        for (int i = 0; i < N; i++)
            if (i % 2 == 0)
                evens[i / 2] = V[i];
            else
                odds[i / 2] = V[i];
        Arrays.sort(odds);
        Arrays.sort(evens);
        for (int i = 0; i < N; i++)
            if (i % 2 == 0)
                V[i] = evens[i / 2];
            else
                V[i] = odds[i / 2];
        for (int i = 0; i + 1 < N; i++)
            if (V[i] > V[i + 1])
                return Integer.toString(i);
        return "OK";
    }

    public static void main(String... args) {
        final Scanner sc = new Scanner(System.in);
        final int T = sc.nextInt();
        for (int c = 1; c <= T; c++) {
            final int N = sc.nextInt();
            final int[] V = new int[N];
            for (int i = 0; i < N; i++)
                V[i] = sc.nextInt();
            System.out.printf("Case #%d: %s\n", c, solve(N, V));
        }
    }
}
public class Solution {
    public static void main(String...args) {
        TroubleSort.main();
    }
}
