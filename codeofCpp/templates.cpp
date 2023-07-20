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

// �������� + ������ + ���鼯
// ����ͼû�й涨�ǿ��������ܺ��л��Ͷ����ͨ�飬��Ҫ���鼯ͳ��ȫ����ͨ�鲢���dfs��⡣��ÿ����ͨ���ڿ��ܺ��л�����Ҫ���жϻ�����������
// ���ҳ�������м�ĳ�߶Ͽ����ֱ��Զϱߵ������˵�Ϊ����һ������dp��������������ȡ������ۼӵ����С�
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
    vis[u] = 1; // ���������ͨ��
    dp[u][1] = a[u];
    dp[u][0] = 0;
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(v == root) // �ɻ�ʱ��ֹ�ظ�����
        {
            dp[root][1] = -inf; // ��Ϊ�Ƕϱ߲�������ȥ u -> root �����ߣ�����dfs�����и��ڵ� u ����ѡ�� root����˰�ѡ�� root �ļ�ֵ��Ϊ����С
            continue;
        }
        dfs(v, root);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

void work(int u)
{
    while(!vis[ds[u]]) // ����Ѱ����ͨ��ĸ� u
    {
        vis[u] = 1;
        u = ds[u]; 
    }
    dfs(u, u);
    ll tp = max(dp[u][0], dp[u][1]);
    u = ds[u]; // ����ǻ����ض���β��ӣ�������β�����
    dfs(u, u);
    ans += max(tp, max(dp[u][0], dp[u][1])); // ȡ���� dfs �𰸵�������ۼ�
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
        ds[v] = u; // ע������ֵ�Ǹ��ڵ㣬��������Ҹ�
    }
    for(int i = 1; i <= n; ++i)
        if(!vis[i]) work(i);
    cout << ans << "\n";
    return 0;
}
