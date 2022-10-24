
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
import java.util.Map.Entry;
import java.util.concurrent.*;
import java.util.stream.*;


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
     * 
     */
    /*
     * solution
     * 
     * 
     */
    private void run(int caseNumber) throws Exception {
        int C = INT();

        int[] b = new int[C];
        for (int i = 0; i < b.length; i++) {
            b[i] = INT();
        }
        
        /// reading input done
        if(debugTestCases.length>0 && Arrays.binarySearch(debugTestCases, caseNumber)<0) {
            if(writeToFile) {
                out.printf("Case #%d: skip\n", caseNumber);
            }
            return;
        }

        /// start solving problem        
//        String[] res = small(C, b);        
        String[] res = greedy(C, b);        
        
        out.printf("Case #%d: %s\n", caseNumber, res == null ? NO : ((res.length+1)+""));
        if (res != null) {
//            String[] ans = done.get(goal);
            for (int i = 0; i < res.length; i++) {
                out.println(res[i]);
            }
            char[] a = new char[C]; 
            fill(a,'.');
            out.println(new String(a));
        }
//        out.printf("Case #%d:", caseNumber);
//        out.println();
    }

    static private String[] greedy(int c, int[] b) {
        if (b[0] == 0 || b[c-1] == 0) {
            return null;
        }
        
        int[] goal = b.clone();
        for (int i = 1; i < goal.length; i++) {
            goal[i] += goal[i-1];
        }
        List<String> ls = new ArrayList<>();
        char[] s = new char[c];
        fill(s,'.');
//        ls.add(new String(s));
        int[] cnt = new int[b.length];
        fill(cnt,1);
//        System.out.println("  goal[" + goal.length + "]=" + Arrays.toString(goal));
        boolean ok = false;
        while (!Arrays.equals(cnt, b)) {
//            ok = true;
            int sum = 0;
            int[] ncnt = new int[c];
            for (int i = 0; i < cnt.length; i++) {
                if (i == 0 || i == cnt.length-1) {
                    ncnt[i] += cnt[i];
                    sum += cnt[i];
                } else if (i > 0 && sum < goal[i-1]) {
                    s[i] = '/';
                    ncnt[i-1] += cnt[i];
                    sum += cnt[i];
                } else {                    
                    sum += cnt[i];
//                    if (i == cnt.length-1) {
//                    } else if (sum < goal[i]) {
//                        s[i+1] = '/';
//                        ncnt[i] += cnt[i+1];
//                        ok = false;
                    if (sum > goal[i]) {
                        s[i] = '\\';
                        ncnt[i+1] += cnt[i];
                        ok = false;
                    } else {
                        ncnt[i] += cnt[i];
                    }
                }
            }
            cnt = ncnt;
            ls.add(new String(s));
//            System.out.println("  ncnt[" + ncnt.length + "]=" + Arrays.toString(ncnt));
//            System.out.println("  s=" + new String(s));
        }
        
        String[] res = new String[ls.size()];
        for (int i = 0; i < res.length; i++) {
            res[i]=ls.get(ls.size()-1-i);
        }
        return res;
    }

    static String[] small(int C, int[] b) {
        char[] a = new char[C];
        a[0] = a[C-1] = '.';
        List<String> ls = new ArrayList<>();
        gen(1, a, ls);
//        System.out.println("  ls=" + ls);
        
        String[] res = null;
        Map<State, String[]> done = new HashMap<>();
        Set<State> cur = new HashSet<>();
        State goal = new State(b);
//        int[] goal = new int[C];
//        fill(goal,1);
        int[] beg = new int[C];
        fill(beg,1);
        State init = new State(beg);
//        State init = new State(b);
        cur.add(init);
//        fill(a,'.');
//        done.put(init, new String[] {new String(a)});
        done.put(init, new String[0]);
        while (true) {
//        for (int step = 0; ; step++) {
            Set<State> next = new HashSet<>();
            for (State st : cur) {
//                if (Arrays.equals(st.a, goal)) {
                if (Arrays.equals(st.a, b)) {
                    res = done.get(st);
                    break;
                }
                String[] ss = done.get(st);
                for (String s : ls) {
                    int[] na = new int[st.a.length];
                    for (int i = 0; i < s.length(); i++) {
                        char c = s.charAt(i);
                        if (c=='.') {
                            na[i] += st.a[i];
                        } else if (c=='/') {
                            na[i-1] += st.a[i];                            
                        } else { // \
                            na[i+1] += st.a[i];
                        }
                    }
                    State nst = new State(na);
                    String[] nss = new String[ss.length+1];
                    if (!done.containsKey(nst)) {
                        next.add(nst);
                        for (int i = 0; i < ss.length; i++) {
                            nss[i] = ss[i];
                        }
                        nss[ss.length] = s;
                        done.put(nst, nss);
                    }
                }
            }
            if (next.isEmpty()) {
                break;
            }
            cur = next;
//            System.out.println("  next=" + next);
        }

        ArrayList<Entry<State, String[]>> all = new ArrayList<>(done.entrySet());
        System.out.println("size="+all.size());
        Collections.sort(all, new Comparator<Entry<State, String[]>>() {
            @Override
            public int compare(Entry<State, String[]> o1, Entry<State, String[]> o2) {
                return o1.getValue().length-o2.getValue().length;
            }
        });
        for (Entry<State, String[]> e : all) {
            System.out.println(e.getKey());
            String[] ss = done.get(e.getKey());
            for (int i = 0; i < ss.length; i++) {
                System.out.println(ss[i]);
            }
            System.out.println();
        }
//        for (State st : done.keySet()) {
//            System.out.println(st);
//            String[] ss = done.get(st);
//            for (int i = 0; i < ss.length; i++) {
//                System.out.println(ss[i]);
//            }
//            System.out.println();
//        }
        
        return res;
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

    private static void gen(int i, char[] a, List<String> ls) {
        if (i==a.length-1) {
            ls.add(new String(a));
            return;
        }
        
        for (char c : ".\\/".toCharArray()) {
            if (c=='/' && a[i-1] == '\\') {
                continue;
            }
            
            a[i] = c;
            gen(i+1, a, ls);
        }
    }
    
    static boolean printInput=false;
//    static boolean printInput=true; // print input case

    static boolean printDoubleCheck=true;
//    static boolean printDoubleCheck=false;

    static boolean redirectStdoutToFile=false;
//    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"

    
//    static boolean writeToFile=true; // output result to file
    static boolean writeToFile=false;

    final static String filePrefix = "A";
    static String[] testFilenames = new String[] {
        null,
//        filePrefix + "-test.in",
//        filePrefix + "-small-attempt0.in",
//        filePrefix + "-small-attempt1.in",
//        filePrefix + "-small.in",
//        filePrefix + "-small-practice.in",
//        filePrefix + "-large.in",
//        filePrefix + "-large-practice.in",
    };

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

//        if (testFilenames[0] != null) myTest();        
        
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
        in.close();

        if (writeToFile) {
            out.close();
        }

        if (testFilename == null) {
            System.err.println("\nTime taken: "+((System.currentTimeMillis()-start)/1000.0)+" sec");
        }

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
        long now = System.currentTimeMillis();
        
        String[] res = small(2, new int[] {1,1});
        System.out.println("  res[" + res.length + "]=" + Arrays.toString(res));
        res = small(2, new int[] {2,0});
        System.out.println("  res=" + res);
        
        for (int C = 2; C < -12; C++) {
            System.out.println("###  C=" + C);
            check(new int[C]);
        }

//        for (int[] a : new int[][] {
//            new int[] {1,1,1},
//            new int[] {1,2,0},
//            new int[] {0,1,2},
//        }) {
//            check(a);
//        }
        
//        int num = -1000;
        int num = 10000;

        for (int i = 1; i <= num; ++i) {
//            int C = lib.Rn.i(2,8);
//            System.out.println("run " + i + ": ");
//            int res = small(lib.Rn.i(0,50);
//            for (int j = 1; j <= i; ++j) {
//                System.out.println(i+","+j+" : "+i);
//            }
        }
        System.out.println("run time = " + (System.currentTimeMillis() - now) / 1000.0 + " sec");
    }

    static void check(int[] a) {
        String[] res;
        System.out.println("  a[" + a.length + "]=" + Arrays.toString(a));
        res = small(a.length, a);
        if (res != null) {
            for (int i = 0; i < res.length; i++) {
                out.println(res[i]);
            }
        } else {
            System.out.println("  res=" + res);
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
