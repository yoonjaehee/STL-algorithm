#include <iostream>
#include <vector>
using namespace std;
int n,m,x,y,k;
int arr[21][21];
vector<int> vec;
vector<int> tec(6,0); // 정육면체 숫자보관
int temp = 0;
int temp2,temp3,temp4;
void mov(int py,int px,int start){
    bool can = false;
    if(start == k){
        return;
    }
    if(vec[start] == 1){ // 동쪽
        if(px + 1 < m){
            can = true;
            px+=1;
            temp = tec[4];
            for(int i=4;i>1;i--){
                tec[i] = tec[i-1];
            }
            tec[1] = temp;
            if(arr[py][px] == 0){
                arr[py][px]=tec[3];
            }
            else{
                tec[3]=arr[py][px];
                arr[py][px] = 0;
            }
        }
    }
    else if(vec[start] == 2){ // 서쪽
        if(px - 1 >= 0){
            can = true;
            px-=1;
            temp = tec[1];
            for(int i=1;i<4;i++){
                tec[i] = tec[i+1];
            }
            tec[4] = temp;
            if(arr[py][px] == 0){
                arr[py][px]=tec[3];
            }
            else{
                tec[3]=arr[py][px];
                arr[py][px] = 0;
            }
        }
    }
    else if(vec[start] == 3){ // 북쪽
        if(py - 1 >= 0){
            can = true;
            py-=1;
            temp = tec[0];
            temp2 = tec[1];
            temp3 = tec[3];
            temp4 = tec[5];
            tec[0] = temp3;
            tec[1] = temp;
            tec[3] = temp4;
            tec[5] = temp2;
            if(arr[py][px] == 0){
                arr[py][px]=tec[3];
            }
            else{
                tec[3]=arr[py][px];
                arr[py][px] = 0;
            }
        }
    }
    else if(vec[start] == 4){ // 남쪽
        if(py + 1 < n){
            can = true;
            py+=1;
            temp = tec[0];
            temp2 = tec[1];
            temp3 = tec[3];
            temp4 = tec[5];
            tec[0] = temp2;
            tec[1] = temp4;
            tec[3] = temp;
            tec[5] = temp3;
            if(arr[py][px] == 0){
                arr[py][px]=tec[3];
            }
            else{
                tec[3]=arr[py][px];
                arr[py][px] = 0;
            }
        }
    }
    if(can){
       
        printf("%d\n",tec[1]);
    }
    mov(py,px,start+1);
}
int main(){
    scanf("%d %d %d %d %d",&n,&m,&y,&x,&k);
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    for(int i=0;i<k;i++){
        scanf("%d",&temp);
        vec.push_back(temp);
    }
    mov(y,x,0);
}