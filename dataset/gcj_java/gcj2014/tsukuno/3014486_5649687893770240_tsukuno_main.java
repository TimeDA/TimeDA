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
       int S = cin.nextInt();
 
       String var[] = new String[N];
       for(int i=0; i<N; ++i) { var[i] = cin.next(); }
 
       System.out.println("Case #" + C + ": " + solve(var, N, S));
 
     }
 
   }
 
   String solve(String var[], int N, int S) {
     int memo[] = new int[100];
     fill(0, N, new int[N], S, var, memo);
     for(int i=99; i>=0; --i) {
       if( memo[i] > 0 ) { return (i + S) + " " + memo[i]; }
     }
     throw new RuntimeException("???");
   }
 
   void fill(int cur, int N, int hist[], int S, String var[], int memo[]) {
 
     if( cur == N ) {
       int sum = score(var, hist, N, S);
       if( sum >= 0 ) { ++memo[sum]; }
       return;
     }
 
     for(int i=0; i<S; ++i) {
       hist[cur] = i;
       fill(cur + 1, N, hist, S, var, memo);
     }
 
   }
 
   int score(String var[], int hist[], int N, int S) {
     int sum = 0;
     for(int i=0; i<S; ++i) {
       int add = 0;
       for(int j=0; j<N; ++j) {
         if( hist[j] != i ) { continue; }
         int share = 0;
         for(int k=0; k<j; ++k) {
           if( hist[k] != i ) { continue; }
           int end = Math.min(var[j].length(), var[k].length());
           for(int l=0; l<end; ++l) {
             if( var[j].charAt(l) == var[k].charAt(l) ) {
               share = Math.max(share, l + 1);
             }
             else { break; }
           }
         }
         add += var[j].length() - share;
       }
       if( add == 0 ) { return -1; }
       sum += add;
     }
     return sum;
   }
 
 }
