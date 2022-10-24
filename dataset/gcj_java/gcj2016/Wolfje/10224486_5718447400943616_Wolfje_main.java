import java.io.OutputStream;
 import java.io.FilenameFilter;
 import java.util.Locale;
 import java.io.FileOutputStream;
 import java.io.IOException;
 import java.io.FileInputStream;
 import java.io.File;
 import java.io.InputStream;
 import java.io.PrintWriter;
 import java.util.Arrays;
 import java.util.Scanner;
 
 /**
  * Built using CHelper plug-in
  * Actual solution is at the top
  *
  * @author Rene
  */
 public class Main {
     public static void main(String[] args) {
         Locale.setDefault(Locale.US);
         InputStream inputStream;
         try {
             final String regex = "D-(small|large).*[.]in";
             File directory = new File(".");
             File[] candidates = directory.listFiles(new FilenameFilter() {
                 public boolean accept(File dir, String name) {
                     return name.matches(regex);
                 }
             });
             File toRun = null;
             for (File candidate : candidates) {
                 if (toRun == null || candidate.lastModified() > toRun.lastModified())
                     toRun = candidate;
             }
             inputStream = new FileInputStream(toRun);
         } catch (IOException e) {
             throw new RuntimeException(e);
         }
         OutputStream outputStream;
         try {
             outputStream = new FileOutputStream("d.out");
         } catch (IOException e) {
             throw new RuntimeException(e);
         }
         Scanner in = new Scanner(inputStream);
         PrintWriter out = new PrintWriter(outputStream);
         TaskD solver = new TaskD();
         int testCount = Integer.parseInt(in.next());
         for (int i = 1; i <= testCount; i++)
             solver.solve(i, in, out);
         out.close();
     }
 
     static class TaskD {
         int allN;
         int[] order;
         int[] modAble;
         int n;
 
         public void solve(int testNumber, Scanner in, PrintWriter out) {
             n = in.nextInt();
             int[] able = new int[n];
             for (int i = 0; i < n; i++) able[i] = Integer.valueOf(in.next(), 2);
             modAble = new int[n];
             int bestCost = 100;
             allN = (1 << n) - 1;
             order = new int[n];
             for (int mask = 0; mask < 1 << (n * n); mask++) {
                 Arrays.fill(modAble, 0);
                 int cost = 0;
                 int z = mask;
                 for (int i = 0; i < n; i++) {
                     int s = z & allN;
                     modAble[i] = able[i] | s;
                     cost += Integer.bitCount(modAble[i] ^ able[i]);
                     z = z >> n;
                 }
                 if (cost >= bestCost) continue;
                 for (int i = 0; i < n; i++) order[i] = i;
                 boolean ok = true;
                 do {
 //                System.out.println("---------");
 //                System.out.println("order " + Arrays.toString(order));
 //                System.out.println("ables " + Arrays.toString(modAble));
                     ok = go(0, 0);
 
 
                 } while (nextPermutation(order) && ok);
                 if (ok && cost < bestCost) bestCost = cost;
             }
             out.printf("Case #%d: %d\n", testNumber, bestCost);
         }
 
         public boolean go(int k, int mask) {
             if (k == n) return true;
             int choices = 0;
             boolean somethingFailed = false;
             for (int i = 0; i < n; i++) {
                 if (((1 << i) & modAble[order[k]]) == 0) continue;
                 if (((1 << i) & mask) != 0) continue;
                 choices++;
                 boolean z = go(k + 1, mask | (1 << i));
                 if (!z) somethingFailed = true;
             }
             if (choices == 0) return false;
             return !somethingFailed;
         }
 
         public boolean nextPermutation(int[] a) {
             if (a.length <= 1)
                 return false;
             int k = a.length - 2;
             while (k >= 0 && a[k] >= a[k + 1])
                 k--;
             int m = a.length - 1;
             if (k < 0) {
                 reverse(a, 0, m);
                 return false;
             }
             while (a[m] <= a[k])
                 m--;
             swap(a, m, k);
             reverse(a, k + 1, a.length - 1);
             return true;
         }
 
         public void reverse(int[] a, int s, int t) {
             while (s < t)
                 swap(a, s++, t--);
         }
 
         public void swap(int[] a, int s, int t) {
             int b = a[s];
             a[s] = a[t];
             a[t] = b;
         }
 
     }
 }
 
