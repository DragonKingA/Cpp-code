/*
//模板
//并查集：
#include <cstdio>
#include <iostream>
using namespace std;
const int N = ;
int ds[N];
void init_set(int n){ for(int i = 1; i <= n; ds[i] = i, i++);}
int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
void merge_set(int x, int y){ if((x = find_set(x)) != (y = find_set(y))) ds[x] = ds[y];}



//二维前缀和
//存储公式：sum[i][j] =  sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j]
// 读取公式：res = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]
#include <iostream>
using namespace std;
const int N = ;
int arr[N][N];
int sum[N][N];
int main()
{       
    int x1,x2,y1,y2;//待求的范围
    //初始化数列
    for(int i=1;i<=N-1;i++) 
        for(int j=1;j<=N-1;j++)
            arr[i][j]=i+j;
    //前缀和操作(实际上可以边读取arr数列数，边进行求和操作)
    for(int i=1;i<=N-1;i++) 
        for(int j=1;j<=N-1;j++)
            sum[i][j] +=  sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];//sum[0][0]=0
    while(cin>>x1>>y1>>x2>>y2)
    {
        int res = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]; 
        //sum[2][2] = sum[1][2] + sum[2][1] - sum[1][1] + arr[2][2] 
        cout<< res <<endl;
    }
    return 0;
}



//二维差分
#include<iostream>
#include<cstdio>
using namespace std;
const int N = ;
int a[N][N], b[N][N];
void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            insert(i, j, i, j, a[i][j]);      //构建差分数组
    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);          //差分操作
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];  //转为二维前缀和
    return 0;
}



//快速幂
//base 底数；index 指数
//线性整数快速幂：
typedef long long ntype;
ntype mod = ;
ntype quick_pow(ll base, ntype index)
{
    ntype ans = 1;
    for(; index; index >>= 1)
    {
        if(index & 1) ans = ans * base % mod;
        base = base * base % mod;
    }
    return ans;
}
//矩阵快速幂：
#include <cstdio>
typedef long long ntype;
const ntype mod = , N = ;//这里 N 指最大矩形边长，n 指实际矩形边长
ntype n, k;
struct matrix{
    ntype mat[N][N];
    matrix operator *(matrix &t){
        matrix ret;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                ntype sum = 0;
                for(int k = 0; k < n; k++) 
                    sum += mat[i][k] * t.mat[k][j] % mod;
                ret.mat[i][j] = sum % mod;
            }
        return ret;
    }
}orimat;
matrix mat_quick_pow(matrix base, ntype index)
{
    matrix ans = orimat;
    for(; index; index >>= 1)
    {
        if(index & 1) ans = ans * base;
        base = base * base;
    }
    return ans;
}
void init(){ for(int i = 0; i < N; i++) orimat.mat[i][i] = 1;}




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
/*


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}

int main()
{



    

    return 0;
}


*/

// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int n;
// int dir[2][2] = {{1, 1}, {-1, 0}};
// int main()
// {
//     untie();
//     cin >> n;
//     while(n--) 
//     {
//         int a, b, c, d;
//         cin >> a >> b >> c >> d;
//         a = a + d - b;
//         int res = d - b + (a -  c);
//         if(a < c || d < b) cout << "-1\n";
//         else cout << res << '\n';
//     }
//     return 0;
// }

//B 
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <vector>
// #include <queue>
// #include <functional>
// #include <map>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e5 + 10;
// int t, n;
// int arr[N], b[N];
// map<int, int> mp;
// int main()
// {
//     untie();
//     cin >> t;
//     while(t--)
//     {
//         mp.clear();
//         cin >> n;
//         int num = 0;
//         for(int i = 1; i <= n; i++) cin >> arr[i];
//         sort(arr + 1, arr + 1 + n);
//         for(int i = 1; i <= n; i++) ++mp[arr[i]];
//         int ind = mp[0] + 1;
//         num = n - mp[0];
//         if(arr[1] > 0 || num + 1 >= mp[0]) cout << "0\n";
//         else if(arr[n] > 1) 
//         {
//             cout << "1\n";
//         }
//         else{
//             cout << arr[n] + 1 << '\n';
//         }
//     }
//     return 0;
// }


//0 0 0 0 1 1 



















































//ABC 293

// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <map>
// #include <set>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e5+ 10;
// int h, w;
// int a[20][20];
// int ans = 0;
// int dir[2][2] = {{1, 0}, {0, 1}};
// map<int, bool> vis;
// void dfs(int x, int y)
// {
//     // if(vis[a[x][y]]) return;
//     if(x == h && y == w) 
//     {
//         ans++;
//         return;
//     }
//     for(int i = 0; i < 2; i++)
//     {
//         int nx = x + dir[i][0], ny = y + dir[i][1];
//         if(nx >= 1 && nx <= h && ny >= 1 && ny <= w && !vis[a[nx][ny]])
//         {
//             // if(nx == h && ny == w)
//             // {
//             //     ans++;
//             //     return;
//             // }
//             vis[a[nx][ny]] = 1;
//             dfs(nx, ny);
//             vis[a[nx][ny]] = 0;
//         }
//     }
// }
// int main()
// {
    
//     scanf("%d%d", &h, &w);
//     for(int i = 1; i <= h; i++)
//         for(int j = 1; j <= w; j++)
//             scanf("%d", &a[i][j]);
//     vis[a[1][1]] = 1;
//     dfs(1, 1);
//     printf("%d", ans);
//     return 0;
// }





/*
blue - 5 - red

blue - 3 - red
*/
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e5 + 5;
// int n, m;
// #define pic pair<int, char>
// pic arr[N];
// map<pic, pic> mp;
// set<pic> ans;
// set<int> cnt;
// set<pic> line;
// int vis[N];
// int test = 0;
// pic find_set(pic x)
// {
//     return x == mp[x] ? x : (mp[x] = find_set(mp[x])); 
// }
// int main()
// {
//     int num = 0;
//     scanf("%d%d", &n, &m);
//     for(int i = 1; i <= n; i++)
//     {
//         pic n1 = pic(i, 'B'), n2 = pic(i, 'R');
//         mp[n2] = n1;
//     }
//     while(m--)
//     {
        // char c1[5], c2[5];
        // int x, y; char xc, yc;
        // scanf("%d %s %d %s", &x, &c1, &y, &c2);
//         xc = c1[0], yc = c2[0];
//         pic m1 = pic(x, xc), m2 = pic(y, yc);
//         cnt.insert(x);
//         cnt.insert(y);
//         // if(x > y) swap(x, y);
//         // if(vis[x] != y && vis[y] != x)
//         // {
//         //     num++;
            
//         // }
//         // line.insert(pic(x, y));

//         mp[m2] = m1;
//         // mp[m2] = m1;
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         pic n1 = pic(i, 'B'), n2 = pic(i, 'R');
//         pic p1 = find_set(n1), p2 = find_set(n2);
//         if(p1 == p2)
//         {
//             ans.insert(p1);
//         }
//         else
//             test++;
//     }
//     int d = n - cnt.size();
//     printf("%d\n", line.size() + d);
//     printf("%d %d\n", ans.size(), num + d);
//     return 0;
// }

// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e2 + 5;//2e5
// int n, m;
// #define pic pair<int, char>
// int ds[N];
// int cnt[N];

// map<pic, bool> vis;
// bool par[N];
// int find_set(int x)
// {
//     return x == ds[x] ? x : (ds[x] = find_set(ds[x]));
// }

// int main()
// {
//     int circle = 0, num = 0;
//     scanf("%d%d", &n, &m);
//     for(int i = 1; i <= n; i++) ds[i] = i, cnt[i] = 0;
//     while(m--)
//     {
//         char c1[5], c2[5];
//         int x, y; char xc, yc;
//         scanf("%d %s %d %s", &x, &c1, &y, &c2);
//         xc = c1[0], yc = c2[0];
//         ds[y] = x;
//         vis[pic(x, xc)] = vis[pic(y, yc)] = 1;
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         if(find_set(x) == find_set(y)) circle++;

//     }
//     printf("%d %d\n", circle, num - circle);
//     return 0;
// }

// B - x - R








// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ntype;
// #define ll long long
// ntype mod;
// ntype quick_pow(ll base, ntype index)
// {
//     ntype ans = 1;
//     for(; index; index >>= 1)
//     {
//         if(index & 1) ans = ans * base % mod;
//         base = base * base % mod;
//     }
//     return ans;
// }
// int main()
// {
//     ll a, x, res = 0;
//     scanf("%lld%lld%lld", &a, &x, &mod);
//     res = a * (quick_pow(a, x - 1) - 1) / (a - 1) % mod;
//     printf("%lld", res);
//     return 0;
// }











//2018年东北农业大学春季校赛（重现赛）

//F、M 签到

