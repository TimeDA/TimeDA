// failed to generate code
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)
#define int long long
typedef long double Double;


class Rectangle{
public:
    int x1,y1;
    int x2,y2;
    void apply(Rectangle r){
        x1 = max(x1, r.x1);
        x2 = min(x2, r.x2);
        y1 = max(y1, r.y1);
        y2 = min(y2, r.y2);
    }
};
struct P{int x,y;};

int solve();

void main_(istream &cin){
    int T;
    cin >> T;

    for(int i = 0 ; i < T ; i++){
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }

}

int solve() {
    int N;
    cin >> N;
    vector<P> ps;
    for(int i = 0 ; i < N ; i++){
        int x,y;
        cin >> x >> y;
        ps.push_back({x,y});
    }
    auto ok = [&](int d){
        Rectangle r;
        int fst = 1;
        for( auto p : ps ){
            if( fst ){
                r = {p.y - d, p.x - d, p.y + d + 1, p.x + d + 1};
                fst = 0;
            }else{
                r.apply({p.y - d, p.x - d, p.y + d + 1 , p.x + d + 1});
            }
        }
        return r.x1 < r.x2 && r.y1 < r.y2;
    };
    int l = 0, r = 1e12;
    while(l != r){
        int m = (l+r) / 2;

        if( ok(m) ){
            r = m;
        }else{
            l = m + 1;
        }
    }
    return l;
}

signed main() {
#ifdef INTELLIJ
    ifstream ifs("/home/kyuridenamida/CLionProjects/untitled/input.txt");
    if (ifs.is_open()) {
        main_(ifs);
        ifs.close();
    } else {
        cerr << "Error: no input." << endl;
    }
#else
    ios::sync_with_stdio(false);
    cin.tie(0);
    main_(cin);
#endif
}


