import java.util.*;

public class Solution {

  public static void main(String args[]) {
    (new Solution()).solve();
  }

  private static final String SMALL = "TOO_SMALL";
  private static final String BIG = "TOO_BIG";
  private static final String AC = "CORRECT";
  private static final String WA = "WRONG_ANSWER";
  
  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {
    	
    	int A = cin.nextInt();
    	int B = cin.nextInt();
    			
    	int N = cin.nextInt();
    	
    	while( true ) {
    		
    		System.out.println(((A + B) / 2));
    		System.out.flush();
    		
    		String res = cin.next();
    		
    		if( res.equals(AC) ) {
    			break;
    		}
    		if( res.equals(WA) ) { return; }
    		if( res.equals(BIG) ) {
    			B = ((A + B) / 2) - 1;
    		}
    		if( res.equals(SMALL) ) {
    			A = ((A + B) / 2) + 1;
    		}
    	}

//      System.out.println("Case #" + C + ": ");

    }

    cin.close();

  }

}
