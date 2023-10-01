#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, temp;
    vector<long long> v(1001, 0);       // int 말고 long long이 필요하다. 범위는 M만큼
    long long sum = 0, answer = 0;      // 이것도 당연히 int형을 초과하므로 long long

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        sum += temp;
        v[sum % M]++;                   // 해당 i구간까지의 누적합
        if (sum % M == 0)
        {
            answer++;                   // M으로 나누어 떨어지면 ++
        }
    }
    for (int i = 0; i <= M; i++)
    {
        answer += v[i] * (v[i] - 1) / 2;    // nC2의 느낌으로 풀어야 한다. 설명은 블로그에 !!!
    }

    cout << answer;

    return 0;
}