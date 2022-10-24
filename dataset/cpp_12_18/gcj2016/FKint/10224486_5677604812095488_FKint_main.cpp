#include <bits/stdc++.h>
 #include <cstdio>
 using namespace std;
 map<int, map<int, map<int, double> > > cache;
 double calc(vector<double> &votes, int left, int right, int nb_yes){
 	if(nb_yes > right-left)
 		return 0;
 	if(right == left+1){
 		if(nb_yes == 1)
 			return votes[left];
 		return 1-votes[left];
 	}
 	if(cache[left][right].count(nb_yes))
 		return cache[left][right][nb_yes];
 	int mid = (left+right)/2;
 	double total = 0;
 	for(int i = 0; i <= nb_yes; ++i){
 		total += calc(votes, left, mid, i)*calc(votes, mid, right, nb_yes-i);
 	}
 	cache[left][right][nb_yes] = total;
 	return total;
 }
 
 int main(){
 	std::ios::sync_with_stdio(false);
 	int nb_cases;
 	cin >> nb_cases;
 	for(int case_nb = 1; case_nb <= nb_cases; ++case_nb){
 		cache.clear();
 		int N, K;
 		cin >> N >> K;
 		vector<double> probs;
 		for(int i = 0; i < N; ++i){
 			double p;
 			cin >> p;
 			probs.push_back(p);
 		}
 		sort(probs.begin(), probs.end());
 		vector<double> votes;
 		for(int i = 0; i < K/2; ++i){
 			votes.push_back(probs[i]);
 			votes.push_back(probs[N-1-i]);
 		}
 		cout << "Case #" << case_nb << ": ";
 		cout << calc(votes, 0, K, K/2) << endl;
 	}
     return 0;
 }
