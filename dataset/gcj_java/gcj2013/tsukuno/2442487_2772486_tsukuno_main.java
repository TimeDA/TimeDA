import java.util.*;
 
 public class Main {
 
   public static void main(String args[]) {
     (new Main()).solve();
   }
 
   int MOD = 1000002013;
 
   int solve(int N, int M, int arr[][]) {
 
     long max = 0;
     for(int i=0; i<M; ++i) {
       max += score(arr[i][1] - arr[i][0], N) * arr[i][2] % MOD;
     }
 
     List<State> queue = new ArrayList<State>();
     for(int i=0; i<M; ++i) {
       queue.add(new State(arr[i][0], arr[i][2], true));
       queue.add(new State(arr[i][1], arr[i][2], false));
     }
     Collections.sort(queue);
 
     int stack[][] = new int[M * 2][2];
     int p = 0;
 
     long min = 0;
 
     int cs = 0;
 
     for(State s : queue) {
       if( s.in ) {
         stack[p][0] = s.pos;
         stack[p][1] = s.num;
         ++p;
       }
       else {
         while( s.num > 0 ) {
           int use = Math.min(stack[p - 1][1], s.num);
           s.num -= use;
           stack[p - 1][1] -= use;
           min += score(s.pos - stack[p - 1][0], N) * use % MOD;
           if( stack[p - 1][1] == 0 ) { --p; }
         }
       }
     }
 
     return (int)((max % MOD + MOD - min % MOD) % MOD);
 
   }
 
   class State implements Comparable<State> {
 
     int pos;
     int num;
     boolean in;
 
     State(int pos, int num, boolean in) {
       this.pos = pos;
       this.num = num;
       this.in = in;
     }
 
     public int compareTo(State s) {
       if( pos == s.pos ) {
         if( in ) { return -1; }
         if( s.in ) { return 1; }
         return 0;
       }
       return pos - s.pos;
     }
 
   }
 
   long score(int D, int N) {
     return (long)(N + N - D + 1) * D / 2 % MOD;
   }
 
   void solve() {
 
     Scanner cin = new Scanner(System.in);
 
     int T = cin.nextInt();
     for(int C=1; C<=T; ++C) {
 
       int N = cin.nextInt();
       int M = cin.nextInt();
 
       int arr[][] = new int[M][3];
       for(int i=0; i<M; ++i) {
         for(int j=0; j<3; ++j) {
           arr[i][j] = cin.nextInt();
         }
       }
 
       System.out.println("Case #" + C + ": " + solve(N, M, arr));
 
     }
 
   }
 
 }
