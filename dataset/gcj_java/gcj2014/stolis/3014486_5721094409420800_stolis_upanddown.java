package round2;
 
 import java.io.File;
 import java.io.PrintWriter;
 import java.util.Scanner;
 
 public class UpAndDown {
     
     public static void main(String[] args) throws Exception {
         File inputFile = new File("B-small-attempt1.in");
         //File inputFile = new File("input.txt");
         Scanner in = new Scanner(inputFile);
         File outputFile = new File("output.txt");
         PrintWriter out = new PrintWriter(outputFile);
 
         int T = in.nextInt();
         for (int t=0; t<T; t++) {
             int N = in.nextInt();
             int[] A = new int[N];
             for (int n=0; n<N; n++) {
                 A[n] = in.nextInt();
             }
             int down = 0;
             int up = N-1;
             int result = 0;
             for (int n=0; n<N; n++) {
                 int min = Integer.MAX_VALUE;
                 int minIndex = 0;
                 for (int i=down; i<=up; i++) {
                     if (A[i] < min) {
                         min = A[i];
                         minIndex = i;
                     }
                 }
                 int toDown = minIndex-down;
                 int toUp = up-minIndex;
                 if (toDown < toUp) {
                     for (int i=toDown-1; i>=0; i--) {
                         int temp = A[down+i];
                         A[down+i] = A[down+i+1];
                         A[down+i+1] = temp;
                     }
                     result += toDown;
                     down++;
                 } else {
                     for (int i=0; i<toUp; i++) {
                         int temp = A[minIndex+i];
                         A[minIndex+i] = A[minIndex+i+1];
                         A[minIndex+i+1] = temp;
                     }
                     result += toUp;
                     up--;
                 }
             }
             
             out.println("Case #"+(t+1)+": "+result);
         }
 
         out.close();
     }
     
 }
