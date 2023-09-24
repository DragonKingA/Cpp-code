#include <bits/stdc++.h>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long
#define all(v) v.begin(), v.end()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a) * (b) /__gcd(a, b)
const int N = 2e5 + 10, inf = 0x7fffffff;
vector<ll> save;

void dfs(ll x)
{
    if(x > 9 && x / 10 % 10 <= x % 10) return;
    save.push_back(x);
    dfs(x + 1);
    dfs(x * 10);
}

void Solve()
{  
    dfs(1);
    sort(all(save));
    save.erase(unique(all(save)));
    int k; cin >> k;
    cout << save[k - 1] << "\n";
}

int main()
{
    untie();
    int T = 1;
    // cin >> T;
    while(T--)
    {
        Solve();
    }
    return 0;
}