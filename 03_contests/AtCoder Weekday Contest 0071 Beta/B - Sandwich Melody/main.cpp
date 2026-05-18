// Accepted
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    s += "d";
    int curr_count = 1;
    long long count[] = {1, 1, 1};
    char sandwich[] = {'a', 'b', 'c'};
    long long sd_count = 0;
    char kept = 'c';
    for (char c : s) {
        if (kept != c) {
            count[2] = curr_count;
            if (sandwich[0] == sandwich[2]) {
                sd_count += count[0]*count[2];
            }
            
            sandwich[0] = sandwich[1];
            sandwich[1] = sandwich[2];
            sandwich[2] = c;

            count[0] = count[1];
            count[1] = count[2];
            count[2] = 1;
            curr_count = 1;
            kept = c;
        } else {
            curr_count++;
        }
    }
    cout << sd_count;
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