//B
//1
//n+1
//2*n + 1
//3*n + 1
//(n-1) * n + 1
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int n;
// const int N = 1e4 + 2;
// #define ll long long
// ll ans[N];
// void test()
// {
//     int c = 1;
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= n; j++)
//         {
//             printf("%4d ", c++);
//         }
//         puts("");
//     }
// }
// int main()
// {
//     int T;

//     scanf("%d", &T);
//     while(T--)
//     {
//         scanf("%d", &n);
//         // test();
//         ll sum = 0;
//         ans[1] = n / 2 + 1;
//         int num = 3;
//         for(int i = 2; i <= n / 2 + 1; i++)
//         {
//             ll st = 1LL * (i - 1) * n + 1 + (n / 2 - i + 1);
//             ans[i] = ans[i - 1] + 1LL * (num - 2) * n + st + (st + num - 1);
//             num += 2;
//         }
//         num = 3;
//         ans[n] = 1LL * (n - 1) * n + 1 + n / 2;
//         for(int i = n - 1; i > n / 2 + 1; i--)
//         {
//             ll st = 1LL * (i - 1) * n + 1 + (i - n / 2 - 1);
//             ans[i] = ans[i + 1] - 1LL * (num - 2) * n + st + (st + num - 1);
//             num += 2;
//         }
//         for(int i = 1; i <= n ;i++)
//             sum += ans[i];
//         printf("%lld\n", sum);
//     }
//     return 0;
// }



//D
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// #include <cstring>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// int n, m;
// const int N = 1e3 + 2;
// char mp[N][N];
// bool vis[N][N];
// int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// struct nd{
//     int x, y;
//     nd(int a = 0, int b = 0) { x = a, y = b;}
// };
// int main()
// {
//     int T;

//     scanf("%d", &T);
//     while(T--)
//     {
//         int sx, sy, ex, ey;
//         scanf("%d%d", &n, &m);
//         memset(vis, 0, sizeof(vis));
//         for(int i = 0; i < n; i++)
//             scanf("%s", &mp[i]);
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 if(mp[i][j] == 's') 
//                     sx = i, sy = j;
//                 else if(mp[i][j] == 't') ex = i, ey = j;
//             }
//         }
//         bool ok = 0;
//         queue<nd> q;
//         vis[sx][sy] = 1;
//         q.push(nd(sx, sy));
//         while(!q.empty())
//         {
//             nd now = q.front();
//             q.pop();
//             int x = now.x, y = now.y;
//             if(x == ex && y == ey)
//             {
//                 ok = 1;
//                 break;
//             }
//             for(int i = 0; i < 4; i++)
//             {
//                 int nx = x + dir[i][0], ny = y + dir[i][1];
//                 if(nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] != 'x' && !vis[nx][ny])
//                 {
//                     vis[nx][ny] = 1;
//                     q.push(nd(nx, ny));
//                 }
//             }
//         }
//         if(ok) printf("YES\n");
//         else printf("NO\n");
//     }
//     return 0;
// }



// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// #include <cstring>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// #define db double
// int n, k;
// const int N = 1e5 + 5;
// struct nd{
//     db w, v;
//     bool operator <(const nd &x) const{
//         return v / w > (x.v / x.w);
//     }
// }q[N];
// db cal()
// {


// }
// int main()
// {
//     int T;

//     scanf("%d", &T);
//     while(T--)
//     {
//         db w_max = 0, v_max = 0;
//         scanf("%d%d", &n, &k);
//         for(int i = 1; i <= n; i++)
//         {
//             db a, b;
//             scanf("%lf%lf", &a, &b);
//             q[i].w = a, q[i].v = b;
//             w_max = max(w_max, a);
//             v_max = max(v_max, b);
//         }
//         db l = 1, r = w_max;
        
//     }
//     return 0;
// }




//E
//求 n 的阶乘的末尾有几个0（后缀0个数sum）
//对于 n! ，容易知道要产生后缀0的最小阶乘时 5!，因为它包含 5 * 2 = 10 这个因子，所以每有一个 5! 就多一个后缀0
//每次就 sum += n / 5, n /= 5 最后得到sum就是 5! 的个数 即 5*2 = 10 的个数 也即后缀0的个数




//H
//AC
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// #include <cstring>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// #define db double
// const int N = 1e2 + 5;

