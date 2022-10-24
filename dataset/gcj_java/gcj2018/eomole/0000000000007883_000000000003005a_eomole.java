import java.util.Scanner;

class WaffleChoppers {
    static final String possible = "POSSIBLE";
    static final String impossible = "IMPOSSIBLE";

    static String solve(int R, int C, int H, int V, char[][] waffle) {
        int chocolates = 0;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (waffle[i][j] == '@')
                    chocolates++;
        if (chocolates % (H * V) > 0)
            return impossible;
        if (chocolates == 0)
            return possible;
        final int unit = chocolates / H / V;
        final int[] hcut = new int[H];
        for (int i = 0, k = 0, cnt = 0; i < R; i++) {
            for (int j = 0; j < C; j++)
                if (waffle[i][j] == '@')
                    cnt++;
            if (cnt == unit * V) {
                hcut[k++] = i + 1;
                cnt = 0;
            } else if (cnt > unit * V)
                return impossible;
        }
        final int[] vcut = new int[V];
        for (int j = 0, k = 0, cnt = 0; j < C; j++) {
            for (int i = 0; i < R; i++)
                if (waffle[i][j] == '@')
                    cnt++;
            if (cnt == unit * H) {
                vcut[k++] = j + 1;
                cnt = 0;
            } else if (cnt > unit * H)
                return impossible;
        }
        for (int k = 0, phcut = 0; k < H; phcut = hcut[k++])
            for (int l = 0, pvcut = 0; l < V; pvcut = vcut[l++]) {
                int cnt = 0;
                for (int i = phcut; i < hcut[k]; i++)
                    for (int j = pvcut; j < vcut[l]; j++)
                        if (waffle[i][j] == '@')
                            cnt++;
                if (cnt > unit)
                    return impossible;
            }

        return possible;
    }

    public static void main(String... args) {
        final Scanner sc = new Scanner(System.in);
        final int T = sc.nextInt();
        for (int c = 1; c <= T; c++) {
            final int R = sc.nextInt();
            final int C = sc.nextInt();
            final int H = sc.nextInt() + 1;
            final int V = sc.nextInt() + 1;
            final char[][] waffle = new char[R][];
            for (int i = 0; i < R; i++)
                waffle[i] = sc.next().toCharArray();
            System.out.printf("Case #%d: %s\n", c, solve(R, C, H, V, waffle));
        }
    }
}
public class Solution {
    public static void main(String...args) {
        WaffleChoppers.main();
    }
}