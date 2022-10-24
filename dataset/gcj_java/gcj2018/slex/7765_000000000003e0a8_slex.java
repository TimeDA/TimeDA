import static java.lang.Math.*;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
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
	
	
	int N;
	int[]W;
	int[][]M;
	int doit(int p, int w){
		int res =0;
		if(M[p][w]!=-1)return M[p][w];
		for(int i=p;i<N;i++){
			if(W[i]<=w){
				int nw = min(6*W[i],w-W[i]);
				int r = 1+ doit(i+1, nw);
				res = max(res,r);
			}
		}
		return M[p][w]=res;
	}
	public String solve2() {
		N = scan.nextInt();
		W = new int[N];
		M = new int[N+1][10001];
		for(int[]m:M)Arrays.fill(m,-1);
		for(int i=0;i<N;i++){
			W[N-i-1]=scan.nextInt();
		}
		int res = doit(0, 10000);
		return ""+res;
	}
	
	public String solve() {
		N = scan.nextInt();
		W = new int[N];
		for(int i=0;i<N;i++){
			W[i]=scan.nextInt();
		}
		int res = 0;
		long[]D = new long[N+1];
		long oo = Long.MAX_VALUE/2;
		Arrays.fill(D, oo);
		D[0]=0;
		
		for(int i=0;i<N;i++){
			
			long w = W[i]*6L;
			for(int j=res;j>=0;j--){
				if(D[j]<=w){
					D[j+1] = min(D[j+1], W[i]+D[j]);
					res = max(res,j+1);
				} 
			}
			
		}

		return ""+res;
	}
	
	
	
	
	
	
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		
	/*	Random R = new Random();
		PrintStream bo =new PrintStream(new FileOutputStream("big.in"));
		for(int i=0;i<1000;i++){
			int x =R.nextInt(1000000000);
			bo.print(x+ " ");
		}
		bo.println();*/
		String name = "big.in";
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
