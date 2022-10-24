import java.util.*;

public class Solution {

  public static void main(String args[]) {
    (new Solution()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

    	int D = cin.nextInt();
    	String com = cin.next();
    	
    	int res = solve(com, D);
    	
      System.out.println("Case #" + C + ": " + (res == -1 ? "IMPOSSIBLE" : ("" + res)));

    }

    cin.close();

  }
  
  int solve(String s, int D) {
	  
	  int trial = 0;
	  while( score(s) > D ) {

		  s = modify(s);
		  if( s == null ) { return -1; }
		  ++trial;
	  }
	  
	 return trial; 
  }
  
  int score(String s) {
	  int N = s.length();
	  int total = 0;
	  int cur = 1;
	  for( int i = 0; i < N; ++i) {
		  if( s.charAt(i) == 'S' ) {
			  total += cur;
		  }
		  else {
			  cur <<= 1;
		  }
	  }
	  return total;
  }
  
  String modify(String s) {
	  int N = s.length();
	  for( int i = N - 1; i >= 1; --i ) {
		  if( s.charAt(i) == 'S' && s.charAt(i - 1) == 'C' ) {
			  return s.substring(0, i - 1) + "SC" + s.substring(i + 1);
		  }
	  }
	  return null;
  }

}
