import static java.lang.Math.*;
 import static java.util.Arrays.*;
 import static java.util.Collections.reverse;
 import static java.lang.Integer.*;
 import static java.lang.Long.parseLong;
 import java.util.*;
 import java.awt.geom.*;
 import java.io.*;
 
 //// Apache Jakarta Common Lang : http://commons.apache.org/lang/
 //import org.apache.commons.lang.builder.*;
 
 // java -Xmx1024m -Xss5m
 @SuppressWarnings("unchecked")
 public class A {
 //    private static final String IMPOSSIBLE = "IMPOSSIBLE";
     private static final String NO = "IMPOSSIBLE";
     public static final long MAX = Long.MAX_VALUE;
     public static final int INF = 1000000000;
     public static final int MOD = 9901; 
     public static final int UNDEF = -3;
 
     /*
      * 
      */
     private void run(int caseNumber) throws Exception {
         /*
          * 
          */
         int n = INT();
 
         int[] d = new int[n+2];
         int[] l = new int[n+2];
         for (int i = 1; i <= n; i++) {
             d[i] = INT();
             l[i] = INT();
         }
         int D=INT();
         final int GOAL=n+1;
         d[0]=0;
         l[0]=l[1];
         d[GOAL]=D;
         l[GOAL]=INF;
         
         /// reading input done
         if(caseNumber<caseStart||caseNumber>caseEnd) {
             System.out.println("### skip case "+caseNumber);
             return;
         }
 
         
         /// start solving problem
         String ret = "NO";
         Set<XY> cur = new HashSet<XY>();
         cur.add(new XY(0, 1));
         Set<XY> done = new HashSet<XY>(cur);
         while (true) {
             //for (int step = 0; step < n; step++) {
             Set<XY> nxt = new HashSet<XY>();
             for (XY xy : cur) {
                 int i=xy.x;
                 int j=xy.y;
                 int len=min(d[j]-d[i],l[j]);
                 int to=d[j]+len;
                 for (int k = j+1; k < d.length; k++) {
                     if (to<d[k])
                         break;
                     
                     XY nxy = new XY(j, k);
                     //if(!nxt.contains(nxy)) { //!!! REMOVE THIS if better solution in the same round is possible
                     if (!done.contains(nxy)) { //!!! REMOVE THIS if better solution in the same round is possible
                         nxt.add(nxy);
                         done.add(nxy);
                         if (k==GOAL) {
                             ret="YES";
                             break;
                         }
                     }
                 }
             }
             if (nxt.isEmpty()) {
                 break;
             }
             cur = nxt;
 //            System.out.println("  nxt=" + nxt);
         }
         
         out.printf("Case #%d: %s\n", caseNumber, ret);
 //        out.printf("Case #%d:", caseNumber);
 //        out.println();
     }
     
     static class XY implements Comparable<XY> {
         int x;
         int y;
 
         public XY(int x, int y) {
             this.x = x;
             this.y = y;
         }
 
         public String toString() {
             return "(" + x + ", " + y + ")";
         }
 
         public int hashCode() {
             int M = 31, r = M + x;
             r = M * r + y;
             return (int) r;
         }
 
         public boolean equals(Object a) {
             if (a == null || getClass() != a.getClass())
                 return false;
             XY o = (XY) a;
             return x == o.x && y == o.y;
         }
 
         public int compareTo(XY o) {
             // < : -1 smallest 1st
             if (x != o.x)
                 return x < o.x ? -1 : 1;
             return y < o.y ? -1 : (y == o.y ? 0 : 1);
         }
     }
 
     
     static boolean printInput=false;
 //    static boolean printInput=true; // print input case
     
     static boolean printDoubleCheck=true;
 //    static boolean printDoubleCheck=false;
     
     static boolean redirectStdoutToFile=false;
 //    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"
 
     
     static boolean writeToFile=true;
 //    static boolean writeToFile=false;
     
 //    static String testFilename=null;
 //    static String testFilename="A-test.in";
     static String testFilename="A-small-attempt0.in";
 //    static String testFilename="A-small-attempt1.in";
 //    static String testFilename="A-small.in";
 //    static String testFilename="A-small-practice.in";
 //    static String testFilename="A-large.in";
 //    static String testFilename="A-large-practice.in";
     
     static String resultFilename=testFilename+"-res.txt";
     
     static BufferedReader in;
     static StringTokenizer inTok = new StringTokenizer("");
 
 //    static Scanner in;
     static PrintWriter out;
 
     //control the cases to run : [caseStart..csaeEnd]
     static int caseStart=1;
 //    static int caseStart=1;
     static int caseEnd=Integer.MAX_VALUE;
 //    static int caseEnd=caseStart+0;
     
     public static void main(String[] args) throws Exception {
         long start = System.currentTimeMillis();
 
 //        myTest();        
         
         // $0 inputFile caseStart caseEnd
         if(args.length>0) {
             testFilename = args[0];
         }
         if(args.length>1) {
             caseStart=parseInt(args[0]);
         }
         if(args.length>2) {
             caseEnd=parseInt(args[1]);
         }
         
         // redirect sys out
         if(redirectStdoutToFile) {            
             String filename = "output.txt";
             System.out.println("NOTE: redirect stdout to file "+filename);
             FileOutputStream fos = new FileOutputStream(filename);
             PrintStream ps = new PrintStream(fos,true);
             System.setOut(ps);
         }
         
         if(testFilename==null) {
             myTest();
         } else {
 //          in = new BufferedReader(new InputStreamReader(System.in));
             in = new BufferedReader(new FileReader(testFilename));
             int NN=INT();
 //            in = new Scanner(System.in);
 //            in = new Scanner(new File(testFilename));
 //            int NN=in.nextInt();
             out = writeToFile ? new PrintWriter(new FileWriter(resultFilename),true) 
                               : new PrintWriter(System.out, true);
             for (int i = 1; i <= NN; i++) {
 //                out.printf("Case #%d: ", i);
                 if (printInput) System.out.println("\n### Case "+i);                
                 new A().run(i);
             }
             in.close();
             
             if(writeToFile) {
                 out.close();
             }
         }
         
         System.out.println("\nTime taken: "+((System.currentTimeMillis()-start)/1000.0)+" sec");
         
         if(writeToFile) {
             File ans=new File(testFilename+"-ans.txt");
             if(ans.exists()&&ans.length()>0) {
                 boolean same=sameFileContent(ans,new File(resultFilename));
                 if(same) {
                     System.out.println("Answer correct :)");
                 } else {
                     System.out.println("ERROR : Answer not matched");
                 }
             }            
         }
     }
     
     private static boolean sameFileContent(File ansFile, File resFile) throws IOException {
         System.out.println();
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
                     System.out.println("### result has more lines than answer");
                     do {
                         System.out.println(sRes);
                     } while ((sRes=res.readLine())!=null);
                     System.out.println();
                     ok=false;
                 }
                 break;
             }
             if(sRes==null) {
                 if(sAns!=null && !sAns.isEmpty()) {
                     System.out.println("### answer has more lines than result");
                     do {
                         System.out.println(sAns);
                     } while ((sAns=ans.readLine())!=null);
                     System.out.println();
                     ok=false;
                 }
                 break;
             }
             String tAns = sAns.trim();
             String tRes = sRes.trim();
             if(!tAns.equals(tRes)) {
                 if (matchDouble(tAns,tRes)) {
                     if (printDoubleCheck) {                            
                         System.out.println("### line "+ln+" pass double check:");
                         System.out.println("ans = "+sAns);
                         System.out.println("res = "+sRes);
                         System.out.println();
                     }                    
                 } else {
                     System.out.println("### line "+ln+" not match:");
                     System.out.println("ans = "+sAns);
                     System.out.println("res = "+sRes);
                     System.out.println();
                     ok=false;
                     wrong.add(ln);
                 }
             }
             ln++;
         }
         if(!ok) {
             System.out.println("wrong : "+wrong.size()+" lines, lines start from 1: "+wrong);
             System.out.println("total : "+ln+" lines");
         }
         ans.close();
         res.close();
         return ok;
     }    
     private static boolean matchDouble(String tAns, String tRes) {
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
                     System.out.println(i+"-th ans!=res: "+sa[i]+" != "+sr[i]);
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
 //            System.out.println(i+" : "+new A().small(Rn.i(0,50)));
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
