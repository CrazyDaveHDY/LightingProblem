#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define INF 0x3f3f3f3f
using namespace std;

const int dx[]={-1, 0, 1, 0};
const int dy[]={0, 1, 0, -1};
const int lim[]={0, 0, 2, 3, 6, 9, 12, 15};

int n, ans=INF, vis[10][10];

inline bool check(int x, int y)
{
    if(x<1 || y<1 || x>n || y>n) return false;
    return true;
}

void dfs(int x, int y, int num, int res)
{
    if(!res)
    {
        ans=min(ans, num);
        return;
    }
    if(x==n+1 && y==1) return;
    if(num<lim[n])
    {
        int val=res;
        for(int i=0; i<4; ++i)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(check(nx, ny) && !vis[nx][ny]) val--;
            vis[nx][ny]++;
        }
        if(y==n) dfs(x+1, 1, num+1, val);
        else dfs(x, y+1, num+1, val);
        for(int i=0; i<4; ++i) vis[x+dx[i]][y+dy[i]]--;
    }
    if(y==n) dfs(x+1, 1, num, res);
    else dfs(x, y+1, num, res);
}

int main()
{
    scanf("%d", &n);
    dfs(1, 1, 0, n*n);
    printf("%d\n", ans);
    return 0;
}