package c2014_c.c2014_round2;
 
 import java.io.BufferedWriter;
 import java.io.File;
 import java.io.FileWriter;
 import java.util.*;
 
 public class Z4 {
 
     public static void main(String[] args) throws Exception {
         FileWriter fw = new FileWriter("C:\\output.txt");
         BufferedWriter out = new BufferedWriter(fw);
         //String pathname = "C:\\Users\\YC14rp1\\Downloads\\z4.txt";
         String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-small-attempt0.in";
         //String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-large.in";
         Scanner scanner = new Scanner(new File(pathname));
         int tn = scanner.nextInt();
         scanner.nextLine();
         for (int ti = 1; ti <= tn; ti++) {
             int m = scanner.nextInt();
             int n = scanner.nextInt();
             List<String> ss = new ArrayList<String>();
             for (int i=0;i<m;i++) {
                 ss.add(scanner.next());
             }
             int[] xx = new int[m];
             int mx = 0;
             int cnt = 0;
             boolean flag = true;
             while (flag) {
                 int cur =0;
                 List<HashSet<String>> ls = new ArrayList<HashSet<String>>();
                 for (int i=0;i<n;i++) {
                     HashSet<String> s = new HashSet<String>();
                     for (int j=0; j<m;j++) {
                         if (xx[j]==i) {
                             String s1 = ss.get(j);
                             for (int k=0; k<= s1.length();k++) {
                                 s.add(s1.substring(0,k));
                             }
                         }
                     }
                     cur += s.size();
                     //ls.add(s);
                 }
                 if (cur==mx) {
                     cnt++;
                     //System.out.println(ls);
                 }
                 if (cur>mx) {
                     mx = cur;
                     cnt = 1;
                 }
                 int i = 0;
                 while (i<m && xx[i]==n-1) {
                     i++;
                 }
                 if (i==m) {
                     flag = false;
                 } else {
                     xx[i]++;
                     for (int j=0;j<i;j++) {
                         xx[j]=0;
                     }
                 }
             }
             String s;
             s = "Case #" + ti + ": "+mx +" "+ cnt;
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
