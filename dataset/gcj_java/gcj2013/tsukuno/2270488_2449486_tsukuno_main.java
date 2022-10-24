import java.util.*;
 
 public class Main {
 
   public static void main(String args[]) {
     (new Main()).solve();
   }
 
   boolean solve(int R, int C, int var[][]) {
 
     int rest = R + C;
     int cutR[] = new int[R];
     int cutC[] = new int[C];
 
     for(int i=0; i<R; ++i) {
       for(int j=0; j<C; ++j) {
         cutR[i] = Math.max(cutR[i], var[i][j]);
         cutC[j] = Math.max(cutC[j], var[i][j]);
       }
     }
 
     for(int i=0; i<R; ++i) {
       for(int j=0; j<C; ++j) {
         if( var[i][j] == cutR[i] || var[i][j] == cutC[j] ) { continue; }
         return false;
       }
     }
 
     return true;
 
   }
 
   void solve() {
 
     Scanner cin = new Scanner(System.in);
 
     int T = cin.nextInt();
     for(int Z=1; Z<=T; ++Z) {
 
       int R = cin.nextInt();
       int C = cin.nextInt();
       int var[][] = new int[R][C];
       for(int i=0; i<R; ++i) {
         for(int j=0; j<C; ++j) {
           var[i][j] = cin.nextInt();
         }
       }
 
       System.out.println("Case #" + Z + ": " + (solve(R, C, var) ? "YES" : "NO"));
 
     }
 
   }
 
 }
