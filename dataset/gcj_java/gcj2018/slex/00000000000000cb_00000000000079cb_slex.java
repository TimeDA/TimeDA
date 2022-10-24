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
		int n = scan.nextInt();
		int[]A = new int[n];
		for(int i=0;i<n;i++)A[i]=scan.nextInt();
		ArrayList<Integer>od=new ArrayList<>();
		ArrayList<Integer>ev=new ArrayList<>();
		for(int i=0;i<n;i++)if(i%2==0)ev.add(A[i]);else od.add(A[i]);
		Arrays.sort(A);
		Collections.sort(ev);
		Collections.sort(od);
		for(int i=0;i<n;i++){
			int x;
			if(i%2==0){
			   x = ev.get(i/2);
			}else x = od.get(i/2);
			if(x!=A[i])return ""+i;
		}
		return "OK";
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