// struct nd{
//     int x, y, t, step;
//     nd(int a = 0, int b = 0, int c = 0, int d = 0) { x = a, y = b, t = c, step = d;}
//     bool operator <(const nd &m) const{ return t > m.t;}
// };
// int n, k, cx, cy, ans = 1e9;
// int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// string mp[N];
// bool vis[3][N][N];//vis[step][x][y] 用不同方式走过的点 不共用 状态

// void bfs(int sx, int sy)
// {
//     priority_queue<nd> q;
//     q.push(nd(sx, sy, 0, 2));
//     vis[2][sx][sy] = 1;

//     while(!q.empty())
//     {
//         nd now = q.top();
//         q.pop();
//         int x = now.x, y = now.y, step = now.step;
//         if(mp[x][y] == 'C') step = 1;
//         else if(mp[x][y] == 'X')
//         {
//             ans = min(ans, now.t);
//             return;
//         }
//         for(int i = 0; i < 4; i++)
//         {
//             int nx = x + dir[i][0], ny = y + dir[i][1];
//             if(nx >= 0 && nx < n && ny >= 0 && ny < n && mp[nx][ny] != 'O' && !vis[step][nx][ny])
//             {
//                 vis[step][nx][ny] = 1;
//                 q.push(nd(nx, ny, now.t + step, step));
//             }
//         }
//     }
// }

// int main()
// {
//     untie();
//     int T;
//     cin >> T;
//     while(T--)
//     {
//         ans = 1e9;
//         memset(vis, 0, sizeof(vis));

//         int sx, sy;
//         cin >> n >> k;

//         for(int i = 0; i < n; i++) cin >> mp[i];
//         for(int i = 0; i < n; i++)
//             for(int j = 0; j < n; j++)
//                 if(mp[i][j] == 'S') 
//                 {
//                     sx = i, sy = j;
//                     break;
//                 }

//         bfs(sx, sy);
        
//         if(ans <= k) cout << "YES\n" << ans << "\n";
//         else cout << "NO\n";
//     }

//     return 0;
// }

//WA
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// #include <cstring>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// #define db double
// int n, k, cx, cy;
// const int N = 1e2 + 5;
// string mp[N];
// bool vis[N][N];
// int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// vector<pair<int, int> > car;
// struct nd{
//     int x, y, t;
//     nd(int a = 0, int b = 0, int c = 0) { x = a, y = b, t = c;}
// };
// int bfs(int sx, int sy, int step, int c)//0求到c，1求到X
// {
//     memset(vis, 0, sizeof(vis));
//     vis[sx][sy] = 1;
//     queue<nd> q;
//     q.push(nd(sx, sy, 0));
//     while(!q.empty())
//     {
//         nd now = q.front();
//         q.pop();
//         int x = now.x, y = now.y;
//         if(c == -1)
//         {
//             if(mp[x][y] == 'X')
//             {
//                 return now.t;
//             }
//         }
//         else
//         {
//             if(x == car[c].first && y == car[c].second)
//             {
//                 return now.t;
//             }
//         }
//         for(int i = 0; i < 4; i++)
//         {
//             int nx = x + dir[i][0], ny = y + dir[i][1];
//             if(nx >= 0 && nx < n && ny >= 0 && ny < n && mp[nx][ny] != 'O' && !vis[nx][ny])
//             {
//                 vis[nx][ny] = 1;
//                 q.push(nd(nx, ny, now.t + step));
//             }
//         }
//     }
//     return 0;
// }
// int main()
// {
//     untie();
//     int T;
//     cin >> T;
//     while(T--)
//     {
//         int sx, sy;
//         cin >> n >> k;
//         car.clear();
//         for(int i = 0; i < n; i++) cin >> mp[i];
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(mp[i][j] == 'S') sx = i, sy = j;
//                 else if(mp[i][j] == 'C') car.push_back(make_pair(i, j));
//             }
//         }
//         int t1 = bfs(sx, sy, 2, -1);//正常走去x
//         int mint = t1, d, t2;
//         if(!car.empty())
//         {
//             for(int i = 0; i < car.size(); i++)
//             {
//                 mint = min(bfs(sx, sy, 2, i) + bfs(car[i].first, car[i].second, 1, -1), mint);
//             }
//             // d = bfs(sx, sy, 2, 0);//先到车
//             // cx = car[0].first, cy = car[0].second;
//             // for(int i = 1; i < car.size(); i++)
//             // {
//             //     int res = bfs(sx, sy, 2, i);
//             //     if(res < d)
//             //     {
//             //         cx = car[i].first, cy = car[i].second;
//             //         d = res;
//             //     }
//             // }
//             // t2 = bfs(cx, cy, 1, -1);//车到x
//             // mint = min(t1, d + t2);
//         }
        
