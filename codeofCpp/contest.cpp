/*
//模板
//并查集：
#include <cstdio>
#include <iostream>
using namespace std;
const int N = ;
int ds[N];
void init_set(int n){ for(int i = 1; i <= n; ds[i] = i, i++);}
int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
void merge_set(int x, int y){ if((x = find_set(x)) != (y = find_set(y))) ds[x] = ds[y];}



//二维前缀和
//存储公式：sum[i][j] =  sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j]
// 读取公式：res = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]
#include <iostream>
using namespace std;
const int N = ;
int arr[N][N];
int sum[N][N];
int main()
{       
    int x1,x2,y1,y2;//待求的范围
    //初始化数列
    for(int i=1;i<=N-1;i++) 
        for(int j=1;j<=N-1;j++)
            arr[i][j]=i+j;
    //前缀和操作(实际上可以边读取arr数列数，边进行求和操作)
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



//二维差分
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
            insert(i, j, i, j, a[i][j]);      //构建差分数组
    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);          //差分操作
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];  //转为二维前缀和
    return 0;
}



//快速幂
//base 底数；index 指数
//线性整数快速幂：
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
//矩阵快速幂：
#include <cstdio>
typedef long long ntype;
const ntype mod = , N = ;//这里 N 指最大矩形边长，n 指实际矩形边长
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


//F
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}

// string str = "The party began, the greasy uncle was playing cards, the fat otaku was eating, and the little beauty was drawing.At the party, people will play a game called Flag Scramble. The rule of this game is that the host speaks a sentence, and people find the letter that appears the most in the sentence. The first person who calls this letter wins. If your answer is wrong or someone else wins, you will be fined. You don't need to deal with many situations, just find the letter that appears most frequently in the statement of this problem and print it out, the letters are case insensitive.Very simple, right? Please remember to count carefully! Do not count wrong! This is the most straightforward question after all, but do not get a time penalty here, it is not worth it! In order for everyone to have a good experience, I really tried my best, and finally thought of such a question as a sign-in question, do not thank me too much, manual dog head.";
// map<char, int> mp;
// int main()
// {
//     untie();
//     cout << 'e';
//     return 0;
// }




//I
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int T;
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         int x;
//         cin >> x;
//         if(x >= 3) cout << "Yes\n";
//         else cout << "No\n";
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
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int T;
// string a, b;
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         cin >> a >> b;
//         int cnta = 0, cntb = 0;
//         vector<int> v1, v2{0};//无0 和 有0
//         for(int i = 0; i < a.size(); i++)
//         {
//             if(cnta & 1)//反转
//             {
//                 if(a[i] == '1') a[i] = '0';
//                 else a[i] = '1';
//             }
//             if(a[i] == b[i]) continue;
//             v1.push_back(i + 1);
//             cnta++;
//         }
//         //固定 a = "00000···"
//         for(int i = 0; i < b.size(); i++)
//         {
//             if(cntb & 1)
//             {
//                 if(b[i] == '1') b[i] = '0';
//                 else b[i] = '1';
//             }
//             if(b[i] == '0') continue;
//             v2.push_back(i + 1);
//             cntb++;
//         }
//         if(v2.size() <= v1.size())//v2优先
//         {
//             for(int i = 0; i < v2.size(); i++) 
//                 cout << (" " + !i) << v2[i];
//         }
//         else
//         {
//             for(int i = 0; i < v1.size(); i++) 
//                 cout << (" " + !i) << v1[i];
//         }
//         cout << '\n';
//     }
//     return 0;
// }
//10001
//cnta = 1


//C
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// int T, n;
// int main()
// {
//     scanf("%d", &T);
//     while(T--)
//     {
//         scanf("%d", &n);
//         ll now = 0, res = n;//至少需要n分
//         while(n--)
//         {
//             ll l, r;
//             scanf("%lld%lld", &l, &r);
//             if(now >= l && now <= r) continue;
//             if(now < l) res += l - now, now = l;
//             else res += now - r, now = r;
//         }
//         printf("%lld\n", res);
//     }
//     return 0;
// }





//E
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int T, arr[100005];
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         int n; cin >> n;
//         for(int i = 1; i <= n; i++) cin >> arr[i];
//         //最后一个结点上
//     }
//     return 0;
// }



//K
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// string s;
// int dy[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
// bool check(int pos)// ' ' - '0' < 0
// {
//     int l = pos, r = pos + 7;
//     int year = 0;
//     //前4位年份存储 + 判断回文
//     while(l <= r)
//     {
//         year = year * 10 + (s[l] - '0');
//         if(s[l] != s[r]) return 0;
//         l++, r--;
//     }
//     int month = (s[pos + 4] - '0') * 10 + (s[pos + 5] - '0');
//     int day = (s[pos + 6] - '0') * 10 + (s[pos + 7] - '0');
//     if(year < 1 || year > 9999) return 0;
//     if(month < 1 || month > 12) return 0;
//     if(day < 1 || day > 31) return 0;
//     //特判二月
//     if(month == 2)
//     {
//         if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return day <= 29;
//         else return day <= 28;
//     }

//     return day >= 1 && day <= dy[month];
// }
// int main()
// {
//     untie();
//     while(getline(cin, s))
//     {
//         if(s == "#") break;
//         int ans = 0;
        
//         s = "*" + s;
//         for(int i = 1; i + 7 <= s.size() - 1; i++)
//         {
//             if(check(i)) ans++;
//         }
//         cout << ans << '\n';
//     }
//     return 0;
// }

//20222202
//12345678




//H
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// const int N = 1e5 + 5;
// int T, n, m;
// int nb[N];

// int tree[N*4];
// bool vis[N*4];

// int ls(int p) { return p << 1;}//左子
// int rs(int p) { return p << 1 | 1;}//右子

// void pushup(int p)//最大值传递
// {
//     int pl = ls(p), pr = rs(p);
//     tree[p] = max(tree[pl] * vis[pl], tree[pr] * vis[pr]);//不存在记为 0
// }

// void build(int p, int pl, int pr)
// {
//     vis[p] = 1;
//     if(pl == pr)
//     {
//         tree[p] = nb[pl];
//         return;
//     }
//     int mid = (pl + pr) >> 1;
//     build(ls(p), pl, mid);
//     build(rs(p), mid + 1, pr);
//     pushup(p);
// }

// void update(int L, int R, int p, int pl, int pr)//去除区间内元素（状态置为不存在即可）
// {
//     if(L <= pl && pr <= R)
//     {
//         vis[p] = 0;
//         return;
//     }
//     int mid = (pl + pr) >> 1;
//     //节点存在就深入访问
//     int nls = ls(p), nrs = rs(p);
//     if(L <= mid && vis[nls]) update(L, R, nls, pl, mid);
//     if(R > mid && vis[nrs]) update(L, R, nrs, mid + 1, pr); 
//     pushup(p);   
// }

// int main()
// {
//     scanf("%d", &T);
//     while(T--)
//     {
//         scanf("%d%d", &n, &m);
//         for(int i = 1; i <= n; i++)
//             scanf("%d", &nb[i]);
//         build(1, 1, n);
//         while(m--)
//         {
//             int l, r;
//             scanf("%d%d", &l, &r);
//             update(l, r, 1, 1, n);
//             //返回剩余全体区间最大值
//             printf("%d\n", tree[1] * vis[1]);
//         }
//     }
//     return 0;
// }





//D
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
const int N = 1e5 + 5;
int n;
map<int, int> mp;
int main()
{
    untie();
    int T;
    cin >> T;
    while(T--)
    {
        int ans = -1;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int x; 
            cin >> x;
            mp[x]++;
        }
        for(auto x : mp)
        {
            
        }
        mp.clear();
    }
    return 0;
}

//1 1 2 2
//
//2 2 2 6 6
//3 2
//2 2 6 6 6
//2 2 2 6 6 6

//2 2 2 2 6 6 6
//1 1 2 2 3 3

//1 1 1 2 2 3 3 3

//以偶数次到达最后一个盘子，






















