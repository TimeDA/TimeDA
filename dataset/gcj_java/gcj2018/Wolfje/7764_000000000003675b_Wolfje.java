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
            int[] d = new int[n];
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; i++) {
                d[i] = scan.nextInt();
                a[i] = scan.nextInt();
                b[i] = scan.nextInt();
            }
            // read input from scanner
            int[] res = solve(d, a, b);

            String resultStr = String.format("Case #%d: %d %d", test + 1, res[0], res[1]);
            System.out.println(resultStr);
        }

    }

    public int[] solve(int[] d, int[] a, int[] b) {
        int n = d.length;
        int[] east = new int[n];
        int[] west = new int[n];

        for (int i = 0; i < n; i++) {
            west[i] = d[i] + a[i];
            east[i] = d[i] - b[i];
        }
        int longest = 0;
        int count = 0;
        for ( int i = 0; i < n; i++ ) {
            int k = go(i, UNKNOWN, UNKNOWN, west, east);
            int l = i - k + 1;
            if ( l > longest) {
                longest = l;
                count = 1;
            } else if ( l == longest ) {
                count++;
            }
        }
        return new int[]{longest, count};
    }

    int UNKNOWN = 1_000_000_000;
    int go(int k, int w, int e, int[] west, int[] east) {
        if ( k < 0 ) return 0;
        if ( west[k] == w || east[k] == e) return go(k-1, w, e, west, east);
        int result = k + 1;
        if ( w == UNKNOWN ) result = go(k-1, west[k], e, west, east);
        if ( e == UNKNOWN ) result = Math.min(result, go(k-1, w, east[k], west, east));
        return result;
    }



}
