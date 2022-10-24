package gcj2017.r2;
 
 import java.util.*;
 
 public class C {
     private static final int[] di = {-1, 0, 1, 0};
     private static final int[] dj = {0, -1, 0, 1};
 
     int R, C;
     char[][] map;
 
     // parse
     public C(final Scanner sc) {
         R = sc.nextInt();
         C = sc.nextInt();
         map = new char[R][];
         for (int i = 0; i < R; i++)
             map[i] = sc.next().toCharArray();
     }
 
     // /
     int mirror1(int d) {
         switch (d) {
             case 0:
                 return 3;
             case 1:
                 return 2;
             case 2:
                 return 1;
             case 3:
                 return 0;
             default:
                 throw null;
         }
     }
 
     // \
     int mirror2(int d) {
         switch (d) {
             case 0:
                 return 1;
             case 1:
                 return 0;
             case 2:
                 return 3;
             case 3:
                 return 2;
             default:
                 throw null;
         }
     }
 
     // solve
     @Override
     public String toString() {
         loop:
         for (int mask = 0; mask < 1 << R * C; mask++) {
             for (int i = 0; i < R; i++)
                 for (int j = 0; j < C; j++) {
                     switch (map[i][j]) {
                         case '|':
                         case '-':
                             map[i][j] = (mask & 1 << i * C + j) > 0 ? '|' : '-';
                             break;
                         default:
                             if ((mask & 1 << i * C + j) > 0)
                                 continue loop;
                     }
                 }
             StringBuilder sb = new StringBuilder("POSSIBLE");
             for(final char[] line : map)
                 sb.append('\n').append(line);
             debug(sb);
             if (validate()) {
 //                StringBuilder sb = new StringBuilder("POSSIBLE");
 //                for(final char[] line : map)
 //                    sb.append('\n').append(line);
                 return sb.toString();
             }
         }
         return "IMPOSSIBLE";
     }
 
     boolean validate() {
         final boolean[][][] visited = new boolean[R][C][4];
         final Queue<Integer> que = new ArrayDeque<>();
         for(int i = 0; i < R; i++)
             for(int j = 0; j < C; j++)
                 if(map[i][j] == '-') {
                     que.offer((i * C + j) * 4 + 1);
                     que.offer((i * C + j) * 4 + 3);
                     visited[i][j][1] = visited[i][j][3] = true;
                 } else if(map[i][j] == '|') {
                     que.offer((i * C + j) * 4);
                     que.offer((i * C + j) * 4 + 2);
                     visited[i][j][0] = visited[i][j][2] = true;
                 }
         while(!que.isEmpty()) {
             final int s = que.poll();
             int d = s % 4;
             int i = s / 4 / C + di[d];
             int j = s / 4 % C + dj[d];
             if(0 <= i && i < R && 0 <= j && j < C) {
                 switch (map[i][j]) {
                     case '/':
                         d = mirror1(d);
                         break;
                     case '\\':
                         d = mirror2(d);
                         break;
                     case '|':
                     case '-':
                         return false;
                     case '#':
                         continue;
                     case '.':
                         break;
                     default:
                         throw null;
                 }
                 if(visited[i][j][d])
                     continue;
                 visited[i][j][d] = true;
                 que.offer((i * C + j) * 4 + d);
             }
         }
         for(int i = 0; i < R; i++)
             for(int j = 0; j < C; j++)
                 if(map[i][j] == '.') {
                     boolean f = false;
                     for(int k = 0; k < 4; k++)
                         f |= visited[i][j][k];
                     if(!f)
                         return false;
                 }
 
         return true;
     }
 
     // Template
     public static void main(String... args) throws Exception {
         try (final Scanner sc = new Scanner(System.in)) {
             final int T = sc.nextInt();
             final Object[] solvers = new Object[T];
             for (int i = 0; i < T; i++)
                 solvers[i] = new C(sc);
             final Iterator<String> results = Arrays.stream(solvers)
                     .map(Object::toString)
                     .iterator();
             for (int i = 1; i <= T; i++)
                 System.out.printf("Case #%s: %s\n", i, results.next());
         }
     }
 
     private static void debug(Object... os) {
         System.err.println(Arrays.deepToString(os));
     }
 }
