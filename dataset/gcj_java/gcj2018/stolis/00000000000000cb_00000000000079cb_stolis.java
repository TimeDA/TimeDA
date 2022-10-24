import java.util.Arrays;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t=1; t<=T; t++) {
            int N = in.nextInt();
            long[] odd = new long[N/2];
            long[] even = new long[(N+1)/2];
            for (int n=0; n<N; n++) {
                long value = in.nextLong();
                if (n%2 == 0) {
                    even[n/2] = value;
                } else {
                    odd[n/2] = value;
                }
            }
            Arrays.sort(odd);
            Arrays.sort(even);
            int firstBug = -1;
            for (int n=0; n<N-1; n++) {
                if (n%2 == 0) {
                    if (even[n/2] > odd[(n+1)/2]) {
                        firstBug = n;
                        break;
                    }
                } else {
                    if (odd[n/2] > even[(n+1)/2]) {
                        firstBug = n;
                        break;
                    }
                }
            }
            String answer = (firstBug == -1) ? "OK" : Integer.toString(firstBug);
            System.out.printf("Case #%d: %s\n", t, answer);
        }
    }

}
