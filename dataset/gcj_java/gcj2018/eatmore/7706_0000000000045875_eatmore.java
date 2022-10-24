import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution {

	// Discuss this round on Codeforces: http://codeforces.com/blog/entry/59547

	static class Matcher {

		int n;
		int edgesLen[], edges[][], capsLen, caps[];

		Matcher(int nn) {
			n = 2 * nn + 2;
			edgesLen = new int[n];
			edges = new int[n][6];
			capsLen = 0;
			caps = new int[6];
			for (int i = 0; i < nn; i++) {
				addEdge(2 * nn, i, 1, 0);
				addEdge(nn + i, 2 * nn + 1, 1, 0);
			}
		}

		int addEdge(int from, int to, int capacity, int reverseCapacity) {
			int cap = capsLen;
			if (caps.length == cap) {
				caps = copyOf(caps, (cap << 1) + 2);
			}
			caps[cap] = capacity;
			caps[cap + 1] = reverseCapacity;
			capsLen = cap + 2;
			int e1s[] = edges[from], e1 = edgesLen[from];
			if (e1s.length == e1) {
				e1s = edges[from] = copyOf(e1s, (e1 << 1) + 2);
			}
			e1s[e1] = to;
			e1s[e1 + 1] = cap;
			edgesLen[from] = e1 + 2;
			int e2s[] = edges[to], e2 = edgesLen[to];
			if (e2s.length == e2) {
				e2s = edges[to] = copyOf(e2s, (e2 << 1) + 2);
			}
			e2s[e2] = from;
			e2s[e2 + 1] = cap + 1;
			edgesLen[to] = e2 + 2;
			return cap;
		}

		int dinic(int source, int sink) {
			int dist[] = new int[n];
			int curEdge[] = new int[n];
			int queue[] = new int[n];
			int flow = 0;
			while (true) {
				fill(dist, -1);
				dist[source] = 0;
				queue[0] = source;
				int queueHead = 0;
				int queueTail = 1;
				do {
					int cur = queue[queueHead++];
					int ndist = dist[cur] + 1;
					for (int i = 0, e[] = edges[cur], en = edgesLen[cur]; i < en; i += 2) {
						if (caps[e[i + 1]] == 0) {
							continue;
						}
						int to = e[i];
						if (dist[to] < 0) {
							dist[to] = ndist;
							queue[queueTail++] = to;
						}
					}
				} while (queueHead < queueTail);
				if (dist[sink] < 0) {
					return flow;
				}
				fill(curEdge, 0);
				int stackSize = 0;
				int cur = source;
				int eNum = 0;
				cur: while (true) {
					if (cur == sink) {
						int curFlow = Integer.MAX_VALUE;
						for (int i = 0; i < stackSize; i++) {
							int c = queue[i];
							curFlow = min(curFlow, caps[edges[c][curEdge[c] + 1]]);
						}
						for (int i = 0; i < stackSize; i++) {
							int c = queue[i];
							int cap = edges[c][curEdge[c] + 1];
							caps[cap] -= curFlow;
							caps[cap ^ 1] += curFlow;
						}
						flow += curFlow;
						stackSize = 0;
						cur = source;
						eNum = curEdge[source];
						continue;
					}
					int ndist = stackSize + 1;
					for (int e[] = edges[cur], en = edgesLen[cur]; eNum < en; eNum += 2) {
						int next = e[eNum];
						if (caps[e[eNum + 1]] != 0 && dist[next] == ndist) {
							curEdge[cur] = eNum;
							queue[stackSize++] = cur;
							cur = next;
							eNum = curEdge[cur];
							continue cur;
						}
					}
					curEdge[cur] = eNum;
					if (stackSize == 0) {
						break;
					}
					cur = queue[--stackSize];
					eNum = curEdge[cur] + 2;
				}
			}
		}
	}

	static void solve() throws Exception {
		int n = scanInt();
		Matcher ms[] = new Matcher[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			ms[i] = new Matcher(n);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int t = scanInt();
				ms[t > 0 ? t - 1 : n + (-t - 1)].addEdge(i, n + j, 1, 0);
			}
		}
		int ans = n * n;
		for (int i = 0; i < 2 * n; i++) {
			ans -= ms[i].dinic(2 * n, 2 * n + 1);
		}
		printCase();
		out.println(ans);
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