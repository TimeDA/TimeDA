#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;


int N;
int A[100010], B[100010];
int na[100010], nb[100010];

void calcNext(int *A, int *na){
	for(int i = N - 1 ; i >= 0 ; i--){
		if( i + 1 == N || A[i] != A[i+1] ){
			na[i] = i+1;
		}else{
			na[i] = na[i+1];
		}
	}
}

int NONE = 1e9;

pair<int,int> addBest(int l,int r,int *A, int *na){
	if( r == N || A[r] != A[l]) return {l,r};
	return {l, na[r]};
}


vector< pair<int,int> > longest;	
void compute(int *A, int *B,int *na, int *nb){
	map< pair<int,int>, vector< pair<int,int> > > mp;
	for(int i = 0 ; i < N ; i++){
		if( i && na[i] == na[i-1] ) continue;
		longest.push_back({i, na[i]});
		if( na[i] == N ) continue;
		mp[{A[i], B[na[i]]}].push_back({i, nb[na[i]]});

	}


	for( auto ele : mp ){
		int l = -1, r = -1;
		for( auto p : ele.second ){
			if( l == -1 ){
				l = p.first;
				r = p.second;
			}else if( r == p.first ){
				r = p.second;
			}else{
				longest.push_back(addBest(l,r,A, na));
				l = p.first;
				r = p.second;
			}
		}
		longest.push_back(addBest(l,r,A, na));
	}


}

int res[100010];
set<int> pos;

void solve(int t){
	longest.clear();
	pos.clear();
	
	scanf("%d",&N);
	
	for(int i = 0 ; i < N ; i++){
		int d,a,b;
		scanf("%d%d%d",&d,&a,&b);
		A[i] = d + a;
		B[i] = d - b;
	}

	calcNext(A, na);
	calcNext(B, nb);
	compute(A, B, na, nb);
	compute(B, A, nb, na);
	sort(longest.begin(), longest.end(),[&](const pair<int,int> &a, const pair<int,int> &b){return a.second > b.second;});
	
	pos.clear();
	for(int i = 0 ; i < N ; i++) pos.insert(i);


	for(auto p : longest ){
		auto it = pos.lower_bound(p.first);
		while( it != pos.end() && (*it) < p.second ){
			res[*it] = p.second;
			it = pos.erase(it);
		}
	}
	assert(pos.size() == 0);
	int ans = 0;
	int mx = 0;
	for(int i = 0 ; i < N ; i++) mx = max(mx, res[i] - i);
	for(int i = 0 ; i < N ; i++) ans += res[i] - i == mx;

	printf("Case #%d: %d %d\n", t, mx, ans);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int i = 0 ; i < T ; i++) solve(i+1);
}