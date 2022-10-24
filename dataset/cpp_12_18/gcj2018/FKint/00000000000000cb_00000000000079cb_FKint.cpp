#include <bits/stdc++.h>
using namespace std;
int first_incorrect(vector<int>& v){
    for(int i = 1; i < v.size(); ++i){
        if(v[i-1] > v[i])
            return i-1;
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for(int case_nb = 1; case_nb <= T; ++case_nb){
        int N; cin >> N;
        vector<int> num(N);
        for(int i = 0; i < N; ++i){ cin >> num[i]; }
        bool ready = false;
        while(!ready){
            ready = true;
            for(int i = 2; i < num.size(); ++i){
                if(num[i-2] > num[i]){
                    swap(num[i-2], num[i]);
                    ready = false;
                }
            }
        }
        cout << "Case #" << case_nb <<": ";
        int res = first_incorrect(num);
        if(res == -1){
            cout << "OK";
        }else{
            cout << res;
        }
        cout << endl;
    }
    return 0;
}