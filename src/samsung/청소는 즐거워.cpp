#include <iostream>
#define DIR_NUM 4
#define MAX_N 499
using namespace std;
int n;
int curr_x, curr_y;
int move_dir, move_num;
int ans;
int grid[MAX_N][MAX_N];
int dust_ratio[DIR_NUM][5][5] = {
    {
        {0,  0, 2, 0, 0},
        {0, 10, 7, 1, 0},
        {5,  0, 0, 0, 0},
        {0, 10, 7, 1, 0},
        {0,  0, 2, 0, 0},
    },
    {
        {0,  0, 0,  0, 0},
        {0,  1, 0,  1, 0},
        {2,  7, 0,  7, 2},
        {0, 10, 0, 10, 0},
        {0,  0, 5,  0, 0},
    },
    {
        {0, 0, 2,  0, 0},
        {0, 1, 7, 10, 0},
        {0, 0, 0,  0, 5},
        {0, 1, 7, 10, 0},
        {0, 0, 2,  0, 0},
    },
    {
        {0,  0, 5,  0, 0},
        {0, 10, 0, 10, 0},
        {2,  7, 0,  7, 2},
        {0,  1, 0,  1, 0},
        {0,  0, 0,  0, 0},
    }
};
bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}
void AddDust(int x, int y, int dust) {
    if(!InRange(x, y))
        ans += dust;
    else
        grid[x][y] += dust;
}
void Move() {
    int dx[DIR_NUM] = {0, 1, 0, -1};
    int dy[DIR_NUM] = {-1, 0, 1, 0};
    curr_x += dx[move_dir]; curr_y += dy[move_dir];
    int added_dust = 0;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++) {
            int dust = grid[curr_x][curr_y] * dust_ratio[move_dir][i][j] / 100;
            AddDust(curr_x + i - 2, curr_y + j - 2, dust);
            added_dust += dust;
        }
    // a% 자리에 먼지를 추가합니다.
    AddDust(curr_x + dx[move_dir], curr_y + dy[move_dir], grid[curr_x][curr_y] - added_dust);
}
bool End() {
    return !curr_x && !curr_y;
}
int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d",&grid[i][t]);
    curr_x = n / 2; curr_y = n / 2;
    move_dir = 0; move_num = 1;
    while(!End()) {
        for(int i = 0; i < move_num; i++) {
            Move();
            // 이동하는 도중 (0, 0)으로 오게 되면,
            // 움직이는 것을 종료합니다.
            if(End())
                break;
        }
        move_dir = (move_dir + 1) % 4;
        if(move_dir == 0 || move_dir == 2)
            move_num++;
    }
    cout << ans;
    return 0;
}