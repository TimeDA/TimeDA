import java.io.*;
 import java.util.*;
 
 public class A {
     FastScanner in;
     PrintWriter out;
 
     long mod = 1000002013;
 
     class Event implements Comparable<Event> {
         int type;
         // 0 -add, 1 - rem
         int cnt;
         int pos;
 
         public Event(int type, int cnt, int pos) {
             super();
             this.type = type;
             this.cnt = cnt;
             this.pos = pos;
         }
 
         @Override
         public int compareTo(Event arg0) {
             if (pos == arg0.pos)
                 return Integer.compare(type, arg0.type);
             return Integer.compare(pos, arg0.pos);
         }
     }
 
     class Passanger {
         int from;
         int cnt;
 
         public Passanger(int from, int cnt) {
             super();
             this.from = from;
             this.cnt = cnt;
         }
 
     }
 
     void solve() {
         int n = in.nextInt();
         int m = in.nextInt();
         long curCost = 0;
         ArrayList<Event> events = new ArrayList<>();
         for (int i = 0; i < m; i++) {
             int fr = in.nextInt();
             int to = in.nextInt();
             int cnt = in.nextInt();
             int x = to - fr;
             long oneTrip = n * 1L * x - (x - 1) * 1L * (x) / 2;
             oneTrip %= mod;
             curCost += oneTrip * cnt;
             curCost %= mod;
             events.add(new Event(0, cnt, fr));
             events.add(new Event(1, cnt, to));
         }
         Collections.sort(events);
         long bestCost = 0;
         ArrayList<Passanger> arr = new ArrayList<>();
         for (Event e : events) {
             if (e.type == 0) {
                 arr.add(new Passanger(e.pos, e.cnt));
             } else {
                 int need = e.cnt;
                 while (need > 0) {
                     Passanger pp = arr.get(arr.size() - 1);
                     arr.remove(arr.size() - 1);
                     int cc = Math.min(pp.cnt, need);
                     need -= cc;
                     pp.cnt -= cc;
                     long x = e.pos - pp.from;
                     long oneTrip = n * 1L * x - (x - 1) * 1L * (x) / 2;
                     oneTrip %= mod;
                     bestCost += oneTrip * cc;
                     bestCost %= mod;
                     if (pp.cnt != 0) {
                         arr.add(pp);
                     }
                 }
             }
         }
         long diff = (curCost - bestCost) % mod;
         if (diff < 0)
             diff += mod;
         out.println(diff);
 
     }
 
     void run() throws IOException {
         try {
             in = new FastScanner(new File("A.in"));
             out = new PrintWriter(new File("A.out"));
 
             int testNumber = in.nextInt();
             for (int test = 1; test <= testNumber; test++) {
                 out.print("Case #" + (test) + ": ");
                 solve();
                 System.out.println(test);
             }
 
             out.close();
         } catch (FileNotFoundException e) {
             e.printStackTrace();
         }
     }
 
     class FastScanner {
         BufferedReader br;
         StringTokenizer st;
 
         public FastScanner(File f) {
             try {
                 br = new BufferedReader(new FileReader(f));
             } catch (FileNotFoundException e) {
                 e.printStackTrace();
             }
         }
 
         public FastScanner(InputStream f) {
             br = new BufferedReader(new InputStreamReader(f));
         }
 
         String next() {
             while (st == null || !st.hasMoreTokens()) {
                 String s = null;
                 try {
                     s = br.readLine();
                 } catch (IOException e) {
                     e.printStackTrace();
                 }
                 if (s == null)
                     return null;
                 st = new StringTokenizer(s);
             }
             return st.nextToken();
         }
 
         boolean hasMoreTokens() {
             while (st == null || !st.hasMoreTokens()) {
                 String s = null;
                 try {
                     s = br.readLine();
                 } catch (IOException e) {
                     e.printStackTrace();
                 }
                 if (s == null)
                     return false;
                 st = new StringTokenizer(s);
             }
             return true;
         }
 
         int nextInt() {
             return Integer.parseInt(next());
         }
 
         long nextLong() {
             return Long.parseLong(next());
         }
     }
 
     public static void main(String[] args) throws IOException {
         new A().run();
     }
 }