import java.io.FileNotFoundException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Solution {

    public static final String IMPOSSIBLE = "IMPOSSIBLE";

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);
        OutputStream outputStream = System.out;
        PrintWriter printWriter = new PrintWriter(outputStream);
        int tn = sc.nextInt();
        sc.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int r = sc.nextInt();
            int b = sc.nextInt();
            int m = Math.max(r,b);
            int[][] used = new int[r + b + 1][r + b +1];
            int rr = r;
            int rb = b;
            int cs = 1;
            int amount = 0;
            main:
            while (rr + rb > 0) {
                amount++;
                int rem = rr + rb;
                if (rr >= rb) {
                    m1:
                    while (true) {
                        for (int i = cs; i >= 0; i--) {
                            if (used[cs][i] == 0) {
                                if (rr >= i && rb >= cs - i) {
                                    used[cs][i] = 1;
                                    rr -= i;
                                    rb -= cs - i;
                                    //System.out.println(i+" "+(cs-i) +" "+rr+" "+rb);

                                    break m1;
                                }
                            }
                        }
                        cs++;
                        if (cs>=r + b + 1) {
                            break main;
                        }
                    }
                } else {
                    m1:
                    while (true) {
                        for (int i = 0; i <= cs; i++) {
                            if (used[cs][i] == 0) {
                                if (rr >= i && rb >= cs - i) {
                                    used[cs][i] = 1;
                                    rr -= i;
                                    rb -= cs - i;
                                    //System.out.println(i+" "+(cs-i) +" "+rr+" "+rb);
                                    break m1;
                                }
                            }
                        }
                        cs++;
                        if (cs>=r + b + 1) {
                            break main;
                        }
                    }
                }
            }
            if (rr+rb>0) {
                amount--;
            }
            String res = "Case #" + ti + ": " + amount;
            printWriter.write(res + "\n");
        }
        printWriter.close();
    }

}
