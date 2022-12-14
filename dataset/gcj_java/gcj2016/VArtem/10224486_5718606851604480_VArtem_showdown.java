import java.io.*;
 import java.util.*;
 
 public class Showdown {
 
     String ans;
 
     int[][] win = new int[][] {
             {-1, 0, 2},
             {0, -1, 1},
             {2, 1, -1},
     };
 
     void go(int p, int r, int s, int[] stack, String cur) {
         if (p == 0 && r == 0 && s == 0) {
             this.ans = cur;
             return;
         }
 
         if (p > 0) {
             int[] newStack = tryAdd(stack, 0);
             if (newStack != null) {
                 go(p - 1, r, s, newStack, cur + "P");
                 if (ans != null) {
                     return;
                 }
             }
         }
 
         if (r > 0) {
             int[] newStack = tryAdd(stack, 1);
             if (newStack != null) {
                 go(p, r - 1, s, newStack, cur + "R");
                 if (ans != null) {
                     return;
                 }
             }
         }
 
         if (s > 0) {
             int[] newStack = tryAdd(stack, 2);
             if (newStack != null) {
                 go(p, r, s - 1, newStack, cur + "S");
                 if (ans != null) {
                     return;
                 }
             }
         }
     }
 
     int[] tryAdd(int[] stack, int val) {
         int[] newStack = stack.clone();
         for (int i = 0; i < newStack.length; i++) {
             if (newStack[i] == -1) {
                 newStack[i ] = val;
                 return newStack;
             } else {
                 if (newStack[i] == val) {
                     return null;
                 } else {
                     val = win[newStack[i]][val];
                     newStack[i] = -1;
                 }
             }
         }
         return newStack;
     }
 
     public void solve() {
         int n = in.nextInt();
         int r = in.nextInt();
         int p = in.nextInt();
         int s = in.nextInt();
 
         int[] stack = new int[n + 1];
         Arrays.fill(stack, -1);
         ans = null;
         go(p, r, s, stack, "");
 
         if (ans == null) {
             out.println("IMPOSSIBLE");
         } else {
             out.println(ans);
         }
     }
 
     public void run() {
         try {
             in = new FastScanner("input.txt");
             out = new PrintWriter("output.txt");
             int tests = in.nextInt();
             for (int i = 1; i <= tests; i++) {
                 long time = System.currentTimeMillis();
                 out.printf("Case #%d: ", i);
                 solve();
                 System.err.printf("Solved case #%d in %d ms\n", i, System.currentTimeMillis() - time);
             }
             out.close();
         } catch (FileNotFoundException e) {
         }
     }
 
     FastScanner in;
     PrintWriter out;
 
     class FastScanner {
         BufferedReader br;
         StringTokenizer st;
 
         public FastScanner(String fileName) {
             try {
                 br = new BufferedReader(new FileReader(fileName));
             } catch (FileNotFoundException e) {
             }
         }
 
         String nextToken() {
             while (st == null || !st.hasMoreElements()) {
                 try {
                     st = new StringTokenizer(br.readLine());
                 } catch (IOException e) {
                 }
             }
             return st.nextToken();
         }
 
         int nextInt() {
             return Integer.parseInt(nextToken());
         }
 
         long nextLong() {
             return Long.parseLong(nextToken());
         }
 
         double nextDouble() {
             return Double.parseDouble(nextToken());
         }
     }
 
     public static void main(String[] args) {
         new Showdown().run();
     }
 }
