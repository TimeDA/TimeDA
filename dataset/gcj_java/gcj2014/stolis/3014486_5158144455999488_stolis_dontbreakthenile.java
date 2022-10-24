package round2;
 
 import java.awt.Point;
 import java.io.File;
 import java.io.PrintWriter;
 import java.util.ArrayList;
 import java.util.List;
 import java.util.Scanner;
 
 public class DontBreakTheNile {
     
     public static void main(String[] args) throws Exception {
         File inputFile = new File("C-small-attempt2.in");
         //File inputFile = new File("input.txt");
         Scanner in = new Scanner(inputFile);
         File outputFile = new File("output.txt");
         PrintWriter out = new PrintWriter(outputFile);
 
         int T = in.nextInt();
         for (int t=0; t<T; t++) {
             int W = in.nextInt();
             int H = in.nextInt();
             int B = in.nextInt();
             boolean[][] used = new boolean[W][H];
             for (int b=0; b<B; b++) {
                 int X0 = in.nextInt();
                 int Y0 = in.nextInt();
                 int X1 = in.nextInt();
                 int Y1 = in.nextInt();
                 for (int x=X0; x<=X1; x++) {
                     for (int y=Y0; y<=Y1; y++) {
                         used[x][y] = true;
                     }
                 }
             }
             Point[] directions = new Point[4];
             directions[0] = new Point(0,1);
             directions[1] = new Point(1,0);
             directions[2] = new Point(0,-1);
             directions[3] = new Point(-1,0);
             int flow = 0;
             for (int start=W-1; start>=0; start--) {
                 int lastX = start;
                 int lastY = 0;
                 int lastDirection = 0;
                 List<Point> visited = new ArrayList<Point>();
                 while (lastY<H-1 && !used[lastX][lastY]) {
                     visited.add(new Point(lastX, lastY));
                     lastDirection = (lastDirection+1)%4;
                     for (int dir=4; dir>0; dir--) {
                         int nextDir = (lastDirection+dir)%4;
                         int nextX = lastX+directions[nextDir].x;
                         int nextY = lastY+directions[nextDir].y;
                         if (nextX >= 0 && nextX < W && nextY >= 0 && nextY < H && !used[nextX][nextY]) {
                             lastX = nextX;
                             lastY = nextY;
                             lastDirection = nextDir;
                             break;
                         }
                     }
                     if (lastX == start && lastY == 0) {
                         break;
                     }
                 }
                 for (Point p : visited) {
                     used[p.x][p.y] = true;
                 }
                 if (lastY == H-1) {
                     flow++;
                 }
             }
 
             out.println("Case #"+(t+1)+": "+flow);
         }
 
         out.close();
     }
     
     static void print(boolean used[][]) {
         for (int w=0; w<used.length; w++) {
             for (int h=0; h<used[w].length; h++) {
                 System.out.print(used[w][h] ? "X" : ".");
             }
             System.out.println();
         }
         System.out.println();
     }
     
 }
