#include<bits/stdc++.h>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long
const int N = 1e2 + 10, mod = 1e9 + 7;
const double eps = 1e-6;
double a[N][N]; // �������

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
    for(int i = 0; i < n; ++i)            // ö���У���Ԫ��
    {
        int maxr = i;                     // Ѱ�ҵ� c �е������
        for(int j = i + 1; j < n; j++)
        	if(fabs(a[j][i]) > fabs(a[maxr][i])) 
                maxr = j;
        if(maxr != i) swap(a[i], a[maxr]);
        if(fabs(a[i][i]) < eps) return 0; // ����ȫΪ 0�����޽����������⣨��û��Ψһ�⣩
        double tp = a[i][i];              // ��Ԫ
        for(int j = 0; j < n; j++)        // ö�������У�����ǰ�У�
        {
            if(j == i) continue;
            double t = a[j][i] / a[i][i]; // �� i �л� 1 ��1 / a[i][i]�� ���� j �еĸ���Ԫ�ػ� 0
            for(int k = 0; k < n + 1; k++) a[j][k] -= a[i][k] * t;
        }
    }
    // ��ϵ������Ϊ��λ����ʹ�� a[i][n] ��Ϊ������ֵ
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