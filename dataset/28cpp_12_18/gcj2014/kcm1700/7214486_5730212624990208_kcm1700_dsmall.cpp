#include <vector>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <string>
 #include <cstring>
 #include <memory.h>
 #include <algorithm>
 #include <cstdio>
 #include <cstdint>
 #include <cstdlib>
 #include <functional>
 #include <numeric>
 
 #include <thread>
 #include <atomic>
 #include <chrono>
 
 using namespace std;
 
 char dat[120][120];
 
 int main()
 {
 	int TT;
 	scanf("%d", &TT);
 	for (int testcase = 1; testcase <= TT; testcase ++)
 	{
 		fprintf(stderr, "Processing case %d\n", testcase);
 
 		int n, A;
 		scanf("%d%d", &n, &A);
 		for (int i = 0; i < n; i++) {
 			scanf("%s", &dat[i]);
 		}
 
 		vector<int> perm;
 		for (int i = 0; i < n; i++) {
 			perm.push_back(i);
 		}
 
 		bool found = false;
 		do
 		{
 			int cur = -1;
 			for (int i = 0; i < n; i++){
 				if (cur == -1 || dat[perm[i]][cur] == 'Y'){
 					cur = perm[i];
 				}
 			}
 			if (cur == A) {
 				printf("Case #%d:", testcase);
 				for (int i = 0; i < n; i++){
 					printf(" %d", perm[i]);
 				}
 				puts("");
 				found = true;
 				break;
 			}
 		} while (next_permutation(perm.begin(), perm.end()));
 		
 		if (!found) {
 			printf("Case #%d: IMPOSSIBLE\n", testcase);
 		}
 
 		fprintf(stderr, "Finished case %d\n", testcase);
 	}
 
 	return 0;
 }