//         if(mint <= k) cout << "YES\n" << mint << "\n";
//         else cout << "NO\n";
//     }
//     return 0;
// }


//I
//二分 单位价值x
//二分判断式子推导：sum = Σv / Σw >= x  --->  sum = Σv - x * Σw >= 0 ---> 收束左端点
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// #define db double
// const int N = 1e5 + 5;
// const db eps = 1e-8;
// int n, k;
// db w[N], v[N], sum[N];
// bool check(db x)
// {
//     double s = 0;
//     for(int i = 1; i <= n; i++)
//         sum[i] = v[i] - x * w[i];
//     sort(sum + 1, sum + 1 + n);
//     for(int i = n; i >= n - k + 1; i--)//选前k大
//         s += sum[i];
//     return s >= 0;
// }
// int main()
// {
//     int T;
//     scanf("%d", &T);
//     while(T--)
//     {
//         scanf("%d%d", &n, &k);
//         for(int i = 1; i <= n; i++) scanf("%lf%lf", &w[i], &v[i]);
//         db l = 0, r = 1e6;
//         while(r - l >= eps)
//         {
//             db mid = (l + r) / 2;
//             if(check(mid)) l = mid;
//             else r = mid;
//         }
//         printf("%.2lf\n", l);
//     }
//     return 0;
// }







//J
//区间dp

//K.
//while寻找初项到取模点的长度mod，取模会导致函数变成周期函数，最初f[0]=0,f[1]=1，在取模点可能有 f[0]==0 && f[1]==1 == 1 时说明取模后数列进入下一个周期
//求f[a^b] % c，则对 a^b 快速幂(用 mod 取模)









/*
5 100
S....
.OOO.
.COO.
OOOO.
X....

7 100
S.....X
COOOX.X
.OXXXXX
.OXO.OX
.OXO.O.
.OXO.O.
..XO...

7 14
S.....C
.OOOOO.
CO...O.
.O.O.OX
.O.O.O.
.O.O.O.
...O...

3 10
SCC
CCC
CCX
*/















//ABC 292

//*G Count Strictly Increasing Sequences (DP)
//没写
//dp[l][r][k][m]
// #include <iostream>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef int ll;
// const ll mod = 998244353;
// ll n, m;
// string str[50];
// int num[50];
// int main()
// {
//     untie();
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++) cin >> str[i];

//     return 0;
// }



































//第十四届蓝桥杯模拟赛（第三期）
//1.
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// bool check(int y)
// {
//     if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
//         return 1;
//     return 0;
// }
// int cal(int x)
// {
//     int res = 0;
//     while(x)
//     {
//         res += x % 10;
//         x /= 10;
//     }
//     return res;
// }
// int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// int main()
// {
//     int ans = 0;
//     for(int year = 1900; year <= 9999; year++)
//     {
//         for(int mon = 1; mon <= 12; mon++)
//         {
//             int ok = 0;
//             if(mon == 2 && check(year)) ok = 1;
//             for(int day = 1; day <= days[mon] + ok; day++)
//                 if(cal(year) == cal(mon) + cal(day)) ans++;
//         }
//     }
//     cout << ans;
//     return 0;
// }


//2.
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <queue>
// using namespace std;
// int n = 30, m = 60;
// int mp[100][100];
// int ans = 0;
// int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// bool vis[100][100];
// struct nd{
//     int x, y;
// };
// void bfs(int x, int y)
// {
//     int res = 1;
//     queue<nd> q;
//     vis[x][y] = 1;
//     q.push(nd{x, y});
//     while(q.size())
//     {
//         nd now = q.front();
//         q.pop();
//         for(int i = 0; i < 4; i++)
//         {
//             int nx = now.x + dir[i][0], ny = now.y + dir[i][1];
//             if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && mp[nx][ny] == 1)
//             {
//                 res++;
//                 q.push(nd{nx, ny});
//                 vis[nx][ny] = 1;
//             }
//         }
//     }
//     ans = max(res, ans);
// }
// int main()
// {
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= m; j++)
//         {
//             char ch;
//             cin >> ch;
//             mp[i][j] = ch - '0';
//         }
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= m; j++)
//         {
//             if(mp[i][j] == 1 && !vis[i][j])
//                 bfs(i, j);
//         }
//     }
//     cout << ans;
//     return 0;
// }

