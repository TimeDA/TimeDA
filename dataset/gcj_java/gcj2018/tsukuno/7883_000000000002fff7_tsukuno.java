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
    	int P = cin.nextInt();
    	
    	int W[] = new int[N];
    	int H[] = new int[N];
    	int base[] = new int[N];
    	double range[] = new double[N];
    	
    	int sum = 0;
    	
    	for(int i = 0; i < N; ++i ) {
    		W[i] = cin.nextInt();
    		H[i] = cin.nextInt();
    		sum += W[i] * 2 + H[i] * 2;
    		base[i] = Math.min(W[i], H[i]) * 2;
    		range[i] = Math.sqrt(W[i] * W[i] + H[i] * H[i]) * 2.0 - base[i];
    	}
    	
      System.out.println("Case #" + C + ": " + solve(base, range, P, sum, N));

    }

    cin.close();

  }
  
  double solve(int base[], double range[], int P, int sum, int N) {
	  
	  int tmp = 0;
	  for( int i = 0; i < N; ++i ) {
		  tmp = Math.max(tmp, base[i]);
	  }
	  int max = tmp * N;
	  double dp[][] = new double[max + 1][N + 1];
	  for(int i = 0; i <= max; ++i ) {
		  for( int j = 0 ; j <= N; ++j ) {
			  dp[i][j] = -1;
		  }
	  }
	  dp[0][0] = 0;
	  
	  for( int i = 0; i < N; ++i ) {
		  for( int j = 0; j <= max; ++j ) {
			  if( dp[j][i] < 0 ) { continue; }
			  // not use;
			  dp[j][i + 1] = Math.max(dp[j][i + 1], dp[j][i]);
			  // use;
			  int k = j + base[i];
			  dp[k][i + 1] = Math.max(dp[k][i + 1], dp[j][i] + range[i]);
		  }
	  }
	  
	  double ans = sum;
	  
	  for( int i = 0 ; i <= max; ++i ) {
		  if( dp[i][N] < 0 ) { continue; }
		  double L = sum + i;
		  double R = sum + i + dp[i][N];
		  // clear;
		  if( L <= P && P <= R ) {
			  return P;
		  }
		  // not clear;
		  if( L <= P && Math.abs(P - L) < Math.abs(P - ans) ) {
			  ans = L;
		  }
		  if( R <= P && Math.abs(P - R) < Math.abs(P - ans) ) {
			  ans = R;
		  }
	  }
	  
	  return ans;
  }

}
