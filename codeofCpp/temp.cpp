#include<bits/stdc++.h>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long
const int N = 1e2 + 10, mod = 1e9 + 7;
const double eps = 1e-6;
double a[N][N]; // 增广矩阵

ll quick_pow(ll base, ll index = mod - 2)
{
    ll ans = 1;
    base %= mod;
    for(; index; index >>= 1)
    {
        if(index & 1) ans = ans * base % mod;
        base = base * base % mod;
    }
    return ans % mod;
}

int Gauss_Jordan(int n)
{
    for(int i = 0; i < n; ++i)            // 枚举列（变元）
    {
        int maxr = i;                     // 寻找第 c 列的最大项
        for(int j = i + 1; j < n; j++)
        	if(fabs(a[j][i]) > fabs(a[maxr][i])) 
                maxr = j;
        if(maxr != i) swap(a[i], a[maxr]);
        if(fabs(a[i][i]) < eps) return 0; // 该列全为 0，故无解或有无穷个解（即没有唯一解）
        double tp = a[i][i];              // 主元
        for(int j = 0; j < n; j++)        // 枚举所有行（除当前行）
        {
            if(j == i) continue;
            double t = a[j][i] / a[i][i]; // 第 i 行化 1 （1 / a[i][i]） ，第 j 行的该列元素化 0
            for(int k = 0; k < n + 1; k++) a[j][k] -= a[i][k] * t;
        }
    }
    // 化系数矩阵为单位矩阵，使得 a[i][n] 即为解向量值
    for(int i = 0; i < n; ++i) a[i][n] /= a[i][i];
    return 1;
}

int main()
{
    untie();
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= n; ++j)
            cin >> a[i][j];
    if(Gauss_Jordan(n) == 0)
    {
        cout << "No Solution\n";
        return 0;
    }
    for(int i = 0; i < n; ++i) cout << fixed << setprecision(2) << a[i][n] << "\n";
    return 0;
}