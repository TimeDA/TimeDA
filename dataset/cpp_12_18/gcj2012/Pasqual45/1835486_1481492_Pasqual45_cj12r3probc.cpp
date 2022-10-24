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
 using namespace std;
 typedef pair<int, int> pii;
 typedef long long ll;
 #define mp make_pair
 
 namespace
 {
 	int cost[2000005];
 }
 
 //int main12R3C()
 int main()
 {
 	ifstream fin("C-small-attempt0.in");
 	ofstream fout("C-small-attempt0.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	int M,F,N;
 	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
 	{
 		fin >> M >> F >> N;
 		vector<pii> v(N);
 		for (int i=0; i<N; ++i)
 			fin >> v[i].first >> v[i].second;
 
 		sort(v.begin(), v.end());
 		cost[0] = F;
 		int time=1, cur = 0;
 		while (cur < v.size())
 		{
 			if (v[cur].second + 1 >= time)
 			{
 				cost[time] = cost[time-1] + v[cur].first;
 				++time;
 			}
 			else
 				++cur;
 		}
 
 		int maxDaysFromOneDelivery = time - 1;
 
 		ll lo=0, hi = M;
 		while (lo+1<hi)
 		{
 			ll mid = (lo+hi)/2; // Attempt to survive mid days
 			ll nDeliveries = (mid+maxDaysFromOneDelivery-1) / maxDaysFromOneDelivery;
 
 			bool suceed = false;
 			while (nDeliveries <= mid && !suceed)
 			{
 				ll smallDelivery = mid/nDeliveries;
 				ll largeDelivery = smallDelivery+1;
 
 				ll numLarge = mid % nDeliveries;
 				ll numSmall = nDeliveries - numLarge;
 
 				ll thisCost = cost[smallDelivery] * numSmall + cost[largeDelivery] * numLarge;
 				if (thisCost <= M)
 					suceed = true;
 
 				++nDeliveries;
 			}
 
 			if (suceed)
 				lo=mid;
 			else
 				hi=mid;
 		}
 
 		fout << "Case #" << zz << ": " << lo << endl;
 	}
 
 	return 0;
 }