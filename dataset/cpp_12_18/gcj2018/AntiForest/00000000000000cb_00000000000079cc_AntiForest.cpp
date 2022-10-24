#include <bits/stdc++.h>

#define INF 1000000010
#define INFLL ((1LL<<62)-5)
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define OF(i,a,b) for (int (i) = (a)-1; (i) >= (b); --(i))
#define SZ(v) int(v.size())

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/

// #define DEBUG 1
#ifdef DEBUG
# define DEBUG_FPRINT(file, fmt, args...) fprintf(file, fmt, ##args)
#else
# define DEBUG_FPRINT(file, fmt, args...) do{} while(0)
#endif

const double EPS = 1e-9;
const double PI = acos(-1);

double getang(double y, double x) {
    return atan2(y, x);
}

struct PT3D {
    double x, y, z;
    PT3D() {}
    PT3D(double x, double y, double z) : x(x), y(y), z(z) {}
    PT3D(const PT3D &p) : x(p.x), y(p.y), z(p.z) {}
    PT3D operator + (const PT3D &p) const {
        return PT3D(x+p.x, y+p.y, z+p.z);
    }
    PT3D operator * (double c) const {
        return PT3D(x*c, y*c, z*c);
    }
    void rotateXY(double ang) {
        double newx = x*cos(ang) - y*sin(ang);
        double newy = x*sin(ang) + y*cos(ang);
        x = newx;
        y = newy;
    }
    void rotateYZ(double ang) {
        double newy = y*cos(ang) - z*sin(ang);
        double newz = y*sin(ang) + z*cos(ang);
        y = newy;
        z = newz;
    }
};

struct cube {
    vector<PT3D> corners;
    vector<PT3D> facecenters;
    cube() {
        facecenters.emplace_back(0.5,0,0);
        facecenters.emplace_back(0,0.5,0);
        facecenters.emplace_back(0,0,0.5);
        for (auto a : {-1,1}) {
            for (auto b : {-1,1}) {
                for (auto c : {-1,1}) {
                    corners.push_back(facecenters[0]*a+facecenters[1]*b+facecenters[2]*c);
                }
            }
        }
    }
    void rotateXY(double ang) {
        for (auto &c : corners) c.rotateXY(ang);
        for (auto &c : facecenters) c.rotateXY(ang);
    }
    void rotateYZ(double ang) {
        for (auto &c : corners) c.rotateYZ(ang);
        for (auto &c : facecenters) c.rotateYZ(ang);
    }
};


struct PT2D {
    double x, y;
    PT2D() {}
    PT2D(double x, double y) : x(x), y(y) {}
    PT2D operator-(const PT2D &p) const {
        return PT2D(x-p.x, y-p.y);
    }
};
double cross(PT2D p, PT2D q) { return p.x*q.y-p.y*q.x; }
bool cmp(PT2D a, PT2D b) { return a.x < b.x || a.x == b.x && a.y < b.y; }
bool cw(PT2D a, PT2D b, PT2D c) {
    return cross(c-a, b-a) > 0;
}
bool ccw(PT2D a, PT2D b, PT2D c) {
    return cross(c-a, b-a) < 0;
}

void convex_hull(vector<PT2D> &a) {
    if (a.size() == 1) return;
    sort(a.begin(), a.end(), &cmp);
    PT2D p1 = a[0], p2 = a.back();
    vector<PT2D> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (size_t i = 1; i < a.size(); i++) {
        if (i == a.size()-1 || cw(p1, a[i], p2)) {
            while (up.size()>=2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size()-1 || ccw(p1, a[i], p2)) {
            while (down.size()>=2 && !ccw(down[down.size()-2], down[down.size()-1], a[i])) 
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for (size_t i = 0; i < up.size(); i++)
        a.push_back(up[i]);
    for (size_t i = down.size()-2; i > 0; i--)
        a.push_back(down[i]);
}

double ComputeSignedArea(const vector<PT2D> &p) {
    double area = 0;
    for (int i = 0; i < p.size(); i++) {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area/2.0;
}
double ComputeArea(const vector<PT2D> &p) {
    return fabs(ComputeSignedArea(p));
}

struct soln {
    cube C;
    double A;

    bool testworks() {
        vector<PT2D> pts;
        for (auto pt : C.corners) {
            pts.emplace_back(pt.x, pt.z);
        }
        convex_hull(pts);
        DEBUG_FPRINT (stderr, "area: %lf\n", ComputeArea(pts));
        return fabs(ComputeArea(pts)-A) < 1e-6;
    }
    void solve() {
        scanf ("%lf", &A);
        double vx, vy, vz;
        double lo = 0;
        double hi = 1/sqrt(3);
        double bSoFar = -1;
        FO (it,0,200) {
            double mid = (lo+hi)/2;
            double mxA = sqrt(2)*sqrt(1-mid*mid)+mid;
            if (mxA < A-EPS) {
                lo = mid;
            } else {
                hi = mid;
                bSoFar = mid;
            }
        }
        vx = bSoFar;

        lo = 0;
        hi = sqrt((1-vx*vx)/2);
        FO (it,0,200) {
            double curvy = (lo+hi)/2;
            double normSoFar = vx*vx+curvy*curvy;
            double curvz = sqrt(1-normSoFar);
            if (vx+curvy+curvz < A+EPS) {
                bSoFar = curvy;
                lo = curvy;
            } else {
                hi = curvy;
            }
        }
        vy = bSoFar;
        vz = sqrt(1-vx*vx-vy*vy);
        PT3D viewPoint(vx,vy,vz);
        DEBUG_FPRINT (stderr, "(vx,vy,vz): %lf %lf %lf\n",
                         viewPoint.x, viewPoint.y, viewPoint.z);

        double xyAng = getang(viewPoint.y, viewPoint.x);
        double xyRotateAng = PI/2-xyAng;
        viewPoint.rotateXY(xyRotateAng);
        C.rotateXY(xyRotateAng);
        DEBUG_FPRINT (stderr, "(vx,vy,vz): %lf %lf %lf\n",
                         viewPoint.x, viewPoint.y, viewPoint.z);

        double yzAng = getang(viewPoint.z, viewPoint.y);
        double yzRotateAng = -yzAng;
        viewPoint.rotateYZ(yzRotateAng);
        C.rotateYZ(yzRotateAng);
        DEBUG_FPRINT (stderr, "(vx,vy,vz): %lf %lf %lf\n",
                         viewPoint.x, viewPoint.y, viewPoint.z);

        DEBUG_FPRINT (stderr, "xyAng: %lf xyRotateAng: %lf "
                         "yzAng: %lf yzRotateAng: %lf\n",
                          xyAng, xyRotateAng, yzAng, yzRotateAng);

        assert(testworks());
        for (auto c : C.facecenters) {
            printf ("%.9lf %.9lf %.9lf\n", c.x, c.y, c.z);
        }
    }
};


int T;
int main() {
    scanf ("%d", &T);
    FO (_z,0,T) {
        printf ("Case #%d:\n", _z+1);
        soln s;
        s.solve();
    }
    return 0;
}
