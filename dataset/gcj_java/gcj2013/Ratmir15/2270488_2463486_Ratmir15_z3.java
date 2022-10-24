package c2013_1;
 
 import java.io.BufferedWriter;
 import java.io.File;
 import java.io.FileWriter;
 import java.util.*;
 
 public class Z3 {
 
     public static void main(String[] args) throws Exception {
         FileWriter fw = new FileWriter("C:\\output.txt");
         BufferedWriter out = new BufferedWriter(fw);
         //String pathname = "C:\\tests\\z3.txt";
         String pathname = "C:\\Users\\YC14rp1\\Downloads\\C-small-attempt0 (1).in";
         //String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-large-practice (3).in";
         Scanner scanner = new Scanner(new File(pathname));
         int tn = scanner.nextInt();
         for (int ti = 1; ti <= tn; ti++) {
             int b = scanner.nextInt();
             int f = scanner.nextInt();
             int j=0;
             double sqrt;
             sqrt = Math.sqrt(b);
             long b1 = (long) Math.floor(sqrt);
             sqrt = Math.sqrt(f);
             long b2 = (long) Math.floor(sqrt);
             for (long i=b1;i<=b2+1;i++) {
                 long s = i*i;
                 if ((s>=b) && (s<=f)) {
                     boolean flag = true;
                     flag = check(i, flag);
                     if (flag) {
                         flag = check(s, flag);
                     }
                     if (flag) {
                         System.out.println(i);
                         System.out.println(s);
                         j++;
                     }
                 }
             }
             String s = "Case #" + ti + ": " + j;
             System.out.println(s);
             out.write(s);
             out.write("\n");
         }
         out.close();
     }
 
     private static boolean check(long i, boolean flag) {
         String x = String.valueOf(i);
         for (int si=0;si<x.length();si++) {
             if (x.charAt(si)!=x.charAt(x.length()-si-1)) {
                 flag = false;
                 break;
             }
         }
         return flag;
     }
 
     private static boolean check(String possibleWord, Set<String> words) {
         return words.contains(possibleWord);
     }
 
 }
