import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Solution problem = new Solution();
        problem.solve(scan);
    }


    public void solve(Scanner scan) {
        int nrTests = scan.nextInt();
        for (int test = 0; test < nrTests; test++) {
            int n = scan.nextInt();
            int[][] grid = new int[n][n];
            for(int i = 0; i < n; i++)
                for ( int j = 0; j < n; j++) grid[i][j] = scan.nextInt();
            // read input from scanner
            int result = solve(grid);

            String resultStr = String.format("Case #%d: %d", test + 1, result);
            System.out.println(resultStr);
        }

    }

    public int solve(int[][] grid) {
        int n = grid.length;

        int best = 100;
        int[][] mat = new int[n][n];
        for ( int mask = 0; mask < (1<<(n*n)); mask++) {
            if ( Integer.bitCount(mask) >= best ) continue;
            for ( int r = 0; r < n; r++)
                for ( int c = 0; c < n; c++ ) {
                    if ( (mask & (1<<(n*r+c))) != 0 ) mat[r][c] = 0;
                    else mat[r][c] = grid[r][c];
                }
            if ( check(mat) ) best = Math.min(best, Integer.bitCount(mask));
        }

        return best;
    }
    public boolean check(int[][] grid) {
        int n = grid.length;
        for ( int r = 0; r < n; r++) {
            for ( int c = 0; c < n; c++) {
                if ( grid[r][c] == 0 ) continue;
                int same = 0;
                for ( int i = 0; i < n; i++ ) {
                    if ( grid[r][c] == grid[r][i]) same++;
                    if ( grid[r][c] == grid[i][c]) same++;
                }
                if ( same > 2 ) return false;
            }
        }
        return true;
    }
}
