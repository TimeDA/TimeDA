import static java.lang.Math.*;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.*;


class Solution {

	Scanner scan;

	public Solution(Scanner s) {
		scan = s;
	}
	
	int intLine(){
		return Integer.parseInt(scan.nextLine());
	}
	
	
	public String solve() {
		int D = scan.nextInt();
		char[]s = scan.next().toCharArray();
		int res =0;
		while(true){
			long cd = eval(s);
			if(cd <=D)return res+"";
			boolean sw=false;
			for(int i=s.length-2;i>=0;i--){
				if(s[i]=='C' &&s[i+1]=='S'){
					sw=true;
					s[i]='S';s[i+1]='C';
					break;
				}
			}
			if(!sw)return "IMPOSSIBLE";
			res++;
		}
		
	}
	
	private long eval(char[] s){
		long p =1;
		long res =0;
		for(char c:s){
			if(c=='C')p*=2;
			else res+=p;
		}
		return res;
	}
	
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		Scanner scan = new Scanner(System.in);
		int N = Integer.parseInt(scan.nextLine());
		for(int c=1;c<=N;c++) {
			
			String res = new Solution(scan).solve();
			System.out.printf("Case #%d: %s\n",c, res);
		}
		
	}
}
