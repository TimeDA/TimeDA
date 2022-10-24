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
 #include<stack>
 #include<algorithm>
 #include<functional>
 #include<numeric>
 using namespace std;
 typedef pair<int, int> pii;
 typedef long long ll;
 #define mp make_pair
 
 namespace
 {
 	bool possible;
 	int N, x[2050];
 	ll result[2050];
 	const static ll big = 1000000000;
 }
 
 void solve(int start, int end)
 {
 	if (start + 1 >= end) return;
 	vector<int> s(1, end);
 
 	ll nextMove = 2;
 	for (int cur = end-1; cur > start; --cur)
 	{
 		if (x[cur] == cur+1)
 		{
 			result[cur] = result[cur+1] - nextMove;
 			s.push_back(cur);
 			nextMove *= 2;
 			continue;
 		}
 
 		while (x[cur] != s.back())
 		{
 			if (s.size() == 1)
 			{
 				possible = false; return;
 			}
 
 			int x1 = s[s.size()-1];
 			int x2 = s[s.size()-2];
 			ll dx = x2-x1;
 			ll y1 = result[x1], y2=result[x2];
 			ll dy = y2-y1;
 
 			ll dxNew = x2-cur;
 			ll dyNew = (dy * dxNew) / dx;
 
 			while (dyNew*dx >= dy*dxNew) 
 				--dyNew;
 
 			result[cur] = result[x2] - dyNew;
 			s.pop_back();
 		}
 
 		s.push_back(cur);
 		nextMove *= 2;
 	}
 }
 
 //int main12R2C()
 int main()
 {
 	ifstream fin("C-small-attempt0.in");
 	ofstream fout("C-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");	
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
 	{
 		fin >> N;
 		possible = true;
 
 		for (int i=0; i<N-1; ++i)
 		{
 			fin >> x[i];
 			--x[i];
 			if (x[i] <= i) possible = false;
 		}
 
 		
 		fill(result, result+2050, big);
 
 		int cur=0;
 		while (cur < N-1 && possible)
 		{
 			solve(cur, x[cur]);
 			cur = x[cur];
 		}
 
 		if (possible)
 		{
 			fout << "Case #" << zz << ":";
 			for (int i=0; i<N; ++i)
 				fout << " " << result[i];
 			fout << endl;
 		}
 		else
 		{
 			fout << "Case #" << zz << ": Impossible" << endl;
 		}
 		
 	}
 
 	return 0;
 }