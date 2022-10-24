import java.io.OutputStream;
 import java.io.FilenameFilter;
 import java.util.Locale;
 import java.io.FileOutputStream;
 import java.io.IOException;
 import java.io.FileInputStream;
 import java.io.File;
 import java.io.InputStream;
 import java.io.PrintWriter;
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
             final String regex = "A-(small|large).*[.]in";
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
             outputStream = new FileOutputStream("a.out");
         } catch (IOException e) {
             throw new RuntimeException(e);
         }
         Scanner in = new Scanner(inputStream);
         PrintWriter out = new PrintWriter(outputStream);
         TaskA solver = new TaskA();
         int testCount = Integer.parseInt(in.next());
         for (int i = 1; i <= testCount; i++)
             solver.solve(i, in, out);
         out.close();
     }
 
     static class TaskA {
         static String letters = "PRS";
 
         public void solve(int testNumber, Scanner in, PrintWriter out) {
             int n = in.nextInt();
             int r = in.nextInt();
             int p = in.nextInt();
             int s = in.nextInt();
             String answer = null;
             for (int k = 0; k < 3; k++) {
                 Node tree = new Node(k, n);
                 int[] count = new int[3];
                 for (int i = 0; i < tree.order.length(); i++) {
                     char c = tree.order.charAt(i);
                     count[letters.indexOf(c)]++;
                 }
                 if (count[0] == p && count[1] == r && count[2] == s) {
                     if (answer == null || tree.order.compareTo(answer) < 0) answer = tree.order;
                 }
             }
             if (answer == null) answer = "IMPOSSIBLE";
             out.printf("Case #%d: %s\n", testNumber, answer);
         }
 
         class Node {
             int x;
             Node left = null;
             Node right = null;
             String order;
 
             public Node(int root, int depth) {
                 x = root;
                 if (depth == 0) {
                     order = "" + letters.charAt(x);
                 } else {
                     left = new Node(root, depth - 1);
                     int other = 0;
                     if (root == 0) other = 1;
                     else if (root == 1) other = 2;
                     right = new Node(other, depth - 1);
                     String a = left.order + right.order;
                     String b = right.order + left.order;
                     if (a.compareTo(b) < 0) order = a;
                     else order = b;
                 }
             }
 
         }
 
     }
 }
 
