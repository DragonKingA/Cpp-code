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







*/
/*


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>

using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long

int main()
{
    untie();





    return 0;
}

*/
/*
������ģ��

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>

using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
#define ll long long
int T;

void Solve()
{


}

int main()
{
    untie();
    cin >> T;
    while(T--)
    {
        Solve();
    }
    return 0;
}

*/































//A
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cctype>
// #include <cstring>
// #include <string>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int main()
// {
//     untie();
//   int t; cin >> t;
//   while (t--)
//   {
//         char num[5];
//         map<int, int> vis;
//         for (int i = 1; i <= 4; i++) cin >> num[i], vis[num[i] - '1' + 1]++;
//         if (vis.size() == 1) cout << "-1";
//         else if (vis.size() == 2)
//         {
//         for (auto v : vis)
//         {
//             if (v.second != 2) cout << '6';
//             else cout << '4';
//             break;
//         }
//         }
//         else cout << '4';
//         cout << endl;
//   }
// }






//B
//��͹�ʽ + ���ִ�
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cctype>
// #include <cstring>
// #include <string>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// int T;
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         ll n;
//         cin >> n;
//         ll ans1 = 0, ans2 = 0;

//         ll l = 1, r = 1e9;
//         while(l < r)
//         {
//             ll mid = l + r >> 1;
//             ll cal = ((((mid - 1) << 3) * mid) >> 1);
//             if(cal < n - 1) l = mid + 1;// ans1 = mid;
//             else r = mid; 
//         }
//         ans1 = l;

//         l = 1, r = 1e9;
//         while(l < r)
//         {
//             ll mid = l + r >> 1;
//             ll cal = (((8 + ((mid - 1) << 3)) * mid) >> 1);
//             if(cal < n) l = mid + 1;// ans2 = mid;
//             else r = mid;
//         }
//         ans2 = l;

//         ans1 = (ans1 - 1) << 1;
//         ans2 = (ans2 << 1) - 1;
//         cout << min(ans1, ans2) << '\n';
//     }
//     return 0;
// }
//���õĶ���
//һ�� x * x ���������ʱ 1 * 1 ���������һ���㣩��ʾ�����������е�ĸ������ʴ�����͹�ʽ
//ע���������
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// int T;
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         ll n;
//         cin >> n;
//         ll l = -1, r = 1e9;//���ִ���Ϊ r��r �� [0, 1e9)  �� l �� [-1, 1e9)
//         while(r - l > 1)
//         {
//             ll mid = l + r >> 1;
//             ll cal = (mid + 1) * (mid + 1);
//             if(cal < n) l = mid;
//             else r = mid;
//         } 
//         cout << r << '\n';
//     }
//     return 0;
// }




























































































































//edu Round 145
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cctype>
// #include <cstring>
// #include <string>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// int T;

// void Solve()
// {


// }

// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         Solve();
//     }
//     return 0;
// }












































//edu Round 144
//A
//�仯����Ϊ 8����"FBFFBFFB"��ѯ�ʵ��Ӵ��Ϊ10���ʴ��ڿ�Խ3�����ڵĿ��ܣ���ô�������ַ�����Ϊ24λ���ɣ���"FBFFBFFBFBFFBFFBFBFFBFFB"��
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cctype>
// #include <cstring>
// #include <string>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// int T;
// string s = "FBFFBFFBFBFFBFFBFBFFBFFB";
// void Solve()
// {
//     int n;
//     string t;
//     cin >> n >> t;
//     cout << (s.find(t) != -1 ? "YES\n" : "NO\n");
//     return;
// }
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         Solve();
//     }
//     return 0;
// }



//B
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cctype>
// #include <cstring>
// #include <string>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// int T;
// void Solve() {
// 	string a, b;
// 	cin >> a >> b;
// 	int n = a.size(), m = b.size();
// 	if (a[0] == b[0]) {
// 		cout << "YES\n";
// 		cout << a[0] << '*' << '\n';
// 		return;
// 	}
// 	if (a[n - 1] == b[m - 1]) {
// 		cout << "YES\n";
// 		cout << '*' << a[n - 1] << '\n';
// 		return;
// 	}
// 	for (int i = 0; i + 1 < n; i++) {
// 		if (b.find(a.substr(i, 2)) != -1) {
// 			cout << "YES\n";
// 			cout << '*' << a.substr(i, 2) << '*' << '\n';
// 			return;
// 		}
// 	}
// 	cout << "NO\n";
// }
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         Solve();
//     }
//     return 0;
// }







































































































































// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>
// #include <cstring>
// #include <string>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// int n;
// int main()
// {
//     untie();
//     int t;
//     cin  >> t;
//     while(t--)
//     {
//         int a, b, c;
//     cin >> a >> b >> c;
//     if(a + b == c)
//     cout << "+\n";
//     else
//         cout << "-\n";
//     }
//     return 0;
// }


// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>
// #include <cstring>
// #include <string>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// int n;
// int arr[200];
// int main()
// {
//     untie();
//     int t;
//     cin  >> t;
//     while(t--)    
//     {
//         cin >> n;
//         ll s1 = 0, s2 = 0;
//         for(int i = 1; i <= n; i++) 
//         {
//             cin >> arr[i];
//             if(arr[i] % 2 == 0) s1 += arr[i];
//             else s2 += arr[i];
//         }
//         if(s1 > s2) cout << "YES\n";
//         else cout << "NO\n";
//     }
//     return 0;
// }




// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>
// #include <cstring>
// #include <string>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// int n;
// char s[2050];
// map<char, int> mp;
// int main()
// {
//     untie();
//     int t;
//     cin  >> t;
//     while(t--)    
//     {
//         mp.clear();
//         cin >> n;
//         for(int i = 1; i <= n; i++) cin >> s[i];
//         mp[s[1]] = 0;
//         int ex = 1, ok = 1;
//         for(int i = 2; i <= n; i++)
//         {
//             if(!mp.count(s[i])) mp[s[i]] = ex;
//             else if(mp[s[i]] != ex)
//             {
//                 ok = 0;
//                 break;
//             }
//             ex ^= 1;
//         }
//         if(ok) cout << "YES\n";
//         else cout << "NO\n";
//     }
//     return 0;
// }



