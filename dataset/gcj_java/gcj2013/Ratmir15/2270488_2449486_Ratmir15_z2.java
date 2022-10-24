package c2013_1;
 
 import java.io.BufferedWriter;
 import java.io.File;
 import java.io.FileWriter;
 import java.util.*;
 
 public class Z2 {
 
     public static void main(String[] args) throws Exception {
         FileWriter fw = new FileWriter("C:\\output.txt");
         BufferedWriter out = new BufferedWriter(fw);
         //String pathname = "C:\\tests\\z1.txt";
         String pathname = "C:\\Users\\YC14rp1\\Downloads\\B-small-attempt0 (1).in";
         //String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-large-practice (3).in";
         Scanner scanner = new Scanner(new File(pathname));
         int tn = scanner.nextInt();
         scanner.nextLine();
         for (int ti = 1; ti <= tn; ti++) {
             int n = scanner.nextInt();
             int m = scanner.nextInt();
             int [][] a = new int[n][];
             int [] rm  = new int[n];
             int [] cm  = new int[m];
             for (int j=1; j<=m;j++) {
                 cm[j-1] = 0;
             }
             for (int i=1; i<=n;i++) {
                 a[i-1] = new int[m];
                 rm[i-1] = 0;
                 for (int j=1; j<=m;j++) {
                     a[i-1][j-1] = scanner.nextInt();
                     if (a[i-1][j-1]>rm[i-1]) {
                         rm[i-1] = a[i-1][j-1];
                     }
                     if (a[i-1][j-1]>cm[j-1]) {
                         cm[j-1] = a[i-1][j-1];
                     }
                 }
             }                           
 
             boolean flag = false;
             x:
             for (int i=0;i<n;i++) {
                 for (int j=0;j<m;j++) {
                     if ((a[i][j]<rm[i]) && (a[i][j]<cm[j])) {
                         flag = true;
 //                        System.out.println(a[i][j]);
 //                        System.out.println(rm[i]);
 //                        System.out.println(cm[j]);
                         break x;
                     }
                     
                 }
             }
 
             String s = "Case #" + ti + ": " + (flag?"NO":"YES");
             System.out.println(s);
             out.write(s);
             out.write("\n");
         }
         out.close();
     }
 
 }
