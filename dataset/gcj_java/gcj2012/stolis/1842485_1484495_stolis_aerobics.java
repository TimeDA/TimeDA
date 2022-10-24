package round2;
 
 import java.awt.Point;
 import java.io.File;
 import java.io.IOException;
 import java.io.PrintWriter;
 import java.util.ArrayList;
 import java.util.Collections;
 import java.util.Comparator;
 import java.util.List;
 import java.util.Scanner;
 
 public class Aerobics {
     static int T;
     static int N;
     static int W;
     static int L;
     static int[] r;
     static int[] x;
     static int[] y;
 
     public static void main(String[] args) throws IOException {
         read();
     }
 
     static PrintWriter pw;
     static void read() throws IOException {
         File output = new File("output.txt");
         pw = new PrintWriter(output);
         File input = new File("input.txt");
         Scanner scanner = new Scanner(input);
         T = scanner.nextInt();
         for (int t=0; t<T; t++) {
             N = scanner.nextInt();
             W = scanner.nextInt();
             L = scanner.nextInt();
             r = new int [N];
             for (int n=0; n<N; n++) {
                 r[n] = 2*scanner.nextInt();
             }
             process(t);
         }
         pw.close();
     }
 
     static int[] toSorted;
     static void process(int t) throws IOException {
         List<Point> list = new ArrayList<Point>();
         for (int n=0; n<N; n++) {
             list.add(new Point(n, r[n]));
         }
         Collections.sort(list, new Comparator<Point>() {
             public int compare(Point o1, Point o2) {
                 int dx = o1.x - o2.x;
                 int dy = o1.y - o2.y;
                 return (dy == 0) ? dx : dy;
             }
         });
         r = new int[N];
         toSorted = new int[N];
         for (int n=0; n<N; n++) {
             Point p = list.get(n);
             r[n] = p.y;
             toSorted[p.x] = n;
         }
 
         x = new int[N];
         y = new int[N];
         int i = fill(W, L, 0, 0, (W>=L), N-1, true);
         if (i != -1) {
             throw new RuntimeException("t "+t+" i "+i);
         } else{
             write(t);
         }
     }
 
     static int fill(int xsize, int ysize, int originx, int originy, boolean horizontally, int index, boolean first) {
         boolean firstRow = first;
         int size = horizontally ? xsize : ysize;
         if (first) {
             x[index] = -r[index]/2;
             y[index] = -r[index]/2;
         } else {
             x[index] = originx;
             y[index] = originy;
         }
         int position = first ? r[index]/2 : r[index];
         int i = index;
         while (true) {
             i--;
             if (i==-1) {
                 // All placed
                 return i;
             } else if ((first && position+r[i]/2 > size) || (!first && position+r[i] > size)) {
                 // Next will not fit
                 if (first || (r[i]+r[index] <= (horizontally ? ysize : size))) {
                     // Next row will fit
                     if (horizontally) {
                         ysize -= firstRow ? r[index]/2 : r[index];
                         originy += firstRow ? r[index]/2 : r[index];
                     } else {
                         xsize -= firstRow ? r[index]/2 : r[index];
                         originx += firstRow ? r[index]/2 : r[index];
                     }
                     x[i] = x[index] + (horizontally ? 0 : r[index]);
                     y[i] = y[index] + (horizontally ? r[index] : 0);
 //                    if (first) {
 //                        if (horizontally) {
 //                            x[i] -= r[i]/2;
 //                        } else {
 //                            y[i] -= r[i]/2;
 //                        }
 //                    }
                     position = first ? r[i]/2 : r[i];
                     index = i;
                     firstRow = false;
                 } else {
                     return i;
                 }
             } else if (2*r[i]<=r[index]) {
                 // Next is too small
                 int ii;
                 if (horizontally) {
                     ii = fill(xsize-position, r[index], position+originx, originy, !horizontally, i, false);
                 } else {
                     ii = fill(r[index], ysize-position, originx, position+originy, !horizontally, i, false);
                 }
                 if (ii == -1) {
                     // All placed
                     return ii;
                 } else {
                     if (r[ii]+r[index] <= (horizontally ? ysize : size)) {
                         // Next row will fit
                         i = ii;
                         if (horizontally) {
                             ysize -= r[index];
                             originy += r[index];
                         } else {
                             xsize -= r[index];
                             originx += r[index];
                         }
                         x[i] = x[index] + (horizontally ? 0 : r[index]);
                         y[i] = y[index] + (horizontally ? r[index] : 0);
                         position = r[i];
                         index = i;
                     } else {
                         return ii;
                     }
                 }
             } else {
                 // Next will fit
                 x[i] = x[i+1] + (horizontally ? r[i+1] : 0);
                 y[i] = y[i+1] + (horizontally ? 0 : r[i+1]);
                 if (horizontally) {
                     y[i] += (r[index]-r[i])/2;
                 } else {
                     x[i] += (r[index]-r[i])/2;
                 }
                 position += r[i];
             }
         }
     }
 
     static void write(int t) throws IOException {
         pw.print("Case #"+(t+1)+": ");
         for (int n=0; n<N; n++) {
             int index = toSorted[n];
             int xx = x[index]+ r[index]/2;
             int yy = y[index]+ r[index]/2;
             pw.print(xx+" "+yy+" ");
         }
         pw.println();
     }
 
 }
