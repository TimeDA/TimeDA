import java.util.ArrayList;
import java.util.Collections;
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
            int[] x = new int[n];
            for ( int i = 0; i < n; i++ ) x[i] = scan.nextInt();
            // read input from scanner
            int result = solve(x);

            String resultStr = String.format("Case #%d: %s", test + 1, result < 0 ? "OK" : result);
            System.out.println(resultStr);
        }

    }

    public int solve(int[] x ) {
        ArrayList<Integer> odd = new ArrayList<Integer>();
        ArrayList<Integer> even = new ArrayList<Integer>();
        for ( int i = 0; i < x.length; i++) {
            if ( i % 2 == 0 ) even.add(x[i]);
            else odd.add(x[i]);
        }
        Collections.sort(odd);
        Collections.sort(even);
        int k = 0;
        for ( int z: even ) { x[k] = z; k += 2; }
        k = 1;
        for ( int z: odd ) { x[k] = z; k += 2; }
        for ( int i = 0; i < x.length - 1; i++ )  {
            if ( x[i] > x[i+1]) return i;
        }
        return -1;
    }
}
