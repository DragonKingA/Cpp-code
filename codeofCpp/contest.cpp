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


// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <cctype>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}

// int main()
// {
//     untie();
//     string s;
//     cin >> s;
//     for(auto &ch : s)
//     {
//         ch -= 32;
//     }
//     cout << s;
//     return 0;
// }


// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <cctype>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// pair<int, int> arr[105];
// int main()
// {
//     untie();
//     int op, x, q, n;
//     cin >> n >> q;
//     while(q--)
//     {
//         cin >> op >> x;
//         if(op == 1) arr[x].first++;
//         else if(op == 2) arr[x].second++;
//         else
//         {
//             if(arr[x].first >= 2 || arr[x].second >= 1) cout << "Yes\n";
//             else cout << "No\n";
//         }
//     }
//     return 0;
// }




#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
typedef int ll;
long long cnt = 0;
const ll N = 2e5 + 5;
ll n;

int main()
{
    untie();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {

    }
    
    cout << cnt;
    return 0;
}







// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e5 + 5;
// struct component{
//     int edge, node;
// }cnt[N];//每个连通块
// int n, m;
// int ds[N];
// void init_set()
// { 
//     for(int i = 1; i <= n; i++) 
//     {
//         ds[i] = i;
//         cnt[i].edge = 0;
//         cnt[i].node = 1;
//     }
// }
// int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
// int main()
// {
//     untie();
//     cin >> n >> m;
//     init_set();
//     for(int i = 1; i <= m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         int uu = find_set(u), vv = find_set(v);
//         if(uu == vv) cnt[uu].edge++;
//         else
//         {
//             ds[vv] = uu;
//             cnt[uu].edge += cnt[vv].edge + 1;
//             cnt[uu].node += cnt[vv].node;
//         }
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         int x = find_set(i);
//         if(cnt[x].edge != cnt[x].node)
//         {
//             cout << "No";
//             return 0;
//         }
//     }
//     cout << "Yes";
//     return 0;
// }



