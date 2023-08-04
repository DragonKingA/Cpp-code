#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 800, mod = 1e9 + 7;
int n, top = 0, sta[N], p[N];//p[i] ��¼�� i ��ƥ����ַ���λ��
ll dp[N][N][3][3];
string s;
void init()//Ԥ���� p[i]���� sta[i] Ϊ���������ַ� '(' ��ջ�������� ')' ʱ��һ�� ')' ��ջ
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
            if(p[l] == r) //Ϊƥ������
            {
                if(len == 2) //���г���Ϊ 2 ʱ����ʼ��dp״̬
                {
                    dp[l][r][0][1] = dp[l][r][0][2] = dp[l][r][1][0] = dp[l][r][2][0] = 1;
                    continue;
                }
                //�ֱ�̳��м�����Ķ�Ӧ״̬
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
            else //��Ϊƥ������
            {
                int k = p[l];//���˴�����Ϊ�ϵ�
                for(int x = 0; x < 3; ++x)
                    for(int y = 0; y < 3; ++y)
                        for(int p = 0; p < 3; ++p)
                            for(int q = 0; q < 3; ++q)
                                if(p == 0 || q == 0 || p != q) //��������������ɫ������ɫ������ͬ
                                    dp[l][r][x][y] = (dp[l][r][x][y] + dp[l][k][x][p] * dp[k + 1][r][q][y] % mod) % mod;//�˷�ԭ��
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