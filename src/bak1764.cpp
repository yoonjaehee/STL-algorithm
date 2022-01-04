#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    vector<string> v;
    for (int i = 0; i < n + m; i++) {
        scanf("%s",s);
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    vector<string> r;
    for (int i = 1; i < n + m; i++) {
        if (v[i].compare(v[i - 1]) == 0)
            r.push_back(v[i++]);
    }
    cout << r.size() << "\n";
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << "\n";
    }
}