#include <bits/stdc++.h>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long
#define all(v) v.begin(), v.end()
const int N = 2e5 + 10;


void Solve()
{
    string s, t; cin >> s;
    t = s;
    int n = s.size();
    for(int i = n - 1; i >= 0; --i)
    {
        bool ok = 0;
        if(s[i] - '0' >= 5)
        {
            if(i == 0) s[i] = '0', s = "1" + s;
            else s[i - 1]++;
            ok = 1;
        } 
        if(i != 0) s[i] = '0';
        if(ok) t = s;
    }
    cout << t << "\n";
}

int main()
{
    untie();
    int T = 1;
    cin >> T;
    while(T--)
    {
        Solve();
    }
    return 0;
}