//WA
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>
// #include <cstring>
// #include <string>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll unsigned long long
// const int N = 2e5 + 10;
// ll a[N];
// int main()
// {
//     untie();
//     int t;
//     cin  >> t;
//     while(t--)    
//     {
//         int n, q;
//         cin >> n >> q;
//         for(int i = 1; i <= n; i++) cin >> a[i];
//         for(int i = 2; i <= n; i++) a[i] += a[i - 1];
//         ll sum = a[n];
//         while(q--)
//         {
//             int l, r;
//             ll k;
//             cin >> l >> r >> k;
//             ll now = sum - (a[r] - a[l - 1]) + 1ull * (r - l + 1) * k;
//             if(now & 1) cout << "YES\n";
//             else cout << "NO\n";
//         }
//     }
//     return 0;
// }



// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>
// #include <cstring>
// #include <string>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// const int N = 2e5 + 10;
// int n;
// ll a[N], s[N];
// ll cal(ll k)
// {
//     return 
// }
// int main()
// {
//     int t;
//     scanf("%d", &t);
//     while(t--)    
//     {
//         scanf("%d", &n);
//         for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
//         for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[1];
//         int l = 1, r = n;
//         while(l <= r)
//         {       
//         }
//         printf("\n");
//         fflush(stdout);
//     }
//     return 0;
// }











//G1
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>
// #include <cstring>
// #include <string>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll unsigned long long
// const int N = 5e3 + 10;
// int a[N];
// int main()
// {
//     untie();
//     int t;
//     cin  >> t;
//     while(t--)    
//     {
//         int n;
//         cin >> n;
//         for(int i = 1; i <= n; i++) cin >> a[i];

//         sort(a + 1, a + 1 + n);
//         ll cnt = 1, last = 0;
//         int ok = 1;
//         for(int i = 1; i <= n; i++)
//         {
//             if(a[i] > cnt)
//             {
//                 ok = 0;
//                 break;
//             }
//             else
//             {
//                 cnt = a[i];
//             }
//             // if(i != 1) cnt <<= 1;
//             cnt += last;
//             last = cnt;
//         }
//         if(ok) cout << "YES\n";
//         else cout << "NO\n";
//     }

//     return 0;
// }


//G2
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>
// #include <cstring>
// #include <string>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll unsigned long long
// const int N = 2e5 + 10;
// int a[N];
// int main()
// {
//     untie();
//     int t;
//     cin  >> t;
//     while(t--)    
//     {
//         int n;
//         cin >> n;
//         for(int i = 1; i <= n; i++) cin >> a[i];
//         sort(a + 1, a + 1 + n);
//         ll cnt = 1, last = 0;
//         int ok = 1;
//         for(int i = 1; i <= n; i++)
//         {
//             if(a[i] > cnt)
//             {
//                 ok = 0;
//                 break;
//             }
//             else
//             {
//                 cnt = a[i];
//             }
//             cnt += last;
//             last = cnt;
//         }
//         if(ok) cout << "YES\n";
//         else cout << "NO\n";
//     }

//     return 0;
// }











//F
//δ���
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>
// #include <cstring>
// #include <string>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll unsigned long long
// const int N = 25010;
// string s;
// string tp[4] = {"DR","DL","UR","UL"};
// map<string, pair<int, int> > dir;
// int n, m, cnt = 0;
// int sx, sy, ex, ey, nx, ny;
// bool check(int x1, int y1, int x2, int y2)
// {
//     int k1 = (y1 - y2) / (x1 - x2), k2 = (ey - y1) / (ex - x1);
//     return k1 == k2;
// }
// void dfs(int x, int y, pair<int, int> op, vector<vector<int> > vis)
// {
//     if(vis[x][y])
//     {
//         cnt = -1;
//         return ;
//     }
//     vis[x][y] = 1;
//     pair<int, int> next;
//     int nx, ny;
//     int d1 = op.first > 0 ? (n - x) : (x - 1);
//     int d2 = op.second > 0 ? (n - y) : (y - 1);
//     if(d1 <= d2)
//     {
//         nx = op.first > 0 ? n : 1;
//         ny = op.second > 0 ? (y + d1) : (y - d1);
//     }
//     else
//     {
//         nx = op.first > 0 ? (x + d2) : (x - d2);
//         ny = op.second > 0 ? m : 1;
//     }
//     ++cnt;
//     if(check(x, y, nx, ny))
//     {
//         return;
//     }
//     if(nx == n || nx == 1) next.first = -op.first;
//     if(ny == m || ny == 1) next.second = -op.second;
//     dfs(nx, ny, next, vis);

// }
// int main()
// {
//     untie();

//     dir[tp[0]] = make_pair(1, 1);
//     dir[tp[1]] = make_pair(1, -1);
//     dir[tp[2]] = make_pair(-1, 1);
//     dir[tp[3]] = make_pair(-1, -1);
    

//     int t;
//     cin  >> t;
//     while(t--)    
//     {
//         cnt = 0;
//         cin >> n >> m >> sx >> sy >> ex >> ey >> s;
//         vector<vector<int> > vis(n + 5, vector<int>(m + 5, 0));

//         dfs(sx, sy, dir[s], vis);
//         cout << cnt << '\n';
//     }

//     return 0;
// }



















































