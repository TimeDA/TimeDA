import java.util.*;
 
 public class Main {
 
   public static void main(String args[]) {
     (new Main()).solve();
   }
 
   void solve() {
 
     Scanner cin = new Scanner(System.in);
 
     int T = cin.nextInt();
     for(int C=1; C<=T; ++C) {
 
       int N = cin.nextInt() - 1;
       Set<Integer> a = new HashSet<Integer>();
       for(int i=0; i<4; ++i) {
         for(int j=0; j<4; ++j) {
           int v = cin.nextInt();
           if( i == N ) { a.add(v); }
         }
       }
 
       int M = cin.nextInt() - 1;
       Set<Integer> b = new HashSet<Integer>();
       for(int i=0; i<4; ++i) {
         for(int j=0; j<4; ++j) {
           int v = cin.nextInt();
           if( i == M ) { b.add(v); }
         }
       }
 
       a.retainAll(b);
 
       String res = "";
       if( a.size() == 0 ) { res = "Volunteer cheated!"; }
       else if( a.size() == 1 ) {
         for( int v : a ) { res += "" + v; }
       }
       else { res = "Bad magician!"; }
 
       System.out.println("Case #" + C + ": " + res);
 
     }
 
   }
 
 }
