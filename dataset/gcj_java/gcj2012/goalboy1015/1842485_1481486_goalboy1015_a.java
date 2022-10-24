
 import java.io.File;
 import java.io.PrintWriter;
 import java.util.Scanner;
 
 public class A {
 
     public static void main(String args[]) throws Exception {
         final String PATH = "/home/goalboy/software installation/codejam-commandline-1.0-beta4/source/";
         final String FILE = "A-small-0";
         Scanner in = new Scanner(new File(PATH + FILE + ".in"));
         PrintWriter out = new PrintWriter(PATH + FILE + ".out");
 
         int test = in.nextInt();
         for (int t = 1; t <= test; t++) {
             int N = in.nextInt();
             Vine vines[] = new Vine[N];
             for (int i = 0; i < N; i++) {
                 vines[i] = new Vine(in.nextInt(), in.nextInt());
             }
             long minStarts[] = new long[N];
             int D = in.nextInt();
             for (int i = 0; i < N; i++) {
                 minStarts[i] = Integer.MAX_VALUE;
             }
             minStarts[0] = 0;
             boolean possible = false;
             for (int i = 0; i < N; i++) {
 //                System.out.println("minStarts["+i+"]: "+minStarts[i]);
                 if (minStarts[i] == Integer.MAX_VALUE) {
                     continue;
                 }
                 long deltaStart = vines[i].d - minStarts[i];
                 if (deltaStart >= D - vines[i].d) {
                     possible = true;
                     break;
                 }
                 for (int j = i + 1; j < N; j++) {
                     long deltaH = vines[j].d - vines[i].d;
 //                    System.out.println("deltaH: "+deltaH);
 //                    System.out.println("vines["+j+"].l: "+vines[j].l);
 //                    System.out.println("deltaStart: "+deltaStart);
                     if (deltaH<=deltaStart/*deltaH * deltaH + vines[j].l * vines[j].l <= deltaStart * deltaStart*/) {
                         minStarts[j] = Math.min(minStarts[j],
                                 Math.max(vines[i].d, vines[j].d - vines[j].l));
                     }
                 }
             }
             out.print("Case #" + t + ": ");
             if (possible) {
                 out.println("YES");
             } else {
                 out.println("NO");
             }
         }
 
         out.close();
     }
 }
 
 class Vine {
 
     long d;
     long l;
 
     Vine(long d, long l) {
         this.d = d;
         this.l = l;
     }
 }