//atc
//A
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>
// #include <cstring>
// #include <string>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// vector<int> v;
// int main()
// {
//     untie();
//     int n;
//     cin >> n;
//     while(n--)
//     {
//         int x;
//         cin >> x;
//         if(x % 2 == 0) v.push_back(x);
//     }
//     for(int i = 0; i < v.size(); i++)
//     {
//         cout << v[i];
//         if(i != v.size() - 1) cout << " ";
//         else cout << "\n";
//     }
//     return 0;
// }



//B
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>
// #include <cstring>
// #include <string>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 120;
// int a[N][N];
// char ans[N][N];
// int main()
// {
//     untie();
//     int n, m;
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++)
//         for(int j = 1; j <= m; j++)
//             cin >> a[i][j];
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= m; j++)
//         {
//             char ch = a[i][j] + 'A' - 1;
//             if(a[i][j] == 0) cout << ".";
//             else cout << ch;
//         }
//         cout << '\n';
//     }
//     return 0;
// }



//C
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <set>
// #include <map>
// #include <queue>
// #include <cstring>
// #include <string>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e5 + 5;
// int n, m;
// int a[N], b[N], c[2 * N];
// map<int, int> mp;
// int main()
// {
//     untie();
//     cin >> n >> m;
//     int cnt = 0;
//     for(int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         c[++cnt] = a[i];
//     }
//     for(int i = 1; i <= m; i++)
//     {
//         cin >> b[i];
//         c[++cnt] = b[i];
//     }
//     sort(c + 1, c + 1 + cnt);
//     for(int i = 1; i <= cnt; i++) mp[c[i]] = i;
//     for(int i = 1; i <= n; i++)
//     {
//         cout << mp[a[i]];
//         if(i != n) cout << " ";
//         else cout << '\n';
//     }
//     for(int i = 1; i <= m; i++)
//     {
//         cout << mp[b[i]];
//         if(i != m) cout << " ";
//         else cout << '\n';
//     }
//     return 0;
// }



//D
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll int
// const int N = 5e5 + 5;
// bool vis[N];
// int main()
// {
//     ll n, q;
//     scanf("%d%d", &n, &q);
//     int h = 1;
//     while(q--)
//     {
//         ll op, x;
//         scanf("%d", &op);
//         if(op == 1);
//         else if(op == 2)
//         {
//             int x;
//             scanf("%d", &x);
//             vis[x] = 1;
//         }
//         else
//         {
//             while(vis[h]) ++h;
//             printf("%d\n", h);
//         }
//     }
//     return 0;
// }



//E
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <cstring>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// const int N = 5e5 + 5;
// int L, n1, n2;
// int main()
// {
//     untie();
//     cin >> L >> n1 >> n2;


//     return 0;
// }














































































//A
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <map>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// string s = "codeforces";
// map<char, bool> mp;
// int main()
// {
//     for(auto ch : s)
//     {
//         mp[ch] = 1;
//     }
//     untie();
//     int t;
//     char ch;
//     cin >> t;
//     while(t--)
//     {
//         cin >> ch;
//         if(mp[ch]) cout << "YES\n";
//         else cout << "NO\n";
//     }
//     return 0;
// }



//B
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <map>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int main()
// {
//     untie();
//     int t, n;
//     cin >> t;
//     while(t--)
//     {
//         cin >> n;
//         char ch;
//         int x = 0, y = 0, ok = 0;
//         while(n--)
//         {
//             cin >> ch;
//             switch(ch)
//             {
//                 case 'L': x--; break;
//                 case 'R': x++; break;
//                 case 'D': y--; break;
//                 case 'U': y++; break;
//             }
//             if(x == 1 && y == 1)
//             {
//                 ok = 1;
//             }
//         }
//         if(ok) cout << "YES\n";
//         else cout << "NO\n";
//     }
//     return 0;
// }



//C
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <map>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e4 + 10;
// char s[N];
// int main()
// {
//     untie();
//     int t, n;
//     cin >> t;
//     while(t--)
//     {
//         cin >> n;
//         cin >> s;
//         int l = 0, r = n - 1;
//         int ans = 0;
//         // if(n & 1) ans = 1;
//         int sum = 0;
//         while(l < r)
//         {
//             if(s[l] != s[r])
//             {
//                 ++sum;
//             }
//             else
//             {
//                 break;
//             }
//             ++l, --r;
//         }
//         ans += n - 2 * sum;
//         cout << ans << '\n';
//     }
//     return 0;
// }



//D
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <map>
// #include <set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e5 + 10;
// string s;
// int c1[200], c2[200];
// int main()
// {
//     untie();
//     int t, n;
//     cin >> t;
//     while(t--)
//     {
//         memset(c1, 0, sizeof(c1));
//         memset(c2, 0, sizeof(c2));
//         cin >> n;
//         cin >> s;
//         int len = s.size(), ans = 0;
//         int cnt1 = 0, cnt2 = 0;
//         for(int i = 0; i < len; i++) 
//         {
//             if(!c2[s[i]]) ++cnt2;
//             c2[s[i]]++;
//         }
//         ans = cnt2;
//         for(int i = 0; i < len; i++)
//         {
//             if(!c1[s[i]]) ++cnt1;
//             c1[s[i]]++;
//             c2[s[i]]--;
//             if(!c2[s[i]]) --cnt2;
//             ans = max(ans, cnt1 + cnt2);
//         }
//         cout << ans << '\n';
//     }
//     return 0;
// }



