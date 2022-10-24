#include <bits/stdc++.h>
using namespace std;
double compute_area(double alpha){
    return cos(alpha) + sin(alpha);
}
#define EPS 1e-12
int main(){
    int T; cin >> T;
    for(int case_nb = 1; case_nb <= T; ++case_nb){
        double A; cin >> A;
        cout << "Case #" << case_nb << ": " << endl;
        double left = 0;
        double right = atan2(1,1);
        double alpha = 0;
        while(left < right - EPS){
            alpha = (left + right) / 2;
            if(compute_area(alpha) > A){
                right = alpha;
            }else{
                left = alpha;
            }
        }
        cout << "0 0 0.5" << endl;
        cout << fixed << setprecision(10);
        cout << 0.5*cos(alpha) << " " << 0.5 * sin(alpha) << " 0" << endl;
        cout << -0.5*sin(alpha) << " " << 0.5 * cos(alpha) << " 0" << endl;
    }
    return 0;
}