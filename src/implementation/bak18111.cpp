#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,b;
int a[504][504];
int mn = 987654321;
int h;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> b;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
			s.insert(a[i][j]);
		}
	}
	
	for(int e = 0; e <= 256; e++){
		int x = 0; 
		int y = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(a[i][j] > e) {
					y += a[i][j] - e;
				} else if(a[i][j] < e){
					x += e - a[i][j];
				}
			}
		}
		if(y + b >= x) {
			int time = y * 2 + x;
			if(mn >= time){
				mn = time;
				h = e;
			}
		}
	}
	cout << mn << " " << h;
	return 0;
}