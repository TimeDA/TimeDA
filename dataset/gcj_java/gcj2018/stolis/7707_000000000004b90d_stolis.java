import java.util.Scanner;

public class Solution {

    static int N;
    static int[] X;
    static int[] Y;
    static int[] Z;
    static boolean[] used;
    static int[] S;

    static boolean solve(int next) {
        if (next == N) {
            return true;
        }
        for (int n = 0; n < N; n++) {
            if (!used[n]) {
                used[n] = true;
                S[next] = n;
                boolean ok = true;
                if (next >= 2) {
                    double expected = Math.signum(plane(S[next - 2], S[next - 1], S[next], X[S[next]], Y[S[next]], 0));
                    for (int nn = 0; nn < N; nn++) {
                        if (!used[nn]) {
                            double actual = Math.signum(plane(S[next - 2], S[next - 1], S[next], X[nn], Y[nn], Z[nn]));
                            if (expected != actual) {
                                ok = false;
                                break;
                            }
                        }
                    }
                }
                if (ok) {
                    boolean result = solve(next + 1);
                    if (result) {
                        return true;
                    }
                }
                used[n] = false;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            N = in.nextInt();
            X = new int[N];
            Y = new int[N];
            Z = new int[N];
            for (int n = 0; n < N; n++) {
                X[n] = in.nextInt();
                Y[n] = in.nextInt();
                Z[n] = in.nextInt();
            }
            used = new boolean[N];
            S = new int[N];
            boolean result = solve(0);
            if (!result) {
                System.out.println("Bug - solution not found!");
            }
            StringBuilder answer = new StringBuilder();
            for (int n = N - 1; n >= 0; n--) {
                answer.append(S[n] + 1).append(' ');
            }
            System.out.printf("Case #%d: %s\n", t, answer);
        }
    }

    static long plane(int i, int j, int k, int x, int y, int z) {
        long x1 = X[i];
        long y1 = Y[i];
        long z1 = Z[i];
        long x2 = X[j];
        long y2 = Y[j];
        long z2 = Z[j];
        long x3 = X[k];
        long y3 = Y[k];
        long z3 = Z[k];
        long d11 = x - x1;
        long d12 = y - y1;
        long d13 = z - z1;
        long d21 = x2 - x1;
        long d22 = y2 - y1;
        long d23 = z2 - z1;
        long d31 = x3 - x1;
        long d32 = y3 - y1;
        long d33 = z3 - z1;
        long result = d11 * d22 * d33 + d12 * d23 * d31 + d21 * d32 * d13
                - d13 * d22 * d31 - d21 * d33 * d12 - d11 * d23 * d32;
        return result;
    }

}
