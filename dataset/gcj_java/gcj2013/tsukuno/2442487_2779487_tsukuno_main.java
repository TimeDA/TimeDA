import java.util.*;
 
 public class Main {
 
   public static void main(String args[]) {
     (new Main()).solve();
   }
 
   int[] solve(int N, int A[], int B[]) {
     int path[] = new int[N];
     if( !solve(N, A, B, path, 0, new boolean[N]) ) {
       throw new RuntimeException("not found");
     }
     return path;
   }
 
   boolean verify(int A[], int B[], int path[], int N) {
     for(int i=0; i<N; ++i) {
       int max = 1;
       for(int j=0; j<i; ++j) {
         if( path[i] > path[j] ) { max = Math.max(max, A[j] + 1); }
       }
       if( max != A[i] ) { return false; }
     }
     for(int i=0; i<N; ++i) {
       int max = 1;
       for(int j=i+1; j<N; ++j) {
         if( path[i] > path[j] ) { max = Math.max(max, B[j] + 1); }
       }
       if( max != B[i] ) { return false; }
     }
     return true;
   }
 
   boolean solve(int N, int A[], int B[], int path[], int cur, boolean used[]) {
 
     // finish;
     if( cur == N ) {
       return verify(A, B, path, N);
     }
 
     int skip = 1;
 
   MAIN:
     for(int i=0; i<N; ++i) {
       if( used[i] ) { continue; }
       if( skip < B[cur] ) {
         ++skip;
         continue;
       }
       int max = 1;
       for(int j=0; j<cur; ++j) {
         if( path[j] < i ) { max = Math.max(max, A[j] + 1); }
         if( path[j] > i && B[j] <= B[cur] ) { continue MAIN; }
       }
       if( max != A[cur] ) { continue; }
       path[cur] = i;
       used[i] = true;
       if( solve(N, A, B, path, cur + 1, used) ) { return true; }
       used[i] = false;
     }
 
     return false;
 
   }
 
   void solve() {
 
     // for(int i=0; i<100; ++i) { test(8); }
 
     Scanner cin = new Scanner(System.in);
 
     int T = cin.nextInt();
     for(int C=1; C<=T; ++C) {
 
       int N = cin.nextInt();
       int A[] = new int[N];
       for(int i=0; i<N; ++i) { A[i] = cin.nextInt(); }
       int B[] = new int[N];
       for(int i=0; i<N; ++i) { B[i] = cin.nextInt(); }
 
       int res[] = solve(N, A, B);
 
       System.out.print("Case #" + C + ":");
       for(int i=0; i<N; ++i) {
         System.out.print(" " + (res[i] + 1));
       }
       System.out.println();
 
     }
 
   }
 
   int[][] gen(int N) {
     int ret[] = new int[N];
     for(int i=0; i<N; ++i) { ret[i] = i + 1; }
     for(int i=N-1; i>0; --i) {
       int index = (int)(Math.random() * i);
       int tmp = ret[i];
       ret[i] = ret[index];
       ret[index] = tmp;
     }
     int A[] = new int[N];
     int B[] = new int[N];
     for(int i=0; i<N; ++i) {
       A[i] = 1;
       for(int j=0; j<i; ++j) {
         if( ret[i] > ret[j] ) { A[i] = Math.max(A[i], A[j] + 1); }
       }
     }
     for(int i=N-1; i>=0; --i) {
       B[i] = 1;
       for(int j=N-1; j>i; --j) {
         if( ret[i] > ret[j] ) { B[i] = Math.max(B[i], B[j] + 1); }
       }
     }
     return new int[][] { ret, A, B };
   }
 
   void test(int N) {
     int X[][] = gen(N);
     int res[] = solve(N, X[1], X[2]);
     if( compare(X[0], res, N) != 0 ) {
       for(int i=0; i<N; ++i) {
         System.err.print(X[0][i] + " ");
       }
       System.err.println();
       for(int i=0; i<N; ++i) {
         System.err.print(res[i] + " ");
       }
       System.err.println();
       for(int i=0; i<N; ++i) {
         System.err.print(X[1][i] + " ");
       }
       System.err.println();
       for(int i=0; i<N; ++i) {
         System.err.print(X[2][i] + " ");
       }
       System.err.println();
       throw new RuntimeException("not unique");
     }
   }
 
   int compare(int a[], int b[], int N) {
     for(int i=0; i<N; ++i) {
       if( a[i] == b[i] ) { continue; }
       return a[i] - b[i];
     }
     return 0;
   }
 
 }
