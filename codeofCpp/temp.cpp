#include <bits/stdc++.h>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long
#define all(v) v.begin(), v.end()
const int N = 200;
int a[N];
void Solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> v;
    ll ans = 0;
    for(int i = 2; i <= n; ++i) 
    {
        int x = abs(a[i] - a[i - 1]);
        ans += 1LL * x;
        v.push_back(x);
    }
    sort(all(v), greater<int>());
    for(int i = 0; i < k - 1; i++) ans -= v[i];
    cout << ans << "\n";
}

int main()
{
    untie();
    int T = 1;
    // int T = 1;
    cin >> T;
    while(T--)
    {
        Solve();
    }
    return 0;
}

/*


*/