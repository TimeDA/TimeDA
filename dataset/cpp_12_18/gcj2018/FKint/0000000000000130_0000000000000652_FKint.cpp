#include <bits/stdc++.h>
using namespace std;

void add_sizes(int s, int nb, map<int, int> &interval_size_frequencies, priority_queue<int>& pq){
    // cerr << "Adding " << nb << " intervals of length " << s << endl;
    if(s == 0) return;
    if(interval_size_frequencies[s] == 0){
        pq.push(s);
    }
    interval_size_frequencies[s] += nb;
}
int main(){
    int T; cin >> T;
    string input;
    for(int case_nb = 1; case_nb <= T; ++case_nb){
        int N, K; cin >> N >> K;
        priority_queue<int> pq;
        pq.push(N);
        map<int, int> interval_size_frequencies;
        interval_size_frequencies[N] = 1;
        cout << "Case #" << case_nb << ": ";
        while(K > 0){
            int t = pq.top(); pq.pop();
            int nb = interval_size_frequencies[t];
            interval_size_frequencies.erase(t);
            int left_size = t/2;
            int right_size = t - (t/2) - 1;
            // cerr << "Found " << nb << " intervals of length " << t << endl;
            if(nb >= K){
                cout << left_size << " " << right_size << endl;
                break;
            }
            K -= nb;
            add_sizes(left_size, nb, interval_size_frequencies, pq);
            add_sizes(right_size, nb, interval_size_frequencies, pq);
        }
    }
    return 0;
}