//E (˼ά �� DP)
//dp
//���� dp[i][0] Ϊ�� i �������ͣ���ǰ����ת����dp[i][1] Ϊ��ǰ��ת������ 
//����ת��ֱ�Ӽ̳����� 1 ~ i-1 ��״̬�� dp[i][0] =  a[i] + max(dp[i - 1][0], dp[i - 1][1]);
//��ת����ֵ ��ȥ��ת���ֵ �� ����a[i - 1]ԭ�����Ƿ�ı䣨dp[i-1][1]˵���ı�����ʷ���ȡ��,�� dp[i][1] = -a[i] + max(dp[i - 1][0] - 2 * a[i - 1], dp[i - 1][1] + 2 * a[i - 1]);
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <map>
// #include <set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// const int N = 2e5 + 10;
// ll a[N], dp[N][2];
// int main()
// {
//     untie();
//     int t, n;
//     cin >> t;
//     while(t--)
//     {
//         memset(dp, 0, sizeof(dp));
//         cin >> n;
//         for(int i = 1; i <= n; i++) cin >> a[i];
//         dp[2][0] = a[1] + a[2], dp[2][1] = -dp[2][0];
//         for(int i = 3; i <= n; i++)
//         {
//             dp[i][0] =  a[i] + max(dp[i - 1][0], dp[i - 1][1]);                              //����ת��ֱ�Ӽ̳����� 1 ~ i-1 ��״̬
//             dp[i][1] = -1LL * a[i] + max(dp[i - 1][0] - 2LL * a[i - 1], dp[i - 1][1] + 2LL * a[i - 1]);//��ת����ֵ ��ȥ��ת���ֵ �� ����a[i - 1]ԭ�����Ƿ�ı䣨dp[i-1][1]˵���ı�����ʷ���ȡ����
//         }
//         cout << max(dp[n][0], dp[n][1]) << "\n";
//     }
//     return 0;
// }
//˼ά - ת������
//���Է���,��ת������Ԫ�صķ���,�Ҳ����ƴ���,��ʵ�Ϳ��Է�ת������ ��������Ԫ�� �ķ���(ֻҪ��������һ��Ԫ���ڼ�һֱ��ת)
//��ֻ��Ҫ�����������,һ��ת���ɽ����и����������
//�������������������: ż����(ֱ���������) �� ������(��ʣ��һ������û���,��ôֻ��Ҫ��ת���������� ����ֵ��С�� �� ʣ��������) 
//����������ʱ,���һ�������ķ�ת���Ӧ�� ��ת���������� ����ֵ��С����,������ֵ��С�����Լ�,����������ת
//�� -4 -5 -6 1 2 3, ���Ӧ�����һ������ �� 1 ���
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <map>
// #include <set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// const int N = 2e5 + 10;
// ll a[N];
// int main()
// {
//     untie();
//     int t, n;
//     cin >> t;
//     while(t--)
//     {
//         ll sum = 0, cnt = 0;
//         cin >> n;
//         for(int i = 0; i < n; i++) 
//         {
//             cin >> a[i];
//             if(a[i] < 0)
//             {
//                 a[i] = -a[i];
//                 ++cnt;
//             }
//             sum += a[i];
//         }
//         if(cnt & 1) sum -= 2 * *min_element(a, a + n);
//         cout << sum << '\n';
//     }
//     return 0;
// }



//F (��������� - ��״���� \ �߶���)
//������ 99999999 �仯һ�κ�Ϊ 72 ,���κ�Ϊ 9,���ܱ仯����������2����
//ֻ��Ҫά�������ڲ���������,�� ai ʱ���仯�������㼴��,������cnt[i]��¼��i��Ԫ�ر仯����
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <map>
// #include <set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll int
// #define lowbit(x) ((x) & -(x))
// const int N = 2e5 + 10;
// ll t[N], a[N], cnt[N];
// int T, n, q;
// void update(ll x, ll d)
// {
//     for(int i = x; i <= n; i += lowbit(i)) t[i] += d;
// }
// ll query(ll x)
// {
//     ll res = 0;
//     for(int i = x; i > 0; i -= lowbit(i)) res += t[i];
//     return res;
// }
// ll cal(ll x)
// {
//     ll res = 0;
//     for(; x; x /= 10) res += x % 10;
//     return res;
// }
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         memset(t, 0, sizeof(t));
//         memset(cnt, 0, sizeof(cnt));
//         cin >> n >> q;
//         for(int i = 1; i <= n; i++) cin >> a[i];
//         while(q--)
//         {
//             ll op, l, r, x;
//             cin >> op;
//             if(op == 1)
//             {
//                 cin >> l >> r;
//                 update(l, 1);
//                 update(r + 1, -1);
//             }
//             else
//             {
//                 cin >> x;
//                 ll tmp = query(x), ans = a[x];
//                 for(int i = cnt[x]; i < tmp && a[x] > 9; i++)//��ֹ�ظ����� �� ��Ч����
//                 {
//                     a[x] = cal(a[x]);//�仯ֱ��Ӧ�õ�ԭ������
//                 }
//                 cnt[x] = tmp;
//                 cout << a[x] << '\n';
//             }
//         }
//     }
//     return 0;
// }








// G1
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <map>
// #include <set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// const int N = 2e5 + 10;
// ll a[N];
// int main()
// {
//     untie();
//     int t, n;
//     cin >> t;
//     while(t--)
//     {
//         ll ans = 0, c;
//         cin >> n >> c;
//         for(int i = 1; i <= n; i++)
//         {
//             cin >> a[i];
//             a[i] += i;
//         }
//         sort(a + 1, a + 1 + n);
//         for(int i = 1; i <= n; i++)
//         {
//             if(c >= a[i])
//             {
//                 ++ans;
//                 c -= a[i];
//             }
//             else
//                 break;
//         }
//         cout << ans << '\n';
//     }
//     return 0;
// }






































//CF 858
//A
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int n;
// int dir[2][2] = {{1, 1}, {-1, 0}};
// int main()
// {
//     untie();
//     cin >> n;
//     while(n--) 
//     {
//         int a, b, c, d;
//         cin >> a >> b >> c >> d;
//         a = a + d - b;
//         int res = d - b + (a -  c);
//         if(a < c || d < b) cout << "-1\n";
//         else cout << res << '\n';
//     }
//     return 0;
// }

