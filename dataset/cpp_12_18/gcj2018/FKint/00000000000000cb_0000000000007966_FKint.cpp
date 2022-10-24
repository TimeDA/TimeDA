#include <bits/stdc++.h>
using namespace std;
long long improve(vector<int>& charges, int N){
    if(charges.back() < N - 1){
        charges.back()++;
        return (1 << (charges.size() - 1));
    }
    for(int i = charges.size() - 1; i > 0; --i){
        if(charges[i] > charges[i-1] + 1){
            charges[i-1]++;
            return (1 << (i-1));
        }
    }
    cerr << "No improvements..." << endl;
}
int main(){
    int T; cin >> T;
    for(int case_nb = 1; case_nb <= T; ++case_nb){
        long long D; cin >> D;
        string seq; cin >> seq;
        vector<int> charges;
        long long current_damage = 0;
        for(int i = 0; i < (int)seq.size(); ++i){
            char c = seq[i];
            if(c == 'C'){
                charges.push_back(i);
            }else{
                current_damage += (1 << charges.size());
            }
        }
        cout << "Case #" << case_nb <<": ";
        if((seq.size() - charges.size()) > D){
            cout << "IMPOSSIBLE";
        }else{
            int nb_hacks = 0;
            while(current_damage > D){
                long long improvement = improve(charges, seq.size());
                current_damage -= improvement;
                nb_hacks++;
            }
            cout << nb_hacks;
        }
        cout << endl;
    }
    return 0;
}