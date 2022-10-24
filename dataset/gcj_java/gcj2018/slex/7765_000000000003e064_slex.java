import static java.lang.Math.*;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.*;

public class Solution {
	Scanner scan;

	public Solution(Scanner s) {
		scan = s;
	}
	
	int intLine(){
		return Integer.parseInt(scan.nextLine());
	}
	
	HashSet<String>all = new HashSet<>();
	char[][]B;
	
	String gen(StringBuffer sb, int p){
		if(p==B[0].length){
			if(!all.contains(sb.toString())){
				return sb.toString();
			}
			return null;
		}
		boolean U[] = new boolean[26];
		for(int i=0;i<B.length;i++){
			if(U[B[i][p]-'A'])continue;
			U[B[i][p]-'A'] = true;
			sb.append(B[i][p]);
			String r =gen(sb,p+1);
			if(r!=null)return r;
			sb.delete(sb.length()-1, sb.length());
		}
		return null;
	}
	
	public String solve() {
		int N = scan.nextInt();
		int L = scan.nextInt();
		B  =new char[N][L];
	
		for(int i=0;i<N;i++){
			String s= scan.next();
			all.add(s);
			B[i]=s.toCharArray();
		}
		long w = 1;
		for(int i=0;i<L;i++){
			HashSet<Character>H = new HashSet<>();
			for(int j=0;j<N;j++)H.add(B[j][i]);
			w*= H.size();
		}
		
			String s = gen(new StringBuffer(), 0);
			if(s!=null)return s;
			return ((char)45)+"";
	}
	
	
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		
		String name = "sample.in";
		InputStream in;
		try{
			Class.forName("TemplateSlex");
			in = new BufferedInputStream(new FileInputStream(name));
		}catch(ClassNotFoundException cnfe){
			in = System.in;
		}
		
		Scanner scan = new Scanner(in);
		int N = Integer.parseInt(scan.nextLine());
		for(int c=1;c<=N;c++) {
			String res = new Solution(scan).solve();
			System.out.format("Case #%d: %s\n", c, res);
		}
		
	}
}
