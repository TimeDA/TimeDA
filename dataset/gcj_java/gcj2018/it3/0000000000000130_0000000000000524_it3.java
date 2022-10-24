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
public class Solution {
//    private static final String IMPOSSIBLE = "IMPOSSIBLE";
    private static final String NO = "IMPOSSIBLE";
    public static final long MAX = Long.MAX_VALUE;
    public static final int INF = 1000000009;
    public static final int MOD = 1000000007;
    public static final int UNDEF = -3;

    /*
     * problem
     * 
The word will be CORRECT if your guess is correct, TOO_SMALL if your guess is less than the correct answer, and TOO_BIG if your guess is greater than the correct answer. Then, you can start another exchange. 
     * 
     */
    /*
     * solution
     * 
     * 
     */
    private void run(int caseNumber) throws Exception {
        int d = INT();
        int n = INT();
        
        int[] k = new int[n];
        int[] s = new int[n];
        for (int i = 0; i < s.length; i++) {
            k[i] = INT();
            s[i] = INT();
        }

        /// reading input done
        if(debugTestCases.length>0 && Arrays.binarySearch(debugTestCases, caseNumber)<0) {
            if(writeToFile) {
                out.printf("Case #%d: skip\n", caseNumber);
            }
            return;
        }

//        System.out.println(a+" "+b+": "+n);
        
        /// start solving problem
        double res = 1e100;
        for (int i = 0; i < s.length; i++) {
            double t = 1.0*(d-k[i])/s[i];
            res = Math.min(res, d/t);
        }
        
        System.out.printf("Case #%d: %f\n", caseNumber, res);
    }

    
    static boolean printInput=false;
//    static boolean printInput=true; // print input case

    static boolean printDoubleCheck=true;
//    static boolean printDoubleCheck=false;

    static boolean redirectStdoutToFile=false;
//    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"

    
//    static boolean writeToFile=true; // output result to file
    static boolean writeToFile=false;

    static String[] testFilenames = new String[] {
        null,
//        "C-test.in",
//        "C-small-attempt0.in",
//        "C-small-attempt1.in",
//        "C-small.in",
//        "C-small-practice.in",
//        "C-large.in",
//        "C-large-practice.in",
    };

    static int THREAD=1;
//    static int THREAD=3;

    static BufferedReader in;
    static StringTokenizer inTok = new StringTokenizer("");
    static PrintWriter out;

    /// only run given cases, {} runs all
    static int[] debugTestCases = {};
//    static int[] debugTestCases = {};
//    static int[] debugTestCases = {};
//    static int[] debugTestCases = {};
//    static int[] debugTestCases = {};
//    static int[] debugTestCases = {};
//    static int[] debugTestCases = {};
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
//        System.out.println("lala");
        
//        solveFile(null);
        for (int i = 0; i < testFilenames.length; i++) {
//            System.out.println((i>0?"\n\n":"") + "##### file["+i+"]: "+testFilenames[i]);
            solveFile(testFilenames[i]);
        }
    }

    static void solveFile(String testFilename) throws Exception {
//        if (testFilename == null) {
//            myTest();
//            return;
//        }

        String resultFilename=testFilename+"-res.txt";
        long start = System.currentTimeMillis();
//        in = new BufferedReader(new InputStreamReader(System.in));
        in = new BufferedReader(testFilename == null ? new InputStreamReader(System.in) : 
                                                       new FileReader(testFilename));
        int NN=INT();
        out = writeToFile ? new PrintWriter(new FileWriter(resultFilename),true) // auto flush
                          : new PrintWriter(System.out, true); // auto flush
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
                new Solution().run(i);
                if (debug) {
                    printInput = false;
                }
            }
        }
        in.close();

        if (writeToFile) {
            out.close();
        }

//        System.out.println("\nTime taken: "+((System.currentTimeMillis()-start)/1000.0)+" sec");

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
                if (!gcjDoubleEq(a, r, tol)) {
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

    private static boolean gcjDoubleEq(double e, double r, double tol) {
        if (Double.isNaN(e)) {
            return Double.isNaN(r);
        } else if (Double.isInfinite(e)) {
            if (e > 0) {
                return r > 0 && Double.isInfinite(r);
            } else {
                return r < 0 && Double.isInfinite(r);
            }
        } else if (Double.isNaN(r) || Double.isInfinite(r)) {
            return false;
        } else if (Math.abs(r - e) < tol) {
            return true;
        } else {
            double min = Math.min(e * (1.0 - tol), e * (1.0 + tol));
            double max = Math.max(e * (1.0 - tol), e * (1.0 + tol));
            return r > min && r < max;
        }
    }

    private static void myTest() throws Exception {
//        int num=-1000;
        int num=10000;
        for (int i = 1; i <= num; ++i) {
//            System.out.println("run " + i + ": " + new A().small(Rn.i(0,50)));
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
