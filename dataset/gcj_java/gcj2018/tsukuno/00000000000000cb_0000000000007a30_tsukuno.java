import java.util.*;

public class Solution {

  public static void main(String args[]) {
    (new Solution()).solve();
  }
  
//  private int ans = 0;

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {
    	
    	int A = cin.nextInt();
    	
    	// in case 3 * N map;
    	int H = 3;
    	int W = (A + 2) / 3;
    	boolean fill[][] = new boolean[H][W];
    	int rest[][] = new int[H -2][W - 2];
    	for( int i = 0; i < H - 2; ++i ) {
    		for( int j = 0; j < W - 2; ++j ) {
    			rest[i][j] = 9;
    		}
    	}
    	
    	// at first fill upper-left cell;
    	send(3, 3);
    	int res[] = recv(cin);
    	int bH = res[0];
    	int bW = res[1];
    	process(fill, rest, res, bH, bW, H - 2, W - 2);
    	while( true ) {
    		// guess;
   		
    		// fill max rest;
    		int cand[] = findMax(rest, H - 2, W - 2);
    		send(cand[0] + bH + 1, cand[1] + bW + 1);
    		
    		res = recv(cin);
    		if( res[0] == 0 && res[1] == 0 ) {
    			break;
    		}
    		process(fill, rest, res, bH, bW, H - 2, W - 2);
    	}

    }

    cin.close();

  }
  
  int[] findMax(int rest[][], int H, int W) {
	  int X = -1;
	  int Y = -1;
	  int score = 0;
	  for( int i = 0; i < H; ++i ) {
		  for( int j = 0; j < W; ++j ) {
			  if( rest[i][j] > score ) {
				  score = rest[i][j];
				  X = i;
				  Y = j;
			  }
		  }
	  }
	  return new int[] { X, Y };
  }
  
  void process(boolean fill[][], int rest[][], int pos[], int bH, int bW, int H, int W) {
	  int X = pos[0] - bH;
	  int Y = pos[1] - bW;
	  if( fill[X][Y] ) { return; }
	  fill[X][Y] = true;
	  for( int i = X - 2; i <= X; ++i ) {
		  if( i < 0 || i >= H ) { continue; }
		  for( int j = Y - 2; j <= Y; ++j ) {
			  if( j < 0 || j >= W ) { continue; }
			  --rest[i][j];
		  }
	  }
  }
  
  void send(int X, int Y) {
	  System.out.println(X + " " + Y);
	  System.out.flush();
//	  ++ans;
  }
  
  int[] recv(Scanner cin) {
	  int res[] = new int[2];
	  res[0] = cin.nextInt();
	  res[1] = cin.nextInt();
	  // Wrong Answer;
	  if( res[0] == -1 && res[1] == -1 ) {
		  System.exit(0);
	  }
	  // solved;
	  if( res[0] == 0 && res[1] == 0 ) {
//		  System.err.println("solved with " + ans + " guesses");
//		  System.err.flush();
//		  ans = 0;
	  }
	  return res;
  }

}
