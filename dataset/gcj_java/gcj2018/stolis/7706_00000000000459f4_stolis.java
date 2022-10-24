import java.util.Scanner;

public class Solution {

    static int R;
    static int C;
    static boolean[][] grid;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            R = in.nextInt();
            C = in.nextInt();
            grid = new boolean[R][C];
            for (int r = 0; r < R; r++) {
                String s = in.next();
                for (int c = 0; c < C; c++) {
                    boolean value = (s.charAt(c) == 'B');
                    grid[r][c] = value;
                }
            }
            int max = 0;
            for (int bw = 0; bw < 2; bw++) {
                for (int raxis = 0; raxis <= R; raxis++) {
                    for (int caxis = 0; caxis <= C; caxis++) {
                        for (int startr = 0; startr < R; startr++) {
                            for (int startc = 0; startc < C; startc++) {
                                boolean[][] used = new boolean[R][C];
                                fill(used, startr, startc, raxis, caxis, bw == 0);
                                int size = 0;
                                for (int r = 0; r < R; r++) {
                                    for (int c = 0; c < C; c++) {
                                        if (used[r][c]) {
                                            size++;
                                        }
                                    }
                                }
                                max = Math.max(max, size);
                            }
                        }
                    }
                }
            }
            System.out.printf("Case #%d: %d\n", t, max);
        }
    }

    private static void fill(boolean[][] used, int r, int c, int raxis, int caxis, boolean bw) {
        boolean expected = (r < raxis) ^ (c < caxis) ^ bw;
        if (!used[r][c] && grid[r][c] == expected) {
            used[r][c] = true;
            if (r > 0) {
                fill(used, r - 1, c, raxis, caxis, bw);
            }
            if (r < R - 1) {
                fill(used, r + 1, c, raxis, caxis, bw);
            }
            if (c < C - 1) {
                fill(used, r, c + 1, raxis, caxis, bw);
            }
            if (c > 0) {
                fill(used, r, c - 1, raxis, caxis, bw);
            }
        }
    }

}
