import java.util.*;

public class Solution {

  public static void main(String args[]) {
    (new Solution()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

    	int robots = cin.nextInt();
    	int bits = cin.nextInt();
    	int cashers = cin.nextInt();
    	int cspec[][] = new int[cashers][3];
    	
    	for( int i = 0; i < cashers; ++i ) {
    		for( int j = 0; j < 3; ++j ) {
    			cspec[i][j] = cin.nextInt();
    		}
    	}
    	
      System.out.println("Case #" + C + ": " + solve(robots, bits, cashers, cspec));

    }

    cin.close();

  }
  
  long solve(int robots, int bits, int cashers, int cspec[][]) {
	  
	  long INF = 2000L * 1000L * 1000L * 1000L * 1000L * 1000L;
	  long HIGH = INF;
	  long LOW = 0;
	  
	  for( int i = 0; i < 100; ++i ) {
		  long time = (HIGH + LOW) / 2;
		  List<Long> can = new ArrayList<Long>();
		  for( int j = 0; j < cashers; ++j ) {
			  long token = (time - cspec[j][2]) / cspec[j][1];
			  token = Math.max(token, 0);
			  token = Math.min(token, cspec[j][0]);
			  can.add(token);
		  }
		  Collections.sort(can);
		  long cand = 0;
		  for( int j = 0; j < robots; ++j ) {
			  if( j >= can.size() ) { break; }
			  cand += can.get(can.size() - j - 1);
		  }
		  if( cand >= bits) {
			  HIGH = time;
		  }
		  else {
			  LOW = time;
		  }
	  }
	  
	  return HIGH;
	  
  }

}
