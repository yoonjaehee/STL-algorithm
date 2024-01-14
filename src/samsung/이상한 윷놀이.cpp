#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[13][13];  // 빨간건지 파란건지 흰건지
vector<vector<int>> vec;
vector<vector<int>> vec3;
vector<vector<int>> vec4;
int n,k;
int res = 0;
int px[4] = {1,-1,0,0};
int py[4] = {0,0,-1,1};
bool comp(vector<int> &a,vector<int> &b){
    if(a[3] <= b[3]){
        return true;
    }
    else{
        return false;
    }
}
void dfs(int start,vector<vector<int>> vec2){
    if(start >1000){
        res = -1;
        return;
    }
    int sty,stx;
    /*printf("before\n");
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            printf("%d",vec2[i][t]);
        }
        printf("\n");
    }*/
    for(int i=0;i<vec.size();i++){
        vector<vector<int>> vec4;
        sty = vec[i][0];
        stx = vec[i][1];
        int ny = vec[i][0] + py[vec[i][2]];
        int nx = vec[i][1] + px[vec[i][2]];
        for(int t=0;t<vec.size();t++){ // 같이 움직이는 것들 추려내기 
            if((vec[i][0] == vec[t][0]) && (vec[i][1] == vec[t][1]) && (vec[i][3] <= vec[t][3])){
                vec4.push_back(vec[t]);
            }
        }
        sort(vec4.begin(),vec4.end(),comp);
        int len = vec4.size();
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || arr[ny][nx] == 2){ // 파란색
            ny = sty - py[vec[i][2]];
            nx = stx - px[vec[i][2]];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || arr[ny][nx] == 2){
                ny = sty;
                nx = stx;
            }
            if(vec[i][2] == 0){
                vec[i][2] = 1;
            }
            else if(vec[i][2] == 1){
                vec[i][2] = 0;
            }
            else if(vec[i][2] == 2){
                vec[i][2] = 3;
            }
            else if(vec[i][2] == 3){
                vec[i][2] = 2;
            }
            if(arr[ny][nx] == 1){
                for(int t=0;t<len;t++){
                    vector<int> temp2 = vec4[t];
                    vec3.push_back(temp2);
                }
                for(int t=len-1;t>=0;t--){
                    vec2[sty][stx]-=1;
                    vec[vec3[t][4]][0] = ny;
                    vec[vec3[t][4]][1] = nx;
                    vec2[ny][nx]+=1;
                    vec[vec3[t][4]][3] = vec2[ny][nx];
                    if(vec2[ny][nx] == 4){
                        res = start+1;
                        return;
                    }
                }
                vec3.clear();
            }
            else{
                for(int t=0;t<len;t++){
                    vector<int> temp2 = vec4[t];
                    vec2[sty][stx]-=1;
                    vec[temp2[4]][0] = ny;
                    vec[temp2[4]][1] = nx;
                    vec2[ny][nx]+=1;
                    vec[temp2[4]][3] = vec2[ny][nx];
                    if(vec2[ny][nx] == 4){
                        res = start+1;
                        return;
                    }
                }
            }
        }
        else if(arr[ny][nx] == 1){ // 빨간색0.
                for(int t=0;t<len;t++){
                    vector<int> temp2 = vec4[t];
                    vec3.push_back(temp2);
                }
                for(int t=len-1;t>=0;t--){
                    vec2[sty][stx]-=1;
                    vec[vec3[t][4]][0] = ny;
                    vec[vec3[t][4]][1] = nx;
                    vec2[ny][nx]+=1;
                    vec[vec3[t][4]][3] = vec2[ny][nx];
                    if(vec2[ny][nx] == 4){
                        res = start+1;
                        return;
                    }
                }
                vec3.clear();
        }
        else{ // 흰색
            for(int t=0;t<len;t++){
                vector<int> temp2 = vec4[t];
                vec2[sty][stx]-=1;
                vec2[ny][nx]+=1;
                vec[temp2[4]][0] = ny;
                vec[temp2[4]][1] = nx;
                vec[temp2[4]][3] = vec2[ny][nx];
                if(vec2[ny][nx] == 4){
                        res = start+1;
                        return;
                    }
            }
        }
    }
    /*printf("after\n");
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            printf("%d",vec2[i][t]);
        }
        printf("\n");
    }*/
    dfs(start+1,vec2);
}
int main(){
    scanf("%d %d",&n,&k);
    vector<vector<int>> arr2(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    for(int i=0;i<k;i++){
        vector<int> temp;
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        temp.push_back(a-1);
        temp.push_back(b-1);
        temp.push_back(c-1);
        if(arr2[a-1][b-1] != 0){
            arr2[a-1][b-1]+=1;
            temp.push_back(arr2[a-1][b-1]);
        }
        else{
            arr2[a-1][b-1] = 1;
            temp.push_back(1);
        }
        temp.push_back(i);
        vec.push_back(temp);
    }
    dfs(0,arr2);
    printf("%d",res);
}