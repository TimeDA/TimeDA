#include <bits/stdc++.h>
 #include <cstdio>
 using namespace std;
 
 struct RPS{
 	int rocks;
 	int papers;
 	int scissors;
 	/*S(const RPS &s){
 		this->papers = s.papers;
 		this->rocks = s.rocks;
 		this->scissors = s.scissors;
 	}*/
 	RPS(){
 		this->papers = 0;
 		this->rocks = 0;
 		this->scissors = 0;
 	}
 	RPS(int p, int r, int s){
 		this->rocks = r;
 		this->papers = p;
 		this->scissors = s;
 	}
 	RPS& operator=(const RPS &s2){
 		this->rocks = s2.rocks;
 		this->papers = s2.papers;
 		this->scissors = s2.scissors;
 	}
 	RPS operator+(const RPS &s2) const{
 		return RPS(papers + s2.papers, rocks + s2.rocks, scissors + s2.scissors);
 	}
 	bool operator==(const RPS &s2)const{
 		return rocks == s2.rocks && papers == s2.papers && scissors == s2.scissors;
 	}
 	void print(){
 		cout << papers << " " << rocks << " " << scissors << endl;
 	}
 };
 char LETTER[3] = {'P', 'R', 'S'};
 int loses_from[3] = {
 	1, 2, 0
 };
 
 void generate_tree(int winner, int N, vector<int> &v, int left, int right){
 	v[left] = winner;
 	if(N == 0){
 		return;
 	}
 	int current_size = 1;
 	while(left + current_size < right){
 		generate_tree(loses_from[winner], N-1, v, left + current_size, left + current_size + current_size);
 		current_size *= 2;
 	}
 }
 map<pair<int, int>, RPS> cache;
 RPS tournament(int N, int winner){
 	if(cache.count(make_pair(N, winner)))
 		return cache[make_pair(N, winner)];
 	RPS current(winner == 0?1:0, winner==1?1:0, winner==2?1:0);
 	int current_size = 1;
 	int tournament_size = 0;
 	while(tournament_size < N){
 		current = current + tournament(tournament_size, loses_from[winner]);
 		tournament_size += 1;
 		current_size *= 2;
 	}
 	cache[make_pair(N, winner)] = current;
 	return current;
 }
 
 void sort_tournament(vector<int> &v, int left, int right){
 	if(right == left+1)
 		return;
 	sort_tournament(v, left, (left+right)/2);	
 	sort_tournament(v, (left+right)/2, right);
 	for(int i = 0; i < (right-left)/2; ++i){
 		if(v[i+left] < v[(left+right)/2+i])
 			return;
 		if(v[i+left] > v[(left+right)/2+i]){
 			for(int j = 0; j < (right-left)/2; ++j){
 				int t = v[left+j];
 				v[left+j] = v[(left+right)/2+j];
 				v[(left+right)/2+j] = t;
 			}
 			return;
 		}
 	}
 }
 
 int main(){
 	std::ios::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int case_nb = 1; case_nb <= T; ++case_nb){
 		int N, R, P, S;
 		cin >> N >> R >> P >> S;
 		RPS res(P, R, S);
 		RPS a = tournament(N, 0);
 		RPS b = tournament(N, 1);
 		RPS c = tournament(N, 2);
 		cout << "Case #" << case_nb <<": ";
 		vector<int> v(1<<N);
 		int winner = -1;
 		if(a == res){
 			winner = 0;
 		}else if(b == res){
 			winner = 1;
 		}else if(c == res){
 			winner = 2;
 		}else{
 			cout << "IMPOSSIBLE";
 		}
 		if(winner != -1){
 			generate_tree(winner, N, v, 0, 1<<N);
 			sort_tournament(v, 0, 1 << N);
 			for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
 				cout << LETTER[*it];
 			}
 		}
 		cout << endl;
 	}
     return 0;
 }
