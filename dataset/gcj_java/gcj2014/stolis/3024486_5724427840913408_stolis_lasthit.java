package round3;
 
 import java.io.File;
 import java.io.PrintWriter;
 import java.util.Arrays;
 import java.util.HashMap;
 import java.util.Map;
 import java.util.Scanner;
 
 public class LastHit {
     static int[] G;
     static int P;
     static int Q;
     
     public static void main(String[] args) throws Exception {
         File inputFile = new File("B-small-attempt1.in");
         Scanner in = new Scanner(inputFile);
         File outputFile = new File("output.txt");
         PrintWriter out = new PrintWriter(outputFile);
 
         int T = in.nextInt();
         for (int t=0; t<T; t++) {
             cache.clear();
             P = in.nextInt();
             Q = in.nextInt();
             int N = in.nextInt();
             int[] H = new int[N];
             G = new int[N];
             for (int n=0; n<N; n++) {
                 H[n] = in.nextInt();
                 G[n] = in.nextInt();
             }
             int answer = solve(new Data(H));
             
             out.println("Case #"+(t+1)+": "+answer);
         }
 
         out.close();
     }
 
     static Map<Data,Integer> cache = new HashMap<Data,Integer>();
     static int solve(Data data) {
         Integer result = cache.get(data);
         if (result != null) {
             return result;
         }
         int max = 0;
         for (int i=-1; i<data.health.length; i++) {
             if (i == -1) {
                 int tower = 0;
                 while (tower<data.health.length && data.health[tower] == 0) {
                     tower++;
                 }
                 if (tower < data.health.length) {
                     int[] copy = new int[data.health.length];
                     System.arraycopy(data.health, 0, copy, 0, data.health.length);
                     copy[tower] = Math.max(0, copy[tower]-Q);
                     max = Math.max(max, solve(new Data(copy)));
                 }
             } else if (data.health[i] > 0) {
                 int[] copy = new int[data.health.length];
                 System.arraycopy(data.health, 0, copy, 0, data.health.length);
                 copy[i] = Math.max(0, copy[i]-P);
                 int gain = (copy[i] == 0) ? G[i] : 0;
                 int tower = 0;
                 while (tower<copy.length && copy[tower] == 0) {
                     tower++;
                 }
                 if (tower < copy.length) {
                     copy[tower] = Math.max(0, copy[tower]-Q);
                 }
                 max = Math.max(max, gain+solve(new Data(copy)));
             }
         }
         cache.put(data, max);
         return max;
     }
 
     static class Data {
         int[] health;
 
         Data(int[] health) {
             this.health = health;
         }
 
         @Override
         public boolean equals(Object obj) {
             int[] h = ((Data)obj).health;
             for (int i=0; i<h.length; i++) {
                 if (h[i] != health[i]) {
                     return false;
                 }
             }
             return true;
         }
 
         @Override
         public int hashCode() {
             int hash = 5;
             hash = 71 * hash + Arrays.hashCode(this.health);
             return hash;
         }
         
         
     }
     
 }
