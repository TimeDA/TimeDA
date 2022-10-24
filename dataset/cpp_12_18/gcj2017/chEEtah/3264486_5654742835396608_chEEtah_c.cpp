#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cctype>
 #include <iostream>
 #include <cassert>
 #include <sstream>
 #include <functional>
 #include <algorithm>
 #include <map>
 #include <string>
 #include <vector>
 #include <set>
 #include <queue>
 
 using namespace std;
 
 int nt;
 
 int main()
 {
 	int nt;
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 
 		long long N, K, rmin = -1, rmax = -1;
 		cin >> N >> K;
 
         map<long long, long long> state;
         state[N] = 1;
 
         while(K > 0 && rmin == -1)
         {
             map<long long, long long> newState;
             map<long long, long long>::reverse_iterator p = state.rbegin(), q = state.rend();
 
             while(p != q)
             {
                 long long len = p->first;
                 long long cnt = p->second;
                 p++;
 
                 long long len1 = (len - 1) / 2;
                 long long len2 =  len      / 2;
                 if (cnt >= K)
                 {
                     rmin = len1;
                     rmax = len2;
                     break;
                 }
                 K -= cnt;
                 newState[len1] += cnt;
                 newState[len2] += cnt;
             }
 
             state = newState;
         }
 
         cout << rmax << " " << rmin << endl;
 	}
 	return 0;
 }
