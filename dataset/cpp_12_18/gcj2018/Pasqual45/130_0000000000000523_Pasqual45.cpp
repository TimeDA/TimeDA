#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for (int i=0; i<t; ++i)
    {
        int a,b,n;
        string s;
        cin >> a >> b >> n;
        while (s != "CORRECT" && n-- > 0)   
        {
            cout << ++a;
        }
    }
}