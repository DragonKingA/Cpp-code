#include <bits/stdc++.h>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long
#define all(v) v.begin(), v.end()
#define gcd(a, b) __gcd(a, b)
const int N = 1e4;


void Solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    ll ct = n / lcm(x, y);
    ll s = n * (n + 1) / 2 - (n - n / x + ct) * (n - n / x + 1 + ct) / 2 - (n / y - ct) * (n / y + 1 - ct) / 2;
    cout << s << "\n";
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