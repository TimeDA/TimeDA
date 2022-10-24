import java.util.*;
 
 public class Main {
 
   public static void main(String args[]) {
     (new Main()).solve();
   }
 
   int[] solve(int n, int see[]) {
 
     for(int i=0; i<n; ++i) {
       for(int j=i+1; j<see[i]-1; ++j) {
         if( see[j] > see[i] ) { return null; }
       }
     }
 
     int cur = 1000 * 1000 * 1000;
     int res[] = new int[n];
     int pos = 0;
     int prev = -1;
     while( true ) {
       res[pos] = cur;
       if( prev >= 0 ) {
         sweep(prev, pos, see, res, cur, 1);
       }
       if( pos == n - 1 ) { break; }
       prev = pos;
       pos = see[pos] - 1;
     }
 
     return res;
 
   }
 
   void sweep(int A, int B, int see[], int res[], int D, int Y) {
 
     int det = -1;
     int prev = A;
 
     for(int i=A+1; i<B; ++i) {
       // who see i first
       if( see[i] - 1 == B ) {
         // determin my height
         res[i] = D - Y * (B - i);
         ++Y;
         sweep(prev, i, see, res, res[i], Y);
         prev = i;
       }
     }
 
   }
 
   void emit(int n, int res[]) {
     if( res == null ) { System.out.println(" Impossible"); }
     else {
       for(int i=0; i<n; ++i) { System.out.print(" " + res[i]); }
       System.out.println();
     }
   }
 
   void solve() {
 
     Scanner cin = new Scanner(System.in);
 
     int T = cin.nextInt();
     for(int C=1; C<=T; ++C) {
 
       int n = cin.nextInt();
       int see[] = new int[n];
       for(int i=0; i<n-1; ++i) { see[i] = cin.nextInt(); }
 
       System.out.print("Case #" + C + ":");
       emit(n, solve(n, see));
 
     }
 
   }
 
 }
