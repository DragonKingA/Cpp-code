// ¼òµ¥Í¼ÂÛ + dfs
#include <bits/stdc++.h>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long
#define all(v) v.begin(), v.end()
const int N = 3e5 + 10;
vector<int> G[N];
ll lim[N], ans = 0;

void dfs(int u, ll d = -2e9)
{
    d = max(d, lim[u]);
    if(d >= 0) ++ans;
    for(int v : G[u]) dfs(v, d - 1);
}

void Solve()
{
    int n, m; cin >> n >> m;
    for(int i = 2; i <= n; ++i)
    {
        int j; cin >> j;
        G[j].push_back(i);
    }
    memset(lim, -0x3f, sizeof(lim));
    while(m--)
    {
        ll x, y; cin >> x >> y;
        lim[x] = max(lim[x], y);        
    }
    dfs(1);
    cout << ans << "\n";
}

int main()
{
    untie();
    int T = 1;
    // int T = 1;
    while(T--)
    {
        Solve();
    }
    return 0;
}