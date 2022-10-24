package round2;
 
 import java.io.File;
 import java.io.PrintWriter;
 import java.util.ArrayList;
 import java.util.HashSet;
 import java.util.List;
 import java.util.Scanner;
 import java.util.Set;
 
 public class TrieSharding {
     static int max;
     static int count;
     static String[] data;
     static int N;
     static int M;
     static List<String>[] lists;
     
     static void solve(int index) {
         if (index == M) {
             for (int i=0; i<N; i++) {
                 if (lists[i].isEmpty()) return;
             }
             int nodes = 0;
             for (int i=0; i<N; i++) {
                 Set<String> set = new HashSet<String>();
                 for (String item : lists[i]) {
                     for (int j=0; j<=item.length(); j++) {
                         set.add(item.substring(0,j));
                     }
                 }
                 nodes += set.size();
             }
             if (nodes == max) {
                 count++;
             } else if (nodes > max) {
                 max = nodes;
                 count = 1;
             }
         } else {
             for (int i=0; i<N; i++) {
                 lists[i].add(data[index]);
                 solve(index+1);
                 lists[i].remove(data[index]);
             }
         }
     }
     
     public static void main(String[] args) throws Exception {
         File inputFile = new File("D-small-attempt0.in");
         Scanner in = new Scanner(inputFile);
         File outputFile = new File("output.txt");
         PrintWriter out = new PrintWriter(outputFile);
 
         int T = in.nextInt();
         for (int t=0; t<T; t++) {
             M = in.nextInt();
             N = in.nextInt();
             data = new String[M];
             in.nextLine();
             for (int m=0; m<M; m++) {
                 data[m] = in.nextLine();
             }
             lists = new List[N];
             for (int n=0; n<N; n++) {
                 lists[n] = new ArrayList<String>(M);
             }
             max = 0;
             count = 0;
             solve(0);
             
             out.println("Case #"+(t+1)+": "+max+" "+count);
         }
 
         out.close();
     }
     
 }
