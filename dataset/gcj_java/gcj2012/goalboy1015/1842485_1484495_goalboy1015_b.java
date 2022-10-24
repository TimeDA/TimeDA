
 import java.io.File;
 import java.io.PrintWriter;
 import java.util.Arrays;
 import java.util.Scanner;
 
 public class B {
 
     static Point points[];
     static int r[];
     static int N;
     static int W;
     static int L;
     static boolean found;
 
     public static void main(String args[]) throws Exception {
         final String PATH = "/home/goalboy/software installation/codejam-commandline-1.0-beta4/source/";
         final String FILE = "B-small-4";
         Scanner in = new Scanner(new File(PATH + FILE + ".in"));
         PrintWriter out = new PrintWriter(PATH + FILE + ".out");
 
         int test = in.nextInt();
         for (int t = 1; t <= test; t++) {
             N = in.nextInt();
             W = in.nextInt();
             L = in.nextInt();
             r = new int[N];
             points = new Point[N];
             for (int i = 0; i < N; i++) {
                 r[i] = in.nextInt();
             }
 //            Arrays.sort(r);
             if (N >= 1) {
                 points[N - 1] = new Point(0, 0);
             }
             if (N >= 2) {
                 points[N - 2] = new Point(W, L);
             }
             found = false;
             search(N - 3);
             out.print("Case #" + t + ":");
             for (Point p : points) {
                 out.print(" " + p.x + " " + p.y);
             }
             out.println();
         }
 
         out.close();
     }
 
     static void search(int index) {
         final int TRY_NUM = 100;
         final double ERROR = 1E-5;
         if (index < 0) {
             found = true;
             return;
         }
         int rest = TRY_NUM;
         while (rest > 0) {
             double x = Math.random() * W;
             double y = Math.random() * L;
             Point p = new Point(x, y);
             boolean inside = false;
             for (int i = index + 1; i < N; i++) {
                 if (distance(p, points[i]) < r[i] + ERROR) {
                     inside = true;
                     break;
                 }
             }
             if (inside) {
                 continue;
             }
             boolean valid = true;
             for (int i = index + 1; i < N; i++) {
                 if (distance(p, points[i]) < r[i] + r[index] + ERROR) {
                     valid = false;
                     break;
                 }
             }
             if (valid) {
                 points[index] = p;
                 search(index - 1);
                 if (found) {
                     return;
                 }
             } else if (index < N - 3) {
                 rest--;
             }
         }
     }
 
     static double distance(Point p1, Point p2) {
         return Math.sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
     }
 }
 
 class Point {
 
     double x;
     double y;
 
     Point(double x, double y) {
         this.x = x;
         this.y = y;
     }
 }