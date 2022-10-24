import java.io.BufferedInputStream;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.*;


import static java.util.Arrays.*;
import static java.lang.Math.*;


 class Solution {
	
	Scanner scan;
	public Solution(Scanner s) {
		this.scan = s;
	}

	class P implements Comparable<P>{
		char s;
		int x;
		P(char ss, int xx){
			s=ss;x=xx;
		}
		@Override
		public int compareTo(P arg0) {
			return arg0.x - x;
		}
	}
	public String solve() {
		String res ="";
		int n = scan.nextInt();
		P[] A = new P[n];
		int tot =0;
		for(int i=0;i<n;i++){
			int x = scan.nextInt();
			tot+=x;
			A[i]=new P((char)('A'+i),x);
		}
		while(tot>0){
			sort(A);
			if((A[0].x==A[1].x && A[0].x +A[1].x ==tot)) {
				A[0].x--;A[1].x--;tot-=2;
				res+=A[0].s+""+A[1].s+" ";
			}else{
				A[0].x--;
				tot--;
				res+=A[0].s+" ";
			}
		}
		return res;
	}
	int intLine(){
		return Integer.parseInt(scan.nextLine());
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


