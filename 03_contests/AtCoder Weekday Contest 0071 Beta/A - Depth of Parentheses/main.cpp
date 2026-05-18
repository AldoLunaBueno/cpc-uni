// Accepted
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int depth= 0;
    int max_depth = 0;
    for (char c : s) {
        if (c == '(') {
            depth++;
        } else {
            depth--;
        }
        max_depth = max(max_depth, depth);
    }
    cout << max_depth;
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
