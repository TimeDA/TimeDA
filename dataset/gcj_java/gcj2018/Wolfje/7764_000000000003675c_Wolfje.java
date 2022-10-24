import java.util.HashMap;
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
            // read input from scanner
            int metals = scan.nextInt();
            int[] a = new int[metals];
            int[] b = new int[metals];
            for ( int i = 0; i < metals; i++ ) {
                a[i] = scan.nextInt() - 1;
                b[i] = scan.nextInt() - 1;
            }
            int[] g = new int[metals];
            for ( int i = 0; i < metals; i++) g[i] = scan.nextInt();
            memo = new HashMap<int[], Integer>();
            int result = solve(g, a, b);

            String resultStr = String.format("Case #%d: %d", test + 1, result);
            System.out.println(resultStr);
        }

    }

    HashMap<int[], Integer> memo;
    public int solve(int[] g, int[] a, int[] b) {
        if ( memo.containsKey(g)) return memo.get(g);
        int result = g[0];
        for ( int i = 0; i < a.length; i++) {
            if ( g[a[i]] > 0 && g[b[i]] > 0) {
                g[i]++;
                g[a[i]]--;
                g[b[i]]--;
                result = Math.max(result, solve(g, a, b));
                g[b[i]]++;
                g[a[i]]++;
                g[i]--;
            }
        }
        memo.put(g, result);
        return result;
    }


}
