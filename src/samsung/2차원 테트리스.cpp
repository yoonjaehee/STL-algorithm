#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<int>> vec;
int blue[10][4]={0,}; // blue
int red[10][4]={0,};
int ans = 0;
void dfs(int start){
    if(start == n){
        return;
    }
    vector<int> tmp = vec[start]; // 명령어
    // 내려가기
    if(tmp[2] == 1){ // 한칸짜리
        int sty = tmp[0];
        int stx = tmp[1];
        while(sty < 9 && blue[sty+1][stx] == 0){ // blue
            sty++;
        }
        blue[sty][stx] = 1;
        sty = tmp[1];
        stx = (3-tmp[0]);
        while(sty < 9 && red[sty+1][stx] == 0){
            sty++;
        }
        red[sty][stx] = 1;
    }
    else if(tmp[2] == 2){ // 정위치 오른쪽
        int sty1 = tmp[0];
        int stx1 = tmp[1];
        int sty2 = tmp[0];
        int stx2 = tmp[1]+1;
        while(sty1 < 9 && sty2 < 9 && blue[sty1+1][stx1] == 0 && blue[sty2+1][stx2] == 0){
            sty1++;
            sty2++;
        }
        blue[sty1][stx1] = 1;
        blue[sty2][stx2] = 1;
        sty1 = tmp[1];
        stx1 = 3-tmp[0];
        sty2 = tmp[1]+1;
        stx2 = 3-tmp[0];
        while(sty1< 9 && sty2 < 9 && red[sty1+1][stx1] == 0 && red[sty2+1][stx2] == 0){
            sty1++;
            sty2++;
        }
        red[sty1][stx1] = 1;
        red[sty2][stx2] = 1;
    }
    else{ // 정위치, 아래
        int sty1 = tmp[0];
        int stx1 = tmp[1];
        int sty2 = tmp[0]+1;
        int stx2 = tmp[1];
        while(sty1 < 9 && sty2 < 9 && blue[sty1+1][stx1] == 0 && blue[sty2+1][stx2] == 0){
            sty1++;
            sty2++;
        }
        blue[sty1][stx1] = 1;
        blue[sty2][stx2] = 1;
        sty1 = tmp[1];
        stx1 = 3-tmp[0];
        sty2 = tmp[1];
        stx2 = (3-tmp[0]-1);
        while(sty1 < 9 && sty2 < 9 && red[sty1+1][stx1] == 0 && red[sty2+1][stx2] == 0){
            sty1++;
            sty2++;
        }
        red[sty1][stx1] = 1;
        red[sty2][stx2] = 1;
    }
    // 다찬거 없애기 + 정렬
    for(int i=1;i<5;i++){
        int redcnt = 0;
        int bluecnt = 0;
        bool change = false;
        for(int t=0;t<4;t++){
            if(blue[10-i][t] == 1){
                bluecnt+=1;
            }
            if(red[10-i][t] == 1){
                redcnt+=1;
            }
        }
        if(bluecnt == 4){
            for(int t=i;t<=5;t++){
                for(int q=0;q<4;q++){
                    blue[10-t][q] = blue[10-t-1][q];
                }
            }
            change = true;
        }
        if(change){
            i-=1;
            ans++;
            continue;
        }
        if(redcnt == 4){
            for(int t=i;t<=5;t++){
                for(int q=0;q<4;q++){
                    red[10-t][q] = red[10-t-1][q];
                }
            }
            change = true;
        }
        if(change){
            i-=1;
            ans++;
            continue;
        }
    }
    // 초과행 없애기
    int len1 = 0; // blue 최대길이
    int len2 = 0; // red 최대길이
    for(int i=5;i>3;i--){
        for(int t=0;t<4;t++){
            if(blue[i][t] != 0){
                if(i == 4){
                    len1 = 2;
                }
                else{
                    len1 = 1;
                }
            }
            if(red[i][t] != 0){
                if(i == 4){
                    len2 = 2;
                }
                else{
                    len2 = 1;
                }
            }
        }
    }
    for(int i=9;i>3;i--){
        for(int t=0;t<4;t++){
            blue[i][t] = blue[i-len1][t];
            red[i][t] = red[i-len2][t];
        }
    }
    /*printf("%d\nblue\n",start);
    for(int i=6;i<10;i++){
        for(int t=0;t<4;t++){
            printf("%d ",blue[i][t]);
        }
        printf("\n");
    }
    printf("red\n");
    for(int i=6;i<10;i++){
        for(int t=0;t<4;t++){
            printf("%d ",red[i][t]);
        }
        printf("\n");
    }
    */
    dfs(start+1);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y,d;
        scanf("%d %d %d",&d,&y,&x);
        vector<int> temp;
        temp.push_back(y);
        temp.push_back(x);
        temp.push_back(d);
        vec.push_back(temp);
    }
    dfs(0);
    int res = 0;
    for(int i=6;i<10;i++){
        for(int t=0;t<4;t++){
            if(blue[i][t] == 1){
                res++;
            }
            if(red[i][t] == 1){
                res++;
            }
        }
    }
    printf("%d\n%d",ans,res);
}