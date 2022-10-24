import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(
				new BufferedReader(new InputStreamReader(System.in)));
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			int R = sc.nextInt();
			int B = sc.nextInt();

			int[][][] wk = new int[2][][];
			int[][][] idx = new int[2][][];
			int[] len = new int[2];

			int loop = 0;
			wk[0] = new int[R + 1][B + 1];
			idx[0] = new int[1][2];
			idx[0][0] = new int[] { R, B };
			len[0] = 1;

			int cur_num = 1;
			int cur_r = 0;
			int max = 0;
			boolean flg = false;
			while (true) {
				int next = (loop + 1) % 2;
				int cur = loop % 2;
				wk[next] = new int[R + 1][B + 1];
				idx[next] = new int[len[cur] * 2][2];
				len[next] = 0;
				for (int i = 0; i < len[cur]; i++) {
					int cur_b = cur_num - cur_r;
					if ((max - wk[cur][idx[cur][i][0]][idx[cur][i][1]]) * cur_num > idx[cur][i][0] + idx[cur][i][1]) {
						continue;
					}
					if (idx[cur][i][0] >= cur_r && idx[cur][i][1] >= cur_b) {
						if (wk[next][idx[cur][i][0] - cur_r][idx[cur][i][1]
								- cur_b] <= wk[cur][idx[cur][i][0]][idx[cur][i][1]]) {
							wk[next][idx[cur][i][0] - cur_r][idx[cur][i][1]
									- cur_b] = wk[cur][idx[cur][i][0]][idx[cur][i][1]]
											+ 1;
							max = Math.max(max, wk[cur][idx[cur][i][0]][idx[cur][i][1]]
											+ 1);
							idx[next][len[next]][0] = idx[cur][i][0] - cur_r;
							idx[next][len[next]++][1] = idx[cur][i][1] - cur_b;
							flg = true;
						}
					}
					if (wk[next][idx[cur][i][0]][idx[cur][i][1]] <= wk[cur][idx[cur][i][0]][idx[cur][i][1]]) {
						wk[next][idx[cur][i][0]][idx[cur][i][1]] = wk[cur][idx[cur][i][0]][idx[cur][i][1]];
						idx[next][len[next]][0] = idx[cur][i][0];
						idx[next][len[next]++][1] = idx[cur][i][1];
					}
				}
				if (cur_r >= cur_num) {
					cur_num++;
					cur_r = 0;
					if (flg == false) {
						break;
					}
					flg = false;
				} else {
					cur_r++;
				}
				loop++;
			}
			System.out.println("Case #" + (t + 1) + ": " + max);
		}
	}
}
