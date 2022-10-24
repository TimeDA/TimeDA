import java.awt.Point;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int S = in.nextInt();
            int[] D = new int[S];
            int[] A = new int[S];
            int[] B = new int[S];
            for (int s = 0; s < S; s++) {
                D[s] = in.nextInt();
                A[s] = in.nextInt();
                B[s] = in.nextInt();
            }
            int[] Ms = new int[S];
            int[] Ns = new int[S];
            for (int s = 0; s < S; s++) {
                Ms[s] = D[s] + A[s];
                Ns[s] = D[s] - B[s];
            }

            int max = 0;
            Set<Point> set = new HashSet<Point>();

            for (int start = 0; start < S; start++) {
                for (int end = S-1; end >= start; end--) {
                    if (end - start + 1 < max) continue;
                    for (int N : Ns) {
                        for (int M : Ms) {
                            boolean ok = true;
                            for (int i = start; i <= end; i++) {
                                int thisM = D[i] + A[i];
                                int thisN = D[i] - B[i];
                                if (thisM != M && thisN != N) {
                                    ok = false;
                                    break;
                                }
                            }
                            if (ok) {
                                int length = end - start + 1;
                                if (length > max) {
                                    max = length;
                                    set.clear();
                                    set.add(new Point(start, end));
                                    break;
                                } else if (length == max) {
                                    set.add(new Point(start, end));
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            System.out.printf("Case #%d: %d %d\n", t, max, set.size());
        }
    }

}
