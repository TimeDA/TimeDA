package qualification;
 
 import java.io.File;
 import java.io.IOException;
 import java.io.PrintWriter;
 import java.util.Scanner;
 
 public class SpeakingInTongues {
     static int T;
     static String[] data;
     static String[] result;
 
     public static void main(String[] args) throws IOException {
         createMapping();
         read();
         process();
         write();
     }
 
     static char[] map;
     static void createMapping() {
         map = new char[26];
         String googlerese = "yeqzejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
         String english = "aozqour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
         for (int i=0; i<googlerese.length(); i++) {
             char c = googlerese.charAt(i);
             char d = english.charAt(i);
             if (c != ' ') {
                 map[c-'a']=d;
             }
         }
 //        for (int i=0; i<map.length; i++) {
 //            System.out.println((char)(i+'a')+" -> "+map[i]);
 //        }
     }
 
     static void read() throws IOException {
         File input = new File("input.txt");
         Scanner scanner = new Scanner(input);
         T = scanner.nextInt();
         scanner.nextLine();
         data = new String[T];
         for (int t=0; t<T; t++) {
             data[t] = scanner.nextLine();
         }
     }
 
     static void process() {
         result = new String[T];
         for (int t=0; t<T; t++) {
             String in = data[t];
             StringBuilder out = new StringBuilder();
             for (int i=0; i<in.length(); i++) {
                 char c = in.charAt(i);
                 if ('a'<=c && c<='z') {
                     out.append(map[c-'a']);
                 } else {
                     out.append(c);
                 }
             }
             result[t] = out.toString();
         }
     }
 
     static void write() throws IOException {
         File output = new File("output.txt");
         PrintWriter pw = new PrintWriter(output);
 
         for (int t=0; t<T; t++) {
             pw.println("Case #"+(t+1)+": "+result[t]);
         }
 
         pw.close();
     }
 
 }
