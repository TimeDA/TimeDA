import java.io.*;
 import java.util.*;
 
 public class B {
     FastScanner in;
     PrintWriter out;
 
     Random rnd = new Random(123);
 
     void solve() throws IOException {
         int n = in.nextInt();
         long p = in.nextLong();
         int curTop = n;
         long needLeft = 0;
         long curAdd = 1;
         while ((1L << curTop) > p) {
             curTop--;
             needLeft += curAdd;
             curAdd *= 2;
         }
         long ans2 = (1L << n) - needLeft;
 
         long rm = 1L << n;
         curAdd = 1;
         long needCnt = 0;
         if (1L << n != p)
             while (true) {
                 long curPos = (1L << n) - rm + 1;
                 if (curPos > p)
                     break;
                 rm /= 2;
                 needCnt += curAdd;
                 curAdd *= 2;
             }
         long ans1 = needCnt;
         if (1L << n == p)
             ans1 = 1L << n;
         ans1--;
         ans2--;
         out.println(ans1 + " " + ans2);
     }
 
     void run() throws IOException {
         try {
             in = new FastScanner(new File("B.in"));
             out = new PrintWriter(new File("B.out"));
 
             int testNumber = in.nextInt();
             for (int test = 1; test <= testNumber; test++) {
                 out.print("Case #" + (test) + ": ");
                 solve();
                 System.out.println(test);
             }
 
             out.close();
         } catch (FileNotFoundException e) {
             e.printStackTrace();
         }
     }
 
     void runIO() {
 
         in = new FastScanner(System.in);
         out = new PrintWriter(System.out);
 
         try {
             solve();
         } catch (IOException e) {
             // TODO Auto-generated catch block
             e.printStackTrace();
         }
 
         out.close();
     }
 
     class FastScanner {
         BufferedReader br;
         StringTokenizer st;
 
         public FastScanner(File f) {
             try {
                 br = new BufferedReader(new FileReader(f));
             } catch (FileNotFoundException e) {
                 e.printStackTrace();
             }
         }
 
         public FastScanner(InputStream f) {
             br = new BufferedReader(new InputStreamReader(f));
         }
 
         String next() {
             while (st == null || !st.hasMoreTokens()) {
                 String s = null;
                 try {
                     s = br.readLine();
                 } catch (IOException e) {
                     e.printStackTrace();
                 }
                 if (s == null)
                     return null;
                 st = new StringTokenizer(s);
             }
             return st.nextToken();
         }
 
         boolean hasMoreTokens() {
             while (st == null || !st.hasMoreTokens()) {
                 String s = null;
                 try {
                     s = br.readLine();
                 } catch (IOException e) {
                     e.printStackTrace();
                 }
                 if (s == null)
                     return false;
                 st = new StringTokenizer(s);
             }
             return true;
         }
 
         int nextInt() {
             return Integer.parseInt(next());
         }
 
         long nextLong() {
             return Long.parseLong(next());
         }
     }
 
     public static void main(String[] args) throws IOException {
         new B().run();
     }
 }