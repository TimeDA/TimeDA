#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ENDL "\n"

bool make_metal(int metal, long long amount, vector<long long>& available, const vector<pair<int, int>>& ingredients, vector<int>& current_stack){
    // detect loops
    long long direct_available = min(amount, available[metal]);
    available[metal] -= direct_available;
    amount -= direct_available;
    if(amount == 0)
        return true;
    if(current_stack[metal])
        return false;
    current_stack[metal]++;
    bool result = make_metal(ingredients[metal].first, amount, available, ingredients, current_stack) && make_metal(ingredients[metal].second, amount, available, ingredients, current_stack);
    current_stack[metal]--;
    return result;
}

bool can_make(long long amount, vector<long long> available /* copy */, const vector<pair<int,int>>& ingredients){
    vector<int> current_stack(available.size(), 0);
    return make_metal(0, amount, available, ingredients, current_stack);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    for(int curr_case = 1; curr_case <= T; ++curr_case){
        int M; cin >> M;
        vector<pair<int, int>> ingredients(M);
        for(int i = 0; i < M; ++i){
            cin >> ingredients[i].first >> ingredients[i].second;
            --ingredients[i].first; --ingredients[i].second;
        }

        vector<long long> available(M);
        for(int i = 0; i < M; ++i){
            cin >> available[i];
        }
        
        long long left = 0;
        long long right = accumulate(available.begin(), available.end(), 0) + 1;
        while(left < right - 1){
            long long mid = (left + right) / 2;
            if(can_make(mid, available, ingredients)){
                left = mid;
            }else{
                right = mid;
            }
        }

        cout << "Case #" << curr_case << ": ";
        cout << left;
        cout << ENDL;
    }
    return 0;
}
