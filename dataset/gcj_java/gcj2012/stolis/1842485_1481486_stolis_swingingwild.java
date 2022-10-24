package round2;
 
 import round1.*;
 import java.io.File;
 import java.io.IOException;
 import java.io.PrintWriter;
 import java.util.Scanner;
 
 public class SwingingWild {
     static int T;
     static int N;
     static int[] d;
     static int[] l;
     static int D;
     static int[] swing;
     static boolean[] result;
 
     public static void main(String[] args) throws IOException {
         read();
         write();
     }
 
     static void read() throws IOException {
         File input = new File("input.txt");
         Scanner scanner = new Scanner(input);
         T = scanner.nextInt();
         result = new boolean[T];
         for (int t=0; t<T; t++) {
             N = scanner.nextInt();
             d = new int[N];
             l = new int[N];
             for (int n=0; n<N; n++) {
                 d[n] = scanner.nextInt();
                 l[n] = scanner.nextInt();
             }
             D = scanner.nextInt();
             process(t);
         }
     }
 
     static void process(int t) {
         swing = new int[N];
         swing[0] = d[0];
         boolean ok = false;
         for (int i=0; i<N; i++) {
             if (d[i]+swing[i]>=D) {
                 ok = true;
                 break;
             }
             for (int j=i+1; j<N; j++) {
                 if (d[i]+swing[i] >= d[j]) {
                     // Can reach j from i
                     swing[j] = Math.max(swing[j], Math.min(l[j], d[j]-d[i]));
                 } else {
                     break;
                 }
             }
         }
         result[t] = ok;
     }
 
     static void write() throws IOException {
         File output = new File("output.txt");
         PrintWriter pw = new PrintWriter(output);
 
         for (int t=0; t<T; t++) {
             pw.println("Case #"+(t+1)+": "+(result[t] ? "YES" : "NO"));
         }
 
         pw.close();
     }
 
 }
