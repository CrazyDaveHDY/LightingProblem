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
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

//输出模块
inline void print(int x, int y)
{
    char ch;
    scanf("%c", &ch);
    system("clear"); //刷新终端
    printf("n = %d ，当前进行第 %d 步操作\n", n, ans);
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(i==x && y==j) printf("@");
            else if(vis[i][j]) printf("#");
            else printf(".");
        }
        printf("\n");
    }
    printf("@ 当前点击的灯泡\n");
    printf("# 被点亮的灯泡\n");
    printf(". 未被点亮的灯泡\n");
}

//点亮 (x, y) 四周的灯泡
void update(int x, int y)
{
    ans++;
    vis[x-1][y]=1;
    vis[x+1][y]=1;
    vis[x][y+1]=1;
    vis[x][y-1]=1;
}

void solve()
{
    for(int i=1; i<=n; ++i)
        if(a[i]) update(1, i), print(1, i); //确定第一行状态
    for(int i=2; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            if(!vis[i-1][j]) update(i, j), print(i, j); //递推得出第 i 行状态
    for(int i=1; i<=n; ++i)
        if(!vis[n][i]) update(n, i+1), print(n, i+1);
}