//B 
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <vector>
// #include <queue>
// #include <functional>
// #include <map>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e5 + 10;
// int t, n;
// int arr[N], b[N];
// map<int, int> mp;
// int main()
// {
//     untie();
//     cin >> t;
//     while(t--)
//     {
//         mp.clear();
//         cin >> n;
//         int num = 0;
//         for(int i = 1; i <= n; i++) cin >> arr[i];
//         sort(arr + 1, arr + 1 + n);
//         for(int i = 1; i <= n; i++) ++mp[arr[i]];
//         int ind = mp[0] + 1;
//         num = n - mp[0];
//         if(arr[1] > 0 || num + 1 >= mp[0]) cout << "0\n";
//         else if(arr[n] > 1) 
//         {
//             cout << "1\n";
//         }
//         else{
//             cout << arr[n] + 1 << '\n';
//         }
//     }
//     return 0;
// }


//0 0 0 0 1 1 



















































//ABC 293

// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <map>
// #include <set>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e5+ 10;
// int h, w;
// int a[20][20];
// int ans = 0;
// int dir[2][2] = {{1, 0}, {0, 1}};
// map<int, bool> vis;
// void dfs(int x, int y)
// {
//     // if(vis[a[x][y]]) return;
//     if(x == h && y == w) 
//     {
//         ans++;
//         return;
//     }
//     for(int i = 0; i < 2; i++)
//     {
//         int nx = x + dir[i][0], ny = y + dir[i][1];
//         if(nx >= 1 && nx <= h && ny >= 1 && ny <= w && !vis[a[nx][ny]])
//         {
//             // if(nx == h && ny == w)
//             // {
//             //     ans++;
//             //     return;
//             // }
//             vis[a[nx][ny]] = 1;
//             dfs(nx, ny);
//             vis[a[nx][ny]] = 0;
//         }
//     }
// }
// int main()
// {
    
//     scanf("%d%d", &h, &w);
//     for(int i = 1; i <= h; i++)
//         for(int j = 1; j <= w; j++)
//             scanf("%d", &a[i][j]);
//     vis[a[1][1]] = 1;
//     dfs(1, 1);
//     printf("%d", ans);
//     return 0;
// }





/*
blue - 5 - red

blue - 3 - red
*/
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e5 + 5;
// int n, m;
// #define pic pair<int, char>
// pic arr[N];
// map<pic, pic> mp;
// set<pic> ans;
// set<int> cnt;
// set<pic> line;
// int vis[N];
// int test = 0;
// pic find_set(pic x)
// {
//     return x == mp[x] ? x : (mp[x] = find_set(mp[x])); 
// }
// int main()
// {
//     int num = 0;
//     scanf("%d%d", &n, &m);
//     for(int i = 1; i <= n; i++)
//     {
//         pic n1 = pic(i, 'B'), n2 = pic(i, 'R');
//         mp[n2] = n1;
//     }
//     while(m--)
//     {
        // char c1[5], c2[5];
        // int x, y; char xc, yc;
        // scanf("%d %s %d %s", &x, &c1, &y, &c2);
//         xc = c1[0], yc = c2[0];
//         pic m1 = pic(x, xc), m2 = pic(y, yc);
//         cnt.insert(x);
//         cnt.insert(y);
//         // if(x > y) swap(x, y);
//         // if(vis[x] != y && vis[y] != x)
//         // {
//         //     num++;
            
//         // }
//         // line.insert(pic(x, y));

//         mp[m2] = m1;
//         // mp[m2] = m1;
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         pic n1 = pic(i, 'B'), n2 = pic(i, 'R');
//         pic p1 = find_set(n1), p2 = find_set(n2);
//         if(p1 == p2)
//         {
//             ans.insert(p1);
//         }
//         else
//             test++;
//     }
//     int d = n - cnt.size();
//     printf("%d\n", line.size() + d);
//     printf("%d %d\n", ans.size(), num + d);
//     return 0;
// }

// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e2 + 5;//2e5
// int n, m;
// #define pic pair<int, char>
// int ds[N];
// int cnt[N];

// map<pic, bool> vis;
// bool par[N];
// int find_set(int x)
// {
//     return x == ds[x] ? x : (ds[x] = find_set(ds[x]));
// }

// int main()
// {
//     int circle = 0, num = 0;
//     scanf("%d%d", &n, &m);
//     for(int i = 1; i <= n; i++) ds[i] = i, cnt[i] = 0;
//     while(m--)
//     {
//         char c1[5], c2[5];
//         int x, y; char xc, yc;
//         scanf("%d %s %d %s", &x, &c1, &y, &c2);
//         xc = c1[0], yc = c2[0];
//         ds[y] = x;
//         vis[pic(x, xc)] = vis[pic(y, yc)] = 1;
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         if(find_set(x) == find_set(y)) circle++;

//     }
//     printf("%d %d\n", circle, num - circle);
//     return 0;
// }

// B - x - R








// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ntype;
// #define ll long long
// ntype mod;
// ntype quick_pow(ll base, ntype index)
// {
//     ntype ans = 1;
//     for(; index; index >>= 1)
//     {
//         if(index & 1) ans = ans * base % mod;
//         base = base * base % mod;
//     }
//     return ans;
// }
// int main()
// {
//     ll a, x, res = 0;
//     scanf("%lld%lld%lld", &a, &x, &mod);
//     res = a * (quick_pow(a, x - 1) - 1) / (a - 1) % mod;
//     printf("%lld", res);
//     return 0;
// }











//2018�궫��ũҵ��ѧ����У������������

//F��M ǩ��

//B
//1
//n+1
//2*n + 1
//3*n + 1
//(n-1) * n + 1
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int n;
// const int N = 1e4 + 2;
// #define ll long long
// ll ans[N];
// void test()
// {
//     int c = 1;
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= n; j++)
//         {
//             printf("%4d ", c++);
//         }
//         puts("");
//     }
// }
// int main()
// {
//     int T;

