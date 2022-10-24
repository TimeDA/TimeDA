import java.io.*;
import java.util.*;

public class Solution {
	public void run() throws IOException {
		int low = in.nextInt();
		int high = in.nextInt() + 1;
		in.nextInt();
		for (;;) {
			int mid = (low + high) / 2;
			System.out.println(mid);
			System.out.flush();
			String responce = in.next();
			switch (responce) {
			case "CORRECT":
				return;
			case "TOO_SMALL":
				low = mid;
				break;
			case "TOO_BIG":
				high = mid;
				break;
			}
		}
	}
	
	static Scanner in;

	public static void main(String[] args) throws IOException {
		in = new Scanner(System.in);
		int tests = in.nextInt();
		for (int t = 0; t < tests; t++) {
			new Solution().run();
		}
		in.close();
	}
}
