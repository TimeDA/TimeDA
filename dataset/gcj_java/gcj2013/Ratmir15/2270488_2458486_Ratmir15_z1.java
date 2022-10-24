package c2013_1;
 
 import java.io.BufferedWriter;
 import java.io.File;
 import java.io.FileWriter;
 import java.util.*;
 
 public class Z1 {
 
     public static void main(String[] args) throws Exception {
         FileWriter fw = new FileWriter("C:\\output.txt");
         BufferedWriter out = new BufferedWriter(fw);
         //String pathname = "C:\\tests\\z4.txt";
         String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-small-attempt2.in";
         //String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-large-practice (3).in";
         Scanner scanner = new Scanner(new File(pathname));
         int tn = scanner.nextInt();
         scanner.nextLine();
         for (int ti = 1; ti <= tn; ti++) {
             int k = scanner.nextInt();
             int n = scanner.nextInt();
             System.out.println(k+" "+n);
             Map<Integer,Integer> keys = new HashMap<Integer, Integer>();
             for (int i=1;i<=k;i++) {
                 int kt = scanner.nextInt();
                 if (keys.containsKey(kt)) {
                     keys.put(kt, keys.get(kt) + 1);
                 } else {
                     keys.put(kt,1);
                 }
             }
             List<Chest> chests = new ArrayList<Chest>(n);
             List<Boolean> opened = new ArrayList<Boolean>(n);
             Map<Integer,Integer> all_keys = new HashMap<Integer, Integer>(keys);
             Map<Integer,Integer> all_chests = new HashMap<Integer, Integer>();
             for (int i=1;i<=n;i++) {
                 opened.add(false);
                 Chest chest = new Chest();
                 chest.t = scanner.nextInt();
                 if (all_chests.containsKey(chest.t)) {
                     all_chests.put(chest.t, all_chests.get(chest.t) + 1);
                 } else {
                     all_chests.put(chest.t,1);
                 }
                 int kn = scanner.nextInt();
                 chest.keys = new ArrayList<Integer>(kn);
                 for (int j=1;j<=kn;j++) {
                     int kt = scanner.nextInt();
                     chest.keys.add(kt);
                     if (!keys.containsKey(kt)) {
                         keys.put(kt, 0);
                     }
                     if (all_keys.containsKey(kt)) {
                         all_keys.put(kt, all_keys.get(kt) + 1);
                     } else {
                         all_keys.put(kt,1);
                     }
                 }
                 chests.add(chest);
             }
             boolean impossible = false;
             for (Map.Entry<Integer, Integer> e : all_chests.entrySet()) {
                 if (e.getValue() > all_keys.get(e.getKey())) {
                     impossible = true;
                     System.out.println(e);
                 }
             }
             String decision;
             if (impossible) {
                 decision = "IMPOSSIBLE";
             } else {
                 List<Integer> solution = new ArrayList<Integer>();
                 boolean b = makeMove(n, keys, chests, opened, solution);
                 String sol = "";
                 for (int ii=0;ii<solution.size();ii++) {
                     if (ii>0) {
                         sol+=" ";
                     }
                     sol += (solution.get(ii)+1);
                 }
                 decision = b?sol:"IMPOSSIBLE";
             }
             String s = "Case #" + ti + ": " + decision;
             System.out.println(s);
             out.write(s);
             out.write("\n");
         }
         out.close();
     }
 
     private static boolean makeMove(int n, Map<Integer, Integer> keys, List<Chest> chests, List<Boolean> opened, List<Integer> solution) {
         boolean win = true;
         for (int ci = 0;ci<n;ci++) {
             Chest ch = chests.get(ci);
             if (!opened.get(ci)) {
                 win = false;
                 Integer keyt = keys.get(ch.t);
                 if (keyt!=null && keyt>0) {
 //                    if (solution.size()<=3) {
 //                        System.out.println("Open "+ ci+" solution "+solution);
 //                    }
                     opened.set(ci, true);
                     Integer cnt = keys.get(ch.t);
                     keys.put(ch.t, cnt - 1);
                     boolean goodmove = false;
                     for (Integer kt : ch.keys) {
                         keys.put(kt, keys.get(kt) + 1);
                         if (kt==ch.t){
                             goodmove = true;
                         }
                     }
                     boolean badmove = false;
                     if (!goodmove && cnt==1) {
                         //lost last key?
                         int kleft = 0;
                         int kneed = 0;
                         for (int ki = 0;ki<n;ki++) {
                             if (!opened.get(ki)) {
                                 int kl = 0;
                                 for (Integer key : chests.get(ki).keys) {
                                     if (key == ch.t) {
                                         kl++;
                                     }
                                 }
                                 if ((chests.get(ki).t != ch.t) && (kl>0)) {
                                     //still have a chance to open chest with this key
                                     kleft++;
                                     break;
                                 }
                                 if (chests.get(ki).t == ch.t) {
                                     kneed++;
                                 }
                             }
                         }
                         if (kleft==0 && kneed>0) {
                             System.out.println("It was bad: "+ci+" "+kleft+" "+kneed);
                             badmove = true;
                         } else {
                             System.out.println("It was not bad: "+ci+" "+kleft+" "+kneed);
                         }
                     }
                     solution.add(ci);
                     boolean inner_win = (!badmove) && makeMove(n, keys, chests, opened, solution);
                     if (inner_win) {
                         return true;
                     }
                     solution.remove(solution.size() - 1);
                     opened.set(ci, false);
                     for (Integer kt : ch.keys) {
                         keys.put(kt, keys.get(kt) - 1);
                     }
                     keys.put(ch.t, cnt);
                     if (goodmove) {
                         //System.out.println("It was good:"+ci);
                         return false;
                     }
                 }
             }
         }
         return win;
     }
 
     private static class Chest {
         private int t;
         private List<Integer> keys;
     }
 }
