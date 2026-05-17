// 339A. Helpful Maths
// Accepted
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int* count = new int[3];
    string s;
    cin >> s;
    string num;
    stringstream ss(s);
    while (getline(ss, num, '+')) {
        if (num == "1") {
            count[0]++;
        } else if (num == "2") {
            count[1]++;
        } else {
            count[2]++;
        }
    }

    int total_count = count[0] + count[1] + count[2];
    bool first = true;
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < count[j]; i++) {
            if (first) {
                cout << j+1;
                first = false;
                continue;
            }
            cout << "+" << j+1;
        }
    }
    if (first == true) cout << 0;
    cout << "\n";

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
