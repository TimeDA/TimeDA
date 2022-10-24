#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int N;
int a[100010];

void func(int p){
	vector <int> v;
	int i;
	for(i=p;i<N;i+=2) v.push_back(a[i]);
	sort(v.begin(),v.end());
	for(i=p;i<N;i+=2) a[i] = v[i/2];
}

void main2(void){
	int i;
	
	cin >> N;
	REP(i,N) scanf("%d", &a[i]);
	
	func(0);
	func(1);
	
	REP(i,N-1) if(a[i] > a[i+1]){
		cout << i << endl;
		return;
	}
	
	cout << "OK" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc + 1);
		main2();
	}
	return 0;
}
