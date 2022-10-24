import java.util.*;

public class Solution {

  public static void main(String args[]) {
    (new Solution()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

    	double D = cin.nextInt();
    	int N = cin.nextInt();
    	
    	double req = 0.0;
    	
    	for( int i = 0; i < N; ++i ) {
    		int cur = cin.nextInt();
    		int speed = cin.nextInt();
    		req = Math.max(req, (D - cur) / speed);
    	}
    	
      System.out.println("Case #" + C + ": " + (D / req));

    }

    cin.close();

  }

}
