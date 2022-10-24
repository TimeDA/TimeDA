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
 
 //int main12R3D()
 int main()
 {
 	ifstream fin("D-small-attempt0.in");
 	ofstream fout("D-small-attempt0.out");
 
 	unsigned int numberOfCases;
 	fin >> numberOfCases;
 
 	char leet[256] = {0};
 	for (char c='a'; c<='z'; ++c)
 		leet[c]=c;
 
 	leet['o'] = '0';
 	leet['i'] = '1';
 	leet['e'] = '3';
 	leet['a'] = '4';
 	leet['s'] = '5';
 	leet['t'] = '7';
 	leet['b'] = '8';
 	leet['g'] = '9';
 
 	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
 	{
 		int k;
 		string s;
 		fin >> k >> s;
 		k=2;
 
 		set<char> sIn[256];
 		set<char> sOut[256];
 		set<char> self;
 
 		for (int i=0; i+1<s.size(); ++i)
 		{
 			for (int j=0; j<4; ++j)
 			{
 				char c1 = (j<2 ? s[i] : leet[s[i]]);
 				char c2 = ((j%2==0) ? s[i+1] : leet[s[i+1]]);
 
 				if (c1 == c2)
 				{
 					self.insert(c1);
 				}
 				else
 				{
 					sOut[c1].insert(c2);
 					sIn[c2].insert(c1);
 				}
 			}
 		}
 
 		int result = 0;
 		int added = 0;
 		for (int i=0; i<256; ++i)
 		{
 			int n1 = sIn[i].size(), n2 = sOut[i].size();
 			if (n1==0 && n2==0) continue;
 
 			result += n2;
 			if (n2 > n1)
 				added += n2-n1;
 		}
 
 		result += max(added, 1) + self.size();
 		fout << "Case #" << zz << ": " << result << endl;
 	}
 
 	return 0;
 }