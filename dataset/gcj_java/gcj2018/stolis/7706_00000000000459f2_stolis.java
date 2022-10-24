import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int C = in.nextInt();
            int[] B = new int[C];
            for (int c=0; c<C; c++) {
                B[c] = in.nextInt();
            }
            if (B[0] == 0 || B[C-1] == 0) {
                System.out.printf("Case #%d: %s\n", t, "IMPOSSIBLE");
                continue;
            }
            int depth = 0;
            int lastUsed = -1;
            for (int c=0; c<C; c++) {
                for (int b=0; b<B[c]; b++) {
                    lastUsed++;
                    depth = Math.max(depth, Math.abs(lastUsed - c));
                }
            }
            char[][] grid = new char[depth+1][C];
            for (int c = 0; c<C; c++) {
                for (int r = 0; r <= depth; r++) {
                    grid[r][c] = '.';
                }
            }
            lastUsed = -1;
            for (int c=0; c<C; c++) {
                for (int b=0; b<B[c]; b++) {
                    lastUsed++;
                    int cc = lastUsed;
                    int rr = 0;
                    while (cc != c) {
                        if (cc < c) {
                            grid[rr][cc] = '\\';
                            cc++;
                        } else {
                            grid[rr][cc] = '/';
                            cc--;
                        }
                        rr++;
                    }
                }
            }

            System.out.printf("Case #%d: %d\n", t, depth+1);
            for (int r = 0; r <= depth; r++) {
                System.out.println(new String(grid[r]));
            }
        }
    }

}
