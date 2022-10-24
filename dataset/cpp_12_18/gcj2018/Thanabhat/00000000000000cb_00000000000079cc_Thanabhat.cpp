#include<iostream>
#include<cmath>

#define eps 1e-12
#define MY_PI 3.14159265358979323846L

using namespace std;

long double cal1(long double angle) {
    return cos(angle) + sin(angle);
}

long double cal2(long double angle) {
    return sqrt(2)*cos(angle) + sin(angle);
}

int solve(int cc) {
    long double area;
    cin>>area;
    cout<<"Case #"<<cc<<": "<<endl;
/*
    if (area < sqrt(2.0) + eps){
        double angle = acos(area/sqrt(2.0));
        cout << angle << endl;
        angle = 45.0 / 180.0 * MY_PI - angle;
        cout << angle << endl;
        cout << 0.5 * cos(angle) << " " << 0.5 * sin(angle) << " " << "0" <<endl;
        cout << -0.5 * sin(angle) << " " << 0.5 * cos(angle) << " " << "0" <<endl;
        cout << "0" << " " << "0" << " " << "0.5" <<endl;
    }
*/

    if (area < sqrt(2.0) + eps){
        long double h = 45.0L / 180.0L * MY_PI, l = 0L, m;
        while(h>l){
            m = (h+l)/2.0L;
            long double calArea = cal1(m);
            if(calArea>area-eps&&calArea<area+eps){
                cout << 0.5L * cos(m) << " " << 0.5L * sin(m) << " " << "0" <<endl;
                cout << -0.5L * sin(m) << " " << 0.5L * cos(m) << " " << "0" <<endl;
                cout << "0" << " " << "0" << " " << "0.5" <<endl;
                return 0;
            }
            if(calArea<area){
                l=m;
            }else{
                h=m;
            }
        }
    } else {
        long double h = 0.61547931L, l = 0L, m;
        while(h>l){
            m = (h+l)/2.0L;
            long double calArea = cal2(m);
            //cout<<l<<" "<<m<<" "<<h<<endl;
            if(calArea>area-eps&&calArea<area+eps){
                cout << 0.5L/sqrt(2.0L) << " " << 0.5L/sqrt(2.0L)*cos(m) << " " << 0.5L/sqrt(2.0L)*sin(m) <<endl;
                cout << -0.5L/sqrt(2.0L) << " " << 0.5L/sqrt(2.0L)*cos(m) << " " << 0.5L/sqrt(2.0L)*sin(m) <<endl;
                cout << 0.0 << " " << -0.5L*sin(m) << " " << 0.5L*cos(m) <<endl;
                return 0;
            }
            if(calArea<area){
                l=m;
            }else{
                h=m;
            }
        }
    }
    return 0;
}

int main() {
    //std::ios::sync_with_stdio(false);

    cout.precision(9);
    //cout<<sqrt(2)*cos(0.61547931)+sin(0.61547931)<<endl;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve(i+1);
    }
    return 0;
}
