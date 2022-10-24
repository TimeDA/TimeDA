import java.util.*;

public class Solution {

  public static void main(String args[]) {
    (new Solution()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

    	double A = cin.nextDouble();
    	
    	double ans[][] = { { 0.5, 0.0, 0.0 },
    			           { 0.0, 0.5, 0.0 },
    			           { 0.0, 0.0, 0.5 } };
    	
    	double d = Math.asin(A / Math.sqrt(2.0)) + Math.PI / 4.0;
    	
    	double trans[][] = {
    			{ Math.sin(d), Math.cos(d), 0.0 },
    			{ -Math.cos(d), Math.sin(d), 0.0 },
    			{ 0.0, 0.0, 1.0 }
    	};
    	
    	double result[][] = multiply(ans, trans);
    	
      System.out.println("Case #" + C + ":");
      for(int i = 0; i < 3; ++i ) {
    	  for( int j = 0; j < 3; ++j ) {
    		  if( j > 0 ) { System.out.print(" "); }
    		  System.out.print(result[i][j]);
    	  }
		  System.out.println();
      }

    }

    cin.close();

  }
  
  double[][] multiply(double a[][], double b[][]) {
	  int N = a.length;
	  double c[][] = new double[N][N];
	  for( int i = 0; i < N; ++i ) {
		  for( int j = 0; j < N; ++j ) {
			  for( int k = 0; k < N; ++k ) {
				  c[i][j] += a[i][k] * b[k][j];
			  }
		  }
	  }
	  return c;
  }

}
