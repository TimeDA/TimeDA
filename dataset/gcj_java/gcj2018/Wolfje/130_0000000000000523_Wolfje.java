import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Solution problem = new Solution(scan);
        problem.solve();
    }

    Scanner in;
    public Solution(Scanner in) {
        this.in = in;
    }
    private void solve() {
        int nrTests = in.nextInt();
        for (int test = 0; test < nrTests; test++) {
            long a = in.nextInt();
            long b = in.nextInt();
            int n = in.nextInt();
            int count = 0;
            boolean done = false;
            while ( !done && count < n) {
                count++;
                long mid = (a + b + 1)/2;
                System.out.println(mid);
                System.err.println("mid " + mid);
                System.out.flush();
                String s = in.next();
                if ( s.equals("TOO_SMALL") ) a = mid;
                else if ( s.equals("TOO_BIG") ) b = mid;
                else if ( s.equals("WRONG_ANSWER") ) return;
                else { done = true; }
            }
        }

    }



}
