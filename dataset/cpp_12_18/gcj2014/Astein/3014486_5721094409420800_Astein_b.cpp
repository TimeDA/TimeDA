#include <vector>
 #include <cstdio>
 #include <algorithm>
 
 using namespace std;
 
 int main()
 {
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		int n;
 		scanf("%d", &n);
 		vector<int> a(n);
 		for (int i = 0; i < n; ++i)
 			scanf("%d", &a[i]);
 		vector<int> b = a;
 		sort(b.begin(), b.end());
 
 		int ret = 0;
 		for (int i = 0; i < n; ++i)
 		{
 			int pos = -1;
 			for (int j = 0; j < n; ++j)
 				if (b[i] == a[j]) { pos = j; break; }
 			// current position = pos
 			int left = 0, right = 0;
 			for (int j = pos - 1; j >= 0; --j)
 				if (a[pos] > a[j]) break; else left++;
 			for (int j = pos + 1; j < n; ++j)
 				if (a[pos] > a[j]) break; else right++;
 
 			if (left > right)
 			{ // go right
 				for (int j = pos + 1; j < n; ++j)
 					if (a[j - 1] > a[j]) break; else { swap(a[j - 1], a[j]); }
 				ret += right;
 			}
 			else
 			{ // go left
 				for (int j = pos - 1; j >= 0; --j)
 					if (a[j + 1] > a[j]) break; else { swap(a[j + 1], a[j]); }
 				ret += left;
 			}
 		}
 		printf("Case #%d: %d\n", cn, ret);
 	}
 }
 
