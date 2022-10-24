
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        OutputStream outputStream = System.out;
        PrintWriter printWriter = new PrintWriter(outputStream);
        int tn = sc.nextInt();
        main:
        for (int ti = 1; ti <= tn; ti++) {
            int a = sc.nextInt();
            boolean[][] arr = new boolean[1000][5];
            int n = ((a - 1) / 3) + 1;
            int y = 2;
            int x = 2;
            while (true) {
                printWriter.write(x + " " + y + "\n");
                printWriter.flush();
                int is = sc.nextInt();
                int js = sc.nextInt();
                if (is == -1 && js == -1) {
                    break main;
                }
                if (is == 0 && js == 0) {
                    continue main;
                }
                arr[is][js] = true;
                if (arr[x - 1][y - 1] && arr[x - 1][y] && arr[x - 1][y + 1] && x < n - 1) {
                    x++;
                }
            }
        }
        printWriter.close();
    }

}
