#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <queue>
 #include <deque>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <numeric>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <memory.h>
 
 using namespace std;
 
 int T;
 
 int a[4][4];
 
 int main()
 {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	scanf("%d", &T);
 	for(int I = 0; I < T; ++I)
 	{
 		printf("Case #%d: ", I + 1);
 		set<int> A, B;
 		int first, second;
 		scanf("%d", &first);
 		first--;
 		for(int i = 0; i < 4; ++i)
 			for(int j = 0; j < 4; ++j)
 				scanf("%d", &a[i][j]);
 		for(int i = 0; i < 4; ++i)
 			A.insert(a[first][i]);
 		scanf("%d", &second);
 		second--;
 		for(int i = 0; i < 4; ++i)
 			for(int j = 0; j < 4; ++j)
 				scanf("%d", &a[i][j]);
 		for(int i = 0; i < 4; ++i)
 			B.insert(a[second][i]);
 		set<int> C;
 		for(set<int> :: iterator it = A.begin(); it != A.end(); ++it)
 			if (B.find(*it) != B.end())
 				C.insert(*it);
 		if (C.size() == 0)
 			printf("Volunteer cheated!\n");
 		else if (C.size() > 1)
 			printf("Bad magician!\n");
 		else
 			printf("%d\n", *C.begin());
 	}
 	return 0;
 }