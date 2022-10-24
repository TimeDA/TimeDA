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
	boolean[][]B;
	
	Random R = new Random();
	int goes =0;
	boolean testGO(int x, int y){
		int r1=R.nextInt(3);
		int r2=R.nextInt(3);
		int xx = x+r1-1;
		int yy = y+r2-1;
		B[xx][yy]=true;
		return false;
	}
	
	boolean go(int x, int y){
		goes++;
		//return testGO(x,y);/*
		System.out.println(x+" "+(y+1));
		System.out.flush();
		int r1=scan.nextInt();int r2=scan.nextInt()-1;
		if(r1<1)return true;
		B[r1][r2]=true;
		return false;
	}
	
	boolean test9(int W){
		for(int x=W-2;x<=W;x++)for(int y=0;y<3;y++)if(!B[x][y])return false;
		return true;
	}
	
	public void solve() {
		int A = scan.nextInt();
		if(A<9)A=9;
		int W = (A+2)/3;
		B = new boolean[W+2][3];
		for(int i=2;i<=W-1;i++){
			while((B[i-1][0]&&B[i-1][1]&&B[i-1][2])==false){
				if(go(i,1))return;
			}
		}
		while(!test9(W)){
			if(go(W-1,1))return;
		}
		System.err.println("Finish after "+goes);
	}
	
	
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		Scanner scan = new Scanner(System.in);
		int N = Integer.parseInt(scan.nextLine());
		for(int c=1;c<=N;c++) {
			
			new Solution(scan).solve();
			
		}
		
	}
}
