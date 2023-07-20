/*

#include <bits/stdc++.h>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long
#define all(v) v.begin(), v.end()
const int N = 1e6 + 10;


void Solve()
{
    


}

int main()
{
    // untie();
    int T = 100;
    // int T = 1;
    // cin >> T;
    while(T--)
    {
        Solve();
    }
    return 0;
}

*/

// 最大独立集 + 基环树 + 并查集
// 所给图没有规定是棵树，可能含有环和多个连通块，需要并查集统计全部连通块并逐个dfs求解。而每个连通块内可能含有环，需要进行断环操作：即把
// 环找出来后从中间某边断开，分别以断边的两个端点为根做一次树形dp（最大独立集），取最大者累加到答案中。
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x7fffffff
const int N = 1e6 + 10, M = 2 * N;

int n, m, k, cnt = 1;
int head[N], ds[N], a[N];
bool vis[N];
ll dp[N][2], ans = 0;

template <class T = int>
class Edge
{
    public:
        int to, next;
        T w;
        Edge(){}
        Edge(int a, int b, T c) : to(a), next(b), w(c){}
        friend void addedge_undirected(Edge e[], int u, int v, T c = 0){ addedge(e, u, v, c), addedge(e, v, u, c);}
        friend void addedge(Edge e[], int u, int v, T c = 0)
        {
            e[cnt] = Edge(v, head[u], c);
            head[u] = cnt++;
        }
};

Edge<int> e[M];

void dfs(int u, int root)
{
    vis[u] = 1; // 标记整个连通块
    dp[u][1] = a[u];
    dp[u][0] = 0;
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(v == root) // 成环时防止重复遍历
        {
            dp[root][1] = -inf; // 因为是断边操作（减去 u -> root 这条边），则dfs过程中父节点 u 不能选择 root，因此把选择 root 的价值设为无穷小
            continue;
        }
        dfs(v, root);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

void work(int u)
{
    while(!vis[ds[u]]) // 向上寻找连通块的根 u
    {
        vis[u] = 1;
        u = ds[u]; 
    }
    dfs(u, u);
    ll tp = max(dp[u][0], dp[u][1]);
    u = ds[u]; // 如果是环，必定首尾相接，这里获得尾部编号
    dfs(u, u);
    ans += max(tp, max(dp[u][0], dp[u][1])); // 取两次 dfs 答案的最大者累计
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) ds[i] = i;
    for(int v = 1; v <= n; ++v)
    {
        int u;
        cin >> a[v] >> u;
        addedge(e, u, v);
        ds[v] = u; // 注意这里值是父节点，方便后续找根
    }
    for(int i = 1; i <= n; ++i)
        if(!vis[i]) work(i);
    cout << ans << "\n";
    return 0;
}
