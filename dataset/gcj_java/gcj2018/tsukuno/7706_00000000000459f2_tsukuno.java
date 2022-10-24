import java.util.*;

public class Solution {

  public static void main(String args[]) {
    (new Solution()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {
    	
    	int Line = cin.nextInt();
    	int array[] = new int[Line];
    	for(int i = 0; i < Line; ++i) {
    		array[i] = cin.nextInt();
    	}
    	
    	String result[] = solve(Line, array);

      System.out.println("Case #" + C + ": " + result[0]);
      for( int i = 1; i < result.length; ++i ) {
    	  System.out.println(result[i]);
      }

    }

    cin.close();

  }
  
  String[] solve(int N, int array[]) {
	  int sum = 0;
	  for( int v : array ) {
		  sum += v;
	  }
	  if( sum != N || array[0] == 0 || array[N - 1] == 0 ) { return new String[] { "IMPOSSIBLE" }; }
	  char map[][] = new char[N + 1][N];
	  for( int i = 0; i <= N; ++i ) {
		  for( int j = 0; j < N; ++j ) {
			  map[i][j] = '.';
		  }
	  }
	  int start = 0;
	  for( int i = 0; i < N; ++i ) {
		  if( array[i] == 0 ) { continue; }
		  move(start, array[i], i, map);
		  start += array[i];
	  }
	  int res = N;
	  while( res > 0 ) {
		  boolean empty = true;
		  for( int i = 0; i < N; ++i ) {
			  if( map[res - 1][i] != '.' ) {
				  empty = false;
				  break;
			  }
		  }
		  if( empty ) { --res; }
		  else { break; }
	  }
	  String result[] = new String[res + 2];
	  result[0] = "" + (res + 1);
	  for( int i = 0; i <= res; ++i ) {
		  result[i + 1] = "";
		  for( int j = 0; j < N; ++j ) {
			  result[i + 1] += map[i][j];
		  }
	  }
	  return result;
  }
  
  void move(int L, int N, int pos, char map[][]) {
	  for( int i = 0; i < N; ++i ) {
		  // move right;
		  if( i + L < pos ) {
			  for( int j = i + L, k = 0; j < pos; ++j, ++k ) {
				  map[k][j] = '\\';
			  }
		  }
		  
		  // move left
		  if( i + L > pos ) {
			  for( int j = i + L, k = 0; j > pos; --j, ++k ) {
				  map[k][j] = '/';
			  }
		  }
	  }
  }

}
