import java.util.*;
 
 public class Main {
 
   public static void main(String args[]) {
     (new Main()).solve();
   }
 
   private static final int INF = Integer.MAX_VALUE;
 
   int solve(int N, int M, int arr[][], int P, int cand[]) {
 
     int next[][][] = new int[N][M][5];
     int count[] = new int[N];
 
     for(int i=0; i<M; ++i) {
       int from = arr[i][0];
       int index = count[from]++;
       next[from][index][0] = arr[i][1];
       next[from][index][1] = arr[i][2];
       next[from][index][2] = arr[i][3];
       next[from][index][3] = i;
       if( arr[i][0] == arr[i][1] ) { next[from][index][4] = 1; }
     }
 
     // for(int i=0; i<N; ++i) { System.err.print(count[i] + " "); } System.err.println();
 
     // worst minimam dijkstra;
     PriorityQueue<State> queue = new PriorityQueue<State>();
     int score[] = new int[N];
     for(int i=1; i<N; ++i) {
       score[i] = INF;
     }
     queue.add(new State(0, 0));
 
     while( !queue.isEmpty() ) {
 
       State s = queue.poll();
       // if( s.pos == 1 ) { break; }
       // System.err.println(s.pos + " : " + s.score + " " + score[s.pos]);
       if( score[s.pos] < s.score ) { continue; }
 
       for(int i=0; i<count[s.pos]; ++i) {
         int nextScore = s.score + next[s.pos][i][2];
         int nextPos = next[s.pos][i][0];
         // System.err.println(s.pos + " => " + nextPos + " : " + nextScore);
         if( score[nextPos] > nextScore ) {
           score[nextPos] = nextScore;
           // System.err.println(s.pos + " => " + nextPos + " : " + nextScore);
           queue.add(new State(nextPos, nextScore));
         }
       }
 
     }
 
     // for GC;
     queue = null;
 
     /*
     for(int i=0; i<N; ++i) {
       System.err.print(score[i] + " ");
     }
     System.err.println();
      */
     boolean used[] = new boolean[M];
     solve(0, 0, score, 0, new int[M], next, count, used);
 
     for(int i=0; i<P; ++i) {
       if( !used[ cand[i] - 1 ] ) { return cand[i]; }
     }
     return -1;
 
   }
 
   void solve(int cur, int score, int worst[], int K, int path[], int next[][][], int count[], boolean used[]) {
 
     if( score > worst[cur] || worst[cur] == INF ) { return; }
 
     if( cur == 1 ) {
       if( score > worst[cur] ) { return; }
       for(int i=0; i<K; ++i) {
         used[ path[i] ] = true;
       }
       return;
     }
 
     for(int i=0; i<count[cur]; ++i) {
       // used;
       if( next[cur][i][4] != 0 ) { continue; }
       next[cur][i][4] = 1;
       path[K] = next[cur][i][3];
       solve(next[cur][i][0], score + next[cur][i][1], worst, K + 1, path, next, count, used);
       next[cur][i][4] = 0;
     }
 
   }
 
   class State implements Comparable<State> {
 
     int pos;
     int score;
 
     State(int pos, int score) {
       this.pos = pos;
       this.score = score;
     }
 
     public int compareTo(State s) {
       if( score < s.score ) { return -1; }
       if( score > s.score ) { return 1; }
       return 0;
     }
 
   }
 
   void solve() {
 
     Scanner cin = new Scanner(System.in);
 
     int T = cin.nextInt();
     for(int C=1; C<=T; ++C) {
 
       int N = cin.nextInt();
       int M = cin.nextInt();
       int P = cin.nextInt();
 
       int arr[][] = new int[M][4];
       for(int i=0; i<M; ++i) {
         for(int j=0; j<4; ++j) {
           arr[i][j] = cin.nextInt();
           if( j < 2 ) { arr[i][j] -= 1; }
         }
       }
 
       int cand[] = new int[P];
       for(int i=0; i<P; ++i) {
         cand[i] = cin.nextInt();
       }
 
       int ret = solve(N, M, arr, P, cand);
 
       System.out.println("Case #" + C + ": " + (ret == -1 ? "Looks Good To Me" : ("" + ret)));
 
     }
 
   }
 
 }
