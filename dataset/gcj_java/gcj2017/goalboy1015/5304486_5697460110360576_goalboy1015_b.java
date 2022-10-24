import java.util.Scanner;
 
 public class B {
 	static int result;
 
 	public static void main(String[] args) {
 		Scanner sc = new Scanner(System.in);
 
 		int T = sc.nextInt();
 		for (int tc = 1; tc <= T; tc++) {
 			System.out.print("Case #" + tc + ": ");
 
 			int N = sc.nextInt();
 			int P = sc.nextInt();
 			int[] R = new int[N];
 			for (int i = 0; i < R.length; i++) {
 				R[i] = sc.nextInt();
 			}
 			int[][] Q = new int[N][P];
 			for (int i = 0; i < N; i++) {
 				for (int j = 0; j < P; j++) {
 					Q[i][j] = sc.nextInt();
 				}
 			}
 
 			System.out.println(solve(N, P, R, Q));
 		}
 
 		sc.close();
 	}
 
 	static int solve(int N, int P, int[] R, int[][] Q) {
 		Range[][] ranges = new Range[N][P];
 		for (int i = 0; i < N; i++) {
 			for (int j = 0; j < P; j++) {
 				ranges[i][j] = computeRange(R[i], Q[i][j]);
 			}
 		}
 
 		int sequence[] = new int[P];
 		for (int i = 0; i < sequence.length; i++) {
 			sequence[i] = i;
 		}
 
 		result = 0;
 		search(sequence, 0, ranges);
 		return result;
 	}
 
 	static Range computeRange(int unit, int actual) {
 		return new Range(divideToCeil(actual * 10, (unit * 11)), actual * 10 / (unit * 9));
 	}
 
 	static int divideToCeil(int a, int b) {
 		return a / b + ((a % b == 0) ? 0 : 1);
 	}
 
 	static void search(int[] sequence, int index, Range[][] ranges) {
 		int N = ranges.length;
 
 		if (index == sequence.length) {
 			int kitNum = 0;
 			if (N == 1) {
 				for (int i = 0; i < sequence.length; i++) {
 					if (Range.isOverlap(ranges[0][i], ranges[0][i])) {
 						kitNum++;
 					}
 				}
 			} else {
 				for (int i = 0; i < sequence.length; i++) {
 					if (Range.isOverlap(ranges[0][i], ranges[1][sequence[i]])) {
 						kitNum++;
 					}
 				}
 			}
 			result = Math.max(result, kitNum);
 
 			return;
 		}
 
 		for (int i = index; i < sequence.length; i++) {
 			swap(sequence, i, index);
 			search(sequence, index + 1, ranges);
 			swap(sequence, i, index);
 		}
 	}
 
 	static void swap(int[] a, int index1, int index2) {
 		int temp = a[index1];
 		a[index1] = a[index2];
 		a[index2] = temp;
 	}
 }
 
 class Range {
 	int min;
 	int max;
 
 	Range(int min, int max) {
 		this.min = min;
 		this.max = max;
 	}
 
 	static boolean isOverlap(Range r1, Range r2) {
 		return Math.max(r1.min, r2.min) <= Math.min(r1.max, r2.max);
 	}
 }