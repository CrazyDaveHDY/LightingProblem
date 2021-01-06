#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include "header.h"
#define LL long long
#define LD long double
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, ans, ans1=INF, ans2, a[MAXN], vis[MAXN][MAXN];

vector<int> vec;

int main()
{
    //输入模块
    printf("请输入灯的行列数n (n行n列):");
    scanf("%d", &n);
    system("clear");

    for(int sta=0; sta<(1<<n); ++sta) //枚举状态
    {
        for(int i=0; i<n; ++i)
            if((sta>>i)&1) update(1, i+1); //确定第一行状态
        for(int i=2; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                if(!vis[i-1][j]) update(i, j); //递推出第 i 行状态
        for(int i=1; i<=n; ++i)
            if(!vis[n][i]) update(n, i+1);
        if(ans<ans1) ans1=ans, ans2=sta; //如果操作步数更少，更新最优方案

        ans=0;
        for(int i=0; i<=n; ++i)
            for(int j=0; j<=n; ++j) vis[i][j]=0; //初始化
    }
    for(int i=0; i<n; ++i)
        if((ans2>>i)&1) a[i+1]=1;
    solve();
    printf("最少需要点击 %d 盏灯，利用率为 %.10lf%%\n", ans1, 25.0*n*n/ans1);
    return 0;
}
