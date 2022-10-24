import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            int minx = Integer.MAX_VALUE;
            int maxx = Integer.MIN_VALUE;
            int miny = Integer.MAX_VALUE;
            int maxy = Integer.MIN_VALUE;
            for (int n=0; n<N; n++) {
                int x = in.nextInt();
                int y = in.nextInt();
                minx = Math.min(minx, x);
                maxx = Math.max(maxx, x);
                miny = Math.min(miny, y);
                maxy = Math.max(maxy, y);
            }
            int X = (maxx-minx+1)/2;
            int Y = (maxy-miny+1)/2;
            int answer = Math.max(X,Y);
            System.out.printf("Case #%d: %s\n", t, answer);
        }
    }

}
