import java.util.Random;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Solution problem = new Solution();
        problem.solve(scan);
    }

    private Random rnd;
    private Scanner scan;

    Solution() {
        rnd = new Random(1);
    }
    public void setSeed(int seed ) {
        rnd.setSeed(seed);
    }
    public void solve(Scanner scan) {
        this.scan = scan;
        rnd = new Random(1);
        int nrTests = scan.nextInt();
        for (int test = 0; test < nrTests; test++) {
            solve(scan.nextInt());
        }

    }
    final static boolean LOCAL = false;

    public int solve(int A) {
//        System.err.println("solve for A = " + A);
        // A = 20 or 200
        int height = 5;
        int width = A/height;
        int[][] map = new int[height+1][width+1];
        for ( int r = 1; r <= height; r++ ) {
            for (int c = 1; c <= width; c++) {
                boolean borderH = r == 1 || r == height;
                boolean borderW = c == 1 || c == width;
                if (borderH && borderW) map[r][c] = 1; // 100
                else if (borderH || borderW) map[r][c] = 1; // 25;
                else map[r][c] = 1;
            }
        }
        int count = 0;
        while ( count < 1000 ) {
            int bestR = 0, bestC = 0, bestScore = 0;
            for ( int r = 2; r < height; r++) {
                for (int c = 2; c < width; c++) {
                    int s = score(map, r, c);
                    if ( s > bestScore ) {
                        bestScore = s;
                        bestR = r;
                        bestC = c;
                    }
                }
            }
            if ( bestScore == 0 ) break;
            count++;
            int r, c;
            if ( LOCAL ) {
                r = bestR + rnd.nextInt(3) - 1;
                c = bestC + rnd.nextInt(3) - 1;
            } else {
//                System.err.println(bestR + " " + bestC);
                System.out.println(bestR + " " + bestC);
                System.out.flush();
                r = scan.nextInt();
                c = scan.nextInt();
                if ( r == 0 && c == 0 ) return count;
                if ( r == -1 && c == -1 ) return -1;
            }

            map[r][c] = 0;

        }
//        System.out.println("number of iterations " + count);
        return count;

    }

    int score(int[][] map, int row, int col) {
        int result = 0;
        for ( int r = row - 1; r <= row + 1; r++)
            for ( int c = col - 1; c <= col + 1; c++) result += map[r][c];
        return result;
    }

}
