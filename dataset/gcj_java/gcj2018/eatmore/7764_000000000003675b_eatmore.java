import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.NavigableSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Solution {

	// Discuss this round on Codeforces: http://codeforces.com/blog/entry/59152

	static class IntIntMap {

		static final int EMPTY = Integer.MIN_VALUE;

		int data[] = new int[4];
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

		static int hash(int key) {
			int hash = key * 1000000007;
			hash ^= hash >> 16;
			hash ^= hash >> 24;
			return hash;
		}

		boolean have(int key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			for (int mask = data.length - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
				if (cur == key) {
					return true;
				} else if (cur == EMPTY) {
					return false;
				}
			}
		}

		int get(int key, int default_) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			for (int mask = data.length - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
				if (cur == key) {
					return data[i + 1];
				} else if (cur == EMPTY) {
					return default_;
				}
			}
		}

		static int[] resize(int data[], int newCapacity) {
			int oldCapacity = data.length;
			int ndata[] = new int[newCapacity];
			for (int i = 0; i < newCapacity; i += 2) {
				ndata[i] = EMPTY;
			}
			for (int mask = newCapacity - 2, i = 0; i < oldCapacity; i += 2) {
				int cur = data[i];
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

		void set(int key, int value) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			int data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
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

		void delete(int key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			int data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
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
			int data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity >> 2 < newCapacity) {
				this.data = resize(data, Integer.highestOneBit(newCapacity - 1) << 3);
			}
		}

		void shrink() {
			int data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity > 4 && oldCapacity >> 3 >= size) {
				this.data = resize(data, max(Integer.highestOneBit(size - 1) << 3, 4));
			}
		}

		static class Iterator {

			final int data[];
			int position = -2;

			Iterator(int data[]) {
				this.data = data;
				advance();
			}

			boolean hasNext() {
				return position < data.length;
			}

			int getKey() {
				return data[position];
			}

			int getValue() {
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

	static class IntIntCounter extends IntIntMap {

		int get(int key) {
			return get(key, 0);
		}

		void set(int key, int value) {
			if (value == 0) {
				delete(key);
			} else {
				super.set(key, value);
			}
		}

		void add(int key, int value) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			int data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
				if (cur == key) {
					data[i + 1] += value;
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
	}

	static class CountEntry implements Comparable<CountEntry> {

		final int i, count;

		CountEntry(int i, int count) {
			this.i = i;
			this.count = count;
		}

		public int compareTo(CountEntry o) {
			return count != o.count ? count - o.count : i - o.i;
		}
	}

	static class Tracker {

		final int v1[], v2[];
		int totalCount, l, r;
		final IntIntCounter v1cnt;
		final NavigableSet<CountEntry> v1cntSorted;
		final Map<Integer, IntIntCounter> v1Tracked;

		Tracker(int v1[], int v2[]) {
			this.v1 = v1;
			this.v2 = v2;
			totalCount = 0;
			l = r = 0;
			v1cnt = new IntIntCounter();
			v1cntSorted = new TreeSet<>();
			v1Tracked = new HashMap<>();
		}

		void add(int i, int a) {
			totalCount += a;
			int val = v1[i];
			int cntOld = v1cnt.get(val);
			if (cntOld != 0) {
				v1cntSorted.remove(new CountEntry(val, cntOld));
			}
			int cntNew = cntOld + a;
			v1cnt.set(val, cntNew);
			if (cntNew != 0) {
				v1cntSorted.add(new CountEntry(val, cntNew));
			}
			int val2 = v2[i];
			for (Entry<Integer, IntIntCounter> e: v1Tracked.entrySet()) {
				if (e.getKey() != val) {
					IntIntCounter trk = e.getValue();
					int v = trk.get(val2) + a;
					if (v == 0) {
						trk.delete(val2);
					} else {
						trk.set(val2, v);
					}
				}
			}
		}

		boolean good() {
			for (CountEntry e: v1cntSorted.descendingSet()) {
				int val = e.i, cnt = e.count;
				if (2 * cnt < totalCount) {
					break;
				}
				IntIntCounter trk = v1Tracked.get(val);
				if (trk == null) {
					v1Tracked.put(val, trk = new IntIntCounter());
					for (int i = l; i < r; i++) {
						if (v1[i] != val) {
							trk.add(v2[i], 1);
						}
					}
					if (v1Tracked.size() > 4) {
						int smallestVal = 0, smallestCount = Integer.MAX_VALUE;
						for (int curVal: v1Tracked.keySet()) {
							int curCount = v1cnt.get(curVal);
							if (smallestCount > curCount) {
								smallestCount = curCount;
								smallestVal = curVal;
							}
						}
						v1Tracked.remove(smallestVal);
					}
				}
				if (trk.size() <= 1) {
					return true;
				}
			}
			return false;
		}
	}

	static void solve() throws Exception {
		int n = scanInt();
		int v1[] = new int[n];
		int v2[] = new int[n];
		Tracker t1 = new Tracker(v1, v2);
		Tracker t2 = new Tracker(v2, v1);
		int p1 = 0, ansLen = -1, ansCount = 0;
		for (int i = 0; i < n; i++) {
			int d = scanInt(), a = scanInt(), b = scanInt();
			v1[i] = d + a;
			v2[i] = d - b;
			t1.add(i, 1);
			t2.add(i, 1);
			t1.r = i + 1;
			t2.r = i + 1;
			while (p1 < i + 1 && !t1.good() && !t2.good()) {
				t1.add(p1, -1);
				t2.add(p1, -1);
				t1.l = p1 + 1;
				t2.l = p1 + 1;
				++p1;
			}
			int cansLen = i + 1 - p1;
			if (cansLen > ansLen) {
				ansLen = cansLen;
				ansCount = 1;
			} else if (cansLen == ansLen) {
				++ansCount;
			}
		}
		printCase();
		out.println(ansLen + " " + ansCount);
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