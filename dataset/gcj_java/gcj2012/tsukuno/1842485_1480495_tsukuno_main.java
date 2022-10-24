import java.util.*;
 
 public class Main {
 
   public static void main(String args[]) {
     (new Main()).solve();
   }
 
   void solve(int h, int w, String map[]) {
 
     int n = 0;
 
     char arr[][] = new char[h][w];
     for(int i=0; i<h; ++i) {
       for(int j=0; j<w; ++j) {
         arr[i][j] = map[i].charAt(j);
         if( '0' <= arr[i][j] && arr[i][j] <= '9' ) {
           n = Math.max(n, arr[i][j] - '0' + 1);
         }
       }
     }
 
     int count = 0;
     for(int k=0; k<n; ++k) {
       for(int i=0; i<h; ++i) {
         for(int j=0; j<w; ++j) {
           if( arr[i][j] == ('0' + k) ) {
             System.out.print(k + ": ");
             solve(arr, i, j, h, w);
           }
         }
       }
     }
 
   }
 
   int dx[] = { 1, 0, -1 };
   int dy[] = { 0, -1, 0 };
 
   void solve(char arr[][], int y, int x, int h, int w) {
 
     boolean vis[][] = new boolean[h][w];
     List<int[]> queue = new ArrayList<int[]>();
 
     vis[y][x] = true;
     queue.add(new int[] { y, x });
 
     for(int i=0; i<queue.size(); ++i) {
       int p[] = queue.get(i);
       for(int j=0; j<3; ++j) {
         int py = p[0] + dy[j];
         int px = p[1] + dx[j];
         if( px < 0 || py < 0 || px >= w || py >= h || arr[py][px] == '#' || vis[py][px] ) { continue; }
         vis[py][px] = true;
         queue.add(new int[] { py, px });
       }
     }
 
     // do not fail
     boolean L[] = new boolean[w];
     boolean R[] = new boolean[w];
 
     int count = 0;
     for(int i=0; i<w; ++i) {
       if( vis[y][i] ) { ++count; }
     }
 
     int used = 0;
     for(int i=0; i<w; ++i) {
       boolean not = (y + 1 >= h ? false : arr[y + 1][i] == '#');
       if( vis[y][i] ) {
         L[used++] = not;
         R[count - used] = not;
       }
     }
 
     for(int i=count; i<w; ++i) {
       L[i] = L[i - 1];
       R[i] = R[i - 1];
     }
 
     boolean check = false;
 
     for(int i=0; i<y; ++i) {
       for(int j=0; j<w; ++j) {
         if( !vis[i][j] || (j > 0 && vis[i][j - 1]) ) { continue; }
         check = true;
         int k = j + 1;
         while( k < w && vis[i][k] ) { ++k; }
         int cand = k - j;
         boolean ok = false;
         boolean LL = true;
         boolean RR = true;
         for(int v=j; v<k; ++v) {
           // cannot fall
           if( !vis[i+1][v] ) {
             L[v - j] = false;
             if( v == j ) { LL = false; }
             R[k - v - 1] = false;
             if( k == (v + 1) ) { RR = false; }
           }
         }
         for(int C=cand; C<w; ++C) {
           L[C] &= LL;
           R[C] &= RR;
         }
       }
     }
 
     boolean lucky = false;
     if( check ) {
       for(int i=0; i<w; ++i) {
         if( L[i] || R[i] ) { lucky = true; }
       }
     }
     else { lucky = true; }
 
     System.out.println(queue.size() + " " + (lucky ? "Lucky" : "Unlucky"));
 
   }
 
   void solve() {
 
     Scanner cin = new Scanner(System.in);
 
     int T = cin.nextInt();
     for(int C=1; C<=T; ++C) {
 
       int h = cin.nextInt();
       int w = cin.nextInt();
       String map[] = new String[h];
       for(int i=0; i<h; ++i) {
         map[i] = cin.next();
       }
 
       System.out.println("Case #" + C + ":");
       solve(h, w, map);
 
     }
 
   }
 
 }
