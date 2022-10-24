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
            int result = solve(scan.nextLong(), scan.next());
            String resultStr = String.format("Case #%d: %s", test + 1, result < 0 ? "IMPOSSIBLE" : result);
            System.out.println(resultStr);
        }
    }

    public int solve(long d, String input) {
        char[] x = input.toCharArray();
        long current = damage(x);
        int count = 0;
        while ( current > d ) {
            int k = x.length - 1;
            while ( k > 0 && (x[k] != 'S' || x[k-1] != 'C')) k--;
            if ( k == 0 ) break;
            x[k - 1] = 'S';
            x[k] = 'C';
            count++;
            current = damage(x);
        }
        return current > d ? -1 : count;
    }

    public long damage(char[] x) {
        long result = 0;
        long strength = 1;
        for ( char c: x ) {
            if ( c == 'C') strength *= 2;
            else result += strength;
        }
        return result;
    }

}
