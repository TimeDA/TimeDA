import java.util.Scanner;
 
 public class B {
 	static double sum;
 	static double result;
 
 	public static void main(String[] args) {
 		Scanner sc = new Scanner(System.in);
 
 		int T = sc.nextInt();
 		for (int tc = 1; tc <= T; tc++) {
 			System.out.print("Case #" + tc + ": ");
 
 			int N = sc.nextInt();
 			int K = sc.nextInt();
 			double[] p = new double[N];
 			for (int i = 0; i < p.length; i++) {
 				p[i] = sc.nextDouble();
 			}
 
 			result = 0;
 			choose(p, new int[K], 0);
 
 			System.out.println(result);
 		}
 
 		sc.close();
 	}
 
 	static void choose(double[] p, int[] chosen, int index) {
 		if (index == chosen.length) {
 			compute(p, chosen);
 			return;
 		}
 
 		for (int i = (index == 0 ? 0 : (chosen[index - 1] + 1)); i < p.length; i++) {
 			chosen[index] = i;
 			choose(p, chosen, index + 1);
 		}
 	}
 
 	static void compute(double[] p, int[] chosen) {
 		// System.out.println(Arrays.toString(chosen));
 		sum = 0;
 		chooseYes(p, chosen, new int[chosen.length / 2], 0);
 		result = Math.max(result, sum);
 	}
 
 	static void chooseYes(double[] p, int chosen[], int[] yeses, int index) {
 		if (index == yeses.length) {
 			boolean[] isYes = new boolean[p.length];
 			for (int yes : yeses) {
 				isYes[chosen[yes]] = true;
 			}
 			double product = 1;
 			for (int oneChosen : chosen) {
 				product *= (isYes[oneChosen] ? p[oneChosen] : (1 - p[oneChosen]));
 			}
 
 			sum += product;
 
 			return;
 		}
 
 		for (int i = (index == 0 ? 0 : (yeses[index - 1] + 1)); i < chosen.length; i++) {
 			yeses[index] = i;
 			chooseYes(p, chosen, yeses, index + 1);
 		}
 	}
 }
