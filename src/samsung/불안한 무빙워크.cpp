#include <iostream>
using namespace std;
int n,k;
int arr[2][50];
bool visited[50];
int res= 0;
void checking(){
    for(int i=n-1;i>=0;i--){
        if(i== n-1){
            visited[i] = false;
            continue;
        }
        if(visited[i] && arr[0][i+1] > 0){
            visited[i] = false;
            visited[i+1] = true;
            arr[0][i+1]--;
        }
    }

}
void move(){
    int tmp = arr[0][n-1];
    for(int i=n-1;i>=0;i--){
        arr[0][i] = arr[0][i-1];
        visited[i] = false;
        visited[i+1] = true;
    }
    arr[0][0] = arr[1][0];
    for(int i=0;i<n-1;i++){
        arr[1][i] = arr[1][i+1];
    }
    arr[1][n-1] = tmp;
}
int cnt;
int walk(){
    if(cnt >= k){
        return 0;
    }
    move(); // 무빙워크 한칸씩
    checking(); // 사람 옮기기
    if(arr[0][0]>0 && !visited[0]){
        arr[0][0]--;
        visited[0]= true;
    }
    cnt = 0; // 0인갯수확인
    for(int i=0;i<2;i++){
        for(int t=0;t<n;t++){
            if(arr[i][t] <= 0){
                cnt++;
            }
        }
    }
    res++;
    walk();
}
int main(){
    scanf("%d %d",&n,&k);
    int temp;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        arr[0][i] = temp;
    }
    for(int i=n-1;i>=0;i--){
        scanf("%d",&temp);
        arr[1][i] = temp;
    }
    walk();
    printf("%d",res);
}