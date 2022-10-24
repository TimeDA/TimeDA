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
    	List<Integer> even = new ArrayList<Integer>();
    	List<Integer> odd = new ArrayList<Integer>();
    	for( int i = 0; i < N; ++i ) {
    		if( (i % 2) == 0 ) { even.add(cin.nextInt()); }
    		else { odd.add(cin.nextInt()); }
    	}
    	
    	Collections.sort(even);
    	Collections.sort(odd);

    	int result = -1;
    	
    	for(int i = 0; i < N - 1; ++i ) {
    		if( (i % 2 == 0 ) ) {
    			if( even.get(i / 2) > odd.get(i / 2) ) {
    				result = i;
    				break;
   				}
    		}
    		else {
    			if( odd.get(i / 2) > even.get((i + 1) / 2) ) {
    				result = i;
    				break;
    			}
    		}
    	}
    	
      System.out.println("Case #" + C + ": " + (result == -1 ? "OK" : ("" + result)));

    }

    cin.close();

  }

}
