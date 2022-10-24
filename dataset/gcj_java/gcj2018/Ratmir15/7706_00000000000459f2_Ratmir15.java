
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Solution {

    public static final String IMPOSSIBLE = "IMPOSSIBLE";

    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        OutputStream outputStream = System.out;
        PrintWriter printWriter = new PrintWriter(outputStream);
        int tn = sc.nextInt();
        sc.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int c = sc.nextInt();
            int[] vars = new int[c];
            int sm = 0;
            for (int i = 0; i < c; i++) {
                vars[i] = sc.nextInt();
                sm += vars[i];
            }
            String res = "";
            int[] fromLefts = new int[c];
            int[] fromRights = new int[c];
            int[] starts = new int[c];
            if (vars[0] == 0 || vars[c - 1] == 0 || sm != c) {
                res = IMPOSSIBLE;
            } else {
                int rows = 1;
                int nextAvailable = 0;
                int current = 0;
                while (current < c) {
                    if (vars[current] > 0) {
                        int fromLeft = Math.min(current - nextAvailable, vars[current]);
                        int fromRight = vars[current] - fromLeft;
                        if (fromLeft > 0) {
                            int x = current - nextAvailable + 1;
                            if (x > rows) {
                                rows = x;
                            }
                        }
                        if (fromRight > 0) {
                            int x = nextAvailable + vars[current] - current;
                            if (x > rows) {
                                rows = x;
                            }
                        }
                        fromLefts[current] = fromLeft;
                        fromRights[current] = fromRight;
                        starts[current] = nextAvailable + vars[current] - 1;
                    }
                    nextAvailable += vars[current];
                    current++;
                }
                res = String.valueOf(rows);
//                System.out.println(Arrays.toString(fromLefts));
//                System.out.println(Arrays.toString(fromRights));
//                System.out.println(Arrays.toString(starts));
                int[][] table = new int[rows][c];
                for (int i = 0; i < c; i++) {
                    for (int j = 0; j < fromLefts[i]; j++) {
                        table[j][i - fromLefts[i] + j] = 1;
                    }
                    for (int j = 0; j < fromRights[i] - 1; j++) {
                        table[j][starts[i] - j] = 2;
                    }
                }
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < rows; i++) {
                    sb.append("\n");
                    for (int j = 0; j < c; j++) {
                        char ch = '.';
                        if (table[i][j] == 1) {
                            ch = '\\';
                        }
                        if (table[i][j] == 2) {
                            ch = '/';
                        }
                        sb.append(ch);
                    }
                }
                res = res + sb;
            }
            String res1 = "Case #" + ti + ": " + res;
            printWriter.write(res1 + "\n");
        }
        printWriter.flush();
        printWriter.close();
    }

}