//     scanf("%d", &T);
//     while(T--)
//     {
//         scanf("%d", &n);
//         // test();
//         ll sum = 0;
//         ans[1] = n / 2 + 1;
//         int num = 3;
//         for(int i = 2; i <= n / 2 + 1; i++)
//         {
//             ll st = 1LL * (i - 1) * n + 1 + (n / 2 - i + 1);
//             ans[i] = ans[i - 1] + 1LL * (num - 2) * n + st + (st + num - 1);
//             num += 2;
//         }
//         num = 3;
//         ans[n] = 1LL * (n - 1) * n + 1 + n / 2;
//         for(int i = n - 1; i > n / 2 + 1; i--)
//         {
//             ll st = 1LL * (i - 1) * n + 1 + (i - n / 2 - 1);
//             ans[i] = ans[i + 1] - 1LL * (num - 2) * n + st + (st + num - 1);
//             num += 2;
//         }
//         for(int i = 1; i <= n ;i++)
//             sum += ans[i];
//         printf("%lld\n", sum);
//     }
//     return 0;
// }



//D
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// #include <cstring>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// int n, m;
// const int N = 1e3 + 2;
// char mp[N][N];
// bool vis[N][N];
// int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// struct nd{
//     int x, y;
//     nd(int a = 0, int b = 0) { x = a, y = b;}
// };
// int main()
// {
//     int T;

//     scanf("%d", &T);
//     while(T--)
//     {
//         int sx, sy, ex, ey;
//         scanf("%d%d", &n, &m);
//         memset(vis, 0, sizeof(vis));
//         for(int i = 0; i < n; i++)
//             scanf("%s", &mp[i]);
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 if(mp[i][j] == 's') 
//                     sx = i, sy = j;
//                 else if(mp[i][j] == 't') ex = i, ey = j;
//             }
//         }
//         bool ok = 0;
//         queue<nd> q;
//         vis[sx][sy] = 1;
//         q.push(nd(sx, sy));
//         while(!q.empty())
//         {
//             nd now = q.front();
//             q.pop();
//             int x = now.x, y = now.y;
//             if(x == ex && y == ey)
//             {
//                 ok = 1;
//                 break;
//             }
//             for(int i = 0; i < 4; i++)
//             {
//                 int nx = x + dir[i][0], ny = y + dir[i][1];
//                 if(nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] != 'x' && !vis[nx][ny])
//                 {
//                     vis[nx][ny] = 1;
//                     q.push(nd(nx, ny));
//                 }
//             }
//         }
//         if(ok) printf("YES\n");
//         else printf("NO\n");
//     }
//     return 0;
// }



// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// #include <cstring>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// #define db double
// int n, k;
// const int N = 1e5 + 5;
// struct nd{
//     db w, v;
//     bool operator <(const nd &x) const{
//         return v / w > (x.v / x.w);
//     }
// }q[N];
// db cal()
// {


// }
// int main()
// {
//     int T;

//     scanf("%d", &T);
//     while(T--)
//     {
//         db w_max = 0, v_max = 0;
//         scanf("%d%d", &n, &k);
//         for(int i = 1; i <= n; i++)
//         {
//             db a, b;
//             scanf("%lf%lf", &a, &b);
//             q[i].w = a, q[i].v = b;
//             w_max = max(w_max, a);
//             v_max = max(v_max, b);
//         }
//         db l = 1, r = w_max;
        
//     }
//     return 0;
// }




//E
//�� n �Ľ׳˵�ĩβ�м���0����׺0����sum��
//���� n! ������֪��Ҫ������׺0����С�׳�ʱ 5!����Ϊ������ 5 * 2 = 10 ������ӣ�����ÿ��һ�� 5! �Ͷ�һ����׺0
//ÿ�ξ� sum += n / 5, n /= 5 ���õ�sum���� 5! �ĸ��� �� 5*2 = 10 �ĸ��� Ҳ����׺0�ĸ���




//H
//AC
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// #include <cstring>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// #define db double
// const int N = 1e2 + 5;

// struct nd{
//     int x, y, t, step;
//     nd(int a = 0, int b = 0, int c = 0, int d = 0) { x = a, y = b, t = c, step = d;}
//     bool operator <(const nd &m) const{ return t > m.t;}
// };
// int n, k, cx, cy, ans = 1e9;
// int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// string mp[N];
// bool vis[3][N][N];//vis[step][x][y] �ò�ͬ��ʽ�߹��ĵ� ������ ״̬

// void bfs(int sx, int sy)
// {
//     priority_queue<nd> q;
//     q.push(nd(sx, sy, 0, 2));
//     vis[2][sx][sy] = 1;

//     while(!q.empty())
//     {
//         nd now = q.top();
//         q.pop();
//         int x = now.x, y = now.y, step = now.step;
//         if(mp[x][y] == 'C') step = 1;
//         else if(mp[x][y] == 'X')
//         {
//             ans = min(ans, now.t);
//             return;
//         }
//         for(int i = 0; i < 4; i++)
//         {
//             int nx = x + dir[i][0], ny = y + dir[i][1];
//             if(nx >= 0 && nx < n && ny >= 0 && ny < n && mp[nx][ny] != 'O' && !vis[step][nx][ny])
//             {
//                 vis[step][nx][ny] = 1;
//                 q.push(nd(nx, ny, now.t + step, step));
//             }
//         }
//     }
// }

// int main()
// {
//     untie();
//     int T;
//     cin >> T;
//     while(T--)
//     {
//         ans = 1e9;
//         memset(vis, 0, sizeof(vis));

//         int sx, sy;
//         cin >> n >> k;

//         for(int i = 0; i < n; i++) cin >> mp[i];
//         for(int i = 0; i < n; i++)
//             for(int j = 0; j < n; j++)
//                 if(mp[i][j] == 'S') 
//                 {
//                     sx = i, sy = j;
//                     break;
//                 }

