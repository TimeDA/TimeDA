//
// google codejam 2018 - qualification - Go, Gopher
// John Smith
//

#include <bits/stdc++.h>

using namespace std;

const uint32_t dd=10;

struct Target {
     uint32_t x;
     uint32_t y;
     uint32_t score;
     list<Target*>::iterator ptr;

     Target( uint32_t x, uint32_t y ) : x(x), y(y), score(9) {}
};

struct Grid {

     uint32_t score;
     uint32_t k;
     vector<list<Target*>> q;

     vector<vector<uint32_t>> g;
     vector<vector<Target*>> t;

     void prepare( uint32_t A );

     Target* choose_target();
     void update( Target t );
};

void Grid::prepare( uint32_t A )
{
     q.resize(0);
     q.resize(10);

     k=1;
     while (k*k < A) k++;
     score = k*k;

     g.resize(k);
     for (auto &r : g) {
          r.resize(k);
          for (auto &s : r) s = 1;
     }

     t.resize(k);
     for (auto &r : t) {
          r.resize(k);
          for (auto &s : r) s = 0;
     }

     for (uint32_t x=1; x<k-1; x++)
     {
          for (uint32_t y=1; y<k-1; y++)
          {
               Target* tgt = new Target(x,y);
               t.at(x).at(y) = tgt;
               q.at(9).push_front(tgt);
               tgt->ptr = q.at(9).begin();
          }
     }
}

Target* Grid::choose_target(void)
{
     for (uint32_t i=9; i<=9; i--)
     {
          if (!q.at(i).empty())
          {
               return *q.at(i).begin();
          }
     }
     return 0;
}

void Grid::update( Target tgt )
{
     if (g.at(tgt.x).at(tgt.y) == 0) return;
     g.at(tgt.x).at(tgt.y) = 0;

     score--;

     uint32_t xlo = tgt.x<=1   ? 1 : tgt.x-1;
     uint32_t xhi = tgt.x>=k-2 ? k-2 : tgt.x+1;

     uint32_t ylo = tgt.y<=1   ? 1 : tgt.y-1;
     uint32_t yhi = tgt.y>=k-2 ? k-2 : tgt.y+1;

     for (auto xx=xlo; xx<=xhi; xx++)
     {
          for (auto yy=ylo; yy<=yhi; yy++)
          {
               Target *tgt = t.at(xx).at(yy);
               q.at(tgt->score).erase(tgt->ptr);
               tgt->score--;
               q.at(tgt->score).push_front(tgt);
               tgt->ptr = q.at(tgt->score).begin();
          }
     }
}

int main(int argc, char ** argv)
{
     ios_base::sync_with_stdio(false);

     uint32_t T;
     cin >> T;
     for (uint32_t j=1; j<=T; j++)
     {
          uint32_t A;
          cin >> A;

          Grid g;
          g.prepare(A);

          uint32_t iter=0;
          while (1) {
               iter++;
               Target *t = g.choose_target();
               if (0) {
                    cout << iter << " ";
                    cout << g.score << " ";
               }
               cout << dd+t->x << " " << dd+t->y << endl;

               int32_t u, v;
               if (1) {
                    cin >> u >> v;
               } else {
                    if (g.score == 0)
                    {
                         u = 0;
                         v = 0;
                    } else {
                         u = dd + t->x - 1 + rand()%3;
                         v = dd + t->y - 1 + rand()%3;
                    }
               }

               if (u==-1 && v==-1)
               {
                    cerr << "Error - exit" << endl;
                    exit(1);
               }
               if (u==0 && v==0)
               {
                    break;
               }
               u -= dd;
               v -= dd;
               g.update(Target(u,v));
          }
     }

     return 0;
}
