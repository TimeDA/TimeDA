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
    	int arr[] = new int[N];
    	int sum = 0;
    	for(int i = 0; i < N; ++i ) {
    		arr[i] = cin.nextInt();
    		sum += arr[i];
    	}
    	
    	List<String> result = new ArrayList<String>();
    	
    	int rest = N;
    	while( sum > 0 ) {
    		int index = findMin(arr, N);
    		arr[index] -= 1;
    		sum -= 1;
    		String ans = "" + (char)('A' + index);
    		if( sum != 2 ) {
    			int index2 = findMin(arr, N);
    			arr[index2] -= 1;
    			sum -= 1;
        		ans += "" + (char)('A' + index2);
    		}
    		result.add(ans);
    	}

      System.out.print("Case #" + C + ":");
      for( String s : result ) {
    	  System.out.print(" " + s);
      }
      System.out.println();

    }

    cin.close();

  }
  
  int findMin(int arr[], int N) {
	  int ret = -1;
	  int val = -1;
	  for( int i = 0; i < N; ++i ) {
		  if( arr[i] == 0 ) { continue; }
		  if( arr[i] > val ) {
			  val = arr[i];
			  ret = i;
		  }
	  }
	  return ret;
  }

}
