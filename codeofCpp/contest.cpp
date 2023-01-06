/*

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cctype>
#include <cmath>

using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}

int main()
{


    return 0;
}

*/

//A
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e5 + 10;
// int n, q;
// map<int, int> mp;
// typedef pair<int, int> pii;
// set<pii> st;
// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 0; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         if(x > y) swap(x, y);
//         if(!st.count(pii(x, y)))
//             st.insert(pii(x, y)), mp[x]++, mp[y]++;
//     }
//     cin >> q;
//     while(q--)
//     {
//         int x;
//         cin >> x;
//         if(mp.count(x)) cout << mp[x] << '\n';
//         else cout << "0\n";
//     }
//     return 0;
// }





//B
//线性dp！
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <string>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 150;
// int n, len, lent;
// string s0, s, nm;
// #define mk(str, i) make_pair(str, i)
// map<string, int> mp{mk("AA", 5),mk("AC", -1),mk("AG", -2),mk("AT", -1),mk("A-", -3),mk("CC", 5),mk("CG", -3),mk("CT", -2),mk("C-", -4),mk("GG", 5),mk("GT", -2),mk("G-", -2),mk("TT", 5),mk("T-", -1)};
// struct nd{
//     string name, dna;
//     int res;
// }q[N];
// int cal(string s, int len)
// {
//     for(int i = 0; i < len; i++)
//     {
//         for(int j = 0 ; j < len; j++)
//         {

//         }
//     }
// }
// int main()
// {
//     untie();
//     cin >> n;
//     cin >> len >> s0;
//     for(int i = 0; i < n ; i++)
//     {
//         cin >> nm >> lent >> s;
//         q[i] = nd{nm, s, cal(s, lent)};
//     }

//     return 0;
// }



// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e5 + 5;
// struct nd{
//     int id, h;  
// }ds[N];
// int n, m;
// int find_set(int x)
// {
//     return x == ds[x].id ? x : (ds[x].id = find_set(ds[x].id));
// }
// void merge_set(int x, int y, int hr)
// {
//     if((x = find_set(x)) != (y = find_set(y)))
//         ds[x].id = ds[y].id, ds[x].h = ds[y].h = max(ds[x].h, ds[y].h);
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     for(int i = 1; i <= n ; i++) ds[i] = nd{i, 0};
//     for(int i = 0; i < m; i++)
//     {
//         int x, y, hr;
//         cin >> x >> y >> hr;
//         merge_set(x, y, hr);
//     }
    
//     return 0;
// }






// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e5 + 10;
// int n, m, b1[N], b2[N], q[N];
// int main()
// {
//     untie();
//     cin >> n >> m;
//     int x;
//     for(int i = 0; i < n; i++) 
//     {
//         int x;
//         cin >> x;
//         q[i] = x;
//     }
//     while(m--)
//     {
//         int l, r, k, c;
//         cin >> l >> r >> k >> c;
        
//     }
//     return 0;
// }


///G
//ceil(n / i) == floor((n - 1) / i) + 1;
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cctype>
#include <cmath>

using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
typedef long long ll;
ll getO(double x)
{
    // cout << "TX: " << (ll)(x + 0.5) << endl;
    return (ll)(x + 0.5);
}
int main()
{
    // untie();
    ll n;
    while(!(cin >> n).eof())
    {
        ll L, R, ans = 0;
        for(L = 1; L <= n; L = R + 1)
        {
            R = n / (n / L);
            ans += (R - L + 1) * getO(1.0 * n / L);
        }
        //ceil
        cout << ans << '\n';
    }
    return 0;
}



