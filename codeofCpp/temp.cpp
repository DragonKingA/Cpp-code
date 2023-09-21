#include <bits/stdc++.h>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long
#define all(v) v.begin(), v.end()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a) * (b) /__gcd(a, b)
const int N = 2e5 + 10, inf = 0x7fffffff;
vector<int> G[N];
int ds[N];

int find_set(int x)
{
    return x == ds[x] ? x : (ds[x] = find_set(ds[x]));
}

void Solve()
{
    
    int n, a, b;
    set<int> st;
    cin >> n >> a >> b;
    for(int i = 0; i <= n; ++i) ds[i] = i;
    for(int i = 0; i <= n; ++i) G[i].clear();
    for(int i = 0; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        int fu = find_set(u), fv = find_set(v);
        if(fu == fv) st.insert(fu);
        else ds[fu] = fv;
    }
    vector<bool> vis(n + 5, 0);
    for(int i = 1; i <= 7; ++i)
    {
        int fi = find_set(i);
        if(st.find(fi) != st.end()) vis[i] = 1;
    }
    for(int i = 1; i <= 7; ++i)
    cout << i << (vis[i] ? " True" : " False") << "\n";
    if(a == b) return cout << "NO\n", void();
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