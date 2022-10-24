import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        int max = 500;
        int maxSingle = 0;
        int sum = maxSingle;
        do {
            maxSingle++;
            sum += maxSingle;
        } while (sum <= max);
        maxSingle--;
        int[][] best = new int[max+1][max+1];
        for (int r = 0; r <= maxSingle; r++) {
            for (int b = 0; b <= maxSingle; b++) {
                int[][] newBest = new int[max+1][max+1];
                for (int rr = 0; rr <= max; rr++) {
                    for (int bb = 0; bb <= max; bb++) {
                        if (rr >= r && bb >= b) {
                            newBest[rr][bb] = Math.max(best[rr][bb], best[rr-r][bb-b] + 1);
                        } else {
                            newBest[rr][bb] = best[rr][bb];
                        }
                    }
                }
                best = newBest;
            }
        }
        /*for (int r = 0; r <= max; r++) {
            for (int c = 0; c <= max; c++) {
                if (best[r][c] != best[c][r]) {
                    System.out.println("BUG");
                }
            }
        }*/
        
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int R = in.nextInt();
            int B = in.nextInt();
            System.out.printf("Case #%d: %d\n", t, best[R][B] - 1);
        }
    }

}
