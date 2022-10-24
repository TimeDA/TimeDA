import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            int[][] A = new int[N][N];
            for (int r=0; r<N; r++) {
                for (int c=0; c<N; c++) {
                    A[r][c] = in.nextInt();
                }
            }
            int[][] B = new int[N][N];
            int min = N*N;
            int limit = 1 << (N*N);
            for (int mask = 0; mask < limit; mask++) {
                for (int r=0; r<N; r++) {
                    for (int c=0; c<N; c++) {
                        int bit = r*N + c;
                        boolean set = (mask & (1 << bit)) != 0;
                        B[r][c] = set ? 0 : A[r][c];
                    }
                }
                boolean ok = true;
                main: for (int r=0; r<N; r++) {
                    for (int c=0; c<N; c++) {
                        for (int rr=0; rr<N; rr++) {
                            for (int cc=0; cc<N; cc++) {
                                if (((r != rr && c == cc) || (c != cc && r == rr)) && B[r][c] != 0 && B[rr][cc] != 0 && B[r][c] == B[rr][cc]) {
                                    ok = false;
                                    break main;
                                }
                            }
                        }
                    }
                }
                if (ok) {
                    min = Math.min(min, Integer.bitCount(mask));
                }
            }

            System.out.printf("Case #%d: %d\n", t, min);
        }
    }

}
