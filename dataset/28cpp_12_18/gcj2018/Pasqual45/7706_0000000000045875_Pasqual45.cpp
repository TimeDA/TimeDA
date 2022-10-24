#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
#include<bitset>
#include<string.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair


struct BM {
	const static int max_nodes = 101;
	explicit BM(int m, int n) : M(m), N(n) { if (max(m, n)>max_nodes) cout << "max_nodes too small!"; memset(b, 0, sizeof(b)); reset(); }
	bool b[max_nodes][max_nodes], f[max_nodes][max_nodes], fM[max_nodes], fN[max_nodes];
	int pM[max_nodes], pN[max_nodes], M, N, matching;

	inline void set(int x, int y) { b[x][y] = true; }
	void reset() { memset(f, 0, sizeof(f)); memset(fM, 0, sizeof(fM)); memset(fN, 0, sizeof(fN)); matching = 0; }
	void addPathM(int i) { fM[i] = true; if (pM[i]<0) return; f[i][pM[i]] = false; return addPathN(pM[i]); }
	void addPathN(int j) { fN[j] = true; f[pN[j]][j] = true; return addPathM(pN[j]); }
	int maximum()
	{
		queue<pair<int, int> > q;
		for (int z = 0; z<M; ++z)
		{
			if (fM[z]) continue;
			memset(pM, -1, sizeof(pM)); memset(pN, -1, sizeof(pN));
			q.push(make_pair(0, z));
			while (!q.empty())
			{
				int time = q.front().first, loc = q.front().second;
				q.pop();
				if (time % 2 == 0)
				{
					int i = loc;
					for (int j = 0; j<N; ++j)
						if (b[i][j] && !f[i][j] && pN[j] < 0)
						{
							pN[j] = i;
							q.push(make_pair(time + 1, j));
							if (!fN[j])
							{	// Found a path!
								addPathN(j);
								++matching;
								while (!q.empty()) q.pop();
								break;
							}
						}
				}
				else
				{
					int j = loc;
					for (int i = 0; i<M; ++i)
						if (b[i][j] && f[i][j] && pM[i] < 0)
							pM[i] = j, q.push(make_pair(time + 1, i));
				}
			}
		}
		return matching;
	}
};


#define fin cin

//int main18R2_C()
int main()
{
	//ifstream fin("test.in");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	vector<BM> m;
	m.reserve(200);
	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		m.clear();

		int N;
		fin >> N;

		for (int i = 0; i < N*2; ++i)
			m.emplace_back(N, N);

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int x;
				fin >> x;
				if (x < 0)
				{
					x = N - x;
				}

				--x;
				m[x].set(i, j);
			}
		}

		int result = N * N;
		for (int i = 0; i < N * 2; ++i)
		{
			int cur = m[i].maximum();
			result -= cur;
		}

		cout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}