//         bfs(sx, sy);
        
//         if(ans <= k) cout << "YES\n" << ans << "\n";
//         else cout << "NO\n";
//     }

//     return 0;
// }

//WA
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>
// #include <cstring>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define ll long long
// #define db double
// int n, k, cx, cy;
// const int N = 1e2 + 5;
// string mp[N];
// bool vis[N][N];
// int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// vector<pair<int, int> > car;
// struct nd{
//     int x, y, t;
//     nd(int a = 0, int b = 0, int c = 0) { x = a, y = b, t = c;}
// };
// int bfs(int sx, int sy, int step, int c)//0��c��1��X
// {
//     memset(vis, 0, sizeof(vis));
//     vis[sx][sy] = 1;
//     queue<nd> q;
//     q.push(nd(sx, sy, 0));
//     while(!q.empty())
//     {
//         nd now = q.front();
//         q.pop();
//         int x = now.x, y = now.y;
//         if(c == -1)
//         {
//             if(mp[x][y] == 'X')
//             {
//                 return now.t;
//             }
//         }
//         else
//         {
//             if(x == car[c].first && y == car[c].second)
//             {
//                 return now.t;
//             }
//         }
//         for(int i = 0; i < 4; i++)
//         {
//             int nx = x + dir[i][0], ny = y + dir[i][1];
//             if(nx >= 0 && nx < n && ny >= 0 && ny < n && mp[nx][ny] != 'O' && !vis[nx][ny])
//             {
//                 vis[nx][ny] = 1;
//                 q.push(nd(nx, ny, now.t + step));
//             }
//         }
//     }
//     return 0;
// }
// int main()
// {
//     untie();
//     int T;
//     cin >> T;
//     while(T--)
//     {
//         int sx, sy;
//         cin >> n >> k;
//         car.clear();
//         for(int i = 0; i < n; i++) cin >> mp[i];
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(mp[i][j] == 'S') sx = i, sy = j;
//                 else if(mp[i][j] == 'C') car.push_back(make_pair(i, j));
//             }
//         }
//         int t1 = bfs(sx, sy, 2, -1);//������ȥx
//         int mint = t1, d, t2;
//         if(!car.empty())
//         {
//             for(int i = 0; i < car.size(); i++)
//             {
//                 mint = min(bfs(sx, sy, 2, i) + bfs(car[i].first, car[i].second, 1, -1), mint);
//             }
//             // d = bfs(sx, sy, 2, 0);//�ȵ���
//             // cx = car[0].first, cy = car[0].second;
//             // for(int i = 1; i < car.size(); i++)
//             // {
//             //     int res = bfs(sx, sy, 2, i);
//             //     if(res < d)
//             //     {
//             //         cx = car[i].first, cy = car[i].second;
//             //         d = res;
//             //     }
//             // }
//             // t2 = bfs(cx, cy, 1, -1);//����x
//             // mint = min(t1, d + t2);
//         }
        
//         if(mint <= k) cout << "YES\n" << mint << "\n";
//         else cout << "NO\n";
//     }
//     return 0;
// }


//I
//���� ��λ��ֵx
//�����ж�ʽ���Ƶ���sum = ��v / ��w >= x  --->  sum = ��v - x * ��w >= 0 ---> ������˵�
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// #define db double
// const int N = 1e5 + 5;
// const db eps = 1e-8;
// int n, k;
// db w[N], v[N], sum[N];
// bool check(db x)
// {
//     double s = 0;
//     for(int i = 1; i <= n; i++)
//         sum[i] = v[i] - x * w[i];
//     sort(sum + 1, sum + 1 + n);
//     for(int i = n; i >= n - k + 1; i--)//ѡǰk��
//         s += sum[i];
//     return s >= 0;
// }
// int main()
// {
//     int T;
//     scanf("%d", &T);
//     while(T--)
//     {
//         scanf("%d%d", &n, &k);
//         for(int i = 1; i <= n; i++) scanf("%lf%lf", &w[i], &v[i]);
//         db l = 0, r = 1e6;
//         while(r - l >= eps)
//         {
//             db mid = (l + r) / 2;
//             if(check(mid)) l = mid;
//             else r = mid;
//         }
//         printf("%.2lf\n", l);
//     }
//     return 0;
// }







//J
//����dp

//K.
//whileѰ�ҳ��ȡģ��ĳ���mod��ȡģ�ᵼ�º���������ں��������f[0]=0,f[1]=1����ȡģ������� f[0]==0 && f[1]==1 == 1 ʱ˵��ȡģ�����н�����һ������
//��f[a^b] % c����� a^b ������(�� mod ȡģ)









/*
5 100
S....
.OOO.
.COO.
OOOO.
X....

7 100
S.....X
COOOX.X
.OXXXXX
.OXO.OX
.OXO.O.
.OXO.O.
..XO...

7 14
S.....C
.OOOOO.
CO...O.
.O.O.OX
.O.O.O.
.O.O.O.
...O...

3 10
SCC
CCC
CCX
*/















//ABC 292

//*G Count Strictly Increasing Sequences (DP)
//ûд
//dp[l][r][k][m]
// #include <iostream>
// #include <algorithm>
// #include <cstdio>
// #include <string>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef int ll;
// const ll mod = 998244353;
// ll n, m;
// string str[50];
// int num[50];
// int main()
// {
//     untie();
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++) cin >> str[i];

//     return 0;
// }



































//��ʮ�Ľ����ű�ģ�����������ڣ�
//1.
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// bool check(int y)
// {
//     if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
//         return 1;
//     return 0;
// }
// int cal(int x)
// {
//     int res = 0;
//     while(x)
//     {
//         res += x % 10;
//         x /= 10;
//     }
//     return res;
// }
// int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// int main()
// {
//     int ans = 0;
//     for(int year = 1900; year <= 9999; year++)
//     {
//         for(int mon = 1; mon <= 12; mon++)
//         {
//             int ok = 0;
//             if(mon == 2 && check(year)) ok = 1;
//             for(int day = 1; day <= days[mon] + ok; day++)
//                 if(cal(year) == cal(mon) + cal(day)) ans++;
//         }
//     }
//     cout << ans;
//     return 0;
// }


