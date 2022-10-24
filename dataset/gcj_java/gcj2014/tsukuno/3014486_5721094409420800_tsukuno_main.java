import java.util.*;
 
 public class Main {
 
   public static void main(String args[]) {
     (new Main()).solve();
   }
 
   void solve() {
 
     Scanner cin = new Scanner(System.in);
 
     int T = cin.nextInt();
     for(int C=1; C<=T; ++C) {
 
       int N = cin.nextInt();
       int arr[] = new int[N];
       for(int i=0; i<N; ++i) {
         arr[i] = cin.nextInt();
       }
 
       System.out.println("Case #" + C + ": " + solve(arr, N));
 
     }
 
   }
 
   int solve(int arr[], int N) {
 
     int L = 0;
     int R = N - 1;
 
     int ret = 0;
 
     while( L < R ) {
       int cur = minIndex(arr, L, R);
       if( cur - L <= R - cur ) {
         ret += cur - L;
         int tmp = arr[cur];
         for(int i=cur; i>L; --i) {
           arr[i] = arr[i - 1];
         }
         arr[L] = tmp;
         ++L;
       }
       else {
         ret += R - cur;
         int tmp = arr[cur];
         for(int i=cur; i<R; ++i) {
           arr[i] = arr[i + 1];
         }
         arr[R] = tmp;
         --R;
       }
     }
 
     return ret;
 
   }
 
   int minIndex(int arr[], int L, int R) {
     int index = -1;
     int value = Integer.MAX_VALUE;
     for(int i=L; i<=R; ++i) {
       if( arr[i] < value ) {
         index = i;
         value = arr[i];
       }
     }
     if( index == -1 ) { throw new RuntimeException(L + " " + R); }
     return index;
   }
 
 }
