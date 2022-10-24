import java.util.*;

public class Solution {

  public static void main(String args[]) {
    (new Solution()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {
    	
    	int N = cin.nextInt();
    	int array[][] = new int[N][N];
    	
    	for( int i = 0; i < N; ++i ) {
    		for(int j = 0; j < N; ++j ) {
    			array[i][j] = cin.nextInt();
    		}
    	}

      System.out.println("Case #" + C + ": " + solve(array, N));

    }

    cin.close();

  }
  
  int solve( int array[][], int N) {
	  
	  int sum = 0;
	  for( int i = 1; i <= N; ++i ) {
		  sum += solve(array, N, i) + solve(array, N, -i);
	  }
	
	  return sum;
  }
  
  int solve(int array[][], int N, int target) {
	  
	  // N * N;
	  // N * 2;
	  // 2
	  
	  int S = N * N + N + N;
	  int T = S + 1;
	  int K = T + 1;

	    List<List<int[]>> graph = new ArrayList<List<int[]>>();
	    for(int i=0; i<K; ++i) {
	      graph.add( new ArrayList<int[]>() );
	    }

	  for(int i = 0; i < N; ++i ) {
		  int SS = N * N + i;
		  set(graph, S, SS, 1, 0);
		  int TT = SS + N;
		  set(graph, TT, T, 1, 0);
	  }
	  
	  int sum = 0;
	  
	  for(int i = 0; i < N; ++i ) {
		  for(int j = 0; j < N; ++j ) {
			  if( array[i][j] != target ) { continue; }
			  boolean conf = false;
			  // row;
			  for(int k = 0; k < N; ++k ) {
				  if( k == i ) { continue; }
				  if( array[i][j] == array[k][j] ) {
					  conf = true;
					  break;
				  }
			  }
			  // col;
			  for( int k = 0; k < N; ++k ) {
				  if( k == j ) { continue; }
				  if( array[i][j] == array[i][k] ) {
					  conf = true;
					  break;
				  }
			  }
			  if( conf == false ) { continue; }
			  ++sum;
			  set(graph, N * N + i, i * N + j, 1, 0);
			  set(graph, i * N + j, N * N + N + j, 1, 0);
		  }
	  }
	  
	    MincostSparseFlow flow = new MincostSparseFlow();
	    List<Map<Integer, Integer>> used = new ArrayList<Map<Integer, Integer>>();
	    for(int i=0; i<K; ++i) { used.add( new HashMap<Integer, Integer>() ); }
	    int res[] = flow.minCostFlow(S, T, K, graph, used);
	    return sum - res[1];

  }

  /* usage
  List<List<int[]>> graph = new ArrayList<List<int[]>>();
  for(int i=0; i<N; ++i) {
    graph.add( new ArrayList<int[]>() );
  }

  MincostSparseFlow flow = new MincostSparseFlow();
  List<Map<Integer, Integer>> used = new ArrayList<Map<Integer, Integer>>();
  for(int i=0; i<N; ++i) { used.add( new HashMap<Integer, Integer>() ); }
  int res[] = flow.minCostFlow(S, T, N, graph, used, req);
*/

void set(List<List<int[]>> graph, int F, int T, int flow, int cost) {
graph.get(F).add(new int[] { T, flow, cost });
}

class MincostSparseFlow {

private int INF = 1000000;

private List<Map<Integer, int[]>> revEdge;

void initRev(int n, List<List<int[]>> graph) {
  revEdge = new ArrayList<Map<Integer, int[]>>();
  for(int i=0; i<n; ++i) {
    revEdge.add( new HashMap<Integer, int[]>() );
  }
  for(int i=0; i<n; ++i) {
    for( int cur[] : graph.get(i) ) {
      revEdge.get(cur[0]).put(i, cur);
    }
  }
}

int[] get(int F, int T) {
  return revEdge.get(T).get(F);
}

int get(List<Map<Integer, Integer>> used, int F, int T) {
  Map<Integer, Integer> map = used.get(F);
  return map.containsKey(T) ? map.get(T) : 0;
}

void set(List<Map<Integer, Integer>> used, int F, int T, int val) {
  used.get(F).put(T, val);
}

int[] minCostFlow(int S, int T, int n, List<List<int[]>> graph, List<Map<Integer, Integer>> used) {
  return minCostFlow(S, T, n, graph, used, INF);
}

// S -> T;
// req : expected flow;
// @return minimal cost (+ total flow : if total flow is unknown (req == INF));
// @return null if flow < req (req != INF);
int[] minCostFlow(int S, int T, int n, List<List<int[]>> graph, List<Map<Integer, Integer>> used, int req) {

  boolean full = (req == INF);

  initRev(n, graph);

  int sum = 0;
  int potential[] = new int[n];

  while( req > 0 ) {

    int res[] = flow(S, T, n, graph, used, potential);
    if( res == null ) {
      return full ? new int[] { sum, INF - req } : null;
    }

    int flow = Math.min(res[0], req);
    sum += flow * res[1];
    req -= flow;

  }

  return new int[] { sum };

}

int[] flow(int S, int T, int n, List<List<int[]>> graph, List<Map<Integer, Integer>> used, int potential[]) {

  int minValue[] = new int[n];
  for(int i=0; i<n; ++i) { minValue[i] = -1; }
  minValue[S] = 0;

  boolean check[] = new boolean[n];

  java.util.PriorityQueue<State> queue = new java.util.PriorityQueue<State>();
  queue.add(new State(S, potential[S], null, INF));

  State end = null;

  while( !queue.isEmpty() ) {

    State s = queue.poll();

    if( check[s.pos] ) { continue; }
    check[s.pos] = true;

    // flow ok;
    if( s.pos == T ) { end = s; }

    for( int to : revEdge.get(s.pos).keySet() ) {
      int revU = get(used, to, s.pos);
      if( revU > 0 ) {
        int next = s.score - get(to, s.pos)[2] + potential[s.pos] - potential[to];
        if( minValue[to] == -1 || minValue[to] > next ) {
          minValue[to] = next;
          queue.add(new State(to, next, s, Math.min(s.flow, revU)));
        }
      }
    }

    for( int cur[] : graph.get(s.pos) ) {
      int to = cur[0];
      int gain = cur[1] - get(used, s.pos, to);
      if( gain > 0 ) {
        int next = s.score + cur[2] + potential[s.pos] - potential[to];
        if( minValue[to] == -1 || minValue[to] > next ) {
          minValue[to] = next;
          queue.add(new State(to, next, s, Math.min(s.flow, gain)));
        }
      }
    }

  }

  if( end == null ) { return null; }

  State s = end;
  int gain = s.flow;
  int score = s.score + potential[s.pos];

  // push actual flow;
  while( true ) {
    State t = s.prev;
    if( t == null ) { break; }
    int revU = get(used, s.pos, t.pos);
    if( revU >= gain ) {
      set(used, s.pos, t.pos, revU - gain);
    }
    else {
      int U = get(used, t.pos, s.pos);
      if( get(t.pos, s.pos)[1] >= U + gain ) {
        set(used, t.pos, s.pos, U + gain);
      }
    }
    s = t;
  }

  // update potential;
  for(int i=0; i<n; ++i) {
    if( minValue[i] == -1 ) { continue; }
    potential[i] += minValue[i];
  }

  return new int[] { gain, score };

}

class State implements Comparable<State> {

  int pos;
  int score;
  State prev;
  int flow;

  State(int pos, int score, State prev, int flow) {
    this.pos = pos;
    this.score = score;
    this.prev = prev;
    this.flow = flow;
  }

  public int compareTo(State s) {
    return score - s.score;
  }

}

}

  
}
