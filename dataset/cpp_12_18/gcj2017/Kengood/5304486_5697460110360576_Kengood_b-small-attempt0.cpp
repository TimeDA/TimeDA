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
 
 #include<unordered_map>
 #include<unordered_set>
 using namespace std;
 
 namespace Matching
 {
 #define MAXN 128
 #define MAXM 128
 
     char G[MAXN][MAXM];
 
     int conjLeft[MAXN]; //left link to which right
     int conjRight[MAXM];
     char visited[MAXM];
 
     int n,m; //graph size
 
     void init(int left, int right)
     {
         memset(G,0,sizeof(G));
         memset(visited, 0,sizeof(visited));
         n = left;
         m = right;
 
         for(int i=0; i<n; i++) conjLeft[i] = -1;
         for(int i=0; i<m; i++) conjRight[i] = -1;
     }
 
     char augment(int no)
     {
         for(int i = 0;i<m;i++)
         {
             if(G[no][i] && !visited[i]) {
                 visited[i]=1;
                 if(conjRight[i]==-1 || augment(conjRight[i])) {
                     conjLeft[no] = i;
                     conjRight[i] = no;
                     return 1;
                 }
             }
         }
         return 0;
     }
     int Matching() {
         int i;
         char foundNewFlow ;
         int nMatched = 0;
 
         do {
             foundNewFlow=0;
             for(i=0; i<m; i++) visited[i] = 0;
             for(i=0; i<n; i++)
             {
                 if(conjLeft[i]==-1)  //not linked
                     if(augment(i)) //can link
                     {
                         foundNewFlow = 1;
                         nMatched++;
                     }
             }
         } while(foundNewFlow);
 
         return nMatched;
     }
 
 };
 
 int main(int __an, char **__ag)
 {	
 	int Case, cases = 0;
 	scanf("%d" , &Case);
 	while (Case--)	
 	{
 		int n, p; cin >> n >> p;
 		vector<int> ingre(n);
 
 		for (int i = 0 ; i < n; ++i)
 		{
 			cin >> ingre[i];
 			(ingre[i]*90) /100;
 			(ingre[i]*110) /100;
 		}
 		vector< vector<int>> pack(n,vector<int>(p));
 		vector< vector<set<int>>> poss(n,vector<set<int>>(p));
 		
 
 		for (int i = 0 ; i < n; ++i)
 		{
 			for (int j = 0; j < p; ++j)
 			{
 				cin >> pack[i][j];
 
 				for (int l = 1; ;++l)
 				{
 					if ((ingre[i]*l*90)/100 > pack[i][j])
 						break;
 					if ((ingre[i]*l*90)/100 <= pack[i][j] && pack[i][j] <= (ingre[i]*l*110)/100)
 						poss[i][j].insert(l);
 
 
 				}
 
 			}
 		}
 
 		int ans = 0;
 		if (n == 1)
 		{
 			for (int j = 0; j < p; ++j)
 			{
 				if (!poss[0][j].empty())
 					++ans;
 			}
 		}
 		else // n == 2
 		{
 			Matching::init(p,p);
 			for (int i = 0; i < p; ++i)
 			{
 				for (int j = 0; j < p; ++j)
 				{
 					bool aa = 0;
 					for (auto iter = poss[0][i].begin(); iter != poss[0][i].end(); ++iter)
 					{
 						if (poss[1][j].find(*iter) != poss[1][j].end())
 						{
 							aa = 1;
 							break;
 						}
 					}
 					if (aa)
 						Matching::G[i][j]=1;
 				}
 			}
 			ans = Matching::Matching();
 		}
 	
 
 
 	
 		printf("Case #%d: " , ++cases);
 		cout << ans << endl;
 
 	}
 
 	return 0;
 }
 
