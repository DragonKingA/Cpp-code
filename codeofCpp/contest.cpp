/*
//ģ��
//���鼯��
#include <cstdio>
#include <iostream>
using namespace std;
const int N = ;
int ds[N];
void init_set(int n){ for(int i = 1; i <= n; ds[i] = i, i++);}
int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
void merge_set(int x, int y){ if((x = find_set(x)) != (y = find_set(y))) ds[x] = ds[y];}



//��άǰ׺��
//�洢��ʽ��sum[i][j] =  sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j]
// ��ȡ��ʽ��res = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]
#include <iostream>
using namespace std;
const int N = ;
int arr[N][N];
int sum[N][N];
int main()
{       
    int x1,x2,y1,y2;//����ķ�Χ
    //��ʼ������
    for(int i=1;i<=N-1;i++) 
        for(int j=1;j<=N-1;j++)
            arr[i][j]=i+j;
    //ǰ׺�Ͳ���(ʵ���Ͽ��Ա߶�ȡarr���������߽�����Ͳ���)
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



//��ά���
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
            insert(i, j, i, j, a[i][j]);      //�����������
    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);          //��ֲ���
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];  //תΪ��άǰ׺��
    return 0;
}



//������
//base ������index ָ��
//�������������ݣ�
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
//��������ݣ�
#include <cstdio>
typedef long long ntype;
const ntype mod = , N = ;//���� N ָ�����α߳���n ָʵ�ʾ��α߳�
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

//ABC 292
//A CAPS LOCK (ǩ����)
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

//B Yellow and Red Card (ǩ����)
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



//C Four Variables
//��(A, B, C, D)������ A*B + C*D = n���� x + y = n���ȼ���ÿ�����������Եĸ�������arr[]�У��� x �ж��ٸ�(A, B)ʹ�� A*B = x��
//��������֪��ÿ��(x, y)�ܲ�������(A, B, C, D)������Ȼ��ö��x (y = n - x)���������ɡ�
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// const int N = 2e5 + 5;
// ll cnt = 0;
// ll arr[N] = {1};
// int n;
// // void init() //149ms
// // {
// //     for(int i = 1; i <= n; i++)
// //     {
// //         ll sum = 1, tp = 1;
// //         for(int j = 2; j * j <= i; j++)
// //         {
// //             if(i % j == 0)
// //             {
// //                 ++sum;
// //             }
// //             tp = j;
// //         }
// //         arr[i] = 2 * sum - (tp * tp == i);
// //     }
// // }
// //���õ�д�� //12ms
// void init()
// {
//     for(int i = 1; i < n; i++)//ö����������
//         for(int j = 1; i * j <= n; j++)
//             arr[i * j]++;//����˻����������1
// }
// int main()
// {
//     untie();
//     cin >> n;
//     init();
//     for(int x = 1; x < n; x++) cnt += arr[x] * arr[n - x];
//     cout << cnt;
//     return 0;
// }






//D Unicyclic Components ��ͼ��
//��ͼ��ÿ����ͨ���Ƿ�����ÿ��ڶ��������߸������
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e5 + 5;
// struct component{
//     int edge, node;
// }cnt[N];//ÿ����ͨ��
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



// E Transitivity
//������������������鷳
//��һ������ͼ����һ��Ŀ��ͼ����Ŀ��ͼ��ÿ����u���㣬u������ԭͼ�����ܵ�������е�v��Ҫ��ֱ����
//bfs����ÿ����u��Ϊ��㣬��ͨ·���ϵ��������е㶼Ҫ��u���ߣ�����cnt++������ȥ���б�������Ҫ�����Ĵ���
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e3 + 5;
// int n, m, cnt = 0;
// bool vis[N];
// vector<int> G[N];
// void bfs(int s)
// {
//     memset(vis, 0, sizeof(vis));
//     queue<int> q;
//     q.push(s);
//     vis[s] = 1;
//     while(q.size())
//     {
//         int u = q.front();
//         q.pop();
//         for(int i = 0; i < G[u].size(); i++)
//         {
//             int v = G[u][i];
//             if(!vis[v])
//             {
//                 vis[v] = 1;
//                 ++cnt;
//                 q.push(v);
//             }
//         }
//     }
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     for(int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         G[u].push_back(v);
//     }
//     for(int i = 1; i <= n; i++) bfs(i);
//     cnt -= m;
//     cout << cnt;
//     return 0;
// }



//F Regular Triangle Inside a Rectangle (��ѧ����)
//�� A >= B
//�����ȼ���AԶ����B����Ȼ��ʱ��BΪ�ߵ��������α߳���󣬼� B / cos(pi / 6) = 2 * B / sqrt(3)                         (1)
//����A = 12, B = 11�������ʱ�����������A����Ȼ�����������������۲���Ӧ�õ����� A > B
//���賤ΪA����ΪB�ľ��Σ��涨�����������һ�������ھ������Ͻǣ�һ�������ھ��ε׳��ߣ���������������ڱ���Ҳ���ܲ��ڱ���
//�����Ҳ���γ���һ���Ա�BΪ����һ��ֱ�Ǳߡ����������αߵ�б�ߵ�һ�����ֱ��������
//�����������һ�������B�γɽǦȣ������һ�������A�γɽ� (pi / 2 - �� - pi / 3) = pi / 6 - ��
//������ΪL���õ��������� Lcos�� = B�� Lcos(pi / 6 - ��) = A�������� �� = arctan(2 * A / B - sqrt(3))
//��ʱ���� L = B / cos��                                                                                            (2)
//���ֻҪ�жϽ��(1)�ͽ��(2)�ĸ��������ĸ����res1��res2�����ܻᳬ��A��Ҳֻ��һ���ᳬ��A����ʵ���Ͻ��(1)��(2)����ֻ��һ���Ǻ���ģ���𰸱���������Сֵ

//AC
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// using namespace std;
// int main()
// {
//     int a, b;
//     scanf("%d%d", &a, &b);
//     if(a < b) swap(a, b);
//     double res1 = 2.0 * b / sqrt(3.0);
//     double res2 = 1.0 * b / cos(atan(2.0 * a / b - sqrt(3.0)));
//     // if(res1 > a) printf("%.20lf\n", res2);
//     // else printf("%.20lf\n",res1);
//     // ��ͬ�¾�
//     printf("%.20lf\n", min(res1, res2));
//     return 0;
// }

//PA    57 pts / 70 pts 
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// using namespace std;
// const long double MAXL = sqrt(6.0L) - sqrt(2.0L);
// int main()
// {
//     int a, b;
//     scanf("%d%d", &a, &b);
//     if(a < b) swap(a, b);
//     if(a > b) 
//     {
//         long double ml = 2.0L * b / sqrt(3.0L);
//         if(ml > a)  printf("%.20Lf\n", 1.0L * b * MAXL);
//         else printf("%.20Lf\n", ml);
//     }
//     else printf("%.20Lf\n", 1.0L * a * MAXL);
//     return 0;
// }



//*G Count Strictly Increasing Sequences (DP)
//dp[l][r][k][m]
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
typedef int ll;
const ll mod = 998244353;
ll n, m;
string str[50];
int num[50];
int main()
{
    untie();
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> str[i];

    return 0;
}




















