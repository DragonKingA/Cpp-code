#include <bits/stdc++.h>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long
#define all(v) v.begin(), v.end()
const int N = 200 + 10;

string s[N];
bool vis[N][N][4]; // 四个方向的点状态
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, cnt = 0; 

void dfs(int x, int y, int d)
{
    if(vis[x][y][0] + vis[x][y][1] + vis[x][y][2] + vis[x][y][3] == 0) ++cnt;
    vis[x][y][d] = 1;
    int tx = x + dir[d][0], ty = y + dir[d][1];
    if(s[tx][ty] == '.')
    {
        dfs(tx, ty, d);
    }
    else
    {
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(s[nx][ny] == '.' && !vis[nx][ny][i])
            {
                dfs(nx, ny, i);
            }
        }
    }
    
}

void Solve()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> s[i];
    for(int i = 0; i < 4; ++i) dfs(1, 1, i);
    cout << cnt << "\n";
}

int main()
{
    // untie();
    int T = 1;
    // cin >> T;
    while(T--)
    {
        Solve();
    }
    return 0;
}
