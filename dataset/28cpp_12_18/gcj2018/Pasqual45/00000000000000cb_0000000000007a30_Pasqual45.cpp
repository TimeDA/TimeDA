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
#include<bitset>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair

int main()
{
	unsigned int numberOfCases;
	cin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
	    int A;
	    cin >> A;
	    
	    int x,y;
	    int a,b;
	    
	    int len = (A+2)/3;
	    vector<vector<int> > v(3, vector<int>(len));
	    vector<int> cnt(len, 0);
	    while (true)
	    {
	        int where = distance(cnt.begin(), min_element(cnt.begin() + 2, cnt.end()));
	        cout << 11 << ' ' << (where + 11 - 2) << endl;
	        
	        cin >> a >> b;
	        if (a == 0 && b ==0) break;
	        if (a == -1 && b == -1) return 0;
	        
	        a -= 10;
	        b -= 10;
	        
	        if (v[a][b] == 0)
	        {
	            v[a][b] = 1;
	            ++cnt[b];
	            ++cnt[b+1];
	            ++cnt[b+2];
	        }
	        
	    }
	}

	return 0;
}
