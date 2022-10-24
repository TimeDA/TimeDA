import java.util.ArrayList;
import java.util.Arrays;
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
            int[] count = new int[n];
            for ( int i = 0; i < n; i++) count[i] = scan.nextInt();
            // read input from scanner
            ArrayList<String> result = solve(count);
            String resultStr = String.format("Case #%d: ", test + 1);
            if ( result.size() == 0 ) resultStr += "IMPOSSIBLE\n";
            else {
                resultStr += result.size() + "\n";
                for ( int i = result.size() - 1; i >= 0; i--) resultStr += result.get(i) +"\n";
            }
            System.out.print(resultStr);
        }

    }

    public ArrayList<String> solve(int[] count) {
        int n = count.length;
        ArrayList<String> result = new ArrayList<>();
        if ( count[0] == 0 || count[n-1] == 0) return result;


        ArrayList<Thing> things = new ArrayList<>();
        int start = 0;
        for ( int c = 0; c < n; c++ ) {
            if ( count[c] == 0 ) continue;
            int last = start + count[c] - 1;
            things.add(new Thing(c, start, last));
            start = last + 1;
        }
        boolean changed = true;
        while ( changed ) {
            char[] next = new char[n];
            changed = false;
            Arrays.fill(next, '.');
            for ( Thing t: things) {
                if ( t.first < t.target) {
                    next[t.first] = '\\';
                    t.first++;
                    changed = true;
                }
                if ( t.last > t.target ) {
                    next[t.last] = '/';
                    t.last--;
                    changed = true;
                }
            }
            result.add(new String(next));
        }
        char[] row = new char[n];
        for(int i = 0; i < n; i++) row[i] = '.';
        result.add(new String(row));
        Collections.reverse(result);
        return result;
    }


    class Thing {
        int target;
        int first, last;
        Thing(int i, int f, int l) {
            target = i;
            first = f;
            last = l;
        }

    }
}
