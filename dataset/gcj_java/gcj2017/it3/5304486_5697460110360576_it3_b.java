import static java.lang.Math.*;
 import static java.util.Arrays.*;
 import static java.util.Collections.reverse;
 import static java.lang.Integer.highestOneBit;
 import static java.lang.Integer.lowestOneBit;
 import static java.lang.Integer.numberOfLeadingZeros;
 import static java.lang.Integer.numberOfTrailingZeros;
 import static java.lang.Integer.bitCount;
 import static java.lang.Integer.parseInt;
 import static java.lang.Long.parseLong;
 
 import java.awt.geom.*;
 import java.io.*;
 import java.math.BigDecimal;
 import java.math.BigInteger;
 import java.util.*;
 import java.util.concurrent.*;
 import java.util.stream.*;
 
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
      * 
      */
     private void run(int caseNumber) throws Exception {
         int N = INT();
         int P = INT();
 
         int[] gram = new int[N];
         for (int i = 0; i < gram.length; i++) {
             gram[i] = INT();
         }
         int[][] quan = new int[N][P];
         for (int i = 0; i < quan.length; i++) {
             for (int j = 0; j < quan[i].length; j++) {
                 quan[i][j] = INT();
             }
         }
         
         
         /// reading input done
         if(debugTestCases.length>0 && Arrays.binarySearch(debugTestCases, caseNumber)<0) {
             if(writeToFile) {
                 out.printf("Case #%d: skip\n", caseNumber);
             }
             return;
         }
 
         
         /// start solving problem
         int res = 0;
         
         if (N==1) {
             for (int i = 0; i < P; i++) {
 //                if (ok(i, quan, gram)) {
 //                if (ok(new int[] {quan[0][i]}, gram)) {
                 if (ok2(new int[] {quan[0][i]}, gram)) {
 //                    System.out.println("  i=" + i);
                     res++;
                 }
             } 
         } else if (N==2) {
             boolean[][] adj = new boolean[P][P];
             for (int p1 = 0; p1 < P; ++p1) {
                 for (int p2 = 0; p2 < P; ++p2) {
                     if (ok2(new int[] {quan[0][p1], quan[1][p2]}, gram)) {
 //                      System.out.println("  i=" + i);
 //                      res++;
                         adj[p1][p2]=true;
                   }                    
                 }
             }
 //            System.out.println("### adj");
 //            for (int i = 0; i < adj.length; i++) {
 //                System.out.printf("%2d: ", i);
 //                System.out.println(Arrays.toString(adj[i]));
 //            }
             res = bipartiteMatch(adj);
         } else {
             System.out.println("ERROR N="+N);
         }
         
         out.printf("Case #%d: %s\n", caseNumber, res);
 //        out.printf("Case #%d:", caseNumber);
 //        out.println();
     }
 
     /*
      * adj=m*n matrix, adj[i][j]=true if i<->j
      * left:  m nodes
      * right: n nodes
      *
      * return maximum match number
      */
     static int bipartiteMatch(boolean[][] adj) {
         if (adj.length == 0)
             return 0;
 
         int n2 = adj[0].length;
         List<Integer>[] adjLst = getAdjLst(adj);
         /*
          * store current match
          * left i --> right matchTo[i], matchTo[i]=-1 if i unused
          */
         int[] matchTo = new int[n2];
         Arrays.fill(matchTo, -1);
         boolean[] used = new boolean[n2];
         int flow = 0;
         for (int i = 0; i < adjLst.length; ++i) {
             Arrays.fill(used, false); // reset unused
             if (augmentPath(adjLst, i, matchTo, used)) {
                 flow++;
             }
         }
         return flow;
     }
 
     static List<Integer>[] getAdjLst(boolean[][] adj) {
         List<Integer>[] adjLst = new List[adj.length];
         for (int i = 0; i < adjLst.length; i++) {
             adjLst[i] = new ArrayList<Integer>();
         }
         for (int i = 0; i < adj.length; i++) {
             for (int j = 0; j < adj[i].length; j++) {
                 if (adj[i][j]) {
                     adjLst[i].add(j);
                 }
             }
         }
         return adjLst;
     }
 
     static boolean augmentPath(List<Integer>[] adjLst, int i1,
             int[] matchTo, boolean[] used) {
         // the previous assign was not matched
         if (i1 == -1)
             return true;
 
         for (int i2 : adjLst[i1]) {
             if (!used[i2]) {
                 used[i2] = true;
                 if (augmentPath(adjLst, matchTo[i2], matchTo, used)) {
                     matchTo[i2] = i1;
                     return true;
                 }
             }
         }
         return false;
     }
     
     // ceil(a/b) , for a>=0, b>0
     static int ceil(int a, int b) {
         return (a + b - 1) / b;
     }
 
     private boolean ok2(int[] val, int[] gram) {
         int lo = 0, hi = INF;
         for (int i = 0; i < gram.length; i++) {
             lo = Math.max(lo, ceil(val[i]*10, 11*gram[i]));
             hi = Math.min(hi, val[i]*10/9/gram[i]);
         }
         return hi > 0 && hi>=lo;
 //        int cnt = val[0]/gram[0];
 //        int d = 1;
 ////        int d = 10;
 ////        int d = 100;
 ////        for (int j = max(1,cnt-1); j <= cnt+2; j++) {
 //        for (int v = max(1,cnt-d); v <= cnt+d; v++) {
 ////            if (okCnt(j, p, quan, gram)) {
 //            if (okCnt(v, val, gram)) {
 //                return true;
 //            }
 //        }
 //        return false;
     }
     
     private boolean ok(int[] val, int[] gram) {
         int cnt = val[0]/gram[0];
         int d = 1;
 //        int d = 10;
 //        int d = 100;
 //        for (int j = max(1,cnt-1); j <= cnt+2; j++) {
         for (int v = max(1,cnt-d); v <= cnt+d; v++) {
 //            if (okCnt(j, p, quan, gram)) {
             if (okCnt(v, val, gram)) {
                 return true;
             }
         }
         return false;
     }
 //    private boolean ok(int p, int[][] quan, int[] gram) {
 //        int cnt = quan[0][p]/gram[0];
 //        for (int j = max(1,cnt-1); j <= cnt+2; j++) {
 //            if (okCnt(j, new int[] {quan[0][p]}, gram)) {
 //                return true;
 //            }
 //        }
 //        return false;
 //    }
 
 
 //    private boolean okCnt(int cnt, int p, int[][] quan, int[] gram) {
 //        for (int j = 0; j < gram.length; j++) {
 //            if (cnt*9*gram[j]>10*quan[j][p] || 10*quan[j][p]>cnt*11*gram[j]) {
 //                return false;
 //            }
 //        }
 //        return true;
 //    }
     
     private boolean okCnt(int cnt, int[] val, int[] gram) {
         for (int i = 0; i < gram.length; i++) {
             if (cnt*9*gram[i]>10*val[i] || 10*val[i]>cnt*11*gram[i]) {
                 return false;
             }
         }
         return true;
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
         "B-test.in",
 //        "B-small-attempt0.in",
 //        "B-small-attempt1.in",
         "B-small-attempt2.in",
 //        "B-small.in",
 //        "B-small-practice.in",
 //        "B-large.in",
 //        "B-large-practice.in",
 //        null, // for myTest()
     };
 
     static int THREAD=1;
 //    static int THREAD=3;
 
     static BufferedReader in;
     static StringTokenizer inTok = new StringTokenizer("");
     static PrintWriter out;
 
     /// only run given cases, {} runs all
 //    static int[] debugTestCases = {7, 35, 74, 81, 85, 89, 94};
 //    static int[] debugTestCases = {89};
 //    static int[] debugTestCases = {7};
 //    static int[] debugTestCases = {5};
 //    static int[] debugTestCases = {2};
     static int[] debugTestCases = {};
 
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
         if (testFilename == null) {
             myTest();
             return;
         }
 
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
         List<GcjSolver> solvers = new ArrayList<GcjSolver>();
         for (int i = 1; i <= totalCase; i++) {
             if (printInput) System.out.println("\n### Case "+i);
 
             solvers.add(new GcjSolver());
         }
 
         List <Future<Object>> results = executor.invokeAll(solvers);
 
         int caseNumber=1;
         for (Future<Object> result : results) {
             /// ! print the output
             out.printf("Case #%d: %s\n", caseNumber, result.get());
             caseNumber++;
         }
         executor.shutdown();
     }
     static class GcjSolver implements Callable<Object> {
         final int n;
 
         /// !! Do all input reading here
         public GcjSolver() throws IOException {
             n = INT();
             throw new RuntimeException("TODO: do reading/solving in "+getClass().getSimpleName());
         }
 
         /// Do no reading here! This is run async!
         /// !! Solve the actual problem here, return the result to print
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
                 if (debugTestCases.length > 0 && tRes.endsWith(": skip")) {
                     // no compare for skip lines
                 } else if (matchDouble(tAns,tRes, showInfo && printDoubleCheck)) {
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
         int num=10000;
         for (int i = 1; i <= num; ++i) {
 //            System.out.println("run " + i + ": " + new B().small(Rn.i(0,50)));
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
