// 题意：一个软件有 m 个子系统，会产生 n 种bug。某人一天发现一个bug，这个bug属于一个子系统。每个bug属于某个子系统的概率是 1 / m，属于某种分类的概率是 1 / n 问发现 n 种bug，每个子系统都发现bug的天数的期望
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const double eps = 1e-9;
// const int N = 1e3 + 10;
// double dp[N][N]; 

// int main()
// {
//     int n, m;
//     while(cin >> n >> m)
//     {
        
//     }
//     return 0;
// }


// 给 n 条通道和 m 元钱，每条通道有三种情况：直接通过、碰上士兵则损失 1 元并返回原地（不够钱则死亡）、死路不通则返回原地。
// 概率分别是 p、q、1-p-q，问在选择最优方式的前提下成功逃生的概率。
// 定义 dp[i][j] 为选择第 i 条通道时还剩下 j 元的概率
#include <iostream>
using namespace std;
#define ll long long
const double eps = 1e-9;
const int N = 1e3 + 10;
double dp[N][N]; 

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        
    }
    return 0;
}