//C
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// struct nd{
//     int t, sc;
// }arr[200];
// int dp[10005];
// int main()
// {
//     int t, m;
//     untie();
//     cin >> t >> m;
//     for(int i = 1; i <= m; i ++)
//     {
//         int a,b,c;
//         cin >> a>> b >> c;
//         arr[i] = nd{a - c, b};
//     }
//     for(int i = 1; i <= m; i ++)
//     {
//         for(int j = t; j >= arr[i].t; j--)
//         {
//             dp[j] = max(dp[j], dp[j - arr[i].t] + arr[i].sc);
//         }
//     }
//     cout << dp[t];
//     return 0;
// }


//D
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e6 + 10;
// int n, m, cnt = 0;
// bool st[N];
// set<int> sum;
// int main()
// {
//     untie();
//     cin >> n >> m;
//     while(m--)
//     {
//         int x, y;
//         cin >> x >> y;
//         if(!st[x] && !st[y])
//             cnt++;
//         if(!st[x] || !st[y])
//             sum.insert(x), sum.insert(y);
//         st[x] = st[y] = 1;    
//     }
//     cout << (cnt + (n - sum.size())) << '\n';
//     return 0;
// }



//E
//需要剪枝
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int n, m, k, sx, sy, ex, ey, ans = -1;
// bool mp[1024][1024];//0表示未走，1表示走过
// int b[1024][1024], dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
// void dfs(int x, int y, int tm)
// {
//     if(x == ex && y == ey)
//     {
//         if(ans == -1) ans = tm;
//         else ans = min(ans, tm);
//         return;
//     }
//     if(ans != -1 && ans == min(abs(ex - x) + 1, abs(ey - y) + 1)) 
//         return;
//     for(int i = 0; i < 4; i++)
//     {
//         int nx = x + dir[i][0];
//         int ny = y + dir[i][1];
//         if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !mp[nx][ny])
//         {
//             if(!b[nx][ny] || tm + 1 < b[nx][ny])
//             {
//                 mp[x][y] = 1;
//                 dfs(nx, ny, tm + 1);
//                 mp[x][y] = 0;
//             }
//         }
//     }
// }
// int main()
// {
//     untie();
//     cin >> n >> m >> k;
//     while(k--)
//     {
//         int t, x, y;
//         cin >> t >> x >> y;
//         mp[x][y] = 2;
//         if(!b[x][y]) b[x][y] = t;
//         else b[x][y] = min(b[x][y], t);
//     }
//     cin >> sx >> sy >> ex >> ey;
//     mp[sx][sy] = 1;
//     dfs(sx, sy, 0);
//     cout << ans;
//     return 0;
// }

/*
xx*.
....
...x
....
*/

//wa
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int n, m, k, sx, sy, ex, ey, ans = -1;
// typedef pair<int, int> p;
// typedef pair<int, p> pii;
// bool mp[1024][1024];//0表示未走，1表示走过
// int b[1024][1024], dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
// void bfs()
// {
//     queue<pii> q;
//     q.push(pii(0, p(sx, sy)));
//     mp[sx][sy] = 1;
//     while(q.size())
//     {
//         pii tp = q.front(); q.pop();
//         int x = tp.second.first, y = tp.second.second, time = tp.first;
//         if(x == ex && y == ey)
//         {
//             ans = time;
//             return;
//         }
//         for(int i = 0; i < 4; i++)
//         {
//             int nx = x + dir[i][0];
//             int ny = y + dir[i][1];
//             if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !mp[nx][ny])
//             {
//                 if(!b[nx][ny] || time + 1 < b[nx][ny])
//                 {
//                     mp[nx][ny] = 1;
//                     q.push(pii(time + 1, p(nx, ny)));
//                 }
//             }
//         }
//     }
// }
// int main()
// {
//     untie();
//     cin >> n >> m >> k;
//     while(k--)
//     {
//         int t, x, y;
//         cin >> t >> x >> y;
//         mp[x][y] = 2;
//         if(!b[x][y]) b[x][y] = t;
//         else b[x][y] = min(b[x][y], t);
//     }
//     cin >> sx >> sy >> ex >> ey;
//     bfs();    
//     cout << ans;
//     return 0;
// }






















