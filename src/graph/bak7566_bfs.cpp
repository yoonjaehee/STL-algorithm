#include <iostream>
#include <queue>
using namespace std;
int n, m;
int arr[1001][1001];
int px[4] = {0, 0, 1, -1};
int py[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;
int max(int a, int b)
{
    return a > b ? a : b;
}
void bfs()
{
    while (!q.empty())
    {
        pair<int,int>cur=q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + px[i];
            int ny = cur.second + py[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (arr[nx][ny] == 0)
                {
                    arr[nx][ny] = arr[cur.first][cur.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}
int main()
{
    int Max = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        for (int p = 0; p < n; p++)
        {
            scanf("%d", &arr[p][i]);
            if (arr[p][i] == 1)
            {
                q.push({p, i});
            }
        }
    }
    bfs();
    for (int i = 0; i < m; i++)
    {
        for (int p = 0; p < n; p++)
        {
            if(arr[p][i]==0){
                printf("-1");
                return 0;
            }
            Max = max(Max, arr[p][i]);
        }
    }
    printf("%d", Max-1);
}