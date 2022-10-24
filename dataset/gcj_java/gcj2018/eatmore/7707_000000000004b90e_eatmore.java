import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class Solution {

	// Discuss this round on Codeforces: https://codeforces.com/blog/entry/59910

	static class LongLongMap {

		static final long EMPTY = Long.MIN_VALUE;

		long data[] = new long[4];
		{
			data[0] = EMPTY;
			data[2] = EMPTY;
		}
		int size = 0;

		boolean isEmpty() {
			return size == 0;
		}

		int size() {
			return size;
		}

		void clear() {
			for (int i = 0; i < data.length; i += 2) {
				data[i] = EMPTY;
			}
			size = 0;
		}

		static int hash(long key) {
			long hash = key * 1000000007;
			hash ^= hash >> 16;
			hash ^= hash >> 24;
			return (int) hash;
		}

		boolean have(long key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			for (int mask = data.length - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					return true;
				} else if (cur == EMPTY) {
					return false;
				}
			}
		}

		long get(long key, long default_) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			for (int mask = data.length - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					return data[i + 1];
				} else if (cur == EMPTY) {
					return default_;
				}
			}
		}

		static long[] resize(long data[], int newCapacity) {
			int oldCapacity = data.length;
			long ndata[] = new long[newCapacity];
			for (int i = 0; i < newCapacity; i += 2) {
				ndata[i] = EMPTY;
			}
			for (int mask = newCapacity - 2, i = 0; i < oldCapacity; i += 2) {
				long cur = data[i];
				if (cur == EMPTY) {
					continue;
				}
				for (int j = hash(cur) & mask;; j = (j - 1) & mask) {
					if (ndata[j] == EMPTY) {
						ndata[j] = cur;
						ndata[j + 1] = data[i + 1];
						break;
					}
				}
			}
			return ndata;
		}

		void set(long key, long value) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					data[i + 1] = value;
					return;
				} else if (cur == EMPTY) {
					data[i] = key;
					data[i + 1] = value;
					if (++size > capacity >> 2) {
						this.data = resize(data, capacity << 1);
					}
					return;
				}
			}
		}

		void delete(long key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					for (int j = i;;) {
						cur = data[j = (j - 1) & mask];
						if (cur == EMPTY) {
							data[i] = EMPTY;
							--size;
							return;
						}
						int k = hash(cur) & mask;
						if ((k >= i) ^ (k < j) ^ (i < j)) {
							data[i] = cur;
							data[i + 1] = data[j + 1];
							i = j;
						}
					}
				} else if (cur == EMPTY) {
					return;
				}
			}
		}

		void expand(int newCapacity) {
			long data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity >> 2 < newCapacity) {
				this.data = resize(data, Integer.highestOneBit(newCapacity - 1) << 3);
			}
		}

		void shrink() {
			long data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity > 4 && oldCapacity >> 3 >= size) {
				this.data = resize(data, max(Integer.highestOneBit(size - 1) << 3, 4));
			}
		}

		static class Iterator {

			final long data[];
			int position = -2;

			Iterator(long data[]) {
				this.data = data;
				advance();
			}

			boolean hasNext() {
				return position < data.length;
			}

			long getKey() {
				return data[position];
			}

			long getValue() {
				return data[position + 1];
			}

			void advance() {
				do {
					position += 2;
				} while (position < data.length && data[position] == EMPTY);
			}
		}

		Iterator iterator() {
			return new Iterator(data);
		}
	}

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

	interface IntComparator {
		public int compare(int o1, int o2);
	}

	static void sortWith(int a[], int n, IntComparator cmp) {
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (cmp.compare(na, ca) >= 0) {
					break;
				}
				a[j] = na;
				j = nj;
			} while (j != 0);
			a[j] = ca;
		}
		int ca = a[0];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				j += (cmp.compare(a[j + 1], a[j + 2]) < 0) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
			a[i] = ca;
			ca = na;
			while (j != 0 && cmp.compare(a[j], ca) < 0) {
				j = (j - 1) >> 1;
			}
			while (j != 0) {
				na = a[j];
				a[j] = ca;
				ca = na;
				j = (j - 1) >> 1;
			}
		}
		a[0] = ca;
	}

	static int k;
	static int point1[], point2[], face1[], face2[];
	static List<IntList> edges, faceEdges;

	static void solve() throws Exception {
		int nEdges = scanInt();
		k = scanInt();
		point1 = new int[nEdges];
		point2 = new int[nEdges];
		final List<Long> points = new ArrayList<>();
		LongLongMap pointMap = new LongLongMap();
		edges = new ArrayList<>();
		int nPoints = 0;
		for (int i = 0; i < nEdges; i++) {
			int x1 = scanInt(), y1 = scanInt();
			long xy1 = (x1 & 0xffffffffL) | ((long) y1 << 32);
			int p1 = (int) pointMap.get(xy1, -1);
			if (p1 < 0) {
				p1 = nPoints;
				points.add(xy1);
				pointMap.set(xy1, p1);
				edges.add(new IntList());
				++nPoints;
			}
			int x2 = scanInt(), y2 = scanInt();
			long xy2 = (x2 & 0xffffffffL) | ((long) y2 << 32);
			int p2 = (int) pointMap.get(xy2, -1);
			if (p2 < 0) {
				p2 = nPoints;
				points.add(xy2);
				pointMap.set(xy2, p2);
				edges.add(new IntList());
				++nPoints;
			}
			point1[i] = p1;
			point2[i] = p2;
			edges.get(p1).push(i);
			edges.get(p2).push(i);
		}
		for (int i = 0; i < nPoints; i++) {
			final int p = i;
			final long xy = points.get(p);
			sortWith(edges.get(i).data, edges.get(i).size, new IntComparator() {
				long getXY(int e) {
					return points.get(p ^ point1[e] ^ point2[e]);
				}
				public int compare(int o1, int o2) {
					return comparePoints(xy, getXY(o1), getXY(o2));
				}
			});
		}
		face1 = new int[nEdges];
		face2 = new int[nEdges];
		fill(face1, -1);
		fill(face2, -1);
		int nFaces = 0;
		faceEdges = new ArrayList<>();
		for (int i = 0; i < nEdges; i++) {
			for (int d = 0; d < 2; d++) {
				int face[], p1, p2;
				if (d == 0) {
					face = face1;
					p1 = point1[i];
					p2 = point2[i];
				} else {
					face = face2;
					p1 = point2[i];
					p2 = point1[i];
				}
				if (face[i] < 0) {
					faceEdges.add(new IntList());
					int cp1 = p1, cp2 = p2, cEdge = i;
					do {
						face[cEdge] = nFaces;
						faceEdges.get(nFaces).push(cEdge);
						int p = -1;
						IntList p2e = edges.get(cp2);
						for (int j = 0; j < p2e.size(); j++) {
							if (p2e.get(j) == cEdge) {
								p = j;
								break;
							}
						}
						if (p < 0) {
							throw new AssertionError();
						}
						cEdge = p2e.get((p + 1) % p2e.size());
						cp1 = cp2;
						if (cp1 == point1[cEdge]) {
							cp2 = point2[cEdge];
							face = face1;
						} else {
							cp2 = point1[cEdge];
							face = face2;
						}
					} while (cp1 != p1 || cp2 != p2);
					++nFaces;
				}
			}
		}
//		for (int i = 0; i < nFaces; i++) {
//			System.err.print("Face " + i + ":");
//			for (int j = 0; j < faceEdges.get(i).size; j++) {
//				System.err.print(" " + faceEdges.get(i).get(j));
//			}
//			System.err.println();
//		}
//		System.err.println(nFaces + " " + nPoints + " " + nEdges);
		if (nFaces + nPoints != nEdges + 2) {
			throw new AssertionError();
		}
		ans = new int[nEdges];
		ansPos = 0;
		used = new boolean[nEdges];
		seen = new boolean[nFaces];
		for (int i = 0; i < k; i++) {
			int f1 = face1[i], f2 = face2[i];
//			System.err.println("E " + i + " " + f1 + " " + f2);
			used[i] = true;
			fill(seen, false);
			boolean h1 = dfsCheck(f1);
			fill(seen, false);
			boolean h2 = dfsCheck(f2);
			if (!(h1 && h2)) {
				fill(seen, false);
				dfsClear(h1 ? f2 : f1);
			}
			ans[ansPos++] = i;
		}
		for (int i = k; i < nEdges; i++) {
			if (!used[i]) {
				dfsClear(face1[i]);
				break;
			}
		}
		if (ansPos != nEdges) {
			throw new AssertionError();
		}
		printCase();
		for (int i = 0; i < nEdges; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(ans[i] + 1);
		}
		out.println();
	}

	static int ans[], ansPos;
	static boolean used[], seen[];

	static boolean dfsCheck(int cur) {
		if (seen[cur]) {
			return false;
		}
		seen[cur] = true;
		IntList e = faceEdges.get(cur);
		for (int i = 0; i < e.size(); i++) {
			int ce = e.get(i);
			if (used[ce]) {
				continue;
			}
			if (ce < k) {
				return true;
			}
			if (dfsCheck(cur ^ face1[ce] ^ face2[ce])) {
				return true;
			}
		}
		return false;
	}

	static void dfsClear(int cur) {
		if (seen[cur]) {
			return;
		}
		seen[cur] = true;
		IntList e = faceEdges.get(cur);
		for (int i = 0; i < e.size(); i++) {
			int ce = e.get(i);
			if (used[ce]) {
				continue;
			}
			used[ce] = true;
			if (ce < k) {
				throw new AssertionError();
			}
			dfsClear(cur ^ face1[ce] ^ face2[ce]);
			ans[ansPos++] = ce;
		}
	}

	static int comparePoints(long xy, long xy1, long xy2) {
		int x1 = (int) xy1 - (int) xy;
		int y1 = (int) (xy1 >> 32) - (int) (xy >> 32);
		int x2 = (int) xy2 - (int) xy;
		int y2 = (int) (xy2 >> 32) - (int) (xy >> 32);
		int q1 = quad(x1, y1);
		int q2 = quad(x2, y2);
		return q1 != q2 ? q1 - q2 : Long.compare((long) y1 * x2, (long) x1 * y2);
	}

	static int quad(int x, int y) {
		return x > 0 ? (y > 0 ? 2 : y < 0 ? 8 : 1) :
			x < 0 ? (y > 0 ? 4 : y < 0 ? 6 : 5) :
			(y > 0 ? 3 : y < 0 ? 7 : 0);
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