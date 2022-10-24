package round2;
 
 import java.io.File;
 import java.io.IOException;
 import java.io.PrintWriter;
 import java.util.Comparator;
 import java.util.Iterator;
 import java.util.LinkedList;
 import java.util.List;
 import java.util.Scanner;
 import java.util.Set;
 import java.util.TreeSet;
 
 public class TicketSwapping {
     static int T;
     static int N;
     static int M;
     static Set<Item> froms;
     static Set<Item> tos;
     static int[] results;
 
     public static void main(String[] args) throws IOException {
         read();
         process();
         write();
     }
 
     static void read() throws IOException {
         File input = new File("input.txt");
         Scanner scanner = new Scanner(input);
         T = scanner.nextInt();
         results = new int[T];
         for (int t=0; t<T; t++) {
             N = scanner.nextInt();
             M = scanner.nextInt();
             froms = new TreeSet<Item>(new Comparator<Item>() {
                 public int compare(Item o1, Item o2) {
                     long diff = o1.from-o2.from;
                     if (diff == 0) {
                         diff = o2.to-o1.to;
                         if (diff == 0) {
                             diff = System.identityHashCode(o1)-System.identityHashCode(o2);
                         }
                     }
                     return (int)Math.signum(diff);
                 }
             });
             tos = new TreeSet<Item>(new Comparator<Item>() {
                 public int compare(Item o1, Item o2) {
                     long diff = o2.to-o1.to;
                     if (diff == 0) {
                         diff = o1.from-o2.from;
                         if (diff == 0) {
                             diff = System.identityHashCode(o1)-System.identityHashCode(o2);
                         }
                     }
                     return (int)Math.signum(diff);
                 }
             });
             for (int m=0; m<M; m++) {
                 int from = scanner.nextInt();
                 int to = scanner.nextInt();
                 int count = scanner.nextInt();
                 froms.add(new Item(from, to, count));
             }
             results[t] = process();
         }
     }
 
     static int process() {
         long originalCost = 0;
         List<Item> items = new LinkedList<Item>();
         for (Item from : froms) {
             originalCost = originalCost+from.cost();
             items.clear();
             Iterator<Item> iterator = tos.iterator();
             while (iterator.hasNext()) {
                 Item to = iterator.next();
                 if (to.to >= from.from) {
                     if (to.to <= from.to) {
                         long count = Math.min(from.count, to.count);
                         from.count -= count;
                         to.count -= count;
                         items.add(new Item(to.from, from.to, count));
                         items.add(new Item(from.from, to.to, count));
                         if (to.count == 0) {
                             iterator.remove();
                         }
                         if (from.count == 0) {
                             break;
                         }
                     }
                 } else {
                     break;
                 }
             }
             tos.addAll(items);
             if (from.count != 0) {
                 tos.add(from);
             }
         }
         long cost = 0;
         for (Item item : tos) {
             cost += item.cost();
         }
         return (int)((originalCost-cost)%1000002013);
     }
     
 
     static void write() throws IOException {
         File output = new File("output.txt");
         PrintWriter pw = new PrintWriter(output);
 
         for (int t=0; t<T; t++) {
             pw.println("Case #"+(t+1)+": "+results[t]);
         }
 
         pw.close();
     }
     
     static class Item {
         public Item(long from, long to, long count) {
             this.from = from;
             this.to = to;
             this.count = count;
         }
         long from;
         long to;
         long count;
         
         long cost() {
             long distance = to - from;
             long payment = (2*N-distance+1)*distance/2;
             long cost = payment*count;
             return cost;
         }
     }
 
 }
