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
 
 //int main12R2B()
 int main()
 {
 	ifstream fin("B-small-attempt0.in");
 	ofstream fout("B-small-attempt0.out");
 	//ifstream fin("test.in");
 	//ofstream fout("test.out");	
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	int N,W,L;
 	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
 	{
 		fin >> N >> W >> L;
 		vector<pii> r(N);
 		vector<int> _x(N), _y(N);
 		for (int i=0; i<N; ++i)
 		{
 			fin >> r[i].first;
 			r[i].second=i;
 		}
 
 		bool swapped = false;
 		if (W>L)
 		{
 			swapped=true;
 			swap(W,L);
 		}
 
 		vector<int>& x = swapped ? _y : _x;
 		vector<int>& y = swapped ? _x : _y;
 
 		sort(r.begin(), r.end());
 		reverse(r.begin(), r.end());
 
 		x[r[0].second]=y[r[0].second]=0;
 		
 		int row=0, col = r[0].first, nextRow = r[0].first;
 		for (int i=1; i<N; ++i)
 		{
 			int loc = r[i].second;
 			int myR = r[i].first;
 			int myCol = col + myR;
 			if (myCol > W)
 			{
 				myCol = 0;
 				row = nextRow + myR;
 				nextRow = row + myR;
 			}
 
 			col = myCol + myR;
 
 			x[loc]=myCol;
 			y[loc]=row;
 		}
 
 		fout << "Case #" << zz << ":";
 		for (int i=0; i<N; ++i)
 			fout << " " << _x[i] << " " << _y[i];
 		fout << endl;
 	}
 
 	return 0;
 }