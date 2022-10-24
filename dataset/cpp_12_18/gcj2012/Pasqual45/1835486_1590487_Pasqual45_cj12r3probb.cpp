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
 	int S;
 	bool stone[105][105];
 	bool touched[105][105];
 	pii corners[6];
 	vector<pii> sides[6];
 	queue<pii> q;
 
 	bool validSpace(int x, int y)
 	{
 		if (x<=0 || y<=0 || x>=2*S || y>=2*S) return false;
 
 		if (x<=S && y<=S) return true;
 		if (x>=S && y>=S) return true;
 		if (x>S) return (y>x-S);
 		return x>y-S;
 	}
 
 	void explore()
 	{
 		while (!q.empty())
 		{
 			int x=q.front().first, y=q.front().second;
 			q.pop();
 			if (touched[x][y]) continue;
 			touched[x][y]=true;
 			for (int i=-1; i<=1; ++i)
 			{
 				for (int j=-1; j<=1; ++j)
 				{
 					if (i==0 && j==0) continue;
 					if (i*j == -1) continue;
 					int a=x+i, b=y+j;
 					if (!validSpace(a,b)) continue;
 					if (stone[a][b] != stone[x][y]) continue;
 					q.push(mp(a,b));
 				}
 			}
 		}
 	}
 
 	void clearTouched() {memset(touched,0,sizeof(touched)); q.swap(queue<pii>()); }
 	void touchCorners(bool withStones)
 	{
 		for (int i=0; i<6; ++i)
 		{
 			int x=corners[i].first, y=corners[i].second;
 			if (stone[x][y] == withStones)
 				q.push(corners[i]);
 		}
 	}
 
 	void touchEdge(int i, bool withStones)
 	{
 		const vector<pii>& side = sides[i];
 		for (int j=0; j<side.size(); ++j)
 		{
 			int x=side[j].first, y=side[j].second;
 			if (stone[x][y] == withStones)
 				q.push(side[j]);
 		}
 	}
 
 	void touchEdges(bool withStones)
 	{
 		for (int i=0; i<6; ++i)
 			touchEdge(i, withStones);
 	}
 
 	bool anyLoners()
 	{
 		clearTouched();
 		touchCorners(false);
 		touchEdges(false);
 		explore();
 
 		for (int i=1; i<2*S; ++i)
 			for (int j=1; j<2*S; ++j)
 				if (validSpace(i,j))
 					if (!stone[i][j] && !touched[i][j])
 						return true;
 		return false;
 	}
 
 	bool anyBridge()
 	{
 		for (int i=0; i<6; ++i)
 		{
 			clearTouched();
 			int x=corners[i].first, y=corners[i].second;
 			if (!stone[x][y]) continue;
 
 			q.push(corners[i]);
 			explore();
 			for (int j=0; j<6; ++j)
 			{
 				if (i==j) continue;
 				int a=corners[j].first, b=corners[j].second;
 				if (touched[a][b])
 					return true;
 			}
 		}
 		return false;
 	}
 
 	bool anyFork()
 	{
 		for (int i=0; i<6; ++i)
 		{
 			clearTouched();
 			touchEdge(i, true);
 			explore();
 
 			int cnt=0;
 			for (int z=0; z<6; ++z)
 			{
 				bool found = false;
 				const vector<pii>& side = sides[z];
 				for (int j=0; j<side.size(); ++j)
 				{
 					int x=side[j].first, y=side[j].second;
 					if (touched[x][y])
 						found = true;
 				}
 				if (found)
 					++cnt;
 			}
 
 			if (cnt >= 3)
 				return true;
 		}
 		return false;
 	}
 
 }
 
 int main()
 {
 	// bridge=1, fork=2, ring=4
 	string winners[8] = {"none", "bridge", "fork", "bridge-fork", "ring", "bridge-ring", "fork-ring", "bridge-fork-ring"};
 
 	ifstream fin("B-small-attempt1.in");
 	ofstream fout("B-small-attempt1.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	int M,x,y;
 	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
 	{
 		fin >> S >> M;
 
 		memset(stone,0,sizeof(stone));
 		memset(touched,0,sizeof(touched));
 
 		corners[0] = mp(1,1);
 		corners[1] = mp(1,S);
 		corners[2] = mp(S,1);
 		corners[3] = mp(2*S-1,S);
 		corners[4] = mp(S,2*S-1);
 		corners[5] = mp(2*S-1,2*S-1);
 
 		int startX[] = {1, 2, 2, S+1, S+1, 2*S-1};
 		int dX[] =     {0, 1, 1, 1, 1, 0};
 
 		int startY[] = {2, 1, S+1, 2, 2*S-1, S+1};
 		int dY[] =     {1, 0, 1, 1, 0, 1};
 
 		for (int i=0; i<6; ++i)
 		{
 			sides[i].clear();
 			for (int j=0; j+2<S; ++j)
 				sides[i].push_back(mp(startX[i] + dX[i] * j, startY[i] + dY[i] * j));
 		}
 
 		int result = 0, finished=0;
 		for (int i=1; i<=M; ++i)
 		{
 			fin >> x >> y;
 			if (result>0) continue;
 			stone[x][y] = true;
 
 			if (anyLoners())
 				result |= 4;
 
 			if (anyBridge())
 				result |= 1;
 
 			if (anyFork())
 				result |= 2;
 
 			if (result > 0)
 				finished = i;
 		}
 
 		fout << "Case #" << zz << ": " << winners[result];
 		if (result > 0)
 			fout << " in move " << finished;
 		fout << endl;
 	}
 
 	return 0;
 }