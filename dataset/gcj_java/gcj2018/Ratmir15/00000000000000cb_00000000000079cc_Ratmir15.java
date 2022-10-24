import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Solution {

    public static double sq(double v) {
        return Math.cos(v) + Math.sin(v);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        OutputStream outputStream = System.out;
        PrintWriter printWriter = new PrintWriter(outputStream);
        int tn = sc.nextInt();
        for (int ti = 1; ti <= tn; ti++) {
            double a = sc.nextDouble();
            double min = 0;
            double max = Math.PI / 4;
            double mnv = sq(min);
            double mxv = sq(max);
            while (Math.abs(mxv - a) > 0.00000000001d || Math.abs(mnv - a) > 0.00000000001d) {
                double cur = min + ((max - min) / 2);
                double curv = sq(cur);
                if (curv > a) {
                    max = cur;
                    mxv = curv;
                } else {
                    min = cur;
                    mnv = curv;
                }
            }
            String res = "Case #" + ti + ":";
            printWriter.write(res + "\n");
            printWriter.print(0.5 * Math.cos(min) + " " + 0.5 * Math.sin(min) + " 0\n");
            printWriter.print(0.5 * Math.cos(min + Math.PI / 2) + " " + 0.5 * Math.sin(min + Math.PI / 2) + " 0\n");
            printWriter.print("0 0 0.5\n");
        }
        printWriter.close();
    }

}
