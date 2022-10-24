import static java.lang.Math.*;
 import static java.util.Arrays.*;
 import static java.util.Collections.reverse;
 import static java.lang.Integer.*;
 import static java.lang.Long.parseLong;
 import java.util.*;
 import java.util.concurrent.*;
 import java.math.BigDecimal;
 import java.math.BigInteger;
 import java.awt.geom.*;
 import java.io.*;
 
 //// Apache Jakarta Common Lang : http://commons.apache.org/lang/
 //import org.apache.commons.lang.builder.*;
 
 // java -Xmx1024m -Xss5m
 @SuppressWarnings("unchecked")
 public class B {
 //    private static final String IMPOSSIBLE = "IMPOSSIBLE";
     private static final String NO = "IMPOSSIBLE";
     public static final long MAX = Long.MAX_VALUE;
     public static final int INF = 1000000000;
     public static final int MOD = 9901; 
     public static final int UNDEF = -3;
 
     /*
      * problem
      * 
      * 
      */
     /*
      * solution
      * 
      * min swap number = number of pairs a[i]>a[j] where i<j = D
      * 
      */
     private void run(int caseNumber) throws Exception {
         int N = INT();
         int[] a = new int[N];
         for (int i = 0; i < a.length; i++) {
             a[i] = INT();
         }
         
         
         /// reading input done
         if(debugTestCases.length>0 && Arrays.binarySearch(debugTestCases, caseNumber)<0) {
             if(writeToFile) {
                 out.printf("Case #%d: skip\n", caseNumber);
             }
 //            System.out.println("----- skip case "+caseNumber+" -----");
             return;
         }
 
         
         int[] na = a.clone();
         sort(na);
         int m=na[na.length-1];
 
         int mIdx=0;
         for (int i = 0; i < a.length; i++) {
             if (a[i]==m) {
                 mIdx=i;
                 break;
             }
         }
         
         if (true) {
 //            int ans=bf(a,na,mIdx);
             int ans=bfs(a,na,mIdx);
             out.printf("Case #%d: %s\n", caseNumber, ans);
             return;
         }
         
         int ret = INF;
         /// start solving problem
         for (int i = 0; i < a.length; i++) {
 //            if (a[i]!=na[a.length-1]) {
 //                continue;
 //            }
             
             int v=0;
             v+=abs(mIdx-i);
             int lo=(i<=mIdx)?i-1:i;
 //            int lo=i;
             for (int j = 0; j <= lo; j++) {
                 for (int j2 = i; j2 <= lo; j2++) {
                     if (a[j]!=m && a[j2]!=m && a[j]>a[j2]) {
                         v++;
                     }
                 }
             }
             for (int j = a.length-1; j>lo; j--) {
                 for (int j2 = a.length-1; j2>lo; j2--) {
                     if (a[j]!=m && a[j2]!=m && a[j]<a[j2]) {
                         v++;
                     }
                 }
             }
             ret = Math.min(ret, v);
 //            for (int j = 0; j < a.length; j++) {
 //                if (i==j) continue; 
 //                
 //                for (int j2 = j+1; j2 < a.length; j2++) {
 //                    if (a[j]>a[i] && a[j2]>a[i] && a[j]);
 //                }
 //            }
 ////            for (int j = 0; j < i; j++) {
 ////                if (a[j]>a[i]) {
 ////                    v++;
 ////                }
 ////            }
         }
         
         out.printf("Case #%d: %s\n", caseNumber, ret);
 //        out.printf("Case #%d:", caseNumber);
 //        out.println();
     }
 
 
     // bfs
     static int bfs(int[] a, int[] sort, int mIdx) {
         int m=a[mIdx];
         Map<State,Integer> done = new HashMap<>();
         Set<State> cur = new HashSet<>();
         State init=new State(a);
         cur.add(init);
         done.put( init, new Integer(0));
 //        while(true) {
         for (int step = 0; ; step++) {
             Set<State> next = new HashSet<>();
             for (State st : cur) {
                 if (ok(st.a, m)){
                     return step;
                 }
                 for (int i = 1; i < a.length; i++) {
                     int[] na=st.a.clone();
                     // swap na[i] & na[i-1]
                     int tmpForSwap = na[i];
                     na[i] = na[i-1];
                     na[i-1] = tmpForSwap;
                     State nst=new State(na);
                     int nv=step+1;
                     //if(!next.contains(nst)) { //!!! REMOVE THIS if use dp to check better position
                     //if(!done.containsKey(nst)||done.get(nst)<nv)) { // want max, if not done OR new solution is better
 //                    if(!done.containsKey(nst)||done.get(nst)>nv)) { // want min, if not done OR new solution is better
                     if (!done.containsKey(nst)) { // want min, if not done OR new solution is better
                         next.add(nst);
                         done.put(nst,nv);
                     }
                 }
             }
             if (next.isEmpty()) {
                 break;
             }
             cur=next;
 //            System.out.println("  next=" + next);
             
         }
         return INF;
     }
     
     static boolean ok(int[] a, int m) {
         int i;
         for (i = 0; i < a.length; i++) {
             if (a[i]==m) {
                 break;
             }
             if (i>0 && a[i]<a[i-1]) {
                 return false;
             }
         }
         for (int j = a.length-1; j>i; j--) {
             if (a[j]>a[j-1]) {
                 return false;
             }
         }
         return true;
     }
 
     static class State implements Comparable<State> {
             int[] a;
             
             public State(int[] a) {
                 super();
                 this.a = a;
                 //Arrays.sort(a); // normalize
             }
             
             /*        // convert 2d, assume all with same size m*n so equals ok
             public State(int[][] a2) {
                 a = new int[a2.length*a2[0].length];
                 int idx=0;
                 for (int i = 0; i < a2.length; i++) {
                     for (int j = 0; j < a2[i].length; j++) {
                         a[idx++]=a2[i][j];
                     }
                 }
                 //Arrays.sort(a); // normalize
             }
             */
             public boolean equals(Object obj) {	    
                 State o = (State) obj;
                 return Arrays.equals(a,o.a);
             }
             
             public int hashCode() {
                 return Arrays.hashCode(a);
             }
             
             public String toString() {
                 return Arrays.toString(a);
             }
             public int compareTo(State o) {
                 return compare(a, o.a); // min first
                 //return -compare(a, o.a); // max first
             }
         }
         static int compare(int[] a1, int[] a2) {
             int n=Math.min(a1.length,a2.length);
             for (int i = 0; i < n; i++) {
                 if(a1[i]<a2[i]) {
                     return -1;
                 }
                 if(a1[i]>a2[i]) {
                     return 1;
                 }
             }
             return a1.length-a2.length;
         }
     
     private int bf(int[] a, int[] na, int mIdx) {
         int n = na.length;
         int ret=INF;
         for (int left = 0; left < (1<<n); left++) {
             int v=0;
             List<Integer> L = new ArrayList<>();
             List<Integer> R = new ArrayList<>();
             for (int i = 0; i < n; i++) {
                 if (i==mIdx) {
                     continue; 
                 }
                 if( has(left,i)) {
                     L.add(a[i]);
                     if (i>mIdx) {
                         v++;
                     }
                 } else {
                     R.add(0,a[i]);
                     if (i<mIdx) {
                         v++;
                     }
                 }
             }
             v+=cnt(L);
             v+=cnt(R);
         }
         return ret;
     }
 
     private int cnt(List<Integer> ls) {
         int ret=0;
         for (int i = 0; i < ls.size(); i++) {
             int v1=ls.get(i);
             for (int j = i+1; j < ls.size(); j++) {
                 int v2=ls.get(j);
                 if (v1>v2) {
                     ret++;
                 }
             }
         }
         return ret;
     }
 
 
     // i-th bit is set
     static boolean has(int mask, int i) {
         return (mask & (1 << i)) != 0;
     }
 
     // set i-th bit to v
     static int set(int mask, int i, boolean v) {
         return v ? set(mask, i) : unset(mask, i);
     }
 
     // set i-th bit
     static int set(int mask, int i) {
         return mask | (1 << i);
     }
 
     // unset i-th bit
     static int unset(int mask, int i) {
         return mask & ~(1 << i);
     }
 
     // mask set contains subset
     static boolean contain(int set, int subset) {
         return (set & subset) == subset;
     }
 
     static boolean printInput=false;
 //    static boolean printInput=true; // print input case
 
     static boolean printDoubleCheck=true;
 //    static boolean printDoubleCheck=false;
     
     static boolean redirectStdoutToFile=false;
 //    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"
 
     
     static boolean writeToFile=true; // output result to file
 //    static boolean writeToFile=false;
 
     static String[] testFilenames = new String[] {
 //        "B-test.in",
 //        "B-small-attempt0.in",
 //        "B-small-attempt1.in",
 //        "B-small-attempt2.in",
         "B-small-attempt3.in",
 //        "B-small.in",
 //        "B-small-practice.in",
 //        "B-large.in",
 //        "B-large-practice.in",
     };
 
     static int THREAD=1;
 //    static int THREAD=3;
 
     static BufferedReader in;
     static StringTokenizer inTok = new StringTokenizer("");
     static PrintWriter out;
 
     /// only run given cases, {} runs all
     static int[] debugTestCases = {};
 //    static int[] debugTestCases = {};
 
     public static void main(String[] args) throws Exception {
         // $0 inputFile caseStart caseEnd
         if (args.length>0) {
             testFilenames = args;
         }
 
         if (debugTestCases.length > 0) {
             System.out.println("NOTE: only run these cases: "+Arrays.toString(debugTestCases)+"\n");            
         }
         // redirect sys out
         if (redirectStdoutToFile) {
             String filename = "output.txt";
             System.out.println("NOTE: redirect stdout to file "+filename);
             FileOutputStream fos = new FileOutputStream(filename);
             PrintStream ps = new PrintStream(fos,true);
             System.setOut(ps);
         }
 
 //        myTest();
 
         for (int i = 0; i < testFilenames.length; i++) {
             System.out.println((i>0?"\n\n":"") + "##### file["+i+"]: "+testFilenames[i]);
             solveFile(testFilenames[i]);
         }
     }
 
     static void solveFile(String testFilename) throws Exception {
         String resultFilename=testFilename+"-res.txt";
         long start = System.currentTimeMillis();
 //        in = new BufferedReader(new InputStreamReader(System.in));
         in = new BufferedReader(new FileReader(testFilename));
         int NN=INT();
         out = writeToFile ? new PrintWriter(new FileWriter(resultFilename),true)
                           : new PrintWriter(System.out, true);
         if (THREAD>1) {
             parallelSolve(NN);
         } else {
             for (int i = 1; i <= NN; i++) {
                 boolean debug=debugTestCases.length>0 && Arrays.binarySearch(debugTestCases, i)>=0;
                 if (debug) {
                     printInput = true;
                 }
 //                out.printf("Case #%d: ", i);
                 if (printInput) System.out.println("\n### Case "+i);
                 new B().run(i);
                 if (debug) {
                     printInput = false;
                 }
             }
         }
         in.close();
 
         if (writeToFile) {
             out.close();
         }
 
         System.out.println("\nTime taken: "+((System.currentTimeMillis()-start)/1000.0)+" sec");
 
         if (writeToFile) {
             boolean first = true;
             String[] suffix = new String[] {
                     "", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                     "-bad", "-bad0", "-bad1", "-bad2", "-bad3", "-bad4", "-bad5", "-bad6", "-bad7", "-bad8", "-bad9", };
             for (int i = 0; i < suffix.length; i++) {
                 File ans=new File(testFilename+"-ans"+suffix[i]+".txt");
                 if(ans.exists()&&ans.length()>0) {
                     boolean same=sameFileContent(ans, new File(resultFilename), first);
                     first = false;
                     if(same) {
                         System.out.println("All pass :)          Answer == "+ans);
                         break;
                     } else {
                         System.out.println("ERROR: Answer != "+ans);
                     }
                 }
             }
         }
     }
     static void parallelSolve(int totalCase) throws Exception {
         int th = Math.min(THREAD, Runtime.getRuntime().availableProcessors());
         System.out.println("thread = "+th);
         ExecutorService executor = Executors.newFixedThreadPool(th);
         List<Solver> solvers = new ArrayList<Solver>();
         for (int i = 1; i <= totalCase; i++) {
             if (printInput) System.out.println("\n### Case "+i);
 
             solvers.add(new Solver());
         }
 
         List <Future<Object>> results = executor.invokeAll(solvers);
 
         int caseNumber=1;
         for (Future<Object> result : results) {
             out.printf("Case #%d: %s\n", caseNumber, result.get());
             caseNumber++;
         }
         executor.shutdown();
     }
     static class Solver implements Callable<Object> {
         final int n;
 
         // Do all input reading here!!
         public Solver() throws IOException {
             n = INT();
             throw new RuntimeException("TODO: do reading/solving in Solver()");
         }
 
         // Do no reading here! This is run async!
         // Solve the actual problem here
         public Object call() throws Exception {
             return n;
         }
     }
 
     private static boolean sameFileContent(File ansFile, File resFile, boolean showInfo) throws IOException {
         if (showInfo) {
             System.out.println();
         }
 
         BufferedReader ans = new BufferedReader(new FileReader(ansFile));
         BufferedReader res = new BufferedReader(new FileReader(resFile));
         boolean ok=true;
         List<Integer> wrong = new ArrayList<Integer>();
         int ln=1;
         while(true) {
             String sAns=ans.readLine();
             String sRes=res.readLine();
             if(sAns==null) {
                 if(sRes!=null) {
                     if (showInfo) {
                         System.out.println("### result has more lines than answer");
                         do {
                             System.out.println(sRes);
                         } while ((sRes=res.readLine())!=null);
                         System.out.println();
                     }
                     ok=false;
                 }
                 break;
             }
             if(sRes==null) {
                 if(sAns!=null && !sAns.isEmpty()) {
                     if (showInfo) {
                         System.out.println("### answer has more lines than result");
                         do {
                             System.out.println(sAns);
                         } while ((sAns=ans.readLine())!=null);
                         System.out.println();
                     }
                     ok=false;
                 }
                 break;
             }
             String tAns = sAns.trim();
             String tRes = sRes.trim();
             if(!tAns.equals(tRes)) {
                 if (matchDouble(tAns,tRes, showInfo && printDoubleCheck)) {
                     if (showInfo && printDoubleCheck) {
                         System.out.println("### line "+ln+" pass double check:");
                         System.out.println("ans = "+sAns);
                         System.out.println("res = "+sRes);
                         System.out.println();
                     }
                 } else {
                     if (showInfo) {
                         System.out.println("### line "+ln+" not match:");
                         System.out.println("ans = "+sAns);
                         System.out.println("res = "+sRes);
                         System.out.println();
                     }
                     ok=false;
                     wrong.add(ln);
                 }
             }
             ln++;
         }
         if(!ok && showInfo) {
             System.out.println("wrong : "+wrong.size()+" lines, lines start from 1: "+wrong);
             System.out.println("total : "+ln+" lines");
         }
         ans.close();
         res.close();
         return ok;
     }
     private static boolean matchDouble(String tAns, String tRes, boolean showInfo) {
         final double tol = 1e-6;
 
         if (!tAns.matches(".*[0-9]+\\.[0-9]+.*") || !tRes.matches(".*[0-9]+\\.[0-9]+.*")) {
             // no 123.456 pattern
             return false;
         }
 
         String[] sa= tAns.split(" ");
         String[] sr= tRes.split(" ");
         if (sa.length!=sr.length) {
             return false;
         }
         for (int i = 0; i < sr.length; i++) {
             if (sa[i].equals(sr[i])) continue;
 
             try {
                 double a = Double.parseDouble(sa[i]);
                 double r = Double.parseDouble(sr[i]);
                 if (abs(a-r)>tol) {
                     if (showInfo) {
                         System.out.println(i+"-th ans!=res: "+sa[i]+" != "+sr[i]);
                     }
                     return false;
                 }
             } catch (NumberFormatException e) {
                 return false;
             }
         }
         return true;
     }
 
 
     private static void myTest() throws Exception {
 //        int num=-1000;
         int num=1000;
         for (int i = 1; i <= num; ++i) {
 //            System.out.println(i+" : "+new B().small(Rn.i(0,50)));
 //            for (int j = 1; j <= i; ++j) {
 //                System.out.println(i+","+j+" : "+i);
 //            }
         }
     }
 
     static String LINE() throws IOException {
         String s=in.readLine();
         if (printInput) System.out.println(s);
         return s;
     }
     static String STR() throws IOException {
         while (!inTok.hasMoreTokens()) {
             String line = LINE();
             if (line == null) {
                 return null;
             }
             inTok = new StringTokenizer(line);
         }
         return inTok.nextToken();
     }
 
     static int INT() throws IOException { return Integer.parseInt(STR()); }
     static long LONG() throws IOException { return Long.parseLong(STR()); }
     static double DOUBLE() throws IOException { return Double.parseDouble(STR()); }
     
     static int INT(String s) { return Integer.parseInt(s); }
     static double DOUBLE(String s) { return Double.parseDouble(s); }
     static long LONG(String s) { return Long.parseLong(s); }
 }
