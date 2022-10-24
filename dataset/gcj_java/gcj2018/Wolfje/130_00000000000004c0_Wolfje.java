import java.util.PriorityQueue;
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
    public void solve() {
        int nrTests = in.nextInt();
        for (int test = 0; test < nrTests; test++) {
            int n = in.nextInt();
            PriorityQueue<Party> list = new PriorityQueue<>();
            for (int i = 0; i < n; i++) {
                list.add(new Party(in.nextInt(), (char)('A' + i)));
            }
            int sum = 0;
            for ( Party p: list) sum += p.amount;
            StringBuilder sb = new StringBuilder();
            while ( list.size() > 0 ) {
                Party p = list.poll();
                sb.append(' ');
                sb.append(p.label);
                p.amount--;
                if ( list.size() == 1 && list.peek().amount > p.amount) {
                    Party q = list.poll();
                    sb.append(q.label);
                    q.amount--;
                    if ( q.amount > 0 ) list.add(q);
                }
                if ( p.amount > 0 ) list.add(p);
            }
            String resultStr = String.format("Case #%d:", test + 1);
            resultStr += sb.toString();
            System.out.println(resultStr);
        }
    }

    class Party implements Comparable<Party> {
        int amount;
        char label;
        Party(int amount, char label) {
            this.amount = amount;
            this.label = label;
        }

        @Override
        public int compareTo(Party o) {
            return o.amount - amount;
        }
    }

}
