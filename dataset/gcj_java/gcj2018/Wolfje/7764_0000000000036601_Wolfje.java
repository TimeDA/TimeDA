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
            int l = scan.nextInt();
            int[] c = new int[l];
            for (int i = 0; i < l; i++) {
                c[i] = scan.nextInt();
            }
            // read input from scanner
            int result = solve(n, c);

            String resultStr = String.format("Case #%d: %d", test + 1, result);
            System.out.println(resultStr);
        }

    }

    public int solve(int n, int[] c) {
        int result = 0;
        ArrayList<Remainder> remainders = new ArrayList<>();
        int total = 0;
        for (int i = 0; i < c.length; i++) {
            result += (c[i]*100)/n;
            int rem = (c[i]*100) % n;
            if ( 2*rem >= n ) result++;
            else {
                int votes = minVotes(n, rem, n);
                remainders.add(new Remainder(rem, votes));
            }
            total += c[i];
        }
        int zzz = minVotes(n, 0, n);
        for ( int i = 0; i < n; i++ ) {
            remainders.add(new Remainder(0, zzz));
        }
        int pick = n - total;
        Collections.sort(remainders);
        for ( Remainder r: remainders ) {
            int votes = Math.min(pick, r.votes);
            result += percentage(n, votes, r.rem);
            pick -= votes;
        }
        return result;
    }

    int minVotes(int n, int rem, int maxVotes) {
        int votes = 0;
        int z = rem;
        while ( 2*z < n && votes < maxVotes) {
            votes++;
            z = (100*votes + rem) % n;
        }
        return votes;
    }

    int percentage(int n, int x, int rem) {
        int z = 100*x + rem;
        int result = z/n;
        z %= n;
        if ( 2*z >= n ) result++;
        return result;
    }

    class Remainder implements Comparable<Remainder> {
        int rem, votes;
        Remainder(int r, int v) {
            rem = r;
            votes = v;
        }

        @Override
        public int compareTo(Remainder o) {
            return votes - o.votes;
        }

        public String toString() { return String.format("rem %d need votes %d", rem, votes); }
    }
}
