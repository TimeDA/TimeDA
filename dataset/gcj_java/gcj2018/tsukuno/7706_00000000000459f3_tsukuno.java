import java.util.*;

public class Solution {

  public static void main(String args[]) {
    (new Solution()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {
    	
    	int R = cin.nextInt();
    	int B = cin.nextInt();

      System.out.println("Case #" + C + ": " + solve(R, B));

    }

    cin.close();

  }
  
  int solve(int R, int B) {
	  
	  if( R < B ) {
		  return solve(B, R);
	  }
	  
	  // assert (R >= B);
	  
	  int useMax = Math.min(R, 40);
	  // used R * min used B * checked R;
	  int dp[][][] = new int[R + 1][B + 1][useMax + 1];
	  for( int i = 0; i <= R; ++i ) {
		  for( int j = 0; j <= B; ++j ) {
			  for(int k = 0; k <= useMax; ++k ) {
				  dp[i][j][k] = -1;
			  }
		  }
	  }
	  
	  int ret = 1;

	  dp[0][0][0] = 0;
	  for( int curR = 0; curR <= useMax; ++curR ) {
		  for(int usedR = 0; usedR <= R - curR; ++usedR ) {
			  for(int usedB = 0; usedB <= B; ++usedB ) {
				  if( dp[usedR][usedB][curR] == -1 ) { continue; }
				  if( curR == useMax ) {
					  ret = Math.max(ret, dp[usedR][usedB][curR] + 1);
					  continue;
				  }
				  // skip curR;
				  dp[usedR][usedB][curR + 1] = Math.max(dp[usedR][usedB][curR + 1], dp[usedR][usedB][curR]);
				  ret = Math.max(ret, dp[usedR][usedB][curR + 1]);
				  int curB = 0;
				  if( curR == 0 ) { ++curB; }
				  int totalB = 0;
				  for( int k = 1; ; ++k ) {
					  if( usedB + totalB + curB > B ) { break; }
					  if( usedR + curR * k > R ) { break; }
					  totalB += curB;
					  dp[usedR + curR * k][usedB + totalB][curR + 1] = Math.max(dp[usedR + curR * k][usedB + totalB][curR + 1], dp[usedR][usedB][curR] + k);
					  ret = Math.max(ret, dp[usedR + curR * k][usedB + totalB][curR + 1]);
					  ++curB;
				  }
			  }
		  }
	  }

	  return ret;
	  
  }

}
