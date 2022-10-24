import java.util.*;
 
 public class Main {
 
   public static void main(String args[]) {
     (new Main()).solve();
   }
 
   long maxRank(long level, int N) {
     // win;
     if( level == 0 ) { return 0; }
     // ends (never happen);
     if( N == 0 ) { return 0; }
     return maxRank((level - 1) >> 1, N - 1) + (1L << (N - 1));
   }
 
   // worst rank;
   long max(int N, long P) {
     long lo = 0;
     long hi = (1 << N);
     for(int i=0; i<(N + 4); ++i) {
       long mid = (lo + hi) / 2;
       if( maxRank(mid, N) < P ) { lo = mid; }
       else { hi = mid; }
     }
     return lo;
   }
 
   long minRank(long level, int N) {
     // always lose;
     if( level == (1L << N) - 1 ) { return level; }
     // ends (never happen);
     if( N == 0 ) { return 0; }
     return minRank((level + 1) >> 1, N - 1);
   }
 
   // best rank;
   long min(int N, long P) {
     long lo = 0;
     long hi = (1 << N);
     for(int i=0; i<(N + 4); ++i) {
       long mid = (lo + hi) / 2;
       if( minRank(mid, N) < P ) { lo = mid; }
       else { hi = mid; }
     }
     return lo;
   }
 
   void solve() {
 
     Scanner cin = new Scanner(System.in);
 
     int T = cin.nextInt();
     for(int C=1; C<=T; ++C) {
 
       int N = cin.nextInt();
       long P = cin.nextLong();
 
       System.out.println("Case #" + C + ": " + max(N, P) + " " + min(N, P));
 
     }
 
   }
 
 }
