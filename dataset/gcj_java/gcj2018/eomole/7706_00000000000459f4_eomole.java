import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

class GridceptionSmall {
    static int solve(int R, int C, char[][] grid) {
        if(R * C <= 4)
            return R * C;
        int ans = 1;
        for (int i = 1; i < 1 << R * C; i++) {
            final boolean[][] map = new boolean[R][C];
            for (int j = 0; j < R; j++)
                for (int k = 0; k < C; k++)
                    map[j][k] = (i & 1 << (j * C + k)) > 0;
            if (connected(map) && bw(map, grid))
                ans = Math.max(ans, Integer.bitCount(i));
        }
        return ans;
    }

    static final int[] di = {0, 1, 0, -1};
    static final int[] dj = {1, 0, -1, 0};

    static boolean connected(boolean[][] map) {
        final boolean[][] visited = new boolean[map.length][map[0].length];
        label:
        for (int i = 0; i < map.length; i++)
            for (int j = 0; j < map[0].length; j++)
                if (map[i][j]) {
                    final Deque<Integer> deq = new ArrayDeque<>();
                    visited[i][j] = true;
                    deq.offerLast(i * map[0].length + j);
                    while (!deq.isEmpty()) {
                        final int p = deq.pollFirst();
                        final int ii = p / map[0].length;
                        final int jj = p % map[0].length;
                        for (int d = 0; d < 4; d++) {
                            final int ni = ii + di[d];
                            final int nj = jj + dj[d];
                            if (0 <= ni && ni < map.length && 0 <= nj && nj < map[0].length && map[ni][nj] && !visited[ni][nj]) {
                                visited[ni][nj] = true;
                                deq.offerLast(ni * map[0].length + nj);
                            }
                        }
                    }
                    break label;
                }
        for (int i = 0; i < map.length; i++)
            for (int j = 0; j < map[0].length; j++)
                if (map[i][j] && !visited[i][j])
                    return false;
        return true;
    }

    static boolean bw(boolean[][] map, char[][] grid) {
        final char[] BW = {'B', 'W'};
        for (int i = 0; i <= map.length; i++)
            for (int j = 0; j <= map[0].length; j++)
                for (int k = 0; k < 2; k++) {
                    boolean success = true;
                    for (int p = 0; p < map.length; p++)
                        for (int q = 0; q < map[0].length; q++)
                            if (map[p][q] && grid[p][q] != BW[(p <= i ? 0 : 1) ^ (q <= j ? 0 : 1) ^ k])
                                success = false;
                    if (success)
                        return true;
                }
        return false;
    }

    public static void main(String... args) {
        final Scanner sc = new Scanner(System.in);
        final int T = sc.nextInt();
        for (int c = 1; c <= T; c++) {
            final int R = sc.nextInt();
            final int C = sc.nextInt();
            final char[][] grid = new char[R][];
            for (int i = 0; i < R; i++)
                grid[i] = sc.next().toCharArray();
            System.out.printf("Case #%d: %s\n", c, solve(R, C, grid));
        }
    }
}
public class Solution {
    public static void main(String... args) {
        GridceptionSmall.main();
    }
}