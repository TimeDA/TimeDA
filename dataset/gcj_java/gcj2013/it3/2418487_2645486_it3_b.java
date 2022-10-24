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
         int E = INT();
         int R = INT();
         int N = INT();
         int[] v = new int[N];
         for (int i = 0; i < v.length; i++) {
             v[i] = INT();
         }
         
         /// reading input done
         if(caseNumber<caseStart||caseNumber>caseEnd) {
             System.out.println("### skip case "+caseNumber);
             return;
         }
 
         /// start solving problem
         
         long ret = small(E,R,v);
         
         out.printf("Case #%d: %s\n", caseNumber, ret);
 //        out.printf("Case #%d:", caseNumber);
 //        out.println();        
     }
 
     
     private long small(int E, int R, int[] v) {
         long[][] gain = new long[v.length+1][E+1];
         for (int i = 0; i < gain.length; i++) {
             for (int j = 0; j < gain[i].length; j++) {
                 gain[i][j]=-1;
             }
         }
         gain[0][E]=0;
         for (int i = 0; i < gain.length-1; i++) {
             for (int e = 0; e < gain[i].length; e++) {
                 if(gain[i][e]<0) continue;
                 
                 for (int e2 = 0; e2 <= e; e2++) {
                     int ne=min(e2+R,E);
                     long nv=gain[i][e]+1L*(e-e2)*v[i];
                     gain[i+1][ne] = Math.max(gain[i+1][ne], nv);
                 }
             }
         }
         long ret=0;
         for (int i = 0; i < gain[gain.length-1].length; i++) {
             ret = Math.max(ret, gain[gain.length-1][i]);
         }
 //        System.out.println("### gain");
 //        for (int i = 0; i < gain.length; i++) {
 //            System.out.printf("%2d: ", i);
 //            System.out.println(Arrays.toString(gain[i]));
 //        }
         return ret;
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
 //    static String testFilename="B-test.in";
     static String testFilename="B-small-attempt0.in";
 //    static String testFilename="B-small-attempt1.in";
 //    static String testFilename="B-small.in";
 //    static String testFilename="B-small-practice.in";
 //    static String testFilename="B-large.in";
 //    static String testFilename="B-large-practice.in";
     
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
                 new B().run(i);
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
                 boolean same=sameFileContent(ans, new File(resultFilename), true);
                 if(same) {
                     System.out.println("Answer correct :)");
                     System.out.println("Answer match file "+ans);
                 } else {
                     System.out.println("ERROR : Answer not matched");
                     
                     // check other possible answer file
                     for (int i = 1; i < 9; i++) {
                         ans=new File(testFilename+"-ans"+i+".txt");
                         if (ans.exists() && ans.length()>0) {                            
                             same=sameFileContent(ans, new File(resultFilename), false);
                             if (same) {
                                 System.out.println("\nAnswer correct :)");
                                 System.out.println("Answer match file "+ans);
                                 break;
                             }
                         }
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
