#include <iostream>
using namespace std;

static long long a[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    long long b, c;        // 형 일치
    cin >> b >> c;

    long long res = 0;     // 합계는 64비트
    for (int i = 0; i < n; i++) {
        res += 1; // 총감독 1명은 무조건

        long long remain = a[i] - b;
        if (remain > 0) {
            // ceil(remain / c)
            res += (remain + c - 1) / c;
        }
    }

    cout << res;
    return 0;
}
