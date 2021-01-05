#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <unistd.h>
#include "header.h"
#define LL long long
#define LD long double
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, ans, a[MAXN], vis[MAXN][MAXN];

int main()
{
    printf("请输入灯的行列数n (n行n列):");
    scanf("%d", &n);
    system("clear");
    for(int i=1; i<=n; ++i)
    {
        if(i%4==1 || i%4==2) a[i]=0;
        else a[i]=1;
    }
    if(n%4==3) a[n]=0;
    solve();
    printf("最少需要点击 %d 盏灯，利用率为 %.10lf%%\n", ans, 25.0*n*n/ans);
    return 0;
}