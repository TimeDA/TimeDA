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
            int r = scan.nextInt();
            int b = scan.nextInt();
            int result = solve(r, b);

            String resultStr = String.format("Case #%d: %d", test + 1, result);
            System.out.println(resultStr);
        }

    }

    public int solve(int r, int b) {

        memo = new HashMap<>();
        return go(r, b, 0) - 1;
    }

    HashMap<Long, Integer> memo;
    private int go(int r, int b, int k) {
        long id = 1_000_000*r + 1_000*b + k;
        if ( !memo.containsKey(id)) {
            int best = 0;
            int i = 1;
            int pickRed = 0;
            int pickBlue = k;
            while ( pickRed <= r && pickBlue <= b) {
                int z = i + go(r-pickRed, b - pickBlue, k+1);
                best = Math.max(best, z);
                i++;
                pickBlue += k;
                pickRed += i - 1;

            }
            memo.put(id, best);
        }
        return memo.get(id);
    }

}
