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
	
	

	public String solve() {
		int N = scan.nextInt();
		boolean U[] = new boolean[N];
		int[]pop = new int[N];
		for(int i =0;i<N;i++){
			int d = scan.nextInt();
			int[]A = new int[d];
			for(int j=0;j<d;j++){
				A[j]=scan.nextInt();
				pop[A[j]]++;
			}
			int res =-1;
			ArrayList<Integer>can = new ArrayList<>();
			for(int j=0;j<d;j++){
				int x = A[j];
				if(U[x]==false){
					can.add(x);
				}
			}
			if(can.size()>0){
				res = can.get(0);
				for(int j=1;j<can.size();j++){
					int x = can.get(j);
					if(pop[x]<pop[res]){
						res = x;
					}
				}
			}
			System.out.println(res);
			if(res!=-1)U[res]=true;
		}
		return "";
	}
	
	
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		
	
		Scanner scan = new Scanner(System.in);
		int N = Integer.parseInt(scan.nextLine());
		for(int c=1;c<=N;c++) {
			new Solution(scan).solve();
			//System.out.format("Case #%d: %s\n", c, res);
		}
		
	}
}
