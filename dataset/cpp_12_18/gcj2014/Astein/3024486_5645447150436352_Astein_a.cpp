#include <iostream>
 #include <vector>
 #include <cstdio>
 
 using namespace std;
 
 int main()
 {
 	int T, p, q, r, s;
 	scanf("%d", &T);
 	int N;
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		scanf("%d%d%d%d%d", &N, &p, &q, &r, &s);
 		vector<int> a(N);
 		vector<long long> acc(N, 0);
 		
 		long long sum = 0;
 
 		for (int i = 0; i < N; ++i)
 		{
 			a[i] = (((long long)i * p + q) % r + s);
 			if (i != 0) acc[i] = acc[i - 1];
 			acc[i] += a[i];
 			sum += a[i];
 		}
 
 		long long ret = sum;
 
 		for (int i = 0; i < N; ++i)
 		{
 			// set A = i
 			long long left = ((i == 0) ? 0 : acc[i - 1]);
 			long long remain = sum - left;
 			
 			long long target = left + remain / 2;
 			int pos = lower_bound(acc.begin(), acc.end(), target) - acc.begin();
 
 			for (int j = pos - 1; j <= pos + 1; ++j)
 			{
 				if (i > j) continue;
 				if (j < 0 || j >= N) continue;
 
 				// set B = j
 
 				long long mid = acc[j] - left;
 				long long right = sum - acc[j];
 
 				long long mv = max(max(left, mid), right);
 				if (ret > mv) ret = mv;
 			}
 		}
 		printf("Case #%d: %.10lf\n", cn, (sum - ret) * 1.0 / sum);
 	}
 }
 
