package c2014_c.c2014_round2;
 
 import java.io.BufferedWriter;
 import java.io.File;
 import java.io.FileWriter;
 import java.util.*;
 
 public class Z2_1 {
 
     public static void main(String[] args) throws Exception {
         FileWriter fw = new FileWriter("C:\\output.txt");
         BufferedWriter out = new BufferedWriter(fw);
         //String pathname = "C:\\Users\\YC14rp1\\Downloads\\z2.txt";
         String pathname = "C:\\Users\\YC14rp1\\Downloads\\B-small-attempt1.in";
         //String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-large.in";
         Scanner scanner = new Scanner(new File(pathname));
         int tn = scanner.nextInt();
         scanner.nextLine();
         for (int ti = 1; ti <= tn; ti++) {
             int n = scanner.nextInt();
             List<Integer> l = new ArrayList<Integer>(n);
             Integer mx = Integer.MIN_VALUE;
             int imx = -1;
             for (int i=0;i<n;i++) {
                 int e = scanner.nextInt();
                 l.add(e);
                 if (e>mx) {
                     mx = e;
                     imx = i;
                 }
            }
 
             boolean flag = false;
             int cnt = 0;
             int prev_cnt = 0;
             while (!flag) {
                 int c = 0;
                 while (c<n-1 && l.get(c)<l.get(c+1)) {
                     c++;
                 }
                 if (c==n) {
                     flag = true;
                     continue;
                 }
                 int c1 = n-1;
                 while (c1>imx && l.get(c1)<l.get(c1-1)) {
                     c1--;
                 }
                 if ((c==imx) && (c1==imx)) {
                     flag = true;
                     continue;
                 }
                 int mi = Integer.MAX_VALUE;
                 int imi = -1;
                 for (int i=c;i<=c1;i++) {
                     if (l.get(i)<mi) {
                         mi = l.get(i);
                         imi = i;
                     }
                 }
                 int i_left = 0;
                 while (l.get(i_left)<mi) {
                     i_left++;
                 }
                 int i_right = n-1;
                 while (l.get(i_right)<mi) {
                     i_right--;
                 }
                 if (imi-i_left<i_right-imi) {
                     for (int i=imi;i>i_left;i--) {
                         l.set(i,l.get(i-1));
                         if (l.get(i).equals(mx)) {
                             imx = i;
                         }
                     }
                     l.set(i_left,mi);
                     cnt+=imi-i_left;
                 } else {
                     for (int i=imi;i<i_right;i++) {
                         l.set(i,l.get(i+1));
                         if (l.get(i).equals(mx)) {
                             imx = i;
                         }
                     }
                     l.set(i_right,mi);
                     cnt+=i_right-imi;
                 }
                 //System.out.println(l);
                 //if (cnt==prev_cnt) {
                 //    throw new IllegalArgumentException();
                 //}
                 prev_cnt = cnt;
             }
             String s;
             s = "Case #" + ti + ": "+cnt;
             System.out.println(s);
             out.write(s);
             out.write("\n");
         }
         out.close();
     }
 
     private static int[][] read2DArray(Scanner scanner, int n, int m) {
         int [][]m1 = new int[n][m];
         for (int i=0;i<n;i++) {
             for (int j=0;j<m;j++) {
                 m1[i][j] = scanner.nextInt();
             }
         }
         return m1;
     }
 
     // 1 0 1 -> [1,0,1]
     private static List<Integer> readIntList(Scanner scanner, int n) {
         List<Integer> l = new ArrayList<Integer>(n);
         for (int i=0;i<n;i++) {
             l.add( scanner.nextInt());
         }
         return l;
     }
 
     // 1 2/ 2 3 -> [[0 1 0],[1 0 1],[0 1 0]]
     private static void readGraphAsMatrix(Scanner scanner, int n, int[][] matrix) {
         for (int i=0;i<n-1;i++) {
             int x = scanner.nextInt();
             int y = scanner.nextInt();
             matrix[x-1][y-1] = 1;
             matrix[y-1][x-1] = 1;
         }
     }
 
     // sdf ssf ggg -> [3]
     private static String[] readArray(Scanner scanner, int n) {
         String[] l2 = new String[n];
         for (int i=0;i<n;i++) {
             l2[i] = scanner.next();
         }
         return l2;
     }
 
     // 1 2 3 4 5 - > (1,2,3,4,5)
     private static HashSet<String> readSet(Scanner scanner, int n) {
         String[] l1 = new String[n];
         HashSet<String> set1 = new HashSet<String>();
         for (int i=0;i<n;i++) {
             l1[i] = scanner.next();
             set1.add(l1[i]);
         }
         return set1;
     }
 
 }
