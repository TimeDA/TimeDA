import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.BitSet;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class Solution {

	// Discuss this round on Codeforces: https://codeforces.com/blog/entry/61114
	
	static class IntList {

		int data[] = new int[3];
		int size = 0;

		boolean isEmpty() {
			return size == 0;
		}

		int size() {
			return size;
		}

		int get(int index) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			return data[index];
		}

		void clear() {
			size = 0;
		}

		void set(int index, int value) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			data[index] = value;
		}

		void expand() {
			if (size >= data.length) {
				data = copyOf(data, (data.length << 1) + 1);
			}
		}

		void insert(int index, int value) {
			if (index < 0 || index > size) {
				throw new IndexOutOfBoundsException();
			}
			expand();
			arraycopy(data, index, data, index + 1, size++ - index);
			data[index] = value;
		}

		int delete(int index) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			int value = data[index];
			arraycopy(data, index + 1, data, index, --size - index);
			return value;
		}

		void push(int value) {
			expand();
			data[size++] = value;
		}

		int pop() {
			if (size == 0) {
				throw new NoSuchElementException();
			}
			return data[--size];
		}

		void unshift(int value) {
			expand();
			arraycopy(data, 0, data, 1, size++);
			data[0] = value;
		}

		int shift() {
			if (size == 0) {
				throw new NoSuchElementException();
			}
			int value = data[0];
			arraycopy(data, 1, data, 0, --size);
			return value;
		}
	}

	static void solve() throws Exception {
		int n = scanInt();
		int p = scanInt();
		boolean attacks[][] = new boolean[n][p];
		boolean defences[][] = new boolean[n][p];
		IntList byAttack[] = new IntList[p];
		for (int i = 0; i < p; i++) {
			byAttack[i] = new IntList();
		}
		int nAttacks[] = new int[n];
		for (int i = 0; i < n; i++) {
			int a = scanInt();
			int d = scanInt();
			for (int j = 0; j < a; j++) {
				int ca = scanInt() - 1;
				attacks[i][ca] = true;
				byAttack[ca].push(i);
				++nAttacks[i];
			}
			for (int j = 0; j < d; j++) {
				defences[i][scanInt() - 1] = true;
			}
		}
		{
			boolean defenceSet[] = new boolean[p];
			boolean defendedSet[] = new boolean[n];
			IntList defendedStack = new IntList();
			defendedSet[0] = true;
			defendedStack.push(0);
			int remainingAttacks[] = nAttacks.clone();
			do {
				int cur = defendedStack.pop();
				for (int i = 0; i < p; i++) {
					if (!defenceSet[i] && defences[cur][i]) {
						defenceSet[i] = true;
						for (int j = 0; j < byAttack[i].size(); j++) {
							int next = byAttack[i].get(j);
							if (--remainingAttacks[next] == 0 && !defendedSet[next]) {
								defendedSet[next] = true;
								defendedStack.push(next);
							}
						}
					}
				}
			} while (!defendedStack.isEmpty());
			for (int i = 0; i < n; i++) {
				if (!defendedSet[i]) {
					printCase();
					out.println("NO");
					return;
				}
			}
		}
		{
			BitSet byNoDefence[] = new BitSet[p];
			for (int i = 0; i < p; i++) {
				byNoDefence[i] = new BitSet();
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < p; j++) {
					if (!defences[i][j]) {
						byNoDefence[j].set(i);
					}
				}
			}
			BitSet canBeat[] = new BitSet[n];
			for (int i = 0; i < n; i++) {
				canBeat[i] = new BitSet();
				for (int j = 0; j < p; j++) {
					if (attacks[i][j]) {
						canBeat[i].or(byNoDefence[j]);
					}
				}
			}
			Solution.n = n;
			edges = canBeat;
			seen = new boolean[n];
			exit = new int[n];
			pos = 0;
			for (int i = 0; i < n; i++) {
				dfs(i);
			}
			fill(seen, false);
			seen2 = new boolean[n];
			dfsList = new int[n];
			boolean allDefences[] = new boolean[p];
			for (int i = n - 1; i >= 0; i--) {
				if (!seen[i]) {
					dfsListSize = 0;
					if (!dfs2(i) && !seen2[0]) {
						fill(allDefences, true);
						for (int j = 0; j < dfsListSize; j++) {
							int cur = dfsList[j];
							for (int k = 0; k < p; k++) {
								if (!defences[cur][k]) {
									allDefences[k] = false;
								}
							}
						}
						j: for (int j = 0;; j++) {
							if (j == dfsListSize) {
								printCase();
								out.println("NO");
								return;
							}
							int cur = dfsList[j];
							for (int k = 0;; k++) {
								if (k == p) {
									break j;
								}
								if (allDefences[k] && attacks[cur][k]) {
									break;
								}
							}
						}						
					}
					for (int j = 0; j < dfsListSize; j++) {
						seen[dfsList[j]] = true;
						seen2[dfsList[j]] = false;
					}
				}
			}
		}
		printCase();
		out.println("YES");
	}
	
	static int n;
	static BitSet edges[];
	static boolean seen[];
	static int exit[];
	static int pos;
	
	static void dfs(int cur) {
		if (seen[cur]) {
			return;
		}
		seen[cur] = true;
		for (int next = 0; next < n; next++) {
			if (edges[cur].get(next)) {
				dfs(next);
			}
		}
		exit[cur] = pos++;
	}
	
	static boolean seen2[];
	static int dfsList[], dfsListSize;
	
	static boolean dfs2(int cur) {
		if (seen2[cur]) {
			return false;
		}
		if (seen[cur]) {
			return true;
		}
		seen2[cur] = true;
		dfsList[dfsListSize++] = cur;
		boolean res = false;
		for (int next = 0; next < n; next++) {
			if (edges[next].get(cur) && dfs2(next)) {
				res = true;
			}
		}
		return res;
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static void printCase() {
		out.print("Case #" + test + ": ");
	}

	static void printlnCase() {
		out.println("Case #" + test + ":");
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			int tests = scanInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}