//K
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     double sum = 0;
//     for(int i = 1; i <= n; i++)
//     {
//         sum += 1.0 * n / i;
//     }
//     printf("%.6lf\n", sum);
//     return 0;
// }








//L
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int flr[100005];
// set<int> vis;
// int main()
// {
//     untie();
//     int n;
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> flr[i];
//     int l = 1, r = 1, ans = 1;
//     while(l <= n)
//     {
//         while(r <= n && (vis.empty() || !vis.count(flr[r])))
//         {
//             vis.insert(flr[r++]);
//         }
//         ans = max(ans, r - l);
//         while(l <= n && flr[l] != flr[r])
//         {
//             vis.erase(flr[l++]);
//         }
//         if(l <= n && r <= n && flr[l] == flr[r])
//             vis.erase(flr[l++]);
//     }
//     cout << ans;
//     return 0;
// }





//J
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// const int N = 1e5 + 2;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
// int n, m, s;
// struct edge{
//     int from, to;
//     ll w;
// };
// struct nd{
//     int id;
//     ll ndis;
//     bool operator < (const nd &a)const{
//         return ndis > a.ndis;
//     }
// };
// vector<edge> e[N];
// ll dis[N];
// bool done[N];
// void dij()
// {
//     priority_queue<nd> que;
//     for(int i = 1; i <= n; i++) dis[i] = INF;
//     dis[s] = 0;
//     que.push(nd{s, dis[s]});
//     while(que.size())
//     {
//         nd u = que.top();
//         que.pop();
//         if(done[u.id]) continue;
//         done[u.id] = 1;
//         for(int i = 0; i < e[u.id].size(); i++)
//         {
//             edge y = e[u.id][i];
//             if(done[y.to]) continue;
//             if(dis[y.to] > y.w + u.ndis)
//             {
//                 dis[y.to] = y.w + u.ndis;
//                 que.push(nd{y.to, dis[y.to]});
//             }
//         }
//     }
// }
// int main()
// {
//     untie();
//     cin >> n >> m >> s;
//     while(m--)
//     {
//         int u, v;
//         ll w;
//         cin >> u >> v >> w;
//         e[u].push_back(edge{u, v, w});
//         e[v].push_back(edge{v, u, w});
//     }
//     dij();
//     for(int i = 1; i <= n; i++)
//         printf(" %lld" + !(i - 1), dis[i]);
//     return 0;
// }









//I
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// const int N = 1e5 + 2;
// int n, m;
// ll p;
// ll a[N], b[N], s[N];
// ll qp(ll a, ll n)
// {
//     ll ans = 1;
//     a %= p;
//     while(n)
//     {
//         if(n & 1) ans = (ans * a) % p;
//         a = (a * a) % p;
//         n >>= 1;
//     }
//     return ans;
// }
// int main()
// {
//     untie();    
//     cin >> n >> m >> p;
//     for(int i = 1; i < n; i ++)
//     {
//         cin >> a[i];
//         b[i] = a[i] - a[i - 1];
//     }
//     int op;
//     while(m--)
//     {
//         cin >> op;
//         if(op == 1)
//         {
//             ll l, r, x, k;
//             cin >> l >> r >> x >> k;
//             ll cal = qp(x, k);
//             b[l] += cal;
//             b[r + 1] -= cal;
//         }
//         else if(op == 2) 
//         {
//             ll x, k;
//             cin >> x >> k;
//             b[x] += k;
//             b[x + 1] -= k;
//         }
//         else if(op == 3)
//         {
//             int l, r;
//             ll sum = 0, res = 0;
//             cin >>l >> r;
//             res = a[1];
//             for(int i = 1; i <= r; i++)
//             {
//                 sum += b[i];
//                 if(i >= l)
//                 {
//                     res = max(res, a[i] + sum);

//                 }
//             }
//         }
//         else if(op == 4)
//         {

//         }
//     }
//     return 0;
// }




















