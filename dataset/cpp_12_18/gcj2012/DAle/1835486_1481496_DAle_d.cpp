#include <fstream>
 #include <iomanip>
 #include <algorithm>
 #include <numeric>
 #include <vector>
 #include <string>
 #include <map>
 #include <set>
 #include <queue>
 #include <utility>
 #include <cmath>
 #include <functional>
 #include <stack>
 #include <set>
 
 using namespace std;
 
 char change(char ch) 
 {
 	switch (ch) 
 	{
 	case 'o': return '0';
 	case 'i': return '1'; 
 	case 'e': return  '3'; 
 	case 'a': return  '4'; 
 	case 's': return  '5'; 
 	case 't': return  '7'; 
 	case 'b': return  '8'; 
 	case 'g': return  '9';
 	}
 	return ch;
 }
 
 int main()
 {
 	ifstream ifs("d.in");
 	ofstream ofs("d.out");
 	int t;
 	ifs >> t;
 	for (int test = 0; test < t; ++test)
 	{
 		int res;
 		ifs >> res;
 		string s;
 		ifs >> s;
 		set<string> st;
 		for (int i = 0; i+1 < s.size(); ++i)
 		{
 			string t = s.substr(i, 2);
 			st.insert(t);
 			st.insert(string(1, change(t[0]))+t[1]);
 			st.insert(string(1, change(t[0]))+change(t[1]));
 			st.insert(string(1, change(t[0]))+t[1]);
 			st.insert(string(1, t[0])+change(t[1]));
 		}
 
 		map<char, int> u,d;
 		for (set<string>::iterator si = st.begin(); si != st.end(); ++si)
 		{
 			u[(*si)[0]]++;
 			d[(*si)[1]]++;
 		}
 		for (map<char, int>::iterator mi = d.begin(); mi != d.end(); ++mi)
 		{
 			u[mi->first] -= mi->second;
 		}
 		int pos = 0, neg = 0;
 		for (map<char, int>::iterator mi = u.begin(); mi != u.end(); ++mi)
 		{
 			if (mi->second > 0) pos += mi->second;
 			else neg += abs(mi->second);
 		}
 		if (pos > 0) --pos;
 		if (neg > 0) --neg;
 		ofs << "Case #" << test+1 << ": " << st.size()+1 + max(pos, neg) << endl;
 	}
 	return 0;
 }
