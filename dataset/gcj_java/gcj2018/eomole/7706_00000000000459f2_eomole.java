import java.util.*;

class FallingBalls {
    static String solve(int C, int[] B) {
        int cnt = 0;
        for (int i = 0; i < C; i++)
            if (B[i] > 0)
                cnt++;
        if (B[0] == 0 || B[C - 1] == 0)
            return "IMPOSSIBLE";
        final int[] L = new int[cnt + 1];
        final int[] P = new int[cnt];
        for (int i = 0, j = 0, k = 0; j < cnt; i++)
            if (B[i] > 0) {
                P[j] = i;
                L[j] = k;
                j++;
                k += B[i];
            }
        L[cnt] = C;
        final char[][] layout = new char[C][C];
        for (int i = 0; i < C; i++)
            for (int j = 0; j < C; j++)
                layout[i][j] = '.';
        for(int i = 0; i < cnt; i++) {
            for(int j = 0; j + L[i] < P[i]; j++)
                layout[j][j + L[i]] = '\\';
            for(int j = 0; L[i + 1] - j - 1 > P[i]; j++)
                layout[j][L[i + 1] - j - 1 ] = '/';
        }
        int row = 0;
        for(int i = 0; i < C; i++)
            for(int j = 0; j < C; j++)
                if(layout[i][j] != '.')
                    row = i + 1;
        final StringBuilder sb = new StringBuilder();
        sb.append(row + 1);
        for (int i = 0; i <= row; i++)
            sb.append('\n').append(layout[i]);
        return sb.toString();
    }

    public static void main(String... args) {
        final Scanner sc = new Scanner(System.in);
        final int T = sc.nextInt();
        for (int c = 1; c <= T; c++) {
            final int C = sc.nextInt();
            final int[] B = new int[C];
            for (int i = 0; i < C; i++)
                B[i] = sc.nextInt();
            System.out.printf("Case #%d: %s\n", c, solve(C, B));
        }
    }
}

public class Solution {
    public static void main(String...args) {
        FallingBalls.main();
    }
}