
import java.io.FileNotFoundException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Solution {

    public static final String POSSIBLE = "POSSIBLE";
    public static final String IMPOSSIBLE = "IMPOSSIBLE";

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);
        OutputStream outputStream = System.out;
        PrintWriter printWriter = new PrintWriter(outputStream);
        int tn = sc.nextInt();
        sc.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int r = sc.nextInt();
            int c = sc.nextInt();
            int h = sc.nextInt();
            int v = sc.nextInt();
            sc.nextLine();
            String [] f = new String[r];
            for (int i=0;i<r;i++) {
                f[i] = sc.nextLine();
            }
            String rr = IMPOSSIBLE;
            for (int i=0;i<r-1;i++) {
                for (int j=0;j<c-1;j++) {
                    int [] rs = new int[4];
                    for (int i1=0;i1<r;i1++) {
                        for (int j1 = 0; j1 < c; j1++) {
                            if (f[i1].charAt(j1)=='@') {
                                if (i1<=i) {
                                    if (j1<=j) {
                                        rs[0]++;
                                    } else {
                                        rs[1]++;
                                    }
                                } else {
                                    if (j1<=j) {
                                        rs[2]++;
                                    } else {
                                        rs[3]++;
                                    }
                                }
                            }
                        }
                    }
                    if (rs[0]==rs[1] && rs[0]==rs[2] && rs[0]==rs[3]) {
                        rr = POSSIBLE;
                    }
                }
            }
            String res = "Case #" + ti + ": " + rr;
            printWriter.write(res + "\n");
        }
        printWriter.close();
    }

}
