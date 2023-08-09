#include <bits/stdc++.h>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long
#define all(v) v.begin(), v.end()
const int N = 2e5 + 10;
const ll mod = 998244353LL;

void Solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;
    for(int i = 1; i < n; i++)
        if(s[i] != '1' && s[i + 1] != '1')
            return cout << "-1\n", void();

    vector<ll> dp(n + 1, 0);
    dp[n] = 1;
    for(int i = n - 1; i > 0; --i)
    {
        dp[i] = dp[i + 1] + 1 + (ll)(s[i + 1] - '1') * dp[i + 1] % mod;
        dp[i] %= mod;
    }
    cout << (dp[1] - dp[n] + mod) % mod << "\n"; // �� dp[1] - 1����ȥ s Ϊ��ʼ�����
}

int main()
{
    untie();
    int T = 1;
    // cin >> T;
    while(T--)
    {
        Solve();
    }
    return 0;
}