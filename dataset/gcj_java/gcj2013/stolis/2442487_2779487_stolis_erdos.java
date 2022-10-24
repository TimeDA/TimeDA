package round2;
 
 import java.io.File;
 import java.io.IOException;
 import java.io.PrintWriter;
 import java.util.Scanner;
 
 public class Erdos {
     static int T;
     static int N;
     static int[] B;
     static int[] X;
     static int[][] results;
 
     public static void main(String[] args) throws IOException {
         read();
         process();
         write();
     }
 
     static void read() throws IOException {
         File input = new File("input.txt");
         Scanner scanner = new Scanner(input);
         T = scanner.nextInt();
         results = new int[T][];
         for (int t=0; t<T; t++) {
             N = scanner.nextInt();
             B = new int[N];
             for (int n=0; n<N; n++) {
                 scanner.nextInt();
             }
             for (int n=0; n<N; n++) {
                 B[n] = scanner.nextInt();
             }
             results[t] = process();
         }
     }
 
     static int[] process() {
         X = new int[N];
         boolean[] used = new boolean[N];
         for (int n=0; n<N; n++) {
             int b = B[n];
             int index = 0;
             while (b>0) {
                 while (used[index]) {
                     index++;
                 }
                 b--;
                 index++;
             }
             index--;
             X[n] = index+1;
             used[index] = true;
         }
         return X;
     }
 
     static void write() throws IOException {
         File output = new File("output.txt");
         PrintWriter pw = new PrintWriter(output);
 
         for (int t=0; t<T; t++) {
             pw.print("Case #"+(t+1)+":");
             int[] result = results[t];
             for (int x : result) {
                 pw.print(" "+x);
             }
             pw.println();
         }
 
         pw.close();
     }
 
 }
