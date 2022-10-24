package round2;
 
 import java.io.File;
 import java.io.IOException;
 import java.io.PrintWriter;
 import java.math.BigInteger;
 import java.util.Scanner;
 
 public class ManyPrizes {
     static int T;
     static int N;
     static long P;
     static long[] max;
     static long[] min;
 
     public static void main(String[] args) throws IOException {
         read();
         write();
     }
 
     static void read() throws IOException {
         File input = new File("input.txt");
         Scanner scanner = new Scanner(input);
         T = scanner.nextInt();
         max = new long[T];
         min = new long[T];
         for (int t=0; t<T; t++) {
             N = scanner.nextInt();
             P = scanner.nextLong();
             process(t);
         }
     }
 
     static void process(int t) {
         long total = 1 << N;
         long xx = 1;
         long x = 1;
         while (P+xx <= total) {
             xx *= 2;
             x++;
         }
         min[t] = total-1;
         if (x != 1) {
             x = N-x+1;
             min[t] = (2 << x) - 2;
         }
         
         long y = 0;
         long yy = total;
         while (yy > P) {
             yy /= 2;
             y++;
         }
         max[t] = total - (1 << y);
     }
 
     static void write() throws IOException {
         File output = new File("output.txt");
         PrintWriter pw = new PrintWriter(output);
 
         for (int t=0; t<T; t++) {
             pw.println("Case #"+(t+1)+": " + min[t] + " " + max[t]);
         }
 
         pw.close();
     }
 
 }
