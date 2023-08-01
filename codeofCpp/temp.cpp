#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
const double eps = 1e-10;
const int N = 250;
double a[N][N], x[N]; // 增广矩阵、解向量
int link[N][N];       // 给每种状态编号
int cnt = 0;              // 状态编号最大值
int equ = 0, var = 0;         // equ 个方程、var 个变量

void init()
{
    equ = var = 210;
    cnt = 0;
    memset(link, -1,  sizeof(link));
    for(int i = 0; i < 20; i++)
        for(int j = 0; j <= i; j++)
            link[i][j] = cnt++;
}

double Gauss() // 默认有解
{
    int row, col, max_r;
    row = col = 0;
    while(row < equ && col < var)
    {
        max_r = row;
        for(int i = row + 1; i < equ; i++)
            if(fabs(a[i][col]) - fabs(a[max_r][col]) > eps)
                max_r = i;
        if(max_r != row)
        {
            for(int j = col; j <= var; j++)
                swap(a[row][j], a[max_r][j]);
        }
        if(fabs(a[row][col]) < eps)
        {
            col++;
            continue;
        }
        for(int i = row + 1; i < equ; i++)
        {
            if(fabs(a[i][col]) > eps)
            {
                double t = a[i][col] / a[row][col];
                a[i][col] = 0.0;
                for(int j = col + 1; j <= var; j++)
                    a[i][j] -= a[row][j] * t;
            }
        }
        row++;
        col++;
    }
    for(int i = equ - 1; i >= 0; i--)
    {
        if(fabs(a[i][i]) < eps) continue;
        double tmp = a[i][var];
        for(int j = i + 1; j < var; j++)
            tmp -= a[i][j] * x[j];
        x[i] = tmp / a[i][i];
    }
    return x[0];
}


int main()
{
    init();
    double p;
    while(~scanf("%lf", &p))
    {
        memset(a, 0, sizeof(a));
        // 构建增广矩阵
        int x; // 当前状态编号
        for(int i = 0; i < 20; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                x = link[i][j];
                a[x][x] = 1;
                a[x][210] = 1;
                a[x][link[i][j + 1]] -= p;
                a[x][link[i][max(0, j - 2)]] -= (1 - p);
            }
            x = link[i][i];
            a[x][x] = 1;
            a[x][210] = 1;
            a[x][link[i][max(0, i - 2)]] -= (1 - p);
            a[x][link[i + 1][i]] -= p;
        }
        printf("%.6lf\n", Gauss());
    }
    return 0;
}




