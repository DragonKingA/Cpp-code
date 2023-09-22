#include <bits/stdc++.h>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long
#define all(v) v.begin(), v.end()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a) * (b) /__gcd(a, b)
const int N = 2e5 + 10, inf = 0x7fffffff;

vector<int> G[N];
int n, a, b, root;
int dep[N], dis[N];

void dfs(int u, int fa = -1)
{
    for(int v : G[u])
    {
        if(dep[v] == -1) dep[v] = dep[u] + 1, dfs(v, u);
        else if(dep[v] < dep[u] && fa != v) root = v;
    }
}

bool Dijkstra()
{
    dis[root] = 0;
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int v : G[u])
            if(dis[v] == -1)
                dis[v] = dis[u] + 1, q.push(v);
    }
    return dis[a] > dis[b];
}

void Solve()
{
    root = -1;
    set<int> st;
    cin >> n >> a >> b;
    for(int i = 0; i <= n; ++i) dis[i] = dep[i] = -1;
    for(int i = 1; i <= n; ++i) G[i].clear();
    for(int i = 1; i <= n; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(a == b) return cout << "NO\n", void();
    dep[b] = 0;
    dfs(b, -1);
    cout << (Dijkstra() ? "YES\n" : "NO\n");
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