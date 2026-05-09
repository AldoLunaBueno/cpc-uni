#include <bits/stdc++.h>
using namespace std;
// accepted

void solve() {
    long long n, k;
    cin >> n >> k;

    if (n > k) {
        if (n % k == 0) {
            cout << 1;
        } else {
            cout << 2;
        }
    } else if (n < k) {
        cout << (k + n - 1) / n; //ceil(k/n);
    } else {
        cout << 1;
    }
    cout << "\n";
}

int main() {
    // Optimización de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}