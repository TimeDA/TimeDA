package c2013_1;
 
 import java.io.BufferedWriter;
 import java.io.File;
 import java.io.FileWriter;
 import java.util.*;
 
 public class Z4 {
     public static final String [] RESULTS = new String[]{"X won","O won","Draw","Game has not completed"};
 
     public static void main(String[] args) throws Exception {
         FileWriter fw = new FileWriter("C:\\output.txt");
         BufferedWriter out = new BufferedWriter(fw);
         //String pathname = "C:\\tests\\ttt.txt";
         String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-small-attempt0 (1).in";
         //String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-large-practice (3).in";
         Scanner scanner = new Scanner(new File(pathname));
         int tn = scanner.nextInt();
         scanner.nextLine();
         for (int ti = 1; ti <= tn; ti++) {
             char [][] d = new char[4][];
             int res = 0;
             int ce = 0;
             if (ti!=1) {
                 scanner.nextLine();
             }
             for (int j=0;j<4;j++) {
                 String pattern = scanner.nextLine();
                 d[j] = pattern.toCharArray();
                 //System.out.println(d[j]);
                 int cx = 0;
                 int co = 0;
                 for (int k=0;k<4;k++) {
                     if (d[j][k] == 'X') {
                         cx++;
                     } else if (d[j][k] == 'O') {
                         co++;
                     } else if (d[j][k] == 'T') {
                         cx++;
                         co++;
                     } else if (d[j][k] == '.') {
                         ce=1;
                     }
                 }
                 if (cx==4) { res = 1; }
                 if (co==4) { res = 2; }
             }
             if ((res==0) && (ce==1)) {
                 res = 4;
             }
             for (int j=0;j<4;j++) {
                 int cx = 0;
                 int co = 0;
                 for (int k=0;k<4;k++) {
                     if (d[k][j] == 'X') {
                         cx++;
                     } else if (d[k][j] == 'O') {
                         co++;
                     } else if (d[k][j] == 'T') {
                         cx++;
                         co++;
                     }
                 }
                 if (cx==4) { res = 1; }
                 if (co==4) { res = 2; }
             }
             int cx = 0;
             int co = 0;
             for (int k=0;k<4;k++) {
                 if (d[k][k] == 'X') {
                     cx++;
                 } else if (d[k][k] == 'O') {
                     co++;
                 } else if (d[k][k] == 'T') {
                     cx++;
                     co++;
                 }
             }
             if (cx==4) { res = 1; }
             if (co==4) { res = 2; }
             cx = 0;
             co = 0;
             for (int k=0;k<4;k++) {
                 if (d[k][3-k] == 'X') {
                     cx++;
                 } else if (d[k][3-k] == 'O') {
                     co++;
                 } else if (d[k][3-k] == 'T') {
                     cx++;
                     co++;
                 }
             }
             if (cx==4) { res = 1; }
             if (co==4) { res = 2; }
             if (res==0) { res = 3; }
 
             String s = "Case #" + ti + ": " + RESULTS[res-1];
             System.out.println(s);
             out.write(s);
             out.write("\n");
         }
         out.close();
     }
 
     private static boolean check(String possibleWord, Set<String> words) {
         return words.contains(possibleWord);
     }
 
 }
