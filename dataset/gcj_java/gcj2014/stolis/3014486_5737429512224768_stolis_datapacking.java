package round2;
 
 import round1b.*;
 import java.io.File;
 import java.io.PrintWriter;
 import java.util.Arrays;
 import java.util.Scanner;
 
 public class DataPacking {
     
     public static void main(String[] args) throws Exception {
         File inputFile = new File("A-small-attempt0.in");
         Scanner in = new Scanner(inputFile);
         File outputFile = new File("output.txt");
         PrintWriter out = new PrintWriter(outputFile);
 
         int T = in.nextInt();
         for (int t=0; t<T; t++) {
             int N = in.nextInt();
             int X = in.nextInt();
             int[] A = new int[N];
             for (int n=0; n<N; n++) {
                 A[n] = in.nextInt();
             }
             Arrays.sort(A);
             int down = 0;
             int up = A.length-1;
             int twos = 0;
             while (down < up) {
                 if (A[down]+A[up] <= X) {
                     twos++;
                     down++;
                 }
                 up--;
             }
             
             out.println("Case #"+(t+1)+": "+(A.length-twos));
         }
 
         out.close();
     }
     
 }
