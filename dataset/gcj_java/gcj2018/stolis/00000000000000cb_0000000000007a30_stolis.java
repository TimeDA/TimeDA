import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int area = in.nextInt();
            boolean[][] A = new boolean[(area + 2) / 3][3];
            int pos = 1;
            boolean done = false;
            while (pos < A.length - 1) {
                System.out.printf("%d %d\n", pos+1, 2);
                System.out.flush();
                int x = in.nextInt();
                int y = in.nextInt();
                if (x == 0 && y == 0) {
                    done = true;
                    break;
                }
                x--;
                y--;
                A[x][y] = true;
                while (pos < A.length - 1 && A[pos - 1][0] && A[pos - 1][1] && A[pos - 1][2]) {
                    pos++;
                }
            }
            pos--;
            while (!done && !(A[pos][0] && A[pos][1] && A[pos][2] && A[pos + 1][0] && A[pos + 1][1] && A[pos + 1][2])) {
                System.out.printf("%d %d\n", pos+1, 2);
                System.out.flush();
                int x = in.nextInt();
                int y = in.nextInt();
                if (x == 0 && y == 0) {
                    done = true;
                    break;
                }
                x--;
                y--;
                A[x][y] = true;
            }
        }
    }

}
