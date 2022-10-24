import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
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

	// Discuss this round on Codeforces: https://codeforces.com/blog/entry/61114
	
	static class MaxFlow {

		// Flow network structures

		static int n;
		static int edgesLen[], edges[][], capsLen;
		static long caps[];

		static void init() {
			edgesLen = new int[n];
			edges = new int[n][6];
			capsLen = 0;
			caps = new long[6];
		}

		static int addEdge(int from, int to, long capacity, long reverseCapacity) {
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

		// Dinic with capacity scaling: O(VE log U)

		static long scaledDinic(int source, int sink) {
			int dist[] = new int[n];
			int curEdge[] = new int[n];
			int queue[] = new int[n];
			long flow = 0;
			for (long scale = 1L << 60; scale != 0; scale >>= 1) {
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
							if (caps[e[i + 1]] < scale) {
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
						break;
					}
					fill(curEdge, 0);
					int stackSize = 0;
					int cur = source;
					int eNum = 0;
					cur: while (true) {
						if (cur == sink) {
							long curFlow = Long.MAX_VALUE;
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
							if (caps[e[eNum + 1]] >= scale && dist[next] == ndist) {
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
			return flow;
		}
	}

	static void solve() throws Exception {
		int xSize = scanInt();
		int ySize = scanInt();
		int n = scanInt();
		int xPos[] = new int[n];
		int yPos[] = new int[n];
		int range[] = new int[n];
		for (int i = 0; i < n; i++) {
			xPos[i] = scanInt() - 1;
			yPos[i] = scanInt() - 1;
			range[i] = scanInt();
		}
		int setXfrom[] = new int[1 << n], setXto[] = new int[1 << n],
			setYfrom[] = new int[1 << n], setYto[] = new int[1 << n];
		long setSize[] = new long[1 << n];
		setXfrom[0] = 0;
		setXto[0] = xSize;
		setYfrom[0] = 0;
		setYto[0] = ySize;
		for (int set = 1; set < 1 << n; set++) {
			int i = Integer.numberOfTrailingZeros(set);
			int pset = set ^ (1 << i);
			setXfrom[set] = max(setXfrom[pset], xPos[i] - range[i]);
			setXto[set] = min(setXto[pset], xPos[i] + range[i] + 1);
			setYfrom[set] = max(setYfrom[pset], yPos[i] - range[i]);
			setYto[set] = min(setYto[pset], yPos[i] + range[i] + 1);
			if (setXfrom[set] < setXto[set] && setYfrom[set] < setYto[set]) {
				setSize[set] = (long) (setXto[set] - setXfrom[set]) * (setYto[set] - setYfrom[set]);
			}
		}
		for (int set = (1 << n) - 1; set != 0; set--) {
			if (setSize[set] == 0) {
				continue;
			}
			int iset = (1 << n) - 1 - set;
			for (int sub = iset; sub != 0; sub = (sub - 1) & iset) {
				setSize[set] -= setSize[set | sub];
			}
		}
		for (int i = 0; i < n; i++) {
			int set = 0;
			for (int j = 0; j < n; j++) {
				if (xPos[i] >= xPos[j] - range[j] && xPos[i] <= xPos[j] + range[j] &&
					yPos[i] >= yPos[j] - range[j] && yPos[i] <= yPos[j] + range[j]) {
					set |= 1 << j;
				}
			}
			--setSize[set];
		}
		int nGoodSets = 0, nGoodSetBits = 0;
		for (int set = 1; set < 1 << n; set++) {
			if (setSize[set] != 0) {
				++nGoodSets;
				nGoodSetBits += Integer.bitCount(set);
			}
		}
		int goodSets[] = new int[nGoodSets];
		long sizeSum = 0;
		long goodSetSize[] = new long[nGoodSets];
		for (int set = 0, i = 0; set < 1 << n; set++) {
			if (setSize[set] != 0) {
				goodSets[i] = set;
				goodSetSize[i] = setSize[set];
				sizeSum += setSize[set];
				++i;
			}
		}
		long totalArea = (long) xSize * ySize;
		MaxFlow.n = 1 + n + nGoodSets + 1;
		MaxFlow.init();
		int entryCaps[] = new int[n];
		for (int i = 0; i < n; i++) {
			entryCaps[i] = MaxFlow.addEdge(0, 1 + i, totalArea, 0);
		}
		int bitCaps[] = new int[nGoodSetBits];
		int setCaps[] = new int[nGoodSets];
		for (int i = 0, j = 0; i < nGoodSets; i++) {
			for (int cur = goodSets[i], bit; cur != 0; cur ^= 1 << bit) {
				bit = Integer.numberOfTrailingZeros(cur);
				bitCaps[j++] = MaxFlow.addEdge(1 + bit, 1 + n + i, totalArea, 0);
			}
			setCaps[i] = MaxFlow.addEdge(1 + n + i, 1 + n + nGoodSets, goodSetSize[i], 0);
		}
		long l = 0, r = totalArea;
		while (l < r) {
			long mid = (l + r + 1) >> 1;
			if (mid > Long.MAX_VALUE / n) {
				r = mid - 1;
				continue;
			}
			for (int i = 0; i < n; i++) {
				MaxFlow.caps[entryCaps[i]] = mid;
				MaxFlow.caps[entryCaps[i] ^ 1] = 0;
			}
			for (int i = 0; i < nGoodSetBits; i++) {
				MaxFlow.caps[bitCaps[i]] = totalArea;
				MaxFlow.caps[bitCaps[i] ^ 1] = 0;
			}
			for (int i = 0; i < nGoodSets; i++) {
				MaxFlow.caps[setCaps[i]] = goodSetSize[i];
				MaxFlow.caps[setCaps[i] ^ 1] = 0;
			}
			if (MaxFlow.scaledDinic(0, 1 + n + nGoodSets) == mid * n) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		long resMin = l;
		l = 0;
		r = totalArea;
		while (l < r) {
			long mid = (l + r) >> 1;
			for (int i = 0; i < n; i++) {
				MaxFlow.caps[entryCaps[i]] = mid;
				MaxFlow.caps[entryCaps[i] ^ 1] = 0;
			}
			for (int i = 0; i < nGoodSetBits; i++) {
				MaxFlow.caps[bitCaps[i]] = totalArea;
				MaxFlow.caps[bitCaps[i] ^ 1] = 0;
			}
			for (int i = 0; i < nGoodSets; i++) {
				MaxFlow.caps[setCaps[i]] = goodSetSize[i];
				MaxFlow.caps[setCaps[i] ^ 1] = 0;
			}
			if (MaxFlow.scaledDinic(0, 1 + n + nGoodSets) == sizeSum) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		long resMax = l;
		printCase();
		out.println(resMax - resMin);
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