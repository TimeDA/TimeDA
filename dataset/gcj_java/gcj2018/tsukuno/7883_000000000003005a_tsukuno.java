import java.util.*;

public class Solution {

  public static void main(String args[]) {
    (new Solution()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {
    	
    	int row = cin.nextInt();
    	int col = cin.nextInt();
    	
    	int H = cin.nextInt();
    	int V = cin.nextInt();
    	
    	int countR[] = new int[row];
    	int countC[] = new int[col];
    	int total = 0;
    	
    	boolean map[][] = new boolean[row][col];
    	for( int i = 0; i < row; ++i ) {
    		String line = cin.next();
    		for( int j = 0; j < col; ++j ) {
    			if( line.charAt(j) == '@' ) { 
    				map[i][j] = true;
    				++total;
    				++countR[i];
    				++countC[j];
    			}
    		}
    	}
    	
    	boolean res = solve(row, col, H, V, countR, countC, total, map);

      System.out.println("Case #" + C + ": " + (res ? "POSSIBLE" : "IMPOSSIBLE"));

    }

    cin.close();

  }
  
  boolean solve(int R, int C, int H, int V, int countR[], int countC[], int total, boolean map[][]) {
  	
  	if( total % ((H + 1) * (V + 1)) != 0 ) {
  		return false;
  	}
  	
  	int cutR[] = new int[H + 2];
  	int cutC[] = new int[V + 2];
  	
  	cutR[H + 1] = R;
  	cutC[V + 1] = C;
  	
  	for( int i = 0; i < H; ++i ) {
  		int sum = 0;
  		int req = total / (H + 1);
  		for( int j = cutR[i]; j < R; ++j ) {
  			sum += countR[j];
  			if( sum == req ) {
  			  cutR[i + 1] = j + 1;
  			  break;
  			}
  			if( sum > req ) { return false; }
  		}
  	}
  	
  	for( int i = 0; i < V; ++i ) {
  		int sum = 0;
  		int req = total / (V + 1);
  		for( int j = cutC[i]; j < C; ++j ) {
  			sum += countC[j];
  			if( sum == req ) {
  				cutC[i + 1] = j + 1;
  				break;
  			}
  			if( sum > req ) { return false; }
  		}
  	}
  	
  	for( int i = 0; i <= H; ++i ) {
  		for( int j = 0; j <= V; ++j ) {
  			int count = 0;
  			int req = total / ((H + 1) * (V + 1));
  			for( int k = cutR[i]; k < cutR[i + 1]; ++k ) {
  				for( int l = cutC[j]; l < cutC[j + 1]; ++l ) {
  					if( map[k][l] ) { ++count; }
  				}
  			}
  			if( count != req ) { return false; }
  		}
  	}

  	return true;
  	
  }

}
