// #include <bits/stdc++.h>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// #define all(v) v.begin(), v.end()
// const int N = 2e5 + 10;


// void Solve()
// {
//     ll ans = 0;
//     int n; cin >> n;
//     map<ll, ll> xx, yy, xoy, yox;
//     for(int i = 0; i < n; ++i)
//     {
//         ll x, y; cin >> x >> y;
//         xx[x]++;
//         yy[y]++;
//         xoy[x + y]++;
//         yox[x - y]++;
//         // ����б�����ֱ�߷��̷ֱ��� y = x + c1 �� y = -x + c2������ж�ֵ x - y = c1 �� x + y = c2
//         // ���� x + y ����б�����ϵķ�������ֵ�ܾ��嵽ĳ��ֱ�ߣ�x - y �����б������
//     }
//     for(auto mp : {xx, yy, xoy, yox})
//         for(auto [val, cnt] : mp)
//             ans += cnt * (cnt - 1);
//     cout << ans << "\n";
// }

// int main()
// {
//     untie();
//     int T = 1;
//     // int T = 100;
//     cin >> T;
//     while(T--)
//     {
//         Solve();
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll unsigned long long
#define all(v) v.begin(), v.end()
const int N = 2e5 + 10;


void Solve()
{
    int n, m; cin >> n >> m;

}

int main()
{
    untie();
    int T = 1;
    // int T = 100;
    cin >> T;
    while(T--)
    {
        Solve();
    }
    return 0;
}
