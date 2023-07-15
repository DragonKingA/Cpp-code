#include <bits/stdc++.h>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long
#define all(v) v.begin(), v.end()
const int N = 2e5 + 10;
int n, T, m;
ll ans = 0;


void dfs(int i)
{
    
}

void Solve()
{
    cin >> n >> T >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        
    }
    
   
    
}

int main()
{
    // untie();
    int _ = 1;
    // int T = 1;
    // cin >> T;
    while(_--)
    {
        Solve();
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// #define all(v) v.begin(), v.end()
// const int N = 100 + 10;
// const ll mod = 998244353LL;
// int n;
// ll a[N], dp[15];

// ll quick_pow(ll base, ll index = mod - 2)
// {
//     ll ans = 1;
//     base %= mod;
//     for(; index; index >>= 1)
//     {
//         if(index & 1) ans = ans * base % mod;
//         base = base * base % mod;
//     }
//     return ans % mod;
// }

// void Solve()
// {
//     cin >> n;
//     for(int i = 1; i <= n; ++i) 
//     {
//         cin >> a[i];
//         for(int j = 1; j <= min(a[i], 10LL); ++j)
//         {
//             dp[j] = (dp[j] + quick_pow(a[i])) % mod;
//         }
//     }
//     // for(int i = 2; i <= 10; ++i)
//     // {
//     //     for(int j = 1; j < i; ++j)
//     //     {
//     //         // if(i - j == j) continue;
//     //         dp[i] = (dp[i] + quick_pow(dp[i - j] * dp[j])) % mod;
//     //     }
//     // }
//     for(int i = 1; i <= 10; ++i)
//     {
//         for(int j = 1; j <= 10; ++j)
//         {
//             // if(i - j == j) continue;
//             dp[i + j] = (dp[i + j] + quick_pow(dp[i] * dp[j])) % mod;
//         }
//     }
//     for(int i = 2; i <= 10; ++i)
//     {
//         if(i & 1) continue;
//         dp[i] = (dp[i] - dp[i / 2] + mod) % mod;
//     }
//     cout << dp[10] % mod << "\n";
// }

// int main()
// {
//     // untie();
//     int _ = 1;
//     // int T = 1;
//     // cin >> T;
//     while(_--)
//     {
//         Solve();
//     }
//     return 0;
// }
