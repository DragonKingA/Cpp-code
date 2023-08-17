// #include<bits/stdc++.h> 
// #define ll long long
// using namespace std;
// const int N = 2e5 + 10, M = 1e6 + 10, inf = 0x3f3f3f3f;
// int dp[N];
// int fir[N], p[N], tp[M];
// int fir2[N], tp2[M];

// int main( )
// {
//     int n; cin >> n;
//     fill(dp + 2, dp + 5 + n, inf);
//     for(int i = 1; i <= n; ++i) 
//     {
//         cin >> p[i];
//         if(fir2[i] == 0 && tp2[p[i]]) fir2[i] = tp2[p[i]];
//         tp2[p[i]] = i;
//     }
//     for(int i = n; i > 0; --i)
//     {
//         if(fir[i] == 0 && tp[p[i]]) fir[i] = tp[p[i]];
//         tp[p[i]] = i;
//     }
//     for(int i = 1; i <= n; ++i) 
//     {
//         dp[i] = min({dp[i], dp[i - 1] + 1, dp[i + 1] + 1});
//         // if(fir[i] > 0) dp[i] = min(dp[i], dp[fir[i]] + 1);
//         if(fir[i] > 0) dp[fir[i]] = min(dp[fir[i]], dp[i] + 1);
//     }
//     for(int k = 0; k < 100; ++k)
//     {
//         for(int i = n; i > 0; --i) dp[i] = min({dp[i], dp[i - 1] + 1, dp[i + 1] + 1});
//         for(int i = n; i > 0; --i)
//         {
//             dp[i] = min({dp[i], dp[i - 1] + 1, dp[i + 1] + 1});
//             if(fir2[i] > 0) dp[i] = min(dp[fir2[i]] + 1, dp[i]);
//         }
//         for(int i = 1; i <= n; ++i) dp[i] = min({dp[i], dp[i - 1] + 1, dp[i + 1] + 1});
//     }
    
//     // for(int i = 1; i <= n; ++i) cout << dp[i] << "\n";
//     cout << dp[n] << "\n";
//     return 0;
// }
// /*
// 10
// 2 1 10 3 4 1 8 9 2 1


// */



// #include<bits/stdc++.h> 
// #define ll long long
// using namespace std;
// const int N = 1e5 + 10, M = 1e6 + 10, inf = 0x3f3f3f3f;
// ll X[N], Y[N], Z[N];
// int n; 

// int main( )
// {
//     cin >> n;
//     for(int i = 1; i <= n; ++i) cin >> X[i] >> Y[i] >> Z[i];
//     sort(X + 1, X + 1 + n);
//     sort(Y + 1, Y + 1 + n);
//     sort(Z + 1, Z + 1 + n);
//     ll midx, midy, midz, midind = (n + 1) / 2;
//     ll sx = 0, sy = 0, sz = 0, ansx = 0, ansy = 0, ansz = 0;
//     midx = X[midind], midy = Y[midind], midz = Z[midind];
//     for(int i = 1; i <= n; ++i)
//     {
//         sx += abs(X[i] - midx);
//         sy += abs(Y[i] - midy);
//         sz += abs(Z[i] - midz);
//     }
//     if(n & 1) --midx, --midy, --midz;
//     else ++midx, ++midy, ++midz;
//     for(int i = 1; i <= n; ++i)
//     {
//         if(X[i] > midx + 1) ansx += X[i] - midx - 1;
//         else if(X[i] < midx - 1) ansx += midx - 1 - X[i];

//         if(Y[i] > midy + 1) ansy += Y[i] - midy - 1;
//         else if(Y[i] < midy - 1) ansy += midy - 1 - Y[i];

//         if(Z[i] > midz + 1) ansz += Z[i] - midz - 1;
//         else if(Z[i] < midz - 1) ansz += midz - 1 - Z[i];
//     }
//     cout << min({sx + sy + ansz, sx + sz + ansy, sy + sz + ansx}) << "\n";
//     return 0;
// }
/*


1 2 3 999 1000

*/



// #include<bits/stdc++.h> 
// #define ll long long
// using namespace std;
// const int N = 1e5 + 10, M = 1e6 + 10, inf = 0x3f3f3f3f;
// int n = 13;
// ll a[N] = {0, 1, 2, 3, 213, 432, 832, 1000, 2003, 7301, 9921, 29310, 30431, 39999, 999999};

// int main( )
// {
//     sort(a + 1, a + 1 + n);
//     ll ansx = -1, sum = 1e9;
//     for(ll x = a[1]; x <= a[n]; ++x)
//     {
//         ll s = 0;
//         for(int i = 1; i <= n; ++i)
//         {
//             if(a[i] > x + 1) s += a[i] - x - 1;
//             else if(a[i] < x - 1) s += x - 1 - a[i];
//         }
//         if(s < sum)
//         {
//             sum = s;
//             ansx = x;
//         }
//     }
//     cout << sum << " " << ansx << "\n";
//     return 0;
// }


#include<bits/stdc++.h> 
#define ll long long
#define pll pair<ll, ll>
using namespace std;
struct nd{
    ll a, b;
    bool operator < (nd ne) const
    {
        if(a == ne.a) return b < ne.b;
        return a > ne.a;
    }
};
int main( )
{
    int n; cin >> n;
    priority_queue<nd> pq;
    for(int i = 0; i < n; ++i)
    {
        ll a, b;
        cin >> a >> b;
        nd now;
        now.a = a, now.b = b;
        pq.push(now);
    }
    cout << pq.top().a << " " << pq.top().b;
    return 0;
}