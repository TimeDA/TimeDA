#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <functional>
#include <utility>
#include <tuple>
#include <numeric>
#include <queue>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <regex>
#include <stack>
#include <limits>

using namespace std;

int f[128][512];

int main() {
	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int test = 0; test < t; ++test) {
		int res = 1;
		memset(f, -1, sizeof(f));
		
		int r, b;
		cin >> r >> b;

		int limitr = (r / 2) + 1;
		int limitb = b / 2 + 1;
		f[0][r] = b;
		int maxl = 1;
		for (int ri = 0; ri <= min(limitr, r); ++ri) {
			for (int bi = 0; bi <= min(limitb, b); ++bi) {
				if (ri || bi) {
					for (int len = maxl; len > 0; --len) {
						for (int rleft = r-ri; rleft >= 0; --rleft) {
							if (f[len-1][rleft+ri] != -1 && f[len-1][rleft+ri] >= bi && f[len][rleft] <= f[len - 1][rleft + ri] - bi) {
								f[len][rleft] = f[len - 1][rleft + ri] - bi;
								if (maxl == len) ++maxl;
								res = max(res, len);
								if (rleft > ri || rleft == ri && f[len][rleft] > bi) {
									res = max(res, len+1);
								}
							}
						}
					}
				}
			}
		}
//		cout << maxl;
		cout << "Case #" << test + 1 << ": " << res << endl;
	}
	return 0;
}
