import java.io.BufferedInputStream;
 import java.io.FileInputStream;
 import java.io.InputStream;
 import java.util.*;
 
 import static java.lang.Math.*; 
 import static java.util.Arrays.*;
 import static java.lang.Integer.*;
 import static java.lang.Character.*;  
 
 
 
 public class A {
 
 	Scanner scan;
 	InputStream in;
 	HashMap<Character, Character>Map = new HashMap<Character, Character>();
 	String[] sampleIn = {
 		"y qee",
 		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
 		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
 		"de kr kd eoya kw aej tysr re ujdr lkgc jv",
 		"z",
 	};
 	String[] sampleOut = {
 			"a zoo",
 			"our language is impossible to understand",
 			"there are twenty six factorial possibilities",
 			"so it is okay if you want to just give up",
 			"q"
 	};
 	
 	
 	int intLine(){
 		return parseInt(scan.nextLine());
 	}
 	
 	String solve(){
 		String s = scan.nextLine();
 		String res = "";
 		for(int i=0;i<s.length();i++)res+=Map.get(s.charAt(i));
 	    return res;
 	}
 	
 	void solveAll(){
 		int N = parseInt(scan.nextLine());
 		for(int i=0;i<N;i++){
 			String r =solve();
 			System.out.format("Case #%d: %s\n",i+1,r);
 		}
 	}
 	
 	A() throws Exception{
 		for(int s=0;s<sampleIn.length;s++){
 			for(int i=0;i<sampleOut[s].length();i++){
 				Map.put(sampleIn[s].charAt(i), sampleOut[s].charAt(i));
 			}
 		}
 		String cn = A.class.getName();
 		String sampleName = cn+"-sample.in";
 		String smallName = cn+"-small-attempt1.in";
 		String largeName = cn+"-large.in";
 		InputStream in = new BufferedInputStream(new FileInputStream(smallName));
 		scan = new Scanner(in);
 	}
 	
 	public static void main(String[] args) throws Exception{
 	    Locale.setDefault(Locale.US); 
 	    new A().solveAll();
 	}
 
 }
