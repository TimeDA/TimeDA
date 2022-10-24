import java.util.*;
 
 public class Main {
 
   public static void main(String args[]) {
     (new Main()).solve();
   }
 
   void test() {
     System.out.println(100);
     for(int j=0; j<100; ++j) {
       System.out.println(10000 + " " + 700);
       for(int i=0; i<10000; ++i) { System.out.print((int)(700) + " "); }
       System.out.println();
     }
   }
 
   void solve() {
 
     Scanner cin = new Scanner(System.in);
 
     int T = cin.nextInt();
     for(int C=1; C<=T; ++C) {
 
       int N = cin.nextInt();
       int X = cin.nextInt();
       int arr[] = new int[N];
       for(int i=0; i<N; ++i) { arr[i] = cin.nextInt(); }
 
       System.out.println("Case #" + C + ": " + solve(arr, N, X));
 
     }
 
   }
 
   int solve(int arr[], int N, int X) {
 
     Arrays.sort(arr);
     boolean used[] = new boolean[N];
 
     int ret = 0;
     for(int i=N-1; i>=0; --i) {
       if( used[i] ) { continue; }
       ++ret;
       for(int j=i-1; j>=0; --j) {
         if( used[j] ) { continue; }
         if( arr[i] + arr[j] <= X ) {
           used[j] = true;
           break;
         }
       }
     }
 
     return ret;
 
   }
 
 }
