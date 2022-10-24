import java.util.*;
 
 public class Main {
 
   public static void main(String args[]) {
     (new Main()).solve();
   }
 
   void solve() {
 
     Scanner cin = new Scanner(System.in);
 
     int T = cin.nextInt();
     for(int C=1; C<=T; ++C) {
 
       int N = cin.nextInt();
       double M[] = new double[N];
       for(int i=0; i<N; ++i) {
         M[i] = cin.nextDouble();
       }
       Arrays.sort(M);
       double K[] = new double[N];
       for(int i=0; i<N; ++i) {
         K[i] = cin.nextDouble();
       }
       Arrays.sort(K);
 
       int ans[] = solve(N, M, K);
       String res = "";
       for( int v : ans ) { res += " " + v; }
 
       System.out.println("Case #" + C + ": " + res);
 
     }
 
   }
 
   int[] solve(int N, double M[], double K[]) {
 
     int ret[] = new int[2];
 
     // cheat play;
     {
       int L = 0;
       for(int i=0; i<N; ++i) {
         // winable;
         if( M[i] > K[L] ) {
           ++ret[0];
           ++L;
         }
         // lose;
         else { }
       }
     }
 
     // normal play;
     {
       int R = N - 1;
 
       for(int i=N-1; i>=0; --i) {
         // win;
         if( M[i] > K[R] ) { ++ret[1]; }
         // lose;
         else { --R; }
       }
 
     }
 
     return ret;
 
   }
 
 }