//3.
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// using namespace std;
// int main()
// {
//     int w, n;
//     scanf("%d%d", &w, &n);
//     w += n % 7;
//     if(w > 7) w -= 7;
//     printf("%d\n", w);
//     return 0;
// }


//4.
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// using namespace std;
// struct nd{
//     int x, y;
// }tow[200];
// int main()
// {
//     int ans = 0;
//     int w, h, n, r;
//     scanf("%d%d%d%d", &w, &h, &n, &r);
//     for(int i = 0; i < n; i++)
//         scanf("%d%d", &tow[i].x, &tow[i].y);
//     for(int x = 0; x <= w; x++)
//     {
//         for(int y = 0; y <= h; y++)
//         {
//             int ok = 0;
//             for(int i = 0; i < n; i++)
//             {
//                 int dx = x - tow[i].x, dy = y - tow[i].y;
//                 if(sqrt(1.0 * dx * dx + 1.0 * dy * dy) <= r)
//                 {
//                     ok = 1;
//                     break;
//                 }
//             }
//             ans += ok;
//         }
//     }
//     printf("%d\n", ans);
//     return 0;
// }

//5.
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// using namespace std;
// const int N = 105;
// int b[N][N];
// void insert(int x1, int y1, int x2, int y2, int c)
// {
//     b[x1][y1] += c;
//     b[x2 + 1][y1] -= c;
//     b[x1][y2 + 1] -= c;
//     b[x2 + 1][y2 + 1] += c;
// }
// int main()
// {
//     int n, m, t;
//     scanf("%d%d", &n, &m);
//     scanf("%d", &t);
//     while(t--)
//     {
//         int r1, c1, r2, c2;
//         scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
//         insert(r1, c1, r2, c2, 1);
//     }
//     for(int i = 1; i <= n; i++)
//         for(int j = 1; j <= m; j++)
//             b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];  //转为二维前缀和
//     int sum = n * m;
//     for(int i = 1; i <= n; i++)
//         for(int j = 1; j <= m; j++)
//             sum -= b[i][j] > 0;
//     printf("%d\n", sum);
//     return 0;
// }

//6.
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// using namespace std;
// const int N = 1e2 + 5;
// int n, m;
// int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// int dis[N][N], gra[N][N];
// int dfs(int x, int y)
// {
//     if(dis[x][y] != -1) return dis[x][y];
//     dis[x][y] = 1;
//     for(int i = 0; i < 4; i++)
//     {
//         int nx = x + dir[i][0], ny = y + dir[i][1];
//         if(nx >= 0 && nx < n && ny >= 0 && ny < m && gra[nx][ny] < gra[x][y])
//             dis[x][y] = max(dis[x][y], dfs(nx, ny) + 1);
//     }
//     return dis[x][y];
// }
// int main()
// {
//     scanf("%d%d", &n, &m);
//     memset(dis, -1, sizeof(dis));
//     for(int i = 0; i < n; i++)
//         for(int j = 0, x; j < m; j++)
//             scanf("%d", &gra[i][j]);
//     int res = 1;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             dis[i][j] = max(dis[i][j], dfs(i, j));
//             res = max(res, dis[i][j]);
//         }
//     }
//     printf("%d\n", res);
//     return 0;
// }

//7.
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// #include <deque>
// using namespace std;
// const int N = 1e6 + 5;
// int arr[N], ans[N];
// deque<int> dq;
// int main()
// {
//     int n, k;
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
//     scanf("%d", &k);
//     for(int i = 1; i <= min(k + 1, n); i++)
//     {
//         while(!dq.empty() && arr[i] <= arr[dq.front()]) dq.pop_front();
//         dq.push_front(i);
//     }
//     ans[1] = arr[dq.back()];
//     for(int i = 2; i + k <= n; i++)
//     {
//         while(!dq.empty() && arr[i + k] <= arr[dq.front()]) dq.pop_front();
//         if(!dq.empty() && dq.back() < i - k) dq.pop_back();
//         dq.push_front(i + k);
//         ans[i] = arr[dq.back()];
//     }
//     for(int i = n - k + 1; i <= n; i++)
//     {
//         if(!dq.empty() && dq.back() < i - k) dq.pop_back();
//         ans[i] = arr[dq.back()];
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         printf("%d", ans[i]);
//         if(i != n) printf(" ");
//     }
//     return 0;
// }











