import java.util.*;
 
 public class Main {
 
   public static void main(String args[]) {
     (new Main()).solve();
   }
 
   boolean solve(int n, int d[], int l[], int req) {
 
     // available max length
     int max[] = new int[n];
     max[0] = d[0];
 
     for(int i=0; i<n; ++i) {
       if( d[i] + max[i] >= req ) { return true; }
       for(int j=i+1; j<n; ++j) {
         // cannot reach
         if( d[j] - d[i] > max[i] ) { break; }
         max[j] = Math.max(max[j], Math.min(d[j] - d[i], l[j]));
       }
     }
 
     return false;
 
   }
 
   void solve() {
 
     Scanner cin = new Scanner(System.in);
     int T = cin.nextInt();
 
     for(int C=1; C<=T; ++C) {
 
       int n = cin.nextInt();
       int d[] = new int[n];
       int l[] = new int[n];
       for(int i=0; i<n; ++i) {
         d[i] = cin.nextInt();
         l[i] = cin.nextInt();
       }
 
       int req = cin.nextInt();
 
       System.out.println("Case #" + C + ": " + (solve(n, d, l, req) ? "YES" : "NO"));
 
     }
 
   }
 
 }
