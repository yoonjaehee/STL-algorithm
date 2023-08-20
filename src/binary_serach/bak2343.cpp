#include <iostream>
#include <vector>
using namespace std;
int main(){
    int len,blue;
    int start = 0;
    int end = 0;
    scanf("%d %d",&len,&blue);
    vector<int> a(len);
    for(int i=0;i<len;i++){
        int temp;
        scanf("%d",&temp);
        if(start<a[i]){
            start = a[i];
        }
        end = end + a[i];
    }
    while(start<=end){
        int mid = (start+end)/2;
        int sum = 0;
        int cnt = 0;
        for(int i=0;i<len;i++){
            if(sum+a[i] > mid){
                cnt++;
                sum = 0;
            }
            sum +=a[i]; 
        }
        if(sum != 0){
            count++;
        }
        if(cnt>blue){
            start = mid + 1;
        }
        else{
            end = mid-1;
        }
    }
}