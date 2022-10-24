#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    string input;
    for(int case_nb = 1; case_nb <= T; ++case_nb){
        int N; cin >> N;
        vector<int> nb_senators(N);
        int total_senators = 0;
        for(int i = 0; i < N; ++i){ 
            cin >> nb_senators[i];
            total_senators += nb_senators[i];
        }
        cout << "Case #" << case_nb << ":";
        while(total_senators > 0){
            int maximal_nb_of_senators = *std::max_element(nb_senators.begin(), nb_senators.end());
            auto f = std::find(nb_senators.begin(), nb_senators.end(), maximal_nb_of_senators);
            auto s = std::find(f + 1, nb_senators.end(), maximal_nb_of_senators);
            cout << " ";
            cout << (char)('A' + (f - nb_senators.begin()));
            --total_senators;
            --(*f);
            if(maximal_nb_of_senators * 2 > total_senators && s != nb_senators.end()){
                cout << (char)('A' + (s - nb_senators.begin()));
                --total_senators;
                --(*s);
            }
            // cerr << endl;
            // cerr << "Situation: (total = " << total_senators << ")" << endl;
            // for(auto x : nb_senators){
            //     cerr << x << " ";
            // }
            // cerr << endl;
        }
        cout << endl;
    }
    return 0;
}