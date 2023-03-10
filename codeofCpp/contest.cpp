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