//2.
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <queue>
// using namespace std;
// int n = 30, m = 60;
// int mp[100][100];
// int ans = 0;
// int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// bool vis[100][100];
// struct nd{
//     int x, y;
// };
// void bfs(int x, int y)
// {
//     int res = 1;
//     queue<nd> q;
//     vis[x][y] = 1;
//     q.push(nd{x, y});
//     while(q.size())
//     {
//         nd now = q.front();
//         q.pop();
//         for(int i = 0; i < 4; i++)
//         {
//             int nx = now.x + dir[i][0], ny = now.y + dir[i][1];
//             if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && mp[nx][ny] == 1)
//             {
//                 res++;
//                 q.push(nd{nx, ny});
//                 vis[nx][ny] = 1;
//             }
//         }
//     }
//     ans = max(res, ans);
// }
// int main()
// {
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= m; j++)
//         {
//             char ch;
//             cin >> ch;
//             mp[i][j] = ch - '0';
//         }
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= m; j++)
//         {
//             if(mp[i][j] == 1 && !vis[i][j])
//                 bfs(i, j);
//         }
//     }
//     cout << ans;
//     return 0;
// }

//3.
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// using namespace std;
// int main()
// {
//     int w, n;
//     scanf("%d%d", &w, &n);
//     w += n % 7;
//     if(w > 7) w -= 7;
//     printf("%d\n", w);
//     return 0;
// }


//4.
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// using namespace std;
// struct nd{
//     int x, y;
// }tow[200];
// int main()
// {
//     int ans = 0;
//     int w, h, n, r;
//     scanf("%d%d%d%d", &w, &h, &n, &r);
//     for(int i = 0; i < n; i++)
//         scanf("%d%d", &tow[i].x, &tow[i].y);
//     for(int x = 0; x <= w; x++)
//     {
//         for(int y = 0; y <= h; y++)
//         {
//             int ok = 0;
//             for(int i = 0; i < n; i++)
//             {
//                 int dx = x - tow[i].x, dy = y - tow[i].y;
//                 if(sqrt(1.0 * dx * dx + 1.0 * dy * dy) <= r)
//                 {
//                     ok = 1;
//                     break;
//                 }
//             }
//             ans += ok;
//         }
//     }
//     printf("%d\n", ans);
//     return 0;
// }

//5.
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// using namespace std;
// const int N = 105;
// int b[N][N];
// void insert(int x1, int y1, int x2, int y2, int c)
// {
//     b[x1][y1] += c;
//     b[x2 + 1][y1] -= c;
//     b[x1][y2 + 1] -= c;
//     b[x2 + 1][y2 + 1] += c;
// }
// int main()
// {
//     int n, m, t;
//     scanf("%d%d", &n, &m);
//     scanf("%d", &t);
//     while(t--)
//     {
//         int r1, c1, r2, c2;
//         scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
//         insert(r1, c1, r2, c2, 1);
//     }
//     for(int i = 1; i <= n; i++)
//         for(int j = 1; j <= m; j++)
//             b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];  //תΪ��άǰ׺��
//     int sum = n * m;
//     for(int i = 1; i <= n; i++)
//         for(int j = 1; j <= m; j++)
//             sum -= b[i][j] > 0;
//     printf("%d\n", sum);
//     return 0;
// }

//6.
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// using namespace std;
// const int N = 1e2 + 5;
// int n, m;
// int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// int dis[N][N], gra[N][N];
// int dfs(int x, int y)
// {
//     if(dis[x][y] != -1) return dis[x][y];
//     dis[x][y] = 1;
//     for(int i = 0; i < 4; i++)
//     {
//         int nx = x + dir[i][0], ny = y + dir[i][1];
//         if(nx >= 0 && nx < n && ny >= 0 && ny < m && gra[nx][ny] < gra[x][y])
//             dis[x][y] = max(dis[x][y], dfs(nx, ny) + 1);
//     }
//     return dis[x][y];
// }
// int main()
// {
//     scanf("%d%d", &n, &m);
//     memset(dis, -1, sizeof(dis));
//     for(int i = 0; i < n; i++)
//         for(int j = 0, x; j < m; j++)
//             scanf("%d", &gra[i][j]);
//     int res = 1;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             dis[i][j] = max(dis[i][j], dfs(i, j));
//             res = max(res, dis[i][j]);
//         }
//     }
//     printf("%d\n", res);
//     return 0;
// }

//7.
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// #include <deque>
// using namespace std;
// const int N = 1e6 + 5;
// int arr[N], ans[N];
// deque<int> dq;
// int main()
// {
//     int n, k;
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
//     scanf("%d", &k);
//     for(int i = 1; i <= min(k + 1, n); i++)
//     {
//         while(!dq.empty() && arr[i] <= arr[dq.front()]) dq.pop_front();
//         dq.push_front(i);
//     }
//     ans[1] = arr[dq.back()];
//     for(int i = 2; i + k <= n; i++)
//     {
//         while(!dq.empty() && arr[i + k] <= arr[dq.front()]) dq.pop_front();
//         if(!dq.empty() && dq.back() < i - k) dq.pop_back();
//         dq.push_front(i + k);
//         ans[i] = arr[dq.back()];
//     }
//     for(int i = n - k + 1; i <= n; i++)
//     {
//         if(!dq.empty() && dq.back() < i - k) dq.pop_back();
//         ans[i] = arr[dq.back()];
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         printf("%d", ans[i]);
//         if(i != n) printf(" ");
//     }
//     return 0;
// }











