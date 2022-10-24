#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

/** Interface */

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );
//{{{
/** Read */

static const int buf_size = 4096;

inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len)
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    if (pos == len)
        return -1;
    return buf[pos++];
}

inline int readChar() {
    int c = getChar();
    while (c <= 32)
        c = getChar();
    return c;
}

template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;

    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}

struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
//}}}

vector<int> trouble_sort(vector<int> v)
{
    bool f = false;
    while (!f)
    {
        f = true;
        for (int i = 0; i < v.size() - 2; ++i)
        {
            if (v[i] > v[i + 2])
            {
                f = false;
                swap(v[i], v[i + 2]);
            }
        }
    }
    return v;
}

void solve()
{
    int n;
    n = readInt();
    //cin >> n;
    vector<int> v1, v2;
    v1.reserve(n);
    v2.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int a;
        a = readInt();
        //cin >> a;
        if (i % 2 == 0) v1.push_back(a);
        else v2.push_back(a);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    vector<int> v;
    v.reserve(n);
    for (int i = 0, i1 = 0, i2 = 0; i < n; ++i)
    {
        if (i % 2 == 0) v.push_back(v1[i1++]);
        else v.push_back(v2[i2++]);
        if (i > 0 && v[i] < v[i - 1])
        {
            cout << i - 1;
            return;
        }
    }
    cout << "OK";
}

int main() {
    int t;
    t = readInt();
    //cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}