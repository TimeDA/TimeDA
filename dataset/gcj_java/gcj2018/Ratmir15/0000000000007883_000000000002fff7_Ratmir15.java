

import java.io.FileNotFoundException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);
        OutputStream outputStream = System.out;
        PrintWriter printWriter = new PrintWriter(outputStream);
        int tn = sc.nextInt();
        sc.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int n = sc.nextInt();
            int p = sc.nextInt();
            int [] w = new int[n];
            int [] h = new int[n];
            for (int i=0;i<n;i++) {
                w[i] = sc.nextInt();
                h[i] = sc.nextInt();
            }
            long current = 2*(w[0]+h[0])*n;
            double maxDif = 2*Math.sqrt(w[0]*w[0]+h[0]*h[0]);
            double res = 0;
            for (int toCut=0;toCut<=n;toCut++) {
                double mn = current + toCut * 2*Math.min(w[0],h[0]);
                double mx = current + toCut * maxDif;
                if (mn<=p &&mx>=p) {
                    res = p;
                } else {
                    if (mn<=p && mx>=res) {
                        res = mx;
                    }
                }
            }
            String reslt = "Case #" + ti + ": " + res;
            printWriter.write(reslt + "\n");
        }
        printWriter.close();
    }


}
