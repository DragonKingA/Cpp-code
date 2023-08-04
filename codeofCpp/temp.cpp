#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 800, mod = 1e9 + 7;
int n, top = 0, sta[N], p[N];//p[i] 记录与 i 相匹配的字符的位置
ll dp[N][N][3][3];
string s;
void init()//预处理 p[i]，而 sta[i] 为接收括号字符 '(' 的栈，当遇到 ')' 时将一个 ')' 出栈
{
    for(int i = 1; i <= n; ++i)
    {
        if(s[i] == '(') sta[++top] = i;
        else
        {
            int pos = sta[top--];
            p[i] = pos;
            p[pos] = i;
        }
    }
}
int main()
{
    cin >> s;
    n = s.size();
    s = '*' + s;
    init();

    for(int len = 2; len <= n; ++len)
    {
        for(int l = 1; l + len - 1 <= n; ++l)
        {
            int r = l + len - 1;
            if(p[l] == r) //为匹配区间
            {
                if(len == 2) //特判长度为 2 时，初始化dp状态
                {
                    dp[l][r][0][1] = dp[l][r][0][2] = dp[l][r][1][0] = dp[l][r][2][0] = 1;
                    continue;
                }
                //分别继承中间区间的对应状态
                for(int i = 0; i < 3; ++i)
                { 
                    for(int j = 0; j < 3; ++j)
                    {
                        if(j != 1) dp[l][r][0][1] = (dp[l][r][0][1] + dp[l + 1][r - 1][i][j]) % mod;
                        if(j != 2) dp[l][r][0][2] = (dp[l][r][0][2] + dp[l + 1][r - 1][i][j]) % mod;
                        if(i != 1) dp[l][r][1][0] = (dp[l][r][1][0] + dp[l + 1][r - 1][i][j]) % mod;
                        if(i != 2) dp[l][r][2][0] = (dp[l][r][2][0] + dp[l + 1][r - 1][i][j]) % mod;
                    }
                }
            }
            else //不为匹配区间
            {
                int k = p[l];//仅此处能作为断点
                for(int x = 0; x < 3; ++x)
                    for(int y = 0; y < 3; ++y)
                        for(int p = 0; p < 3; ++p)
                            for(int q = 0; q < 3; ++q)
                                if(p == 0 || q == 0 || p != q) //相邻两个若有颜色，则颜色不能相同
                                    dp[l][r][x][y] = (dp[l][r][x][y] + dp[l][k][x][p] * dp[k + 1][r][q][y] % mod) % mod;//乘法原理
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            ans = (ans + dp[1][n][i][j]) % mod;
    cout << ans << '\n';
    return 0;
}