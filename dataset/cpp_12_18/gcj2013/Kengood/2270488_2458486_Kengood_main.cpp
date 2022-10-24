#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <numeric>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <string>
 #include <complex>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <cctype>
 #include <cstring>
 #include <climits>
 #include <ctime>
 using namespace std;
 
 #define IN_THE_SET(_set,_val) (_set.find(_val) != _set.end())
 
 int cases , Case = 1;
 ////////////
 
 struct Box
 {
 	int need;
 	vector<int> prize;
 }box[24];
 
 struct State
 {
 	vector<int> path;
 	int vis;
 	map<int,int> key;
 };
 
 int main()
 {	
 	//aaa(); return 0;
 	scanf("%d" , &cases);	
 	while( cases-- )
 	{
 		printf("Case #%d: " , Case++);   
 		int n , k;
 		cin >> k >> n;
 		map<int,int> startkey;
 		for(int i = 0 ; i < k; ++i)
 		{
 			int t; cin >> t;
 			++startkey[t];
 		}
 
 		for(int i = 0 ; i < n; ++i)
 		{
 			cin >> box[i].need;
 			box[i].prize.clear();
 			int t,a; cin >> t;
 			while(t--)
 			{
 				cin >>a; box[i].prize.push_back(a);
 			}
 		}
 
 		State now;
 		now.key = startkey;
 		now.vis = 0;
 
 		queue<State> q;
 		q.push(now);
 
 		set< pair<int, map<int,int> > > vis;
 
 		while( !q.empty() )
 		{
 			now = q.front(); q.pop();			
 			if( now.vis == (1<<n)-1 )
 			{
 				for(int i = 0 ; i < n; ++i)
 				{
 					if(i) cout << " ";
 					cout << now.path[i];
 				}
 				cout << endl;
 				goto next;
 			}
 			pair< int , map<int,int> > hh = make_pair( now.vis , now.key );
 			if( IN_THE_SET(vis , hh) ) continue;
 			vis.insert(hh);
 
 			for(int i = 0 ; i < n; ++i)
 			{
 				if( !(now.vis&(1<<i) ) && now.key[box[i].need] > 0 )
 				{
 					State net = now;
 					net.vis|=(1<<i);
 					--net.key[box[i].need];
 					net.path.push_back(i+1);
 					for(int j = 0 ; j < box[i].prize.size(); ++j)
 						++net.key[box[i].prize[j]];
 					q.push(net);
 				}
 			}
 
 
 		}
 		cout << "IMPOSSIBLE" << endl;
 
 		next:;
 	}
 
 
 	return 0;
 }
