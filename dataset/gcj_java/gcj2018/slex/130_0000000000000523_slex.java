import java.util.Scanner;

public class Solution {
	static Scanner scan = new Scanner(System.in);
	
	static void solve(int a, int b, int n){
		a++;b++;
		for(int t=0;t<n;t++){
			int x = (a+b)/2;
			System.out.println(x);
			System.out.flush();
			String s = scan.next();
			if(s.equals("CORRECT")||s.equals("WRONG_ANSWER"))return;
			if(s.equals("TOO_SMALL")){
				a = x;
			}else if(s.equals("TOO_BIG")){
				b = x;
			}
	
		}
	}
	public static void main(String[] args) {
	int t = scan.nextInt();
	for(int i=0;i<t;i++){
		int a = scan.nextInt();
		int b = scan.nextInt();
		int n = scan.nextInt();
		solve(a,b,n);
	}
}
}
