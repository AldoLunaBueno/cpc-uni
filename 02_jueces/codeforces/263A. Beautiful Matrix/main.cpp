// 263A - Beautiful Matrix
// Accepted

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k = 0;
    for (; k < 25; k++) {
        int a;
        cin >> a;
        if (a == 1) break;
    }
    int i = k / 5;
    int j = k % 5;
    cout << abs(2-i) + abs(2-j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
