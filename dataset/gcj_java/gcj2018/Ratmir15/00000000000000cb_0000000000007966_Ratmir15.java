
import java.io.FileNotFoundException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Solution {

    public static final String IMPOSSIBLE = "IMPOSSIBLE";

    public static String simplify(String s) {
        int lastIndex = s.length() - 1;
        while (lastIndex > 0 && s.charAt(lastIndex) == 'C') {
            lastIndex--;
        }
        s = s.substring(0, lastIndex + 1);
        return s;
    }

    public static double calculate(String s) {
        double res = 0;
        double cur = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'C') {
                cur *= 2;
            } else {
                res += cur;
            }
        }
        return res;
    }


    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);
        OutputStream outputStream = System.out;
        PrintWriter printWriter = new PrintWriter(outputStream);
        int tn = sc.nextInt();
        sc.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            String s = sc.nextLine();
            String[] vars = s.split(" ");
            int power = Integer.valueOf(vars[0]);
            String line = simplify(vars[1]);
            double pw = calculate(line);
            double prev = pw + 1;
            int removed = 0;
            while (pw < prev && pw > power) {
                prev = pw;
                int c = line.lastIndexOf('C');
                if (c == -1) {
                    continue;
                }
                line = simplify(line.substring(0, c) + "SC" + line.substring(c + 2));
                pw = calculate(line);
                removed++;
            }
            String rr = "";
            if (pw > power) {
                rr = IMPOSSIBLE;
            } else {
                rr = String.valueOf(removed);
            }
            String res = "Case #" + ti + ": " + rr;
            printWriter.write(res + "\n");
        }
        printWriter.close();
    }

}
