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
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10, M = 2 * N;

int n, m, cnt = 1;
int head[N];
int dp[N][N];

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

void dfs(int u, int fa = 0)
{

    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to, w = e[i].w, t = 0;
        if(v == fa) continue;
        dfs(v, u);
        

    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        addedge_undirected(e, u, v);
    }
    for(int i = 1; i <= n; ++i) cin >> dp[i][1];

    dfs(1);
    
    return 